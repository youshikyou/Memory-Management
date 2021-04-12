#include <stdlib.h>
#include <iostream>

class MyMovableClass
{
private:
    int _size;
    int *_data;

public:
    MyMovableClass(size_t size) // constructor
    {
        _size = size;
        _data = new int[_size];
        std::cout << "CREATING instance of MyMovableClass at " << this << " allocated with size = " << _size*sizeof(int)  << " bytes" << std::endl;
    }

    ~MyMovableClass() // 1 : destructor
    {
        std::cout << "DELETING instance of MyMovableClass at " << this << std::endl;
        delete[] _data;
    }
    MyMovableClass(const MyMovableClass&source)
    {
        _size = source._size;
        _data = new int[_size];
        *_data = *source._data;
        std::cout << "COPYING content of instance " << &source << " to instance " << this << std::endl;
    }
    
    MyMovableClass & operator=(const MyMovableClass&source)
    {
        std::cout << "ASSIGNING content of instance " << &source << " to instance " << this << std::endl;
        if(this == &source)
        {
            return *this;
        }
        delete[] _data;
        _size = source._size;
        _data = new int[_size];
        *_data = *source._data;
        return *this;
    }
  MyMovableClass createObject(int size)
  {
  MyMovableClass obj(size); // regular constructor
  return obj; // return MyMovableClass object by value
  }
};
int main()
{
    MyMovableClass obj1(10); // regular constructor
    MyMovableClass obj2(obj1); // copy constructor
    obj2 = obj1; // copy assignment operator

    return 0;
}