
#include <iostream>
#include "Header.h"

int main()
{

	setlocale(0, "");
	String title("Учимся кушать пиццу");
	String lession("Перегурзка пиццы");
	title.show_string();
	title + " я типа учусь";
	title.show_string();


}