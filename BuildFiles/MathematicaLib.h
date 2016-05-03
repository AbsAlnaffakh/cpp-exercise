
#include <vector> // to allow the use of vectors
#include <stdexcept>
#include <exception>
#include <iostream> // used with std::in /std::out
#include <string> // used to allow for the use of strings
#include <string.h> // used tp provide string functions strlen()
#include <ctype.h> // used to allow the use of isnum() /isspace() /isalpha()

using namespace std;

namespace MyMathLib
{ 
	class MathematicaLib
	{
	public:
		static double DoTheMath(char const* equation);

	private:
		static double MathematicaLib::ExecutePEMDAS(vector<string> SortedEquation);

		static void Help();

		static void History(vector<string> CommandHistory);

		static double IsThisAnEquation(char const* equation);

		static double Undo(); // goes back one stepo

		static void ClearRestart();

		static void Load();

		// Returns a + b
		static double Add(double a, double b);

		// Returns a - b
		static double Subtract(double a, double b);

		// Returns a * b
		static double Multiply(double a, double b);

		// Returns a / b
		static double Divide(double a, double b);

	};
}