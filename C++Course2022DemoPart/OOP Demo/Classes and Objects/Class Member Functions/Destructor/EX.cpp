/*
 ===================================================================================================
Source:https://www.geeksforgeeks.org/

Destructor is another special member function that is called by the compiler when the scope of the object ends.
  ===================================================================================================
 */
// C++ program to explain destructors

#include <bits/stdc++.h>
using namespace std;
class Geeks
{
	public:
	int id;
	
	//Definition for Destructor
	~Geeks()
	{
		cout << "Destructor called for id: " << id <<endl;
	}
};

int main()
{
	Geeks obj1;
	obj1.id=7;
	int i = 0;
	while ( i < 5 )
	{
		Geeks obj2;
		obj2.id=i;
		i++;	
	} // Scope for obj2 ends here

	return 0;
} // Scope for obj1 ends here
