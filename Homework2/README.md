Date & Time Arithmetic

Description: This project implements a simple system to perform date and time arithmetic operations, such as calculating the difference between two DateTime objects in terms of months, days, hours, minutes, and seconds.

Features:

* DateTime Class: Combines date and time information into a single DateTime object.
* Date Class: Represents a date with year, month, and day.
* Time Class: Represents a time with hour, minute, and second.
* Difference Calculation: Computes the difference between two DateTime objects, including months, days, hours, minutes, and seconds.

Classes:
- Date class
    Constructor: Initializes a Date object with a specific year, month, and day.
    Getters: Methods to retrieve the year, month, and day.
    totalDays(): Helper method to calculate the total number of days since a fixed reference date
    
- Time class
    Constructor: Initializes a Time object with a specific hour, minute, and second.
    Getters: Methods to retrieve the hour, minute, and second.
    totalSeconds(): Helper method to calculate the total number of seconds since midnight.

- DateTime class
Combines a Date and a Time to represent a specific date and time.

    Constructor: Initializes a DateTime object with a specific date and time.
    format(): Outputs the DateTime in a readable format.
    difference(): Calculates and displays the difference between two DateTime objects in terms of months, days, hours, minutes, and seconds.
