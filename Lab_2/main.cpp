#include "Appearance.h"
#include <stdlib.h>

using namespace std;
 
int main()
{
	setlocale(0, "");
	Appearance arrayFirst(5);
	arrayFirst.appAdd("Moskow", 123123, 22, 15);
	String first("Moskow", 123123, 22, 15);
	arrayFirst.appAdd(first);
	arrayFirst.appKeyInput();
	system("cls");
	////arrayFirst.appDisplay();
	////arrayFirst.appEquality(0, 1); //Верно
	////arrayFirst.appEquality(100, 50); //Ошибка
	////arrayFirst.appRemove(2);
	////arrayFirst.appRemove(50);
	////arrayFirst.appDisplay();

	//Проверка фильтра
	for (int i = 0; i < 3; i++)
	{  
		arrayFirst.appDisplay();
		/*arrayFirst.appShowFind(arrayFirst.appFind());*/
		String *findResult = arrayFirst.appFindAll();
		String findResult2 = *findResult;
		findResult2.showString();
		/*arrayFirst.appShowFind(arrayFirst.appFindAll());*/
		system("pause");
		system("cls");
	}
}

