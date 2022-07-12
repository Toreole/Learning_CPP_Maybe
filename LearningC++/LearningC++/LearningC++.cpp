// LearningC++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Calculator.h"
#include "Randomizer.h"

using namespace std;

int test(int* numberByPointer)
{
    //getting the value thats stored at the pointer location requires a * in front of the pointer name.
    return *numberByPointer + 1;
}

//the const int& uses the pointed-to int object.
//making it const is useful since the value should only be read inside the function
int plusOne(const int& num)
{
    return num + 1;
}

//where is the functional difference to plusOne? 
int plusOne_B(const int num)
{
    return num + 1;
}

int main()
{
    //the preferred way to manage objects: smart pointers like
    unique_ptr<Calculator> cPtr(new Calculator());
    //just like standard ("raw") pointers, use the -> arrow to access the value.
    cPtr->Calculate(10, '+', 2);

    //the only way to create a pointer to an int is to allocate it the normal way first, then create the pointer.
    int bigN = 10;
    int* bigNptr = &bigN;

    int xx = plusOne(1);
    int yy = plusOne(*bigNptr);
    int zz = plusOne_B(*bigNptr);

    //expected to print 11
    cout << test(bigNptr) << endl;

    //using new it creates an object in memory, and gives us the address (pointer)
    Randomizer* randomPtr = new Randomizer();
    //using a function on the pointer requires an arrow (->)
    cout << randomPtr->in_range(50, 100) << endl;
    //manual creation requires manual deletion so we dont cause memory leaks.
    delete randomPtr;

    //^ manual management discourage in modern C++ apparently. use smart pointers instead, they will automatically release memory

    //what is this exactly? I can clearly call its method, so i assume it is not NULL.
    //Does this mean that it is automatically created and destroyed at the end of the scope?
    Randomizer random;

    for(int i = 0; i < 40; ++i)
        cout << random.in_range(2, 10) << endl;
    cout << endl;

    //-------- CALCULATOR -----------

    double x = 0.0;
    double y = 0.0;
    double result = 0.0;
    char oper = '+';

    cout << "Calculator Console Application" << endl << endl;
    cout << "Please enter the operation to perform. Format: a+b | a-b | a*b | a/b" << endl;

    Calculator c;
    while (true)
    {
        cin >> x >> oper >> y;
        if (oper == '/' && y == 0)
        {
            cout << "Can't divide by 0." << endl;
            continue;
        }
        result = c.Calculate(x, oper, y);
        cout << "Result is: " << result << endl;
    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
