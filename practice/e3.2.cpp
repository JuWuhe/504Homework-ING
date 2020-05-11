#include<iostream>
using namespace std;

class Container{
protected:
    double radius;
public:
    Container(double r){
        radius = r;
    }
    Container(){
        radius = 0;
    }
    virtual double area() = 0;
    virtual double volume() = 0;
    virtual void print() = 0;
};

class Cube:public Container{  //正方体
public:
    Cube(double r){
        radius = r;
    }
    double area(){
        return radius*radius*6;
    }
    double volume(){
        return radius*radius*radius;
    }
    void print(){
        cout << "正方体表面积：" << area() << "  体积：" << volume() << endl;
    }
};

class Sphere:public Container{  //球体
public:
    Sphere(double r){
        radius = r;
    }
	double area()    
	{
		return 4 * 3.1415 * radius * radius;
	}
	double volume()  
	{
		return  (3.1415 * (4.0 / 3) * radius * radius * radius);
	}
	void print()     
	{
		cout << "球体表面积：" << area() << "  体积：" << volume() << endl;
	}
};

class Cylinder:public Container{  //圆柱体
    double height;
public:
    Cylinder(double r,double h){
        radius = r;
        height = h;
    }
    double area()    
	{
		return 2 * 3.1415 * radius *(radius + height);
	}
	double volume()  
	{
		return  3.1415 * height * radius * radius;
	}
	void print()     
	{
		cout << "圆柱体表面积：" << area() << "  体积：" << volume() << endl;
	}
};

void TopPrint(Container &r){
    r.print();
}

int main(){
    Container *p;
    Cube cu(1);
    Sphere sp(2);
    Cylinder cy(3,4);
    p = &cu;
    cout << p->area() << endl;
    cout << p->volume() << endl;
    p->print();
    p = &sp;
    cout << p->area() << endl;
    cout << p->volume() << endl;
    p->print();
    p = &cy;
    cout << p->area() << endl;
    cout << p->volume() << endl;
    p->print();
    TopPrint(cu);
    TopPrint(sp);
    TopPrint(cy);
    return 0;
}