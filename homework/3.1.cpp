#include<iostream>
using namespace std;

class Date
{
    private:
        int year,month,day;
    public:
    Date(int y =2000,int m =1,int d =1){
        SetDate(y,m,d);
    }
    void SetDate(int y,int m,int d){
        year = y;
        month = m;
        day = d;
    }

    int Getyear(){
        return year;
    }

    int Getmonth(){
        return month;
    }

    int Getday(){
        return day;
    }

    
};

class Product
{
    private:
       string name;
       double price;
       Date deptime;
       string factory;
       bool easy_break;
       Date valtime; 
       string color;
       double high;
    public:
        Product(string n){
            name = n;
            cout << "Constrcting One...." << endl;
        }
        Product(string n,double pr){
            factory = "unnamed";
            easy_break = 0;
            name = n;
            price = pr;
            cout << "Constrcting Two...." << endl;
        }
        Product(string n,double pr,int x,int y,int z):deptime(x,y,z){
            factory = "unnamed";
            easy_break = 0;
            name = n;
            price = pr;
            cout << "Constrcting Three...." << endl;
        }
        void SetProduct(string n,double pr,int x,int y,int z,string fa,bool ea,int a,int b,int c,string co,double h){
            name = n;
            price = pr;
            deptime.SetDate(x,y,z);
            factory = fa;
            easy_break = ea;
            valtime.SetDate(a,b,c);
            color = co;
            high = h;
        }
        void output(){
            cout<<name<<" "<<price<<endl;
            cout<<deptime.Getyear()<<"-"<<deptime.Getmonth()<<"-"<<deptime.Getday()<<endl;
            cout<<factory<<" "<<easy_break<<endl;
            cout<<valtime.Getyear()<<"-"<<valtime.Getmonth()<<"-"<<valtime.Getday()<<endl;
        }
}; 

int main()
{
       string  s;
       cin>>s;
       Product p1("car");
       Product p2("glass",3.00);
       Product p3("pen",5.00,2009,3,14);
       p1.SetProduct("car",100000.0,2009,3,14,"nanjing",0,2010,10,14,"red",1.5);
       p1.output();
       p2.output();
       p3.output();
       return 0;
}