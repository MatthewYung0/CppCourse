/*
 ===================================================================================================
Source:https://www.geeksforgeeks.org
Runtime polymorphism: This type of polymorphism is achieved by virtual Function Overriding.

    Function overriding on the other hand occurs when a derived class has a definition for one of the  virtual member functions of the base class. 
    That base function is said to be overridden.


Source:https://www.tutorialspoint.com/
Virtual Function

A virtual function is a function in a base class that is declared using the keyword virtual. 
Defining in a base class a virtual function, with another version in a derived class, 
signals to the compiler that we don't want static linkage for this function.

What we do want is the selection of the function to be called at any given point in the program
 to be based on the kind of object for which it is called. This sort of operation is referred to as dynamic linkage, or late binding.



class Shape {
   protected:
      int width, height;
      
   public:
      Shape( int a = 0, int b = 0) {
         width = a;
         height = b;
      }
      virtual int area() {
         cout << "Parent class area :" <<endl;
         return 0;
      }
};

Pure Virtual Functions

It is possible that you want to include a virtual function in a base class so that it may be redefined in 
a derived class to suit the objects of that class, but that there is no meaningful definition you could give for the function in the base class.

class Shape {
   protected:
      int width, height;

   public:
      Shape(int a = 0, int b = 0) {
         width = a;
         height = b;
      }
      
      // pure virtual function
      virtual int area() = 0;
};

The = 0 tells the compiler that the function has no body and above virtual function will be called pure virtual function.

  ===================================================================================================
 */

// C++ program for function overriding

#include <bits/stdc++.h>
using namespace std;

class base
{
public:
	virtual void print ()
	{ cout<< "print base class" <<endl; }

	void show ()
	{ cout<< "show base class" <<endl; }
};

class derived:public base
{
public:
	void print () //print () is already virtual function in derived class, we could also declared as virtual void print () explicitly
	{ cout<< "print derived class" <<endl; }

	void show ()
	{ cout<< "show derived class" <<endl; }
};

//main function
int main()
{
	base *bptr;
	derived d;
	bptr = &d;
	
	//virtual function, binded at runtime (Runtime polymorphism)
	bptr->print();
	
	// Non-virtual function, binded at compile time
	bptr->show();

	return 0;
}
