#include "String.h"

String::String(const char* _name, int _number, int _hour, int _min) {
	setName(_name);
	setNumber(_number);
	setData(_hour, _min);
}

String::String() {
	this->setData(-1, -1);
	this->setName("--");
	this->setNumber(-1);
}

bool String::operator== (String& second) //������ ��������� 2 �������� ������
{
	int i = 0;
	while (true)
	{
		if ((this->cityName[i] == '\0') && (second.cityName[i] == '\0'))
			break;
		if (this->cityName[i] != second.cityName[i])
			return false;
		i++;
	}
	if (this->number != second.number)
		return false;
	if (this->hour != second.hour)
		return false;
	if (this->min != second.min)
		return false;
	return true;
} 

bool String::operator!= (String& second)
{
	return !(this[0] == second);
}

String::~String()
{

}

void String::showString() { //����� (�����)
	std::cout << "������ ���������� � ������ " << getNumber() << std::endl;
	std::cout << "� ������ " << getName() << std::endl;
	std::cout << "����� ������ " << getHour() << " : " << getMin() << std::endl;
}
 
void String::inputString() {  //���� � �������� (�����)
	char name[256];
	int number;
	int hour, min;
	std::cout << "������� ������ ������: ";
	std::cin >> name;
	std::cout << "������� �����: ";
	std::cin >> number;
	std::cout << "������� ����� � ������� (��� ������): ";
	std::cin >> hour >> min;
	std::cout << std::endl;
	this->setData(hour, min);
	this->setName(name);
	this->setNumber(number);
}
//----------------------------------------------//
