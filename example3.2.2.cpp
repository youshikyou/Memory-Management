#include <iostream>

void func(int &i)
{
    int j = 3;
    std::cout<<"stack bottom: "<< &i<<'\n';
    std::cout<<"current: "<< &j<<'\n';
    func(i);
}

int main()
{
    int i = 1;
    func(i);
    return 0;
}