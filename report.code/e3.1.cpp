#include<iostream>
using namespace std;

class Point{
private:
    double x,y;
public:
    Point(double x =0.0,double y =0.0){
        this->x=x;
        this->y=y;
    }
    Point& operator++(){
        ++x;
        ++y;
        return *this;
    }
    Point& operator-(const Point &p){
        x-=p.x;
        y-=p.y;
        return *this;
    }
    friend Point& operator+(const Point &p1,const Point &p2);
    friend Point& operator+(const Point &p1,double a);
    friend ostream &operator << (ostream &output, Point&p);

};

Point& operator+(const Point &p1,const Point &p2){
    Point p(p1.x+p2.x,p1.y+p2.y);
    return p;
}

Point& operator+(const Point &p1,double a){
    Point p(p1.x+a,p1.y+a);
    return p;
}

ostream &operator << (ostream &output, Point&p){
    output << "(" << p.x << "," << p.y << ")" << endl;
}

int main(){
    Point pt1(10.5,20.8),pt2(-5.3,18.4),pt3;
    cout<<"original pt1,pt2,pt3 are:\n";
    cout<<pt1<<pt2<<pt3;
    pt3=pt1+100.8;
    cout<<"after pt3=pt1+100.8, pt3 is:"<<pt3;
    pt3=pt1+pt2;
    cout<<"after pt3=pt1+pt2, pt3 is:"<<pt3;
    pt3=++pt1;
    ++pt2;
    cout<<"after ++ pt1,pt2,pt3 are:\n";
    cout<<pt1<<pt2<<pt3;
    pt3=pt1-pt2;
    cout<<"after pt3=pt1-pt2, pt3 is:"<<pt3;
    return 0 ;
}