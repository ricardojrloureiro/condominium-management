#include "meeting.h"

void Meeting::addAttendance(int m1) {
	ownersId.push_back(m1);
}
void Meeting::removeAttendance(int m1) {
	for(unsigned int i=0;i<ownersId.size();i++) {
		if(ownersId[i] == m1) {
			ownersId.erase(ownersId.begin()+i);
		}
	}
}

int Meeting::getDate() {
	return date;
}
void Meeting::setDate(int date) {
	this->date = date;
}
