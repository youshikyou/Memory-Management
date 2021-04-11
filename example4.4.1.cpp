#include <stdlib.h>
#include <iostream>

class MyClass
{
private:
    int *_number;

public:
    MyClass()
    {
        std::cout << "Allocate memory\n";
        _number = (int *)malloc(sizeof(int));
    }
    ~MyClass()
    {
        std::cout << "Delete memory\n";
        free(_number);
    }
    void setNumber(int number)
    {
        *_number = number;
        std::cout << "Number: " << _number << "\n";
    }
};
//By separating allocation from construction, 
//we can get a significant performance increase.C++ allows us to do this by using a construct called placement new: 
//With placement new, we can pass a preallocated memory and construct an object at that memory location.
//The syntax new (memory) is denoted as placement new. 
//The difference to the "conventional" new we have been using so far is that that no memory is allocated. 
//The call constructs an object and places it in the assigned memory location. 
//There is however, no delete equivalent to placement new, so we have to call the destructor explicitly in this case 
void *memory = malloc(sizeof(MyClass));
MyClass *object = new (memory) MyClass;
object->~MyClass();
free(memory); 