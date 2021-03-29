#include <iostream>
#include <string>


class ATS_INFO
{
private:
	char cityName[256];
	int number;
	int hour, min;

public:
	//Constuct
	ATS_INFO(const char*, int, int, int);
	ATS_INFO();
	~ATS_INFO();

	//Operators
	bool operator== (ATS_INFO&);
	bool operator!= (ATS_INFO&);
	

	//Set Functions
	void setName(const char * _name){
		strcpy_s(this->cityName, _name);
	}
	void setNumber(int _number) {
		this->number = _number;
	}
	void setData(int _hour, int _min) {
		this->hour = _hour;
		this->min = _min;
	}
	

	//Get Fuctions
	char* getName() {
		return cityName;
	}
	long getNumber() {
		return number;
	}
	int getHour() {
		return hour;
	}
	int getMin() {
		return min;
	}

	//Functions
	void showString();
	void inputString();
};


