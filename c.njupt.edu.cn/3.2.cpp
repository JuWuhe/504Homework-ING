#include<iostream>
using namespace std;
class Student
{
    private:
    int age;
    string name;
    public:
    static int count;
    public:
    Student(int m, string n);
    Student();
    ~Student( );
    void Print( ) const;
};

int Student::count = 0;

Student::Student(int m, string n)
{
    age = m;
    name = n;
    count++;
}
Student::Student()
{
    age = 0;
    name = "unnamed";
    count++;
}
Student::~Student()
{
    count--;
}
void Student::Print( ) const
{
    cout<<"count="<<count<<endl;
    cout<<name<<"  "<<age<<endl;
}

int main()
{
    cout<<"count="<<Student::count<<endl;
    string stuname="ZhangHong";
    Student s1,*p=new Student(23,stuname);
    s1.Print();
    p->Print();
    delete p;
    s1.Print();
    Student Stu[4];
    cout<<"count="<<Student::count<<endl;
    return 0;   
}