#include "Queue.h"
#include <functional>
#include <stdlib.h>


using namespace std;


int main()
{
	setlocale(0, "");
	//setlocale(0, "");
	//Appearance arrayFirst(5);
	//arrayFirst.appAdd("1", 1, 24, 15);
	//arrayFirst.appAdd("3", 3, 24, 15);
	//arrayFirst.appAdd("4", 4, 24, 15);
	//arrayFirst.appAdd("2", 2, 24, 15);
	//arrayFirst.appAdd("0", 0, 24, 15);
	//ATS_INFO first("Moskow", 123123, 22, 15);
	//arrayFirst.appAdd(first);
	//arrayFirst.appKeyInput();
	//system("cls");
	//arrayFirst.appDisplay();
	//arrayFirst.appEquality(0, 1); //Верно
	//arrayFirst.appEquality(100, 50); //Ошибка
	//arrayFirst.appRemove(2);
	//arrayFirst.appRemove(50);
	//arrayFirst.appDisplay();

	//Appearance newFilterClass(5);
	//Appearance* s = arrayFirst.appFindAll([](ATS_INFO& first) {
	//	return first.getNumber() > 3;
	//	});
	//if (s != nullptr)
	//	newFilterClass = *s;
	//newFilterClass.appDisplay();

	//Appearance sortClass(5);
	//sortClass = arrayFirst.appSort([](ATS_INFO& first, ATS_INFO& second) {
	//	return first.getNumber() < second.getNumber();
	//	});
	//sortClass.appDisplay();

	ATS_INFO first("1", 123, 15, 14);
	ATS_INFO second("2", 123, 14, 13);
	ATS_INFO thrid("3", 123, 13, 12);
	ATS_INFO four("4", 123, 12, 11);
	ATS_INFO five("5", 123, 11, 10);
	ATS_INFO null;

	Queue* queueAts = new Queue;
	queueAts->pushQueue(first);
	queueAts->pushQueue(second);
	queueAts->pushQueue(thrid);
	queueAts->pushQueue(four);
	queueAts->pushQueue(five);

	/*Queue* queueAts2 = new Queue;
	queueAts2->pushQueue(first);
	queueAts2->pushQueue(second);
	queueAts2->pushQueue(thrid);
	queueAts2->pushQueue(four);
	queueAts2->pushQueue(five);*/

	//queueAts->extend(queueAts2);
	queueAts->showQueue();
	//cout << endl;
	//null = *queueAts->popQueue(); //Delete
	//null.showString();
	//null = *queueAts->peekQueue();
	//null.showString();

}

