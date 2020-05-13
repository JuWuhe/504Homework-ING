#include<iostream>
#include<fstream>
using namespace std;

class Student{
    string num;
    string name;
    string sex;
    int score;
public:
    Student(string nu="",string na="",string se="",int s=0){
        num = nu;
        name = na;
        sex = se;
        score = s;
    }
    friend ostream & operator <<(ostream &out,const Student &s);
};

ostream &operator<<(ostream &out,const Student &s){
    out << "学号："<<s.num<<"，姓名："<<s.name<<"，性别："<<s.sex<<"，成绩："<<s.score << endl;
    return out;
}

void CreatBiFile(string filename){
    ofstream out(filename);
    out.clear();
    Student stu[3] = {Student("B1903xxx","张三","男",80),Student("B1903xxx","李四","男",60),Student("B1903xxx","王二麻","女",90)};
    //cout << stu[0] << stu[1] << stu[2];
    out.write((char *)stu, sizeof(Student) * 3);
    out.close();
}


void ReadBiFile(string filename){
	Student stu;
	ifstream in(filename);
	while (!in.eof())
	{
		in.read((char *)&stu, sizeof(Student));
        cout << stu;
	}
	in.close();
}

int main(){
	CreatBiFile("D:\\stu.dat");
	ReadBiFile("D:\\stu.dat");
	return 0;
}