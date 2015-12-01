#include "Event.h"
#include "ICSAccess.h"
#include <string>
#include <wx/wx.h>
#include <wx/datetime.h>
#include <wx/string.h>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

FileNotFoundException::FileNotFoundException(const string& message) : errorDescription(message) { }

string FileNotFoundException::what() const
{
    return errorDescription;
}


ICSAccess::ICSAccess(const string& filepath)
{
    filename = filepath;
}

vector<Event> ICSAccess::getEvents(){
	string Line, NextLine;
	Component CurrentComponent = Component::VCALENDAR, PrevComponent = Component::VCALENDAR;
	string summary, eventStart, eventEnd, UID, prevUID;
	string freq, until;
	int rcount;
	bool recurs = false, hasSum = false, hasEnd = false, useable = true;
	wxDateTime WXstart, WXend;
	Event currentEvent;
	vector<Event> events;
	FrequencyEnum eventFreq;
	fstream File;

	File.open(filename.c_str(), ios::in | ios::binary);

	if (!File.is_open()) {
        throw FileNotFoundException("Error: File '" + filename + "' could not be read");
	}

	getline(File, NextLine);

	while (!File.eof()) {
		Line = NextLine;
		// lines can be wrapped after 75 octets so we may have to unwrap them
		for (;;) {
			getline(File, NextLine);
			if (NextLine[0] != '\t' && NextLine[0] != ' ')
				break;
			Line += NextLine.substr(1);
		}

		switch (CurrentComponent) {
			case Component::VCALENDAR:
				if (Line.find("BEGIN:VEVENT") == 0) {
					CurrentComponent = Component::VEVENT;
				}
				break;

			case Component::VEVENT:
				if (Line.find("UID") == 0) {
                    prevUID = UID;
                    UID = getProperty(Line);

				} else if (Line.find("DTSTART") == 0) {
					eventStart = getProperty(Line);

					if (eventStart.length() < 15){
                        useable = false;
					}
					else{

					useable = true;

					string date = eventStart.substr(0,8);

                    date.insert(4,"-");
                    date.insert(7, "-");

                    string time = eventStart.substr(9,6);

                    time.insert(2,":");
                    time.insert(5,":");

                    if (!WXstart.ParseDate(date.c_str())){
                        useable = false;
                    }
                    if (!WXstart.ParseTime(time.c_str())){
                        useable = false;
                    }
					}

				} else if (Line.find("DTEND") == 0) {
					eventEnd = getProperty(Line);

					if (eventEnd.length() < 15){
                        useable = false;
					}
					else{

					string date = eventEnd.substr(0,8);

                    date.insert(4,"-");
                    date.insert(7, "-");

                    string time = eventEnd.substr(9,6);

                    time.insert(2,":");
                    time.insert(5,":");

                    if (!WXend.ParseDate(date.c_str())){
                        useable = false;
                    }
                    if (!WXend.ParseTime(time.c_str())){
                        useable = false;
                    }
					hasEnd = true;
					}

				} else if (Line.find("SUMMARY") == 0) {
					summary = getProperty(Line);
					hasSum = true;

				} else if (Line.find("RRULE") == 0) {
				    recurs = true;
					freq = getSubProperty(Line, "FREQ");
					rcount = atoi(getSubProperty(Line, "COUNT").c_str());
					until = getSubProperty(Line, "UNTIL");
					if (until != "" && useable)
                        rcount = untilToCount(eventStart, freq, until);
                    if (rcount == 0){
                        rcount = 1000;
                    }
                    else if (rcount == (-1))
                        useable = false;
                    if (useable){
                        if (freq == "DAILY")
                            eventFreq = FrequencyEnum::DAILY;
                        if (freq == "WEEKLY")
                            eventFreq = FrequencyEnum::WEEKLY;
                        if (freq == "MONTHLY")
                            eventFreq = FrequencyEnum::MONTHLY;
                        if (freq == "YEARLY")
                            eventFreq = FrequencyEnum::ANNUALLY;
                    }

				} else if (Line.find("END:VEVENT") == 0) {
                    if (useable){
                        if (recurs){
                            currentEvent = Event(summary, WXstart, WXend, eventFreq, rcount);
                        } else {
                            currentEvent = Event(summary, WXstart, WXend);
                        }
                    } else {
                        currentEvent = Event();
                    }
                    events.push_back(currentEvent);
					//TODO: Create new event, push into vector
					CurrentComponent = Component::VCALENDAR;

					recurs = false;
					hasEnd = false;
					hasSum = false;
					useable = false;
					freq = "";
					until = "no";
					summary = "";
					eventStart = "";
                    eventEnd = "";
                    rcount = -1;
                    eventFreq = FrequencyEnum::NONE;
				}
				break;
		}
	}
	File.close();
	return events;
}

int ICSAccess::untilToCount(const string& firstTime, const string& freq, const string& lastTime) const {
    wxDateTime WXstart, WXend;
    wxTimeSpan WXdiff;

    if (firstTime.length() < 15 || lastTime.length() < 15){
        return -1;
    }

    string date = firstTime.substr(0,8);

    date.insert(4,"-");
    date.insert(7, "-");

    string time = firstTime.substr(9,6);

    time.insert(2,":");
    time.insert(5,":");

    if (!WXstart.ParseDate(date.c_str())){
        return -1;
    }
    if (!WXstart.ParseTime(time.c_str())){
        return -1;
    }

    date = lastTime.substr(0,8);

    date.insert(4,"-");
    date.insert(7, "-");

    time = lastTime.substr(9,6);

    time.insert(2,":");
    time.insert(5,":");


    if (!WXend.ParseDate(date.c_str())){
        return -1;
    }
    if (!WXend.ParseTime(time.c_str())){
        return -1;
    }

    if (WXstart.IsEarlierThan(WXend)){
        WXdiff = WXend.Subtract(WXstart);
        if (freq == "DAILY")
            return WXdiff.GetDays();
        else if (freq == "WEEKLY")
            return WXdiff.GetWeeks();
        else if (freq == "MONTHLY")
            return (WXdiff.GetWeeks() / 4);
        else if (freq == "YEARLY")
            return (WXdiff.GetWeeks() / 52);
        else
            return -1;
    } else {
        return -1;
    }
    return 0;
}

void ICSAccess::deleteICS(){
    if (remove(filename.c_str()) != 0)
        throw FileNotFoundException("Error: File '" + filename + "' could not be deleted");

    return;
}

string ICSAccess::getProperty(const string &Line) const {
		// if VALUE=DATE or VALUE=DATE-TIME used, then the date is not directly
		// after the property name so we just search for the string after ':'
		string Temp = Line.substr(Line.find_first_of(':')+1);
		unsigned int Length = Temp.length();
		if (Length > 0 && Temp[Length-1] == '\r')
			Temp.resize(Length-1);
		return Temp;
}

string ICSAccess::getSubProperty(const string &Line, const char *SubProperty) const {
		size_t Pos = Line.find(SubProperty);
		if (Pos == string::npos)
			return "";
		Pos += strlen(SubProperty) + 1;
		return Line.substr(Pos, Line.find_first_of(';', Pos)-Pos);
}

void ICSAccess::addEvent(const Event& eventToAdd){
    ifstream original(filename);
    ofstream temp("./data/temp.txt");
    string line;
    bool written = false;

    while (original >> line){
        if (line.find("BEGIN:VEVENT") == 0 && written == false){
            temp << "BEGIN:VEVENT" << endl;
            temp << "DTSTART:" << eventToAdd.getStart().GetAsDOS() << endl;
            temp << "DTEND:" << eventToAdd.getEnd().GetAsDOS() << endl;
            if (eventToAdd.getFrequency() != FrequencyEnum::NONE){
                if (eventToAdd.getFrequency() == FrequencyEnum::DAILY)
                    temp << "RRULE:FREQ=DAILY;COUNT=" << eventToAdd.getRepeatCount() << ";" << endl;
                if (eventToAdd.getFrequency() == FrequencyEnum::WEEKLY)
                    temp << "RRULE:FREQ=WEEKLY;COUNT=" << eventToAdd.getRepeatCount() << ";" << endl;
                 if (eventToAdd.getFrequency() == FrequencyEnum::MONTHLY)
                    temp << "RRULE:FREQ=MONTHLY;COUNT=" << eventToAdd.getRepeatCount() << ";" << endl;
                 if (eventToAdd.getFrequency() == FrequencyEnum::ANNUALLY)
                    temp << "RRULE:FREQ=YEARLY;COUNT=" << eventToAdd.getRepeatCount() << ";" << endl;

            }
            temp << "SUMMARY:" << eventToAdd.getTitle() << endl;
            temp << "END:VEVENT" << endl;
            written = true;
        }
        temp << line << endl;
    }
    original.close();
    temp.close();
    if (remove(filename.c_str()) != 0)
        return;
        //throw error

    rename("./data/temp.txt", filename.c_str());
}

void ICSAccess::deleteEvent(int eventNum){
    ifstream original(filename);
    ofstream temp("./data/temp.txt");
    string line;
    int eventCount = -1;

    while(getline(original,line)){
        if (line.find("BEGIN:VEVENT") == 0) {
            eventCount++;
        }
        if (eventCount != eventNum){
            temp << line << endl;
        }
    }
    original.close();
    temp.close();
    if (remove(filename.c_str()) != 0)
        return;
        //throw error

    rename("./data/temp.txt", filename.c_str());
}
