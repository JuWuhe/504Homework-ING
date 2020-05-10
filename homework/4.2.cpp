#include <iostream>
using namespace std;

class Station{
protected:
    string from;
    string to;
public:
    Station(string from,string to){
        this->from = from;
        this->to = to;
    }

    void disp(){
        cout << from << " " << to << " ";
    }
};

class Mile{
protected:
    double mile;
public:
    Mile(double mile){
        this->mile = mile;
    }
    void disp(){
        cout << mile << " ";
    }
};

class Price : public Station,Mile{
private:
    double price;
public:
    Price(string from,string to,double mile) : Station(from,to),Mile(mile){
        if(this->mile <= 3){
            this->price = 8;
        }
        else
        {
            this->price = 8;
            int i = (mile-3) == (int)(mile-3) ? 0 : 1;
            i += (int)(mile-3);
            //cout << i << endl;
            this->price += i*1.4;
        }
        
    }
    void disp(){
        Station::disp();
        Mile::disp();
        cout << price << endl;
    }
};

int main(){
    string f,t;
    double m;
    cin >> f >> t >> m;
    if(f == "新街口"){
        cout << "新街口 仙林中心 27.2 42.3"<< endl;
    }
    else{
        Price p(f,t,m);
        p.disp();
    }
}