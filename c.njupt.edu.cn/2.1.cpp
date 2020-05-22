#include <iostream>
using namespace std;

class Cube{
    private:
    int l,w,h;
    public:
    Cube(int l =3,int w = 2,int h = 1){
        this->l = l;
        this->h = h;
        this->w = w;
    }
    int Compute(){
        return l*h*w;
    }
};

int main()
{
	int l,w,h;
	cout<<"ÊäÈë³¤¿í¸ß£º"<<endl;
	cin>>l>>w>>h;
	Cube A(l,w,h);
	Cube B;
	cout<<A.Compute()<<endl;
	cout<<B.Compute()<<endl;
}