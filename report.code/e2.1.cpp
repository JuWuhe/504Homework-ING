#include<iostream>
using namespace std;

class Vehicle{
protected:
    int MaxSpeed;
    int Weight;
public:
    Vehicle(int m,int w){
        this->MaxSpeed = m;
        this->Weight = w;
        cout << "Constructing Vehicle...."<< endl;
    }
    ~Vehicle(){
        cout << "Destructing Vehicle...." << endl;
    }
    void Run(){
        cout << "The Vehicle is running!" << endl;
    }
    void Stop(){
        cout << "Please stop running!" << endl;
    }
    void Show(){
        cout << "It\'s maxspped is:" << MaxSpeed << endl;
        cout << "It\'s weight is:" << Weight << endl;
    }
};

class Bicycle : virtual public Vehicle{
protected:
    int Height;
public:
    Bicycle(int m,int w,int h):Vehicle(m,w){
        this->Height = h;
        cout << "Constructing Bicycle...."<< endl;
    }
    ~Bicycle(){
        cout << "Destructing Bicycle...." << endl;
    }
    void Show(){
        Vehicle::Show();
        cout << "It\'s height is:" << Height << endl;
    }
};

class Car : virtual public Vehicle{
protected:
    int SeatNum;
public:
    Car(int m,int w,int s) : Vehicle(m,w){
        this->SeatNum = s;
        cout << "Constructing Car...." << endl;
    }
    ~Car(){
        cout << "Destructing Car...." << endl;
    }
    void Show(){
        Vehicle::Show();
        cout << "It\'s seatnumber is:" << SeatNum << endl;
    }
};

class MotorCycle: public Bicycle,public Car{
public:
    MotorCycle(int m,int w,int h,int s):Vehicle(m,w),Bicycle(m,w,h),Car(m,w,s){
        
    }
};

int main(){
    Bicycle b(1,2,3);
    b.Run();
    b.Stop();
    b.Show();
    Car c(1,2,4);
    c.Run();
    c.Stop();
    c.Show();
    return 0;
}