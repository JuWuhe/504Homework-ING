#include <iostream>
#include <stdlib.h>
using namespace std;

class Matrix{
private:
    int *m,row,col;
public:
    Matrix(int r,int c){
        this->row = r;
        this->col = c;
        m = new int[row*col];
        cout<<"请输入该矩阵元素:" << endl;
        for(int i = 0;i<row;i++){
            for(int j = 0;j<col;j++){
                cin >> m[i*col+j];
            }
        }
    }
    Matrix(){
        row = col = 0;
        m = NULL;
    }
    ~Matrix(){
        delete m;
    }
    friend Matrix& operator+(Matrix&,Matrix&);
    Matrix& operator=(Matrix&mat){
        delete m;
        m = new int[mat.row*mat.col];
        row = mat.row;
        col = mat.col;
        for(int i = 0;i<row;i++){
            for(int j = 0;j<col;j++){
                *(m+i*col+j)=*(mat.m+i*mat.col+j);
            }
        }
        return *this;
    }
    void disp()
    {
        for(int i=0;i<row;i++)
        {
            cout<<'\t';
            for(int j=0;j<col;j++)
                cout<<*(m+i*col+j)<<'\t';
            cout<<endl;
        }
    }
};

Matrix& operator+(Matrix&m1,Matrix&m2){
    if(m1.col!=m2.col || m1.row!=m2.row){
        cout <<"program terminated!" << endl;
        exit(0);
    }
    else{
        for(int i = 0;i<m1.row;i++){
            for(int j =0;j<m1.col;j++){
                (*(m1.m+i*m1.col+j))+=(*(m2.m+i*m2.col+j));
            }
        }
    }
    return m1;
}

int main()
{
	int row_a,col_a,row_b,col_b;
	cout<<"请输入am矩阵的行数和列数:"<<endl;
	cin>>row_a>>col_a;
	Matrix am(row_a,col_a);
	cout<<"请输入bm矩阵的行数和列数:"<<endl;
	cin>>row_b>>col_b;
	Matrix bm(row_b,col_b),cm;
	cout<<"am:"<<endl;
	am.disp();
	cout<<"bm:"<<endl;
	bm.disp();
	cm=am+bm;
	cout<<"cm=am+bm:"<<endl;
	cm.disp();
	am=bm;
	cout<<"am=bm:"<<endl;
	am.disp();
	return 0;
}