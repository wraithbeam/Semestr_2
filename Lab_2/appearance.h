#include "String.h"

class Appearance
{
public:
	Appearance(int); //������
    ~Appearance();
    void appAdd(const char* _name, int _number, int _hour, int _min);
    void appAdd(String&);
    void appRemove(int);
    void appDisplay();
    void appEquality(int, int);
    void appKeyInput();

    // ---------4-------- //
    String& operator[](int);
    Appearance& operator=(Appearance&);
    int appFind();
    String* appFindAll();
    void appShowFind(int numberCorrectElement);
    void appShowFind(int* numberOfCorrect);
    bool equalityCharWithChar(char*);
    

private:
	String* ats_info; 
	int currentIndex = 0;   // ������� ������
	int totalRecords;
    void checkFullMass();

    
};
