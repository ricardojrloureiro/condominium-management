#ifndef MEETING_H_
#define MEETING_H_

#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class Meeting {
	int date;
	vector<string> attendingProperties;
public:
	Meeting() {date=0;}
	Meeting(int date): date(date) {}
	Meeting(int date,vector<string> prop):date(date),attendingProperties(prop) {}
	void addAttendance(string);
	void removeAttendance(string);
	int getDate();
	void setDate(int);
	vector<string> getAttendance() {return attendingProperties;}

};

#endif /* MEETING_H_ */
