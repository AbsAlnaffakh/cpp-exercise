
//MathematicaLib.cpp

#include "MathematicaLib.h"

//not sure about this ome
//#include <sstream> 

// Need A function for undo

namespace MyMathLib{
	
	vector<string> commandHistory; // used to store commands
	vector<double> equationHistory; // used to store the solving process and allow for undos
	

	double MathematicaLib::DoTheMath(char const* equation){
		
		commandHistory.insert(commandHistory.end(), equation); // saves each inputted command into a vector
		try{
			if (strcmp("Help", equation) == 0) { Help(); return 0.0; }
			else if (strcmp("Undo", equation) == 0) { return Undo(); }
			else if (strcmp("ClearRestart", equation) == 0){ ClearRestart(); return 0.0; }
			else if (strcmp("History", equation) == 0){ History(commandHistory); return 0.0; }
			else if (strcmp("Load", equation) == 0){ Load(); return 0.0; }
			else if (strlen(equation) > 100) { cout << "Input enetered is too big" << endl; return 0.0; } // used to limit input
			else
			{
				return IsThisAnEquation(equation); 
			}
		}
		catch (exception e){ cout << "Invalid input" << endl;  return 0; }
		return 0.0; // when an equations was not inputted
	}// end of DoTheMath 

	void  MathematicaLib::Load(){ // loads simple instructions
		cout << "Please type your equation in the formats shown below (Dont forget to add spaces)\n"
				"For Multipication x * y \n"
				"For Division x / y \n"
				"For Substraction x - y \n"
				"For Addision x + y \n"
				"For Mixed operations x * y / z - i + 40 \n"
				"For More Commands Type 'help' \n";
	}

	void  MathematicaLib::ClearRestart(){ // clears progress and restarts the Application
		 
		commandHistory.clear(); // used to display command history
		equationHistory.clear(); // use to allow for undo methods	 
	}

	void MathematicaLib::Help(){ // loads simple hel instructions
		 cout << "Reset/Clear -- Delets All Progress And History\n"
			     "Undo        -- Go Back One Step\n"
			     "History     -- Display Command History\n"
				 "Load        -- Loads instructions\n";
	}// end of Help

	double  MathematicaLib::Undo(){

		for (unsigned int k = 0 ; k < equationHistory.size(); k++){
			cout << equationHistory[k] << endl;	
		}
		//equationHistory.clear();
		return 0.0;
		
	}

	void  MathematicaLib::History(vector<string> CommandHistory){ // displays vector contents
		
		for (unsigned int k = 0; k < CommandHistory.size(); k++){  
			cout << CommandHistory[k] << endl;
		}	
	}// end of History

	double MathematicaLib::IsThisAnEquation(char const* equation){ // checks the equation for a valid format
		try{
		vector <string> SeperatedValues;
		//vector<string> TempGH; // no longer needed
		string tempo = "         ";
		int temp = 0; // an incrementer
		int SOG = 0; //start of group

		for (unsigned int j = 0; j < strlen(equation); j++) // this intialy filters out invalid inputs
		{
			
				if (isspace(equation[0])){ // check if the first charecter is a space (invalid input)
					cout << "The first charecter should be a number not a space" << endl;
					return 0.0;
				}
				else if (isdigit(equation[0]) == 0){ // if the first charecter is not a number
					cout << "The first charecter must be a number" << endl;
					return 0.0;
				}
				else if (isalpha(equation[j])){// if a letter is encounterd 
					cout << "Letters are not valid inputs within equations" << endl;
					return 0.0;
				}
				//else if ((isspace(equation[j + 1])) && (isdigit(equation[j + 2]) > 0)){// if there is no value after an operator 
				//	cout << "Each operator must be followed by a space and then a number" << endl;
				//	return 0.0;
				//}
				else if (isspace(equation[j]) && isspace(equation[j + 1])){ // checks if more than one space is included
					cout << "No more than two consecutive spaces should be included" << endl;
					return 0.0;
				}
				else if (isspace(equation[j])) {
					tempo.resize(j - SOG); // resizes tempo dynamicaly
					for (int n = SOG; n < j; n++){
						tempo[temp] = equation[n]; // populates tempo while reading the equation
						temp++; // an incrementer
						SOG = j + 1; //skip the space	
					}

					SeperatedValues.push_back(tempo); // loads each group of values into a vector
					tempo.clear(); // clears its contents therfore the next group can be stored
					temp = 0; // makes TEMP GH to be overwritten


					//unnecessary!!!
					//TempGH.push_back(tempo); //stores the extracted group within a vector
					//SeperatedValues.push_back(TempGH[0]); // then stores it within another
					//TempGH.clear(); // 
				}

			
		}
		
			return ExecutePEMDAS(SeperatedValues); // executes a method that solves the equation
		}
		catch (exception e){ cout << "Invalid input" << endl;  return 0; }
	}// end of IsThisAnEquation

	double MathematicaLib::ExecutePEMDAS(vector<string> SeperatedValues){ // executes an equation in PEMDAS order
		try{
			equationHistory.clear(); // to clear the history of previous equations
			double ExtractedNum0 = 0.0;
			double ExtractedNum1 = 0.0;
			double result = 0.0;

			for (unsigned int p = 0; p < SeperatedValues.size(); p++){ // this goes by PEMDAS, the order below is important

				if (strcmp("*", SeperatedValues[p].c_str()) == 0){ // should I Multiply

					ExtractedNum0 = stod(SeperatedValues[p - 1]); // load vector contents into a double 
					ExtractedNum1 = stod(SeperatedValues[p + 1]);
					SeperatedValues.erase(SeperatedValues.begin() + p - 1, SeperatedValues.begin() + p + 1); //removes this part as it has been solved (leaves one part )
					SeperatedValues.at(p - 1) = to_string(Multiply(ExtractedNum0, ExtractedNum1)); // returns the result to the vector 
					result = Multiply(ExtractedNum0, ExtractedNum1);
					//cout << result << endl;
					p = 0; //look for another
					equationHistory.insert(equationHistory.end(), result);

				}
			}
			for (unsigned int p = 0; p < SeperatedValues.size(); p++){ // this goes by PEMDAS, the order below is important
				if (strcmp("/", SeperatedValues[p].c_str()) == 0){// should I devide

					ExtractedNum0 = stod(SeperatedValues[p - 1]); // load vector contents into a double 
					ExtractedNum1 = stod(SeperatedValues[p + 1]);
					SeperatedValues.erase(SeperatedValues.begin() + p - 1, SeperatedValues.begin() + p + 1); //removes this part as it has been solved (leaves one part )
					SeperatedValues.at(p - 1) = to_string(Divide(ExtractedNum0, ExtractedNum1)); // returns the result to the vector 
					result = Divide(ExtractedNum0, ExtractedNum1);
					//cout << result << endl;
					p = 0; //look for another
					equationHistory.insert(equationHistory.end(), result);
				}
			}
			for (unsigned int p = 0; p < SeperatedValues.size(); p++){ // this goes by PEMDAS, the order below is important
				if (strcmp("+", SeperatedValues[p].c_str()) == 0){//should I add

					ExtractedNum0 = stod(SeperatedValues[p - 1]); // load vector contents into a double 
					ExtractedNum1 = stod(SeperatedValues[p + 1]);
					SeperatedValues.erase(SeperatedValues.begin() + p - 1, SeperatedValues.begin() + p + 1); //removes this part as it has been solved (leaves one part )
					SeperatedValues.at(p - 1) = to_string(Add(ExtractedNum0, ExtractedNum1)); // returns the result to the vector 
					result = Add(ExtractedNum0, ExtractedNum1);
					//cout << result << endl;
					p = 0; //look for another
					equationHistory.insert(equationHistory.end(), result);
				}
			}
			for (unsigned int p = 0; p < SeperatedValues.size(); p++){ // this goes by PEMDAS, the order below is important
				if (strcmp("-", SeperatedValues[p].c_str()) == 0){//should I subtract

					ExtractedNum0 = stod(SeperatedValues[p - 1]); // load vector contents into a double 
					ExtractedNum1 = stod(SeperatedValues[p + 1]);
					SeperatedValues.erase(SeperatedValues.begin() + p - 1, SeperatedValues.begin() + p + 1); //removes this part as it has been solved (leaves one part )
					SeperatedValues.at(p - 1) = to_string(Subtract(ExtractedNum0, ExtractedNum1)); // returns the result to the vector 
					result = Subtract(ExtractedNum0, ExtractedNum1);
					//cout <<  result << endl;
					p = 0; //look for another
					equationHistory.insert(equationHistory.end(), result);
				}
			}
			return result;
		}
		catch (exception e){ return 0; }
	}


	double MathematicaLib::Add(double a, double b){// Adds
		return a + b;
	}

	double MathematicaLib::Subtract(double a, double b){// subtracts
		return a - b;
	}

	double MathematicaLib::Multiply(double a, double b){// multiplies
		
			return a * b;
	}

	double MathematicaLib::Divide(double a, double b){ // divides
		return a / b;
	}

}
