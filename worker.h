#ifndef WORKER_H_
#define WORKER_H_

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Worker{
	long id;
	string name;
	float wage;
	static long workerId;
public:
	string getName();
	void setName(string);
	float getWage();
	void setWage(float);
	Worker(string);
	Worker(long,float,string);
	Worker(string,float);
	void setId(int);

	long getId();
};
#endif /* WORKER_H_ */
