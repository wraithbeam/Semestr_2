#include "ATS_INFO.h"
#include <iostream>

using namespace std;

class Queue {
private: 
	Queue* nextElementLink; 
	Queue* pastElementLink;
	ATS_INFO atsInfo;
	int totalRecords = 0;
public:
	Queue() { nextElementLink = NULL; pastElementLink = NULL; }
	Queue(Queue& second); //����������� �����������

	void pushQueue(const ATS_INFO& atsInfo); //�������� � �����
	void showQueue(); 
	void extend(Queue* donor); //���������� ��������
	bool fullCheck(); //�������� ������������

	Queue* nextQueue(); //������� �� ������ ��������
	ATS_INFO* popQueue(); //Delete
	ATS_INFO* peekQueue(); //With out delete

	Queue* operator=(Queue& donor); //������������� 
	Queue* operator+(Queue* second); //�����������
	void operator+= (Queue* second); //����������� 
	bool operator==(Queue& second); //���������

};