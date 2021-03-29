#include "ATS_INFO.h"
#include <functional>

using namespace std;

class Appearance
{
private:
    ATS_INFO* ats_info;
    int currentIndex = 0;   // Текущий индекс
    int totalRecords;
    void checkFullMass();
public:
	Appearance(int); //массив
    ~Appearance();
    void appAdd(const char* _name, int _number, int _hour, int _min);
    void appAdd(ATS_INFO&);
    void appRemove(int);
    void appDisplay();
    void appEquality(int, int);
    void appKeyInput();
    int getCurrentIndex();

    // ---------4-------- //
    ATS_INFO& operator[](int);
    Appearance& operator=(Appearance&);
    Appearance* appFind(const function<bool(ATS_INFO&)>& func);
    Appearance* appFindAll(const function<bool(ATS_INFO&)>& func);
    Appearance& appSort(const function<bool(ATS_INFO&, ATS_INFO&)>& func);
    void appSwap(int, int);
   
};