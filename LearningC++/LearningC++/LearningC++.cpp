// LearningC++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Calculator.h"
#include "Randomizer.h"
#include "Person.h"

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

//incrementing an integer by pointer is possible, it directly changes whatever is stored in memory.
void incrementByPointer(int* ptr)
{
    *ptr += 1;
}

//incrementing an integer by reference like this is not possible.
//this should work for modifying data in bigger objects, but it doesnt let you overwrite a standalone integer.
void incrementByReference(int& i)
{
    i *= 1;
}

//this is taken from the getting started tutorial by microsoft.
void run_calculator()
{
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
}

//change a persons first name by passing a reference to the object.
void change_name_ref(Person& p, std::string nName)
{
    p.FirstName = nName;
}

//change a persons first name by using the pointer to the object.
//this ptr can not be const!
void change_name_ptr(Person* pptr, std::string nName)
{
    pptr->FirstName = nName;
}

//print the full name of a person. prototype method
void print_name(Person& p);

//testing things when using an actual class for storing data.
void run_person_tests()
{
    //creating two unique pointers to two seperate persons.
    unique_ptr<Person> pptrA(new Person("Max", "Monday"));
    unique_ptr<Person> pptrB(new Person("Tina", "Tuesday"));

    change_name_ref(*pptrA, "Mike");
    print_name(*pptrA);

    change_name_ptr(pptrB.get(), "Tim");
    print_name(*pptrB);
}

void run_numbers_test()
{
    //the preferred way to manage objects: smart pointers like
    unique_ptr<Calculator> cPtr(new Calculator());

    //just like standard ("raw") pointers, use the -> arrow to access the value.
    cPtr->Calculate(10, '+', 2);

    //the only way to create a pointer to an int is to allocate it the normal way first, then create the pointer.
    int bigN = 10;
    int* bigNptr = &bigN;
    //print 10
    cout << "Initial Value: " << bigN << endl;

    incrementByPointer(bigNptr);
    //print 11
    cout << "By Pointer: " << bigN << endl;

    incrementByReference(*bigNptr);
    //print 11 again!!!
    cout << "By Reference: " << bigN << endl;

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

    for (int i = 0; i < 40; ++i)
        cout << random.in_range(2, 10) << endl;
    cout << endl;
}

int main()
{
    run_person_tests();

    return 0;
}

//implement the print_name function
void print_name(Person& p)
{
    cout << p.ToString() << endl;
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
