#pragma once
#pragma warning(disable : 4996)
//compiler wanted me to use localtime_s but i couldnt convert for the life of me

#include <ctime>
#include <iostream>
#include <string>

namespace timestamp {
	tm getTime();
	
	class Timestamp {
	//this class is pretty much me wanting a good way to keep track of time
	//kinda similar to python's perf_counter
	//might add more later
	private:
		tm time;
	public:
		Timestamp(tm t = timestamp::getTime());
		//want user to be able to input their own tm but if they don't, it just gets the current time
		tm getTm();
		int getYear();
		int getMonth();
		std::string getMonthStr();
		int getDay();
		int getHour();
		int getMinute();
		int getSecond();
		int getWeekday();
		//by default the weekday comes in int but i wanted a string as well
		std::string getWeekdayStr();
		//also option to get the time as a string (does not include weekday)
		//formatting of string in timstamp.cpp
		std::string getFullTime();
	};
	
	int differenceSeconds(timestamp::Timestamp time1, timestamp::Timestamp time2);
}