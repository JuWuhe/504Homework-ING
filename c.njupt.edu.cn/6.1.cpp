#include <iostream>

template <class T>
void swap(T &a,T &b){
    T temp = a;
    a = b;
    b = temp;
}

int main(){
    double a,b;
    std::cin >> a >> b;
    swap(a,b);
    std::cout << a << " " << b << std::endl;
    return 0;
}