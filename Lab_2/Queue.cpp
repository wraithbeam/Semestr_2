#include "Queue.h"


Queue::Queue(Queue& second)//Копировать
{
	this->atsInfo = second.atsInfo;
	this->nextElementLink = second.nextElementLink;
	this->pastElementLink = second.pastElementLink;
	this->totalRecords = second.totalRecords;
}

void Queue::pushQueue(const ATS_INFO& atsInfo) //Добавление
{
	Queue* nextElement = new Queue;

	nextElement->atsInfo = atsInfo;
	nextElement->nextElementLink = nextElementLink;
	if(nextElement->nextElementLink != NULL)
		nextElement->nextElementLink->pastElementLink = nextElement;
	nextElementLink = nextElement;
	totalRecords++;
}

void Queue::showQueue() //Отобразить
{
	Queue* tempElement = new Queue; tempElement = this;

	while (tempElement->nextElementLink != NULL) {
		tempElement = tempElement->nextElementLink;
	} 
	for (int i = 0; i < totalRecords; i++) //А вот, так захотел
	{
		tempElement->atsInfo.showString();
		tempElement = tempElement->pastElementLink;
	}

}

void Queue::extend(Queue* donor) //Склеивание очередей
{
	while (donor->nextElementLink != NULL) {
		donor = donor->nextElementLink;
	}
	while (donor != NULL) { //А теперь вот так захотел
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

bool Queue::fullCheck() //Проврка забитости
{
	if (totalRecords > 0)
		return true;
	else
		return false;
}

Queue* Queue::nextQueue() //очередь со второго элемента
{
	Queue* tempElement = new Queue; tempElement = this;
	tempElement->popQueue();
	tempElement->totalRecords = totalRecords - 1;
	return tempElement;

}

ATS_INFO* Queue::popQueue()	//Вытащить + удалить
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

ATS_INFO* Queue::peekQueue() //прост вытащить
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

Queue Queue::operator=(Queue donor) //Присвоить
{
	this->atsInfo = donor.atsInfo;
	this->nextElementLink = donor.nextElementLink;
	this->pastElementLink = donor.pastElementLink;
	this->totalRecords = donor.totalRecords;
	return *this;
}

Queue* Queue::operator+(Queue* second) //Расширить
{
	Queue* tempElement = new Queue; tempElement = this;
	tempElement->extend(second);
	return tempElement;
}
//
void Queue::operator+=(Queue* second) //Расширить
{
	extend(second);
}

bool Queue::operator==(Queue& second) //Проверка равенства
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

