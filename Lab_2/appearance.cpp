#include "appearance.h"

Appearance::Appearance(int count) { //Динамический список объектов
    this->totalRecords = count;
    ats_info = new String[count];
    std::cout << "Сконструирован список по адресу: " << this << std::endl;
}

Appearance::~Appearance() {

};

void Appearance::appAdd(const char* _name, int _number, int _hour, int _min) {
    if (currentIndex < totalRecords) {
        ats_info[currentIndex] = String(_name, _number, _hour, _min);
        currentIndex++;
        checkFullMass();
    }
    else
        std::cout << "Слишком много записей" << std::endl;
}

void Appearance::appAdd(String& temp_atsInfo) {
    if (currentIndex < totalRecords) {
        ats_info[currentIndex] = temp_atsInfo;
        currentIndex++;
        checkFullMass();
    }
    else
        std::cout << "Error: Слишком много студентов\n" << std::endl;
}

void Appearance::appRemove(int number) {

    if (number < currentIndex) {
        for (int i = number; i < currentIndex - 1; i++) {
            ats_info[i] = ats_info[i + 1];
        }
        currentIndex--;
        std::cout << "Успешно удален.\n" << std::endl;
    }
    else
        std::cout << "Error: Элемент не инициализирован.\n" << std::endl;
}

void Appearance::appDisplay() {
    if (currentIndex != 0) {
        for (int i = 0; i < currentIndex; i++) {
            ats_info[i].showString();
            std::cout << "____________________________" << std::endl;
        }
    }
    else
        std::cout << "Список пуст." << std::endl;
    std::cout << "Всего сохраненных записей " << currentIndex << std::endl << std::endl;
}

void Appearance::appEquality(int first, int second) {
    if ((first <= currentIndex) && (second <= currentIndex))
        if (ats_info[first] == ats_info[second])
            std::cout << "Объекты равны\n" << std::endl;
        else
            std::cout << "Объекты не равны\n" << std::endl;
    else
        std::cout << "Error: Значения вне списка.\n" << std::endl;

}

void Appearance::appKeyInput() {
    int answer;
    std::cout << "\nЗаполнение массива объектов.\nВыберите действие:\n1. Заполнить весь массив с текущего элемента." <<
        "\n2. Заполнить следующий элемент массива.\nНa текущий момент заполнено " << currentIndex << " обекта(-ов).\n";
    std::cin >> answer;
    if (answer == 1) {
        for (int i = currentIndex; i < totalRecords; i++) {
            ats_info[i].inputString();
            currentIndex++;
        }
    }
    if (answer == 2) {
        ats_info[currentIndex].inputString();
        currentIndex++;
    }
}

void Appearance::checkFullMass() {
    if (currentIndex == totalRecords) {
        std::cout << "Список заполнен!" << std::endl << std::endl;
    }
}

//Лабораторная работа 4

String& Appearance::operator[](int index) {
    return ats_info[index];
}

Appearance& Appearance::operator=(Appearance& second) {
    this->currentIndex = second.currentIndex;
    this->totalRecords = second.totalRecords;
    ats_info = new String[currentIndex];
    for (int i = 0; i < currentIndex; i++)
        ats_info[i] = second.ats_info[i];
    return *this;
}

int Appearance::appFind() {
    std::cout << "Выберите критерий поиска:\n1. Страна вызова.\n2. Номер вызова.\n3. Время вызова." << std::endl;
    int answer;
    std::cin >> answer;
    char city[256]; int number = -1, hour = -1, min = -1;
    switch (answer)
    {
    case 1: std::cout << "Введите страну: "; std::cin >> city; break;
    case 2: std::cout << "Введите номер: "; std::cin >> number; break;
    case 3: std::cout << "Введите время в формате час минута: "; std::cin >> hour >> min; break;
    default: std::cout << "Неверный ввод!\n"; break;
    }
    for (int i = 0; i < currentIndex; i++){
        if (!(strcmp(ats_info[i].getName(), city)) && (answer == 1))
            return i;
        else if ((ats_info[i].getNumber() == number) && (answer == 2))
            return i;
        else if ((ats_info[i].getHour() == hour) && (ats_info[i].getMin() == min) && (answer == 3))
            return i;
    }
    std::cout << "Значение не было найдено!" << std::endl << std::endl;
    return -1;
}

String* Appearance::appFindAll(){
    std::cout << "Сортировка до последнего!\nВыберите критерий поиска:\n1. Страна вызова.\n2. Номер вызова.\n3. Время вызова." << std::endl;
    int answer;
    std::cin >> answer;
    char city[256]; int number = -1, hour = -1, min = -1;
    switch (answer)
    {
    case 1: std::cout << "Введите страну: "; std::cin >> city; break;
    case 2: std::cout << "Введите номер: "; std::cin >> number; break;
    case 3: std::cout << "Введите время в формате час минута: "; std::cin >> hour >> min; break;
    default: std::cout << "Неверный ввод!\n"; break;
    }
    int* numbersOfCorrectElements = new int[currentIndex];
    int k = 0;
    for (int i = 0; i < currentIndex; i++) {
        if (!(strcmp(ats_info[i].getName(), city)) && (answer == 1))
            numbersOfCorrectElements[k++] = i;
        else if ((ats_info[i].getNumber() == number) && (answer == 2))
            numbersOfCorrectElements[k++] = i;
        else if ((ats_info[i].getHour() == hour) && (ats_info[i].getMin() == min) && (answer == 3))
            numbersOfCorrectElements[k++] = i;
    }
    if (k != 0)
        return nullptr;
    else {
        std::cout << "Значение не было найдено!" << std::endl << std::endl;
        numbersOfCorrectElements[0] = -1;
        //return numbersOfCorrectElements;
    }

}

void Appearance::appShowFind(int numberCorrectElement)
{
    if(numberCorrectElement != -1)
        std::cout << "Элемент соответствуюший фильтру " << numberCorrectElement + 1 << std::endl << std::endl;
    else
        std::cout << "Error: значение не было найдено!" << std::endl << std::endl;
}

void Appearance::appShowFind(int* numberOfCorrect)
{
    std::cout << "Элементы соответствуюшие фильтру: ";
    if (numberOfCorrect[0] != -1)
        for (int i = 0; i < currentIndex; i++)
            std::cout << numberOfCorrect[i] << "; ";
    else
        std::cout << "Error: значения не были найдены!";
    std::cout << std::endl << std::endl;
}

