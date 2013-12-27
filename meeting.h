#ifndef MEETING_H_
#define MEETING_H_

#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class Meeting {
	int date;
	vector<int> ownersId;
	string subject;
public:
	Meeting() {date=0;}
	Meeting(int date,string subject): date(date),subject(subject){}
	Meeting(int date, vector<int> prop,string subject):date(date),ownersId(prop), subject(subject) {}
	void addAttendance(int);
	void removeAttendance(int);
	int getDate();
	void setDate(int);
	vector<int> getAttendance() {return ownersId;}
	void setAttendance(vector<int> i){ownersId=i;}
	string getSubject() {return subject;}

};

#endif /* MEETING_H_ */
