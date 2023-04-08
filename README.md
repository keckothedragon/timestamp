# Timestamp class
## Purpose
The Timestamp class is used to represent a timestamp at a given point in time. I made this because I couldn't find a good way to represent a timestamp in C++.

This is somewhat similar to Python's perf_counter, with some differences.
## Usage
### Timestamp class
The Timestamp class stores a tm struct from the library ctime. It allows you to get data from that tm, as well as convert the tm to a string.

The initializer takes a tm struct, which the user can input manually. If no tm struct is given, the current time is used.

Also, this is meant to be used with the Visual Studio compiler, as gcc may have issues.

### The class has the following methods:
tm getTm() - returns the Timestamp's tm struct

int getYear() - returns the year

int getMonth() - returns the month

string getMonthStr() - returns the month as a string

int getDay() - returns the day

int getHour() - returns the hour

int getMinute() - returns the minute

int getSecond() - returns the second

int getWeekday() - returns the day of the week as int

string getWeekdayStr() - returns the day of the week as string

string getFullTime() - returns the full time as string

### Built-in functions
There are two built-in functions:
getTime() - returns the current time as a tm object, with 1900 added to the year and 1 addedd to the month

differenceSeconds() - takes two Timestamp objects and returns the difference in seconds between them, most similar to perf_counter. It is not reccommended to use a Timestamp created with getTime() as a parameter, and a Timestamp created with no parameters, as sometimes it can cause issues.

Ex (**DON'T** do this):

Timestamp time1 = Timestamp(getTime());

Timestamp time2 = Timestamp();