#include "meeting.h"

void Meeting::addAttendance(string m1) {
	attendingProperties.push_back(m1);
}
void Meeting::removeAttendance(string m1) {
	for(unsigned int i=0;i<attendingProperties.size();i++) {
		if(attendingProperties[i] == m1) {
			attendingProperties.erase(attendingProperties.begin()+i);
		}
	}
}

int Meeting::getDate() {
	return date;
}
void Meeting::setDate(int date) {
	this->date = date;
}
