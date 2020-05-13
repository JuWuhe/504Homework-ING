#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Course{
private:
    string name;
    int number;
public:
    friend ostream & operator << (ostream & out,const Course &p);
    friend istream & operator >> (istream & in,Course &p);
};

istream & operator >> (istream & in,Course &p){
    in >> p.name;
    in >> p.number;
    return in;
}

ostream & operator << (ostream & out,const Course &p){
    out << "课程名：" << p.name << ",人数：" << p.number << endl;
    return out;
}

int main(){
    Course p;
    ifstream myfile("D:\\course.txt");
    string temp;
    if (!myfile.is_open()) { 
        cout << "Open false" << endl; 
    }
    while(!myfile.eof()){
        myfile >> p;
        cout << p;
    }
    myfile.close();
    return 0;
}