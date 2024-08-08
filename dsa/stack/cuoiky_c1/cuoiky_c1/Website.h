#include <string>
using namespace std;
#pragma once
class Website
{
private:
	string address;
	int accessTimes;
	Website* next;
	Website* back;


public:

	Website(string _address) {
		address = _address;
		accessTimes = 1;
		next = nullptr;
		back = nullptr;

	}

	void setNext(Website* target) {
		next = target;
	}
	Website* getNext() {
		return next;
	}
	void setBack(Website* target) {
		back = target;
	}
	Website* getBack() {
		return back;
	}
	void increaseAccessTimes() {
		accessTimes++;
	}

	string getAddress() {
		return address;
	}
	int getAccessTimes() {
		return accessTimes;
	}
};

