#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

class Student{
    char num[20];
    char name[20];
    char sex[20];
    int score;
public:
    Student(char* nu="",char* na="",char* se="",int s=0){
        strcpy(num,nu);
        strcpy(name,na);
        strcpy(sex,se);
        score = s;
    }
    friend ostream & operator <<(ostream &out,const Student &s);
};

ostream &operator<<(ostream &out,const Student &s){
    out << "ѧ�ţ�"<<s.num<<"��������"<<s.name<<"���Ա�"<<s.sex<<"���ɼ���"<<s.score << endl;
    return out;
}

void CreatBiFile(const string filename){
    ofstream out(filename);
    out.clear();
    Student stu[3] = {Student("B1903xxx","����","��",80),Student("B1903xxx","����","��",60),Student("B1903xxx","������","Ů",90)};
    //cout << stu[0] << stu[1] << stu[2];
    out.write((char *)stu, sizeof(Student) * 3);
    out.close();
}


void ReadBiFile(const string filename){
	Student stu[3];
	ifstream in(filename);
    int i = 0;
	while (!in.eof())
	{
		in.read((char *)&stu[i++], sizeof(Student));
	}
    for(int j = 0;j<i-1;j++){ // i-1����Ϊeofǰ�и��ո�
        cout << stu[j];
    }
	in.close();
}

int main(){
	CreatBiFile("D:\\stu.dat");
	ReadBiFile("D:\\stu.dat");
	return 0;
}