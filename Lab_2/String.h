#include <iostream>
#include <string>


class String
{
public:
	//Constuct
	String(const char*, int, int, int);
	String();
	~String();

	//Operators
	bool operator== (String&);
	bool operator!= (String&);
	

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

private:
	char cityName[256];
	int number;
	int hour, min;

};


