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
	Queue(Queue& second); //Конструктор копирования

	void pushQueue(const ATS_INFO& atsInfo); //Добавить в конец
	void showQueue(); 
	void extend(Queue* donor); //Склеивание очередей
	bool fullCheck(); //Проверка заполнености

	Queue* nextQueue(); //Очередь со втрого элемента
	ATS_INFO* popQueue(); //Delete
	ATS_INFO* peekQueue(); //With out delete

	Queue* operator=(Queue& donor); //Приравнивание 
	Queue* operator+(Queue* second); //Объединение
	void operator+= (Queue* second); //Объединение 
	bool operator==(Queue& second); //Сравнение

};