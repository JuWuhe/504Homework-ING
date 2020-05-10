#include <iostream>
using namespace std;

class shape
{
protected:
	double radius;
public:
	shape(double r)
	{
		radius = r;
	}
	shape()
	{
		radius = 0;
	}
	virtual double area() = 0;   
	virtual double volume() = 0; 
	virtual void print() = 0;    
};


class sphere:public shape //球体
{
private:
	double radius;
public:
	sphere(double r)
	{
		radius = r;
	}
	virtual double area()    
	{
		return 4 * 3.1415 * radius * radius;
	}
	virtual double volume()  
	{
		return  (3.1415 * (4.0 / 3) * radius * radius * radius);
	}
	virtual void print()     
	{
		cout << "球体表面积为：" << area() << "  球体体积为：" << volume() << endl;
	}
};

class cylinder :public shape //圆柱体
{
private:
	double height;
	double radius;
public:
	cylinder(double r, double h)
	{
		radius = r;
		height = h;
	}
	virtual double area()    
	{
		return 2 * 3.1415 * radius *(radius + height);
	}
	virtual double volume()  
	{
		return  3.1415 * height * radius * radius;
	}
	virtual void print()     
	{
		cout << "圆柱体表面积为：" << area() << "  圆柱体体积为：" << volume() << endl;
	}

};


int main() {
   shape *p;
   double  r,h;
   cout<<"input r & h："<<endl;
   cin>>r>>h;
   cylinder cy(r,h);
   sphere sp(r);
   p=&cy;
   cout<<p-> volume()<<endl;    		
   p=&sp;
   cout<<p-> volume()<<endl; 
   return 0;
}