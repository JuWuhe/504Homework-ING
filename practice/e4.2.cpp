#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void ReadFile(const char *s){
	string ch;
	ifstream myfile(s);
	if (!myfile.is_open())
	{
		cout << "Open false" << endl;
		exit(1);
	}
	while (!myfile.eof()){
        getline(myfile,ch);
        cout << ch << endl;
    }
	myfile.close();
}

void Change(const char *s1, const char *s2)
{
	ifstream ifile(s1);
	if (!ifile)
	{
		cout << "Open fasle" << endl;
		exit(1);
	}
	ofstream ofile(s2);
    ofile.clear();
	char ch;
	while (ifile.get(ch))
	{
		if (ch >= 'a'&&ch <= 'z'){
			ch -= 32;
        }
		ofile.put(ch);
	}
	ifile.close();
	ofile.close();
}

int main(){
    char s1[20],s2[20];
    cin >> s1 >> s2;
    ReadFile(s1);
    Change(s1,s2);
    ReadFile(s2);
    return 0;
}