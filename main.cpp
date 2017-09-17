#include <iostream>

using namespace std;

void assignZeroPBV(int num)
    {
        num = 0;
    }
void assignZeroPBR(int& num)
    {
        num = 0;
    }
int main()
{
    int num = 100;
    cout<<"The integer-variable \"num\" is assigned with a value of "<<num<<endl;
    assignZeroPBV(num);
    cout<< "The value of 'num' after it is passed to the assignZero function by value, is: "<<num<<endl;
    assignZeroPBR(num);
    cout<< "The value of 'num' after it is passed to the assignZero function by reference, is: "<<num<<endl;
    cout<<"This shows that when a variable is passed-by-value to the assign function, the data or value associated with it,"<<endl;
    cout<<"is replicated to another storage location, and passed to the function. That is why the value of 'num' does not change."<<endl;
    cout<<"Whereas when the variable is passed-by-reference, the a reference to actual parameter(num) is passed."<<endl;
    cout<<"Hence the value changes."<<endl;


}
