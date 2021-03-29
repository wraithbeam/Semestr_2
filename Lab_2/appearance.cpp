#include "appearance.h"
#include <functional>

Appearance::Appearance(int count) { //Динамический список объектов
    this->totalRecords = count;
    ats_info = new ATS_INFO[count];
    //std::cout << "Сконструирован список по адресу: " << this << std::endl;
}

Appearance::~Appearance() {

};

void Appearance::appAdd(const char* _name, int _number, int _hour, int _min) {
    if (currentIndex < totalRecords) {
        ats_info[currentIndex] = ATS_INFO(_name, _number, _hour, _min);
        currentIndex++;
        checkFullMass();
    }
    else
        std::cout << "Слишком много записей" << std::endl;
}

void Appearance::appAdd(ATS_INFO& temp_atsInfo) {
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

int Appearance::getCurrentIndex() {
    return currentIndex;
}

//Лабораторная работа 4

ATS_INFO& Appearance::operator[](int index) {
    return ats_info[index];
}

Appearance& Appearance::operator=(Appearance& second) {
    this->currentIndex = second.currentIndex;
    this->totalRecords = second.totalRecords;
    ats_info = new ATS_INFO[currentIndex];
    for (int i = 0; i < currentIndex; i++)
        ats_info[i] = second.ats_info[i];
    return *this;
}


Appearance* Appearance::appFind(const function<bool(ATS_INFO&)>& func){
    static Appearance tempFindRecords(1);
    for (int i = 0; i < currentIndex; i++)
        if (func(ats_info[i])) {
            tempFindRecords.appAdd(ats_info[i]);
            return &tempFindRecords;
        }
    return nullptr;
}

Appearance* Appearance::appFindAll(const function<bool(ATS_INFO&)>& func){
    static Appearance tempFindRecords(currentIndex);
    for (int i = 0; i < currentIndex; i++)
        if (func(ats_info[i]))
            tempFindRecords.appAdd(ats_info[i]);
    return ((tempFindRecords.getCurrentIndex() > 0) ? &tempFindRecords : nullptr);
}

Appearance& Appearance::appSort(const function<bool(ATS_INFO&, ATS_INFO&)>& func)
{
    static Appearance sortRecords(currentIndex);
    sortRecords = *this;
    for (int i = 0; i < currentIndex; i++)
        for (int j = 0; j < currentIndex-1; j++)
            if (func(sortRecords[j], sortRecords[j+1]))
                sortRecords.appSwap(j, j+1);
    return sortRecords;
}

void Appearance::appSwap(int index1, int index2)
{
    ATS_INFO tempRecords;
    tempRecords = this->ats_info[index1];
    this->ats_info[index1] = this->ats_info[index2];
    this->ats_info[index2] = tempRecords;
}

