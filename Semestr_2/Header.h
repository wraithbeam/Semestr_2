#pragma once
#include <iostream>;
#include <string>
using namespace std;

class String
{
public:
	String(const char*);
	void operator+ (const char *);
	void chr_minus(char);
	void show_string(void);
	~String();
private:
	char data[256];
};

String::String(const char* str) 
{
	strcpy_s(data, str);
}

String::~String() 
{

}

void String::operator+(const char* str)
{
	strcat_s(data, str);
}

void String::show_string(void)
{
	cout << data << endl;
}

void String::chr_minus(char letter)
{
	char temp[256];
	int i, j;
	for (i = 0, j = 0; data[i]; i++)
		if (data[i] != letter)
			temp[j++] = data[i];
	temp[j] = NULL;
	strcpy_s(data, temp);
}
