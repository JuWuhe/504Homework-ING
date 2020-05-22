#include <iostream>
using namespace std;

class Time{
private:
    int Hour;
    int Minute;
    int Second;
    void update(){
        if(Second >= 60){
            Second -= 60;
            Minute ++;
        }
        if(Minute >= 60){
            Minute -= 60;
            Hour ++;
        }
        if(Hour >= 24){
            Hour -= 24;
        }
    }
public:
    Time(int Hour,int Minute,int Second){
        cout << "¹¹Ôì" << endl;
        setHour(Hour);
        setMin(Minute);
        setSec(Second);
    }
    Time(const Time &t){
        cout << "¿½±´" << endl;
        setHour(t.Hour);
        setMin(t.Minute);
        setSec(t.Second);
    }
    ~Time(){
        cout << "Îö¹¹" << endl;
    }
    void setHour(int Hour){
        this->Hour = Hour;
    }
    void setMin(int Minute){
        this->Minute = Minute;
    }
    void setSec(int Second){
        this->Second = Second;
    }
    void IncreaceOneSecond(){
        Second++;
        update();
    }
    void PrintTime(){
        update();
        cout<< Hour << ":" << Minute << ":" << Second << endl;
    }
};

void f(Time *t){
    t -> PrintTime();
}

int main(){
    Time time1(9,59,59);
    Time time2(time1);
    Time * p = &time2;
    f(p);
    //time1.IncreaceOneSecond();
    //f(time1);
    return 0;
}