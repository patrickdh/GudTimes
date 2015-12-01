#include <iostream>
#include <wx/datetime.h>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <ostream>
#include <istream>
#include <sstream>

#include "wx/arrstr.h"
#include "Calendar.h"
#include "Event.h"

using namespace std;

void searchTimeSlotAnnually(Event event, bool (&table)[24][4], wxDateTime date);
void searchTimeSlotMonthly(Event event, bool (&table)[24][4], wxDateTime date);
void searchTimeSlotWeekly(Event event, bool (&table)[24][4], wxDateTime date);
void searchTimeSlotDaily(Event event, bool (&table)[24][4], wxDateTime date);
void searchTimeSlot(vector<Event> events, int duration, wxDateTime date);
vector<wxDateTime> findValidSlots(bool table[24][4], int duration, wxDateTime date);
void printTable(bool table[24][4]);
bool dateComparison(wxDateTime, wxDateTime);
int startMinuteToIndexConversion(int minutes);
int endMinuteToIndexConversion(int minutes);

bool orderStartTime(int start1, int start2){
    return (start1 < start2);
}

int main(int argc, char** argv)
{
    vector<string> all_args;

    if (argc > 1) {
        all_args.assign(argv + 1, argv + argc);

        vector<Event> events;
        string PATH = all_args[0];
        string durationString = all_args[1];
        string dateString = all_args[2];
        cout << PATH << endl;
        cout << durationString << endl;
        cout << dateString << endl;
        wxDateTime date, start, finish;

        int duration = atoi(durationString.c_str());

        wxString wxDateString(dateString);
        date.ParseDate(wxDateString);
        try {
            Calendar cal(PATH, false);
            events = cal.getEvents();
        } catch(FileNotFoundException) {
            return -1;
        }

    /* Test Case Event Times
        wxDateTime bufferStart(11, wxDateTime::Sep, 2015, 0);
        wxDateTime bufferEnd(11, wxDateTime::Sep, 2015, 3);
        Event buffer("Event 1", bufferStart, bufferEnd, FrequencyEnum::ANNUALLY, 3);
        events.push_back(buffer);

        bufferStart = wxDateTime(7, wxDateTime::Sep, 2015, 5);
        bufferEnd = wxDateTime(7, wxDateTime::Sep, 2015, 8);
        buffer = Event("Event 2", bufferStart, bufferEnd, FrequencyEnum::DAILY, 10);
        events.push_back(buffer);

        bufferStart = wxDateTime(11, wxDateTime::Aug, 2015, 10, 30);
        bufferEnd = wxDateTime(11, wxDateTime::Aug, 2015, 13);
        buffer = Event("Event 3", bufferStart, bufferEnd, FrequencyEnum::MONTHLY, 2);
        events.push_back(buffer);

        bufferStart = wxDateTime(11, wxDateTime::Sep, 2015, 18);
        bufferEnd = wxDateTime(11, wxDateTime::Sep, 2015, 21);
        buffer = Event("Event 4", bufferStart, bufferEnd);
        events.push_back(buffer);

        bufferStart = wxDateTime(4, wxDateTime::Sep, 2015, 18);
        bufferEnd = wxDateTime(4, wxDateTime::Sep, 2015, 23);
        buffer = Event("Event 5", bufferStart, bufferEnd, FrequencyEnum::WEEKLY, 3);
        events.push_back(buffer);*/

        searchTimeSlot(events, duration, date);
    }

    return 0;
}

void searchTimeSlot(vector<Event> events, int duration, wxDateTime date){
    int numberEvents = events.size();
    int i, j, ei; //ei is the event index
    int s_hour, s_minute;
    int e_hour, e_minute;
    int s_minuteIndex, e_minuteIndex;
    int freeSlots;
    Event eventToCheck;
    FrequencyEnum frequency;
    wxDateTime startDT, endDT, start, finish;
    vector<wxDateTime> validTimes;
    wxArrayString generatedTimes;
    bool freeTimeTable[24][4];
    bool setMinute;

    cout << "Date we want: " << date.FormatISODate() << endl;

     for (int i =0; i<events.size(); i++){
        start = events[i].getStart();
        finish = events[i].getEnd();
        cout << events[i].getTitle() << " : " << start.FormatISODate() << " to " << finish.FormatISODate() << " --- " << start.FormatISOTime() << " to " << finish.FormatISOTime() << endl;
    }

    //Initialize all of the available slots to be true
    for (i = 0; i <24 ; i++){
        for (j=0; j<4 ; j++){
            freeTimeTable[i][j] = true;
        }
    }

    //Go through each of the events
    for (ei = 0; ei < numberEvents; ei++){
        eventToCheck = events[ei];
        //cout << eventToCheck.getTitle() << endl;
        frequency = events[ei].getFrequency();
        if (frequency == FrequencyEnum::WEEKLY)
            searchTimeSlotWeekly(eventToCheck, freeTimeTable, date);
        else if (frequency == FrequencyEnum::MONTHLY)
            searchTimeSlotMonthly(eventToCheck, freeTimeTable, date);
        else if (frequency == FrequencyEnum::ANNUALLY)
            searchTimeSlotAnnually(events[ei], freeTimeTable, date);
        else if (frequency == FrequencyEnum::DAILY)
            searchTimeSlotDaily(events[ei], freeTimeTable, date);
        else{ //frequency == FrequencyEnum::NONE
            startDT = events[ei].getStart();
            endDT = events[ei].getEnd();
            if (startDT.FormatISODate() == date.FormatISODate()){
                cout << "Passed single event test" << endl;
                s_hour = startDT.GetHour();
                e_hour = endDT.GetHour();

                s_minute = startDT.GetMinute();
                e_minute = endDT.GetMinute();

                s_minuteIndex = startMinuteToIndexConversion(s_minute);
                e_minuteIndex = endMinuteToIndexConversion(e_minute);

                //Set false flags for each interval that an event occupies
                for (i = s_hour; i <= e_hour; i++){
                    setMinute = false;
                    for (j = 0; j < 4; j++){
                        if (!setMinute && i == s_hour){
                            j = s_minuteIndex;
                            setMinute = true;
                        }
                        //Do not set the time interval to be flagged as 'busy' if the events ends on the hour
                        if (i == e_hour && e_minute == 0)
                            break;
                        freeTimeTable[i][j] = false;
                        if (i == e_hour && j == e_minuteIndex)
                            break;
                    }
                }
            }
        }
    }

    printTable(freeTimeTable);

    validTimes = findValidSlots(freeTimeTable, duration, date);
    freeSlots = validTimes.size() / 2;

    ofstream output("./data/test.txt");
    if (output.is_open()){
        output << freeSlots << '\n';
        for (i = 0; i < validTimes.size(); i++){
            if (i%2 == 0)
                output << validTimes[i].FormatISOTime() << ';';
            else
                output << validTimes[i].FormatISOTime() << '\n';
        }
    }

    cout << freeSlots << endl;
    for (i = 0; i <validTimes.size() ; i++){
        if (i % 2 == 0)
            cout << validTimes[i].GetHour() << ":" << validTimes[i].GetMinute() << " to ";
        else
            cout << validTimes[i].GetHour() << ":" << validTimes[i].GetMinute() << endl;
    }
}

void searchTimeSlotAnnually(Event event, bool (&table)[24][4], wxDateTime date){
    int i, j;

    bool sameDateFlag = false;
    int repeat = event.getRepeatCount();
    wxDateTime startDT = event.getStart();
    wxDateTime endDT = event.getEnd();

    for (int i = 0; i < repeat; i++){
        if (date.IsSameDate(startDT)){
            sameDateFlag = true;
            break;
        }
        startDT.SetYear(startDT.GetYear() + 1);
    }

    if (sameDateFlag){
        int s_hour, s_minute;
        int e_hour, e_minute;
        int s_minuteIndex, e_minuteIndex;
        bool setMinute;

        s_hour = startDT.GetHour();
        e_hour = endDT.GetHour();

        s_minute = startDT.GetMinute();
        e_minute = endDT.GetMinute();

        s_minuteIndex = startMinuteToIndexConversion(s_minute);
        e_minuteIndex = endMinuteToIndexConversion(e_minute);

        for (i = s_hour; i <= e_hour; i++){
            setMinute = false;
            for (j = 0; j < 4; j++){
                if (!setMinute && i == s_hour){
                    j = s_minuteIndex;
                    setMinute = true;
                }
                //Do not set the time interval to be flagged as 'busy' if the events ends on the hour
                if (i == e_hour && e_minute == 0)
                    break;
                table[i][j] = false;
                if (i == e_hour && j == e_minuteIndex)
                    break;
            }
        }
    }
}

void searchTimeSlotMonthly(Event event, bool (&table)[24][4], wxDateTime date){
    int i, j;

    bool sameDateFlag = false;
    int repeat = event.getRepeatCount();
    wxDateTime startDT = event.getStart();
    wxDateTime endDT = event.getEnd();

    for (int i = 0; i < repeat; i++){
        if (date.IsSameDate(startDT)){
            cout << "Passed Monthly Test" << endl;
            sameDateFlag = true;
            break;
        }
        startDT.SetMonth((wxDateTime::Month)(startDT.GetMonth() + 1));
    }
    if (sameDateFlag){
        int s_hour, s_minute;
        int e_hour, e_minute;
        int s_minuteIndex, e_minuteIndex;
        bool setMinute;

        s_hour = startDT.GetHour();
        e_hour = endDT.GetHour();

        s_minute = startDT.GetMinute();
        e_minute = endDT.GetMinute();

        s_minuteIndex = startMinuteToIndexConversion(s_minute);
        e_minuteIndex = endMinuteToIndexConversion(e_minute);

        for (i = s_hour; i <= e_hour; i++){
            setMinute = false;
            for (j = 0; j < 4; j++){
                if (!setMinute && i == s_hour){
                    j = s_minuteIndex;
                    setMinute = true;
                }
                //Do not set the time interval to be flagged as 'busy' if the events ends on the hour
                if (i == e_hour && e_minute == 0)
                    break;
                table[i][j] = false;
                if (i == e_hour && j == e_minuteIndex)
                    break;
            }
        }
    }
}

void searchTimeSlotWeekly(Event event, bool (&table)[24][4], wxDateTime date){
    cout << event.getTitle() << endl;
    int i, j;

    bool sameDateFlag = false;
    int repeat = event.getRepeatCount();
    cout << repeat << endl;
    if (repeat < 0)
        repeat = 1;
    if (repeat == 1000)
        repeat = 25;
    wxDateTime startDT;
    startDT = event.getStart();
    wxDateTime endDT;
    endDT = event.getEnd();

    for (int i = 0; i < repeat; i++){
        //cout << startDT.FormatISODate()<< endl;
        if (date.IsSameDate(startDT)){
            cout << "Passed Weekly Test" << endl;
            cout << date.FormatISODate() << "\n" << endl;
            sameDateFlag = true;
            break;
        }
        startDT+= wxTimeSpan::Week();
    }
    if (sameDateFlag){
        int s_hour, s_minute;
        int e_hour, e_minute;
        int s_minuteIndex, e_minuteIndex;
        bool setMinute;

        s_hour = startDT.GetHour();
        e_hour = endDT.GetHour();

        s_minute = startDT.GetMinute();
        e_minute = endDT.GetMinute();

        s_minuteIndex = startMinuteToIndexConversion(s_minute);
        e_minuteIndex = endMinuteToIndexConversion(e_minute);

        for (i = s_hour; i <= e_hour; i++){
            setMinute = false;
            for (j = 0; j < 4; j++){
                if (!setMinute && i == s_hour){
                    j = s_minuteIndex;
                    setMinute = true;
                }
                //Do not set the time interval to be flagged as 'busy' if the events ends on the hour
                if (i == e_hour && e_minute == 0)
                    break;
                table[i][j] = false;
                if (i == e_hour && j == e_minuteIndex)
                    break;
            }
        }
    }
}

void searchTimeSlotDaily(Event event, bool (&table)[24][4], wxDateTime date){
    int i, j;

    bool sameDateFlag = false;
    int repeat = event.getRepeatCount();
    cout << "number of repeats: " << repeat << endl;
    wxDateTime startDT = event.getStart();
    wxDateTime endDT = event.getEnd();

    for (int i = 0; i < repeat; i++){
        cout << startDT.FormatISODate() << endl;
        if (date.FormatISODate() == startDT.FormatISODate()){
            cout << "Passed Daily Test" << endl;
            sameDateFlag = true;
            break;
        }
        startDT += wxTimeSpan::Day();
    }
    if (sameDateFlag){
        int s_hour, s_minute;
        int e_hour, e_minute;
        int s_minuteIndex, e_minuteIndex;
        bool setMinute;

        s_hour = startDT.GetHour();
        e_hour = endDT.GetHour();

        s_minute = startDT.GetMinute();
        e_minute = endDT.GetMinute();

        s_minuteIndex = startMinuteToIndexConversion(s_minute);
        e_minuteIndex = endMinuteToIndexConversion(e_minute);

        for (i = s_hour; i <= e_hour; i++){
            setMinute = false;
            for (j = 0; j < 4; j++){
                if (!setMinute && i == s_hour){
                    j = s_minuteIndex;
                    setMinute = true;
                }
                //Do not set the time interval to be flagged as 'busy' if the events ends on the hour
                if (i == e_hour && e_minute == 0)
                    break;
                table[i][j] = false;
                if (i == e_hour && j == e_minuteIndex)
                    break;
            }
        }
    }
}

void printTable(bool table[24][4]){
    for (int i = 0; i < 24 ; i++){
        cout << i << '\t';
        for (int j = 0; j < 4 ; j++){
            if (table[i][j])
                cout << 'T' << ' ';
            else
                cout << 'F' << ' ';
        }
        cout << '\n';
    }
}

int calcFreeSlots(bool table[24][4]){
    int freeSlots = 0;
    int i, j;

    for (i=0 ; i<24; i++){
        //Boundary Condition - The First Hour
        if (i == 0){
            for (j = 0 ; j < 4; j++){
                if (j == 0 && table[i][j])
                    freeSlots++;
                else if (j == 3 && !table[i][j] && table[i+1][0])
                    freeSlots++;
            }
        //Boundary Condition - The Last Hour
        } else if (i == 23) {
            for (j = 0; j < 4; j++){
                if (j == 3);
                else if (!table[i][j] && table[i][j+1])
                    freeSlots++;
            }
        } else {
            for (int j = 0; j <4; j++){
                if (j == 3 && !table[i][j] && table[i+1][0])
                    freeSlots++;
                else if (!table[i][j] && table[i][j+1])
                    freeSlots++;
            }
        }
    }
    return freeSlots;
}

int endMinuteToIndexConversion(int minutes){
    if (minutes >= 0 && minutes <= 15)
        return 0;
    else if (minutes > 15 && minutes <= 30)
        return 1;
    else if (minutes > 30 && minutes <=45)
        return 2;
    else if (minutes > 45 && minutes <=60)
        return 3;
    else
        return -1;
}

int startMinuteToIndexConversion(int minutes){
    if (minutes >= 45 && minutes <= 60)
        return 3;
    else if (minutes >= 30 && minutes < 45)
        return 2;
    else if (minutes >= 15 && minutes < 30)
        return 1;
    else if (minutes >= 0 && minutes <= 15)
        return 0;
    else
        return -1;
}

vector<wxDateTime> findValidSlots(bool table[24][4], int duration, wxDateTime date){
    vector<wxDateTime> wxValidTimes;
    vector<int> validHours;
    vector<int> validMinutes;
    int i, j;

    int day = date.GetDay();
    wxDateTime::Month month = date.GetMonth();
    int year = date.GetYear();

    int freeSlotDuration = 0;
    int startHour, endHour;
    int startMinuteIndex, endMinuteIndex;
    wxDateTime buffer;

    for (i=0 ; i<24; i++){
        //Boundary Condition - The First Hour
        if (i == 0){
            for (j = 0 ; j < 4; j++){
                //First Index - cannot check previous value
                if (j == 0 && table[i][j]){
                    freeSlotDuration += 15;
                    startHour = i;
                    startMinuteIndex = j;
                }
                //Indicating that this slot is free
                else if (table[i][j]){
                    freeSlotDuration += 15;
                    //Indicating that this is the start of a free slot
                    if (!table[i][j-1]){
                        startHour = i;
                        startMinuteIndex = j;
                    }
                }
                //Indicating that this is the end of a free slot
                else if (!table[i][j] && table[i][j-1]){
                    if (freeSlotDuration >= duration){
                        endHour = i;
                        endMinuteIndex = j;
                        validHours.push_back(startHour);
                        validHours.push_back(endHour);
                        validMinutes.push_back(startMinuteIndex*15);
                        validMinutes.push_back(endMinuteIndex*15);
                    }
                    freeSlotDuration = 0;
                } else if (!table[i][j])
                    freeSlotDuration = 0;
            }
        //Boundary Condition - The Last Hour
        } else if (i == 23) {
            for (j = 0; j <4 ; j++){
                //First Index - Have to check if this is the start of a new free slot
                if (j == 0 && table[i][j]){
                    freeSlotDuration += 15;
                    if (!table[i-1][3]){
                        startHour = i;
                        startMinuteIndex = j;
                    }
                }
                //If the time slot is free
                else if (table[i][j]){
                    freeSlotDuration += 15;
                    //If this is the start of a new time slot
                    if (!table[i][j-1]){
                        startHour = i;
                        startMinuteIndex = j;
                    }
                    //If this is the last index
                    if (j == 3){
                        if (freeSlotDuration >= duration){
                            endHour = 0;
                            endMinuteIndex = 0;
                            validHours.push_back(startHour);
                            validHours.push_back(endHour);
                            validMinutes.push_back(startMinuteIndex*15);
                            validMinutes.push_back(endMinuteIndex*15);
                        }
                        freeSlotDuration = 0;
                    }
                }
                //Indicating that this is the end of a free slot
                else if (!table[i][j] && table[i][j-1]){
                    if (freeSlotDuration >= duration){
                        endHour = i;
                        endMinuteIndex = j;
                        validHours.push_back(startHour);
                        validHours.push_back(endHour);
                        validMinutes.push_back(startMinuteIndex*15);
                        validMinutes.push_back(endMinuteIndex*15);
                    }
                    freeSlotDuration = 0;
                } else if (!table[i][j])
                    freeSlotDuration = 0;
            }

        } else {
            for (int j = 0; j <4; j++){
                //First Index - must check last index of previous hour
                if (j == 0 && table[i][j]){
                    freeSlotDuration += 15;
                    //Indicating that it is the start of a new free slot
                    if (!table[i-1][3]){
                        startHour = i;
                        startMinuteIndex = j;
                    }
                }
                else if (table[i][j]){
                    freeSlotDuration += 15;
                    //Indicating that it is the start of a new free slot
                    if (!table[i][j-1]){
                        startHour = i;
                        startMinuteIndex = j;
                    }
                } else if (!table[i][j] && table[i][j-1]){
                    if (freeSlotDuration >= duration){
                        endHour = i;
                        endMinuteIndex = j;
                        cout << freeSlotDuration << '\t';
                        cout << startHour << ':' << startMinuteIndex*15 << " to " << endHour << ':' << endMinuteIndex*15 << endl;
                        validHours.push_back(startHour);
                        validHours.push_back(endHour);
                        validMinutes.push_back(startMinuteIndex*15);
                        validMinutes.push_back(endMinuteIndex*15);
                    }
                    freeSlotDuration = 0;
                } else if (!table[i][j])
                    freeSlotDuration = 0;
            }
        }
    }

    for (i = 0; i<validHours.size() ; i++){
        if (i%2 == 0)
            cout << "Start at " << validHours[i] << ":" << validMinutes[i] << endl;
        else
            cout << "End at " << validHours[i] << ":" << validMinutes[i] << endl;
    }
    for (i = 0; i< validHours.size(); i++){
        buffer = wxDateTime(day, month, year, validHours[i], validMinutes[i]);
        wxValidTimes.push_back(buffer);
    }
    return wxValidTimes;
}
