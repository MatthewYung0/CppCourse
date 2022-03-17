/*
 ===================================================================================================
Source:https://www.geeksforgeeks.org/

Constructors are special class members which are called by the compiler every time an object of that class is instantiated.
 Constructors have the same name as the class and may be defined inside or outside the class definition.

There are different types of constructors:

Default constructors
Parameterized constructors

 
  ===================================================================================================
 */

// C++ program to demonstrate constructors

#include <bits/stdc++.h>
using namespace std;
class Geeks
{
	public:
	int id;
	
	//Default Constructor
	Geeks()
	{
		cout << "Default Constructor called" << endl;
		id=-1;
	}
	
	//Parameterized Constructor
	Geeks(int x)
	{
		cout << "Parameterized Constructor called" << endl;
		id=x;
	}
};
int main() {
	
	// obj1 will call Default Constructor
	Geeks obj1;
	cout << "Geek id is: " <<obj1.id << endl;
	
	// obj1 will call Parameterized Constructor
	Geeks obj2(21);
	cout << "Geek id is: " <<obj2.id << endl;
	return 0;
}



