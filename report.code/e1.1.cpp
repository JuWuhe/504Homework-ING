#include <iostream>
using namespace std;

class BookCard{
private:
    string id;
    string stuName;
    int number;
public:
    BookCard(string id = "B19010250",string name = "??",int num = 4){
        this->id = id;
        this->stuName = name;
        this->number = num;
    }
    void display(){
        cout << id << " " << stuName << " " << number << endl;
    }
    bool borrow(){
        return (number < 10) ? number++,true : false;
    }
};

void f(BookCard &bk){
    if (!bk.borrow())
    {
    bk.display();
    cout<<"you have borrowed 10 books,can not borrow any more!"<<endl;
    }
    else
    bk.display();
}

int main(){
    BookCard bk1("B20190620","??",10),bk2;
    f(bk1);
    f(bk2);
    return 0;
}