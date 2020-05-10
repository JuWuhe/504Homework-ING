#include <iostream>
#include <string>
using namespace std;

class Car{
    private:
    int year;
    double price;
    string brand;
    string type;
    void SetCar(string brand ="undefinition",string type = "undefinition",int year = 2000,double price = 0){
        this->brand = brand;
        this->type = type;
        this->year = year;
        this->price = price;
    }
    public:
    Car(string brand ="undefinition",string type = "undefinition",int year = 2000,double price = 0){
        SetCar(brand,type,year,price);
    }
    string GetBrand(){
        return brand;
    }
    string GetType(){
        return type;
    }
    int GetYear(){
        return year;
    }
    double GetPrice(){
        return price;
    }
};

int main() 
{ 
    Car car1("FIAT","Palio",2007,6.5); 
    cout << car1.GetBrand () <<"|"<<car1.GetType (  ) <<"|"<<car1.GetYear (  ) <<"|" <<car1.GetPrice (  ) <<endl; 
    Car car2; 
    cout << car2.GetBrand ()<<"|"<<car2.GetType (  )<<"|"<<car2.GetYear (  ) <<"|" <<car2.GetPrice (  )<<endl; 
    return 0; 
}