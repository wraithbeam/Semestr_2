#include "Queue.h"


void Queue::toFirstElem(Queue& elem)
{
	while (elem.nextElementLink != NULL) {
		elem = *nextElementLink;
	}
}

Queue::Queue(Queue& second)//����������
{
	this->atsInfo = second.atsInfo;
	this->nextElementLink = second.nextElementLink;
	this->pastElementLink = second.pastElementLink;
	this->totalRecords = second.totalRecords;
}

void Queue::pushQueue(const ATS_INFO& atsInfo) //����������
{
	Queue* nextElement = new Queue;

	nextElement->atsInfo = atsInfo;
	nextElement->nextElementLink = nextElementLink;
	if(nextElement->nextElementLink != NULL)
		nextElement->nextElementLink->pastElementLink = nextElement;
	nextElementLink = nextElement;
	totalRecords++;
}

void Queue::showQueue() //����������
{
	Queue* tempElement = new Queue; tempElement = this;

	toFirstElem(*tempElement);

	for (int i = 0; i < totalRecords; i++) //� ���, ��� �������
	{
		tempElement->atsInfo.showString();
		tempElement = tempElement->pastElementLink;
	}

}

void Queue::extend(Queue* donor) //���������� ��������
{
	toFirstElem(*donor);

	while (donor != NULL) { //� ������ ��� ��� �������
		Queue* nextElement = new Queue;

		nextElement->atsInfo = donor->atsInfo;
		nextElement->nextElementLink = nextElementLink;
		if (nextElement->nextElementLink != NULL)
			nextElement->nextElementLink->pastElementLink = nextElement;
		nextElementLink = nextElement;
		totalRecords++;

		donor = donor->pastElementLink;
	}
}

bool Queue::fullCheck() //������� ���������
{
	if (totalRecords > 0)
		return true;
	else
		return false;
}

Queue* Queue::nextQueue() //������� �� ������� ��������
{
	Queue* tempElement = new Queue; tempElement = this;
	tempElement->popQueue();
	tempElement->totalRecords = totalRecords - 1;
	return tempElement;

}

ATS_INFO* Queue::popQueue()	//�������� + �������
{
	if (totalRecords != 0) {
		Queue* tempElement = new Queue; tempElement = this;
		Queue saveFirst;

		while (tempElement->nextElementLink->nextElementLink != NULL)
			tempElement = tempElement->nextElementLink;

		saveFirst = *tempElement->nextElementLink;
		delete tempElement->nextElementLink;
		tempElement->nextElementLink = nullptr;

		totalRecords--;
		return &(saveFirst.atsInfo);
	}
	else
		return NULL;
}

ATS_INFO* Queue::peekQueue() //����� ��������
{
	if (totalRecords != 0)
	{
		Queue* tempElement = new Queue;
		tempElement = this;

		while (tempElement->nextElementLink != NULL)
			tempElement = tempElement->nextElementLink;
		return &tempElement->atsInfo;
	}
	else
		return NULL;
}

ATS_INFO* Queue::find(const function<bool(ATS_INFO&)>& func)
{
	toFirstElem(*this);

	while (!func(atsInfo)) {
		if (pastElementLink == NULL)
			return nullptr;
		*this = *pastElementLink;
	}
	return &atsInfo;
}

ATS_INFO* Queue::findAll(const function<bool(ATS_INFO&)>& func)
{
	ATS_INFO* arrayATS = new ATS_INFO[totalRecords]; int k = 0;

	toFirstElem(*this);

	while (true) {
		if (func(atsInfo))
			arrayATS[k++] = atsInfo;
		if (pastElementLink != NULL)
			*this = *pastElementLink;
		else break;
	}
	
	return arrayATS;
}

Queue Queue::operator=(Queue donor) //���������
{
	this->atsInfo = donor.atsInfo;
	this->nextElementLink = donor.nextElementLink;
	this->pastElementLink = donor.pastElementLink;
	this->totalRecords = donor.totalRecords;
	return *this;
}

Queue* Queue::operator+(Queue* second) //���������
{
	Queue* tempElement = new Queue; tempElement = this;
	tempElement->extend(second);
	return tempElement;
}
//
void Queue::operator+=(Queue* second) //���������
{
	extend(second);
}

bool Queue::operator==(Queue& second) //�������� ���������
{
	if (totalRecords == second.totalRecords) 
	{
		Queue tempElement; tempElement = *this;
		while (tempElement.nextElementLink != NULL) 
		{
			if (tempElement.atsInfo != second.atsInfo) return false;

			tempElement = *tempElement.nextElementLink;
			second = *second.nextElementLink;
		}
		return true;
	}
	else return false;
}

