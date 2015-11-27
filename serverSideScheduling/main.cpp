#include <iostream>
#include <wx/datetime.h>
#include <vector>
#include <algorithm>
#include <fstream>
#include <ostream>
#include <istream>
#include <sstream>

#include "wx/arrstr.h"
#include "Calendar.h"
#include "Event.h"

using namespace std;

//enum wxDateTime::Month {Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec};

void searchTimeSlotAnnually(Event event, bool (&table)[24][4], int month, int day, int year);
void searchTimeSlotMonthly(Event event, bool (&table)[24][4], int month, int day, int year);
void searchTimeSlotWeekly(Event event, bool (&table)[24][4], int month, int day, int year);
void searchTimeSlotDaily(Event event, bool (&table)[24][4], int month, int day, int year);
void searchTimeSlot(vector<Event> events, int duration, int day, int month, int year);
wxArrayString generateTimeRange (vector<wxDateTime> vt, int duration);
vector<wxDateTime> findValidSlots(bool table[24][4], int duration, wxDateTime::Month month, int day, int year);
void printTable(bool table[24][4]);
bool dateComparison(wxDateTime, wxDateTime);
int startMinuteToIndexConversion(int minutes);
int endMinuteToIndexConversion(int minutes);

bool orderStartTime(int start1, int start2){
    return (start1 < start2);
}

int main(int argc, char** argv)
{
    stringstream ss;

    ss << argv[1];
    string PATH;
    ss >> PATH;

    ss << argv[2];
    int duration;
    ss >> day;

    ss << argv[3];
    string dateString;
    ss >> dateString;

    vector<Event> events;
    /* Test Case Event Times */
        wxDateTime bufferStart(11, wxDateTime::Sep, 2015, 0);
        wxDateTime bufferEnd(11, wxDateTime::Sep, 2015, 3);
        Event buffer("Event 1", bufferStart, bufferEnd, FrequencyEnum::ANNUALLY, 3);
        events.push_back(buffer);

        bufferStart = wxDateTime(7, wxDateTime::Sep, 2015, 5);
        bufferEnd = wxDateTime(7, wxDateTime::Sep, 2015, 8);
        buffer = Event("Event 2", bufferStart, bufferEnd, FrequencyEnum::DAILY, 5);
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
        events.push_back(buffer);

    searchTimeSlot(events, 150 , 11, 8, 2015);
    return 0;
}

void searchTimeSlot(vector<Event> events, int duration, int day, int month, int year){
    //vector <Event> events = Calendar.getEvents();
    int numberEvents = events.size();
    int i, j, ei; //ei is the event index
    int s_hour, s_minute;
    int e_hour, e_minute;
    int s_minuteIndex, e_minuteIndex;
    int freeSlots;
    FrequencyEnum frequency;
    wxDateTime startDT, endDT;
    vector<wxDateTime> validTimes;
    wxArrayString generatedTimes;
    bool freeTimeTable[24][4];
    bool setMinute;

    //Initialize all of the available slots to be true
    for (i = 0; i <24 ; i++){
        for (j=0; j<4 ; j++){
            freeTimeTable[i][j] = true;
        }
    }

    //Go through each of the events
    for (ei = 0; ei < numberEvents; ei++){
        frequency = events[ei].getFrequency();
        if (frequency == FrequencyEnum::WEEKLY)
            searchTimeSlotWeekly(events[ei], freeTimeTable, day, month, year);
        else if (frequency == FrequencyEnum::MONTHLY)
            searchTimeSlotMonthly(events[ei], freeTimeTable, day, month, year);
        else if (frequency == FrequencyEnum::ANNUALLY)
            searchTimeSlotAnnually(events[ei], freeTimeTable, day, month, year);
        else if (frequency == FrequencyEnum::DAILY)
            searchTimeSlotDaily(events[ei], freeTimeTable, day, month, year);
        else{ //frequency == FrequencyEnum::NONE
            startDT = events[ei].getStart();
            endDT = events[ei].getEnd();

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

    printTable(freeTimeTable);

    wxDateTime::Month test = (wxDateTime::Month)(8);
    validTimes = findValidSlots(freeTimeTable, duration, test, 11, 2015);
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

    cout << '\n';
    if (validTimes.empty())
        cout << "No times available" << endl;
    else
        generatedTimes = generateTimeRange(validTimes, duration);

}

void searchTimeSlotAnnually(Event event, bool (&table)[24][4], int day, int month, int year){
    int i, j;
    bool sameDateFlag = false;
    int repeat = event.getRepeatCount();
    wxDateTime startDT = event.getStart();
    wxDateTime endDT = event.getEnd();

    wxDateTime dayTest (day, (wxDateTime::Month)month, year);
    for (int i = 0; i < repeat; i++){
        if (dayTest.IsSameDate(startDT)){
            cout << "Passed Annual Test" << endl;
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

void searchTimeSlotMonthly(Event event, bool (&table)[24][4], int day, int month, int year){
    int i, j;
    bool sameDateFlag = false;
    int repeat = event.getRepeatCount();
    wxDateTime startDT = event.getStart();
    wxDateTime endDT = event.getEnd();

    wxDateTime dayTest (day, (wxDateTime::Month)month, year);
    for (int i = 0; i < repeat; i++){
        if (dayTest.IsSameDate(startDT)){
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

void searchTimeSlotWeekly(Event event, bool (&table)[24][4], int day, int month, int year){
    int i, j;
    bool sameDateFlag = false;
    int repeat = event.getRepeatCount();
    wxDateTime startDT = event.getStart();
    wxDateTime endDT = event.getEnd();

    wxDateTime dayTest (day, (wxDateTime::Month)month, year);
    for (int i = 0; i < repeat; i++){
        if (dayTest.IsSameDate(startDT)){
            cout << "Passed Weekly Test" << endl;
            sameDateFlag = true;
            break;
        }
        startDT.SetDay((startDT.GetDay() + 7));
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

void searchTimeSlotDaily(Event event, bool (&table)[24][4], int day, int month, int year){
    int i, j;
    bool sameDateFlag = false;
    int repeat = event.getRepeatCount();
    wxDateTime startDT = event.getStart();
    wxDateTime endDT = event.getEnd();

    wxDateTime dayTest (day, (wxDateTime::Month)month, year);
    for (int i = 0; i < repeat; i++){
        if (dayTest.GetWeekDay() == startDT.GetWeekDay()){
            cout << "Passed Daily Test" << endl;
            sameDateFlag = true;
            break;
        }
        startDT.SetDay((startDT.GetDay() + 1));
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

wxArrayString generateTimeRange (vector<wxDateTime> vt, int duration){
    int i;
    int sMin, eMin;
    int sHour, eHour;
    int cHour, cMin;
    int hourAdjust, minuteAdjust;
    wxDateTime bufferDT(0,0,0);
    wxDateTime dt1, dt2;

    wxArrayString listItems;
    wxString buffer, b1, b2, b3, b4;

    for (i = 0; i < vt.size(); i+=2){
        sMin = vt[i].GetMinute() + vt[i].GetHour()*60;
        eMin = vt[i+1].GetMinute() + vt[i+1].GetHour()*60;

        sHour = vt[i].GetHour();
        eHour = vt[i+1].GetHour();

        cHour = sHour;
        cMin = sMin;

        hourAdjust = (int)(duration / 60);
        minuteAdjust = duration - (hourAdjust * 60);

        while ((eMin - cMin) >= duration){
            bufferDT.SetHour(vt[i].GetHour());
            bufferDT.SetMinute(vt[i].GetMinute());

            buffer << bufferDT.FormatISOTime();

            bufferDT.SetHour(vt[i].GetHour() + hourAdjust);
            bufferDT.SetMinute(vt[i].GetMinute() + minuteAdjust);

            buffer << "-" << bufferDT.FormatISOTime();
            listItems.Add(buffer);

            buffer.clear();

            vt[i].SetMinute((vt[i].GetMinute() + 15) % 60);
            if (vt[i].GetMinute() == 0)
                vt[i].SetHour(vt[i].GetHour() + 1);
            cMin += 15;
        }
    }
    return listItems;
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

vector<wxDateTime> findValidSlots(bool table[24][4], int duration, wxDateTime::Month month, int day, int year){
    vector<wxDateTime> wxValidTimes;
    vector<int> validHours;
    vector<int> validMinutes;
    int i, j;
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
