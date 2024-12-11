//
//  homework2pt2.cpp
//  CIS25
//
//  Created by Merary Murillo on 12/11/24.
//

#include "homework2pt2.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

namespace AddOns{

// Date constructor
Date::Date(int y, int m, int d) : year(y), month(m), day(d) {}

// Getters for year, month, and day
int Date::getYear() const {
    return year;
}

int Date::getMonth() const {
    return month;
}

int Date::getDay() const {
    return day;
}

// Define the totalDays() method for Date class
int Date::totalDays() const {
    int y = year;
    int m = month;
    int d = day;
    
    // Adjust for months (Zeller's congruence needs months to be from 3 to 14)
    if (m <= 2) {
        m += 12;
        y--;
    }

    // Calculate days in each year
    int daysInYear = y * 365 + y / 4 - y / 100 + y / 400;
    
    // Calculate days in each month of the current year
    static const int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int daysInCurrentYear = 0;
    for (int i = 0; i < m - 1; i++) {
        daysInCurrentYear += daysInMonth[i];
    }

    // Adjust for leap years (February in leap years has 29 days)
    if (m > 2 && (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0))) {
        daysInCurrentYear += 1;
    }

    // Add days of the current month
    daysInCurrentYear += d;

    return daysInYear + daysInCurrentYear;
}


// Day of the week using Zeller's Congruence (0 = Saturday, 1 = Sunday, 2 = Monday, etc..)
int Date::dayOfWeek() const {
    int y = year;
    int m = month;
    if (m <= 2) {
        m += 12;
        y--;
    }
    int k = y % 100;
    int j = y / 100;
    int h = (day + 13 * (m + 1) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;
    return h;
}

// Number of days in the month, considering leap years
int Date::daysOfMonth() const {
    if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            return 29;  // Leap year
        } else {
            return 28;
        }
    }
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12: return 31;
        case 4: case 6: case 9: case 11: return 30;
        default: return 0;  // Invalid month
    }
}

// Time constructor
Time::Time(int h, int m, int s) : hour(h), minute(m), second(s) {}

// Getters for hour, minute, and second
int Time::getHour() const { return hour; }
int Time::getMinute() const { return minute; }
int Time::getSecond() const { return second; }

// Calculate total seconds since midnight
int Time::totalSeconds() const {
    return hour * 3600 + minute * 60 + second;
}

// DateTime constructor with time zone offset
DateTime::DateTime(int year, int month, int day, int hour, int min, int sec, int tzOffset)
    : date1(year, month, day), time1(hour, min, sec), timeZoneOffset(tzOffset) {}

// Adjust DateTime to a new time zone
void DateTime::adjustToTimeZone(int newTimeZoneOffset) {
    int offsetDifference = newTimeZoneOffset - timeZoneOffset;
    timeZoneOffset = newTimeZoneOffset;
    int totalSecondsToAdjust = offsetDifference * 3600;  // Convert to seconds
    int totalSeconds = time1.totalSeconds() + totalSecondsToAdjust;

    int newHour = totalSeconds / 3600;
    totalSeconds %= 3600;
    int newMinute = totalSeconds / 60;
    int newSecond = totalSeconds % 60;

    time1 = Time(newHour, newMinute, newSecond);
}

// Adjust for daylight saving time
void DateTime::adjustForDST(bool isDST) {
    if (isDST) {
        int newHour = time1.getHour() + 1;
        if (newHour >= 24) newHour -= 24;  // Handle overflow of hours
        time1 = Time(newHour, time1.getMinute(), time1.getSecond());
    }
}

// Output DateTime in a human-readable format
void DateTime::format() const {
    cout << "Date: " << date1.getYear() << "-" << setw(2) << setfill('0') << date1.getMonth() << "-"
         << setw(2) << setfill('0') << date1.getDay() << " Time: " << setw(2) << setfill('0') << time1.getHour() << ":"
         << setw(2) << setfill('0') << time1.getMinute() << ":" << setw(2) << setfill('0') << time1.getSecond()
         << " UTC" << (timeZoneOffset >= 0 ? "+" : "") << timeZoneOffset << endl;
}

// Serialize DateTime to string
string DateTime::serialize() const {
    ostringstream oss;
    oss << date1.getYear() << "-" << setw(2) << setfill('0') << date1.getMonth() << "-" << setw(2) << setfill('0') << date1.getDay() << " ";
    oss << setw(2) << setfill('0') << time1.getHour() << ":" << setw(2) << setfill('0') << time1.getMinute() << ":" << setw(2) << setfill('0') << time1.getSecond();
    oss << " UTC" << (timeZoneOffset >= 0 ? "+" : "") << timeZoneOffset;
    return oss.str();
}

// Deserialize DateTime from string
DateTime DateTime::deserialize(const string& serialized) {
    int year, month, day, hour, minute, second, tzOffset;
    char delimiter;

    istringstream iss(serialized);
    iss >> year >> delimiter >> month >> delimiter >> day >> delimiter >> hour >> delimiter >> minute >> delimiter >> second >> delimiter >> delimiter >> tzOffset;

    return DateTime(year, month, day, hour, minute, second, tzOffset);
}

// Calculate the difference between two DateTime objects
void DateTime::difference(const DateTime& other) const {
    int daysDiff = date1.totalDays() - other.date1.totalDays();
    int timeDiff = time1.totalSeconds() - other.time1.totalSeconds();
    
    int hours = timeDiff / 3600;
    timeDiff %= 3600;
    int minutes = timeDiff / 60;
    int seconds = timeDiff % 60;

    if (timeDiff < 0) {
        hours = -hours;
        minutes = -minutes;
        seconds = -seconds;
        daysDiff -= 1;
    }

    cout << "Difference: " << daysDiff << " days, " << hours << " hours, " << minutes << " minutes, " << seconds << " seconds." << endl;
}


}
