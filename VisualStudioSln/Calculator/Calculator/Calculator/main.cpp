#include <iostream>

using namespace std;

int main()
{
	
	/*
	1. used namespace std to avoid :: 
	2. 
	*/
	
	//execute a method here
	
	//char
	char test;

	char InputArgument; 

	
	// the library method should look like DoTheMath(Equation)

	
	cout << "\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/" << endl;
	cout << "Please type your equation in the formats shown below"<< endl;
	cout << "For Multipication x * y " << endl;
	cout << "For Division x / y " << endl;
	cout << "For Substraction x - y " << endl;
	cout << "For Addision x + y " << endl;
	cout << "For Mixed operations x * y / z - i + 40" << endl;
	cout << "For More Commands Type 'help' " << endl;




	//include the below lines
	cout << "Reset/Clear -- Delets All Progress And History" << endl;
	cout << "Undo		 -- Go Back One Step" << endl;
	cout << "History     -- Display Command History" << endl;
	cout << "Exit        -- Exit Application" << endl;
	cout << "Help" << endl;

	cin >> test;
}