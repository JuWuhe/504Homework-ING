#include<iostream>
using namespace std;
class Boy;

class Girl{
private:
    string name;
    int age;
public:
    friend Boy;
    friend void VistBoyGirl(Boy&,Girl&);
    void VisitBoy(Boy &boy);
    Girl(int age = 18,string name = "Lilith"){
        this->age = age;
        this->name = name;
    }
    void printGirl(){
        cout << age << " " << name << endl;
    }
};

class Boy{
private:
    string name;
    int age;
public:
    friend  Girl;
    friend void VistBoyGirl(Boy&,Girl&);
    Boy(int age = 18,string name = "James"){
        this->age = age;
        this->name = name;
    }
    void printBoy(){
        cout  << age << " " << name << endl;
    }
    void VisitGirl(Girl &girl);
};
void Girl::VisitBoy(Boy &boy){
    cout << boy.age << " " << boy.name << endl;
}

void Boy::VisitGirl(Girl &girl){
    cout << girl.age << " " << girl.name << endl;
}

void VistBoyGirl(Boy &boy,Girl &girl){
    cout << boy.age << " " << boy.name << endl;
    cout << girl.age << " " << girl.name << endl;
}

int main(){
    Boy jam;
    Girl Lith;
    VistBoyGirl(jam,Lith);
    return 0;
}