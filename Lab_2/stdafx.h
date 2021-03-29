#include <iostream>
#include <string>


class String 
{
public:
	String(const char *);
	bool operator== (String);
	bool operator!= (String);
	~String();
private:
	char data[256];
};

String::String(const char* str)
{
	strcpy_s(data, str);
}

bool String::operator== (String second)
{
	int i = 0;
	while (true)
	{
		if ((data[i] != second.data[i]) && (data[i] != '\0') && (second.data[i] != '\0'))
			return false;
		if ((data[i] == second.data[i]) && (data[i] == '\0') && (second.data[i] == '\0'))
			return true;
		if ((data[i] == '\0') || (second.data[i] == '\0'))
			return false;
		i++;
	}
}
bool String::operator!= (String second)
{
	int i = 0;
	while (true)
	{
		if ((data[i] != second.data[i]) && (data[i] == '\0') && (second.data[i] == '\0'))
			return true;
		if ((data[i] == second.data[i]) && (data[i] != '\0') && (second.data[i] != '\0'))
			return false;
		if ((data[i] == '\0') || (second.data[i] == '\0'))
			return false;
		i++;
	}
}

String::~String()
{

}


