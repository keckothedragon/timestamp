#include "timestamp.h"

using namespace timestamp;

//most of the methods are self-explanatory, just returning values of the tm struct
Timestamp::Timestamp(tm t) {
	this->time = t;
}

tm Timestamp::getTm() {
	return this->time;
}

int Timestamp::getYear() {
	return this->time.tm_year;
	//1900 has been added to this year if using getTime()
}

int Timestamp::getMonth() {
	return this->time.tm_mon;
	//1 has been added to this month if using getTime()
}

std::string Timestamp::getMonthStr() {
	switch (this->time.tm_mon) {
	case 0:
		return "January";
	case 1:
		return "February";
	case 2:
		return "March";
	case 3:
		return "April";
	case 4:
		return "May";
	case 5:
		return "June";
	case 6:
		return "July";
	case 7:
		return "August";
	case 8:
		return "September";
	case 9:
		return "October";
	case 10:
		return "November";
	case 11:
		return "December";
	}
}

int Timestamp::getDay() {
	return this->time.tm_mday;
}

int Timestamp::getHour() {
	return this->time.tm_hour;
}

int Timestamp::getMinute() {
	return this->time.tm_min;
}

int Timestamp::getSecond() {
	return this->time.tm_sec;
}

int Timestamp::getWeekday() {
	return this->time.tm_wday;
}

std::string Timestamp::getWeekdayStr() {
	switch (this->time.tm_wday) {
	case 0:
		return "Sunday";
	case 1:
		return "Monday";
	case 2:
		return "Tuesday";
	case 3:
		return "Wednesday";
	case 4:
		return "Thursday";
	case 5:
		return "Friday";
	case 6:
		return "Saturday";
	}
}

std::string Timestamp::getFullTime() {
	//format: yyyy-mm-dd hh:mm:ss
	std::string time;
	//split this to multiple lines so it's easier to read
	
	//all the for loops and if statements are ensuring that the time is formatted correctly
	//with the appropriate amt of digits for each
	for (int i = std::to_string(this->getYear()).length(); i < 4; i++) {
		time += "0";
	}
	time += std::to_string(this->getYear()) + "-";
	
	if (std::to_string(this->getMonth()).length() == 1) {
		time += "0";
	}
	time += std::to_string(this->getMonth()) + "-";
	
	if (std::to_string(this->getDay()).length() == 1) {
		time += "0";
	}
	time += std::to_string(this->getDay()) + " ";
	
	if (std::to_string(this->getHour()).length() == 1) {
		time += "0";
	}
	time += std::to_string(this->getHour()) + ":";
	
	if (std::to_string(this->getMinute()).length() == 1) {
		time += "0";
	}
	time += std::to_string(this->getMinute()) + ":";
	
	if (std::to_string(this->getSecond()).length() == 1) {
		time += "0";
	}
	time += std::to_string(this->getSecond());
	
	return time;
}

//even tho im using namespace timestamp, compiler wasnt happy
//so i explicitly said it here
int timestamp::differenceSeconds(Timestamp time1, Timestamp time2) {
	//pretty self explanatory, subtracts the seconds to get the difference in time
	//would add ms but ctime's tm struct doesnt have ms and i cant be bothered to convert
	return time2.getSecond() - time1.getSecond();
}

tm timestamp::getTime() {
	time_t now = time(0);
	tm* ltm = localtime(&now);
	//uses ctime's built-in function to get the time as a tm
	
	ltm->tm_year += 1900;
	ltm->tm_mon += 1;
	//adds 1900 to the year and 1 to the month to reflect the way humans tell time
	return* ltm;
}