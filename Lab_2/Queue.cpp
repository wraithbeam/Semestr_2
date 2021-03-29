#include "Queue.h"


Queue::Queue(Queue* second)//����������
{
	this->atsInfo = second->atsInfo;
	this->nextElementLink = second->nextElementLink;
	this->pastElementLink = second->pastElementLink;
	this->totalRecords = second->totalRecords;
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

	while (tempElement->nextElementLink != NULL) {
		tempElement = tempElement->nextElementLink;
	} 
	while (tempElement->pastElementLink != NULL)
	{
		tempElement->atsInfo.showString();
		tempElement = tempElement->pastElementLink;
	}

}

void Queue::extend(Queue* donor) //���������� ��������
{
	donor = donor->nextElementLink;
	while (donor->nextElementLink != NULL) {
		Queue* nextElement = new Queue;

		nextElement->atsInfo = donor->atsInfo;
		nextElement->nextElementLink = nextElementLink;
		nextElementLink = nextElement;
		if (this->nextElementLink->nextElementLink != NULL)
			this->nextElementLink->nextElementLink->pastElementLink = nextElementLink;
		totalRecords++;
		donor = donor->nextElementLink;
	}
	this->nextElementLink->pastElementLink = nextElementLink;
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
		return &saveFirst.atsInfo;
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

//Queue* Queue::operator=(Queue donor) //���������
//{
//	return nullptr;
//}
//
//Queue* Queue::operator+(Queue second) //���������
//{
//	return nullptr;
//}
//
//Queue* Queue::operator+=(Queue second) //���������
//{
//	return nullptr;
//}
//
//bool Queue::operator==(Queue second) //�������� ���������
//{
//	return false;
//}

