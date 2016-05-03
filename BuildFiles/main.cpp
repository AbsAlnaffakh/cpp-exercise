#include <iostream>
#include "MathematicaLib.h"
//#include <gtest/gtest.h> // the google test framweork for unit testing
#include <string>

using namespace std; // used to avoid using std::
using namespace MyMathLib; //used to avoid using MyMathLib::
// the use of these name spaces should not cause errors as long as there are no naming conflicts



int main(int argc, char* argv[])
{

	// usage examples
	/*MathematicaLib::DoTheMath("222 * 2 ");
	MathematicaLib::DoTheMath("46 / 2 ");
	MathematicaLib::DoTheMath("81 + 32 ");
	MathematicaLib::DoTheMath("56 - 89 ");
	MathematicaLib::DoTheMath("4 / -2 ");
	MathematicaLib::DoTheMath("2 * 2 - 8 * 4 * 20 + 1 ");
	MathematicaLib::DoTheMath("5 * 5 + -8 + 2 * 22 ");*/

	/*testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	return 0;*/


	string InputArgument;
	MathematicaLib::DoTheMath("Load"); // used to provide basic instructions

	while (true) // this is only here to use the library as an application
	{
		try{
			getline(cin, InputArgument); // dont use cin>> it eliminates spaces
			cout << MathematicaLib::DoTheMath(InputArgument.c_str()) << endl; // call the function from the library
		}
		catch (...){ // catches any other invalid input
			cout << "Invalid input, Please try again assuring you follow the guidlines" << endl;
		}
	}
	
	return 0;
}



//TEST(TestingDoTheMath, TestingCommands)
//{	
//	EXPECT_EQ(0, MathematicaLib::DoTheMath("ClearRestart"));
//	EXPECT_EQ(0, MathematicaLib::DoTheMath("Help"));
//	EXPECT_EQ(0, MathematicaLib::DoTheMath("Undo"));
//	EXPECT_EQ(0, MathematicaLib::DoTheMath("Load"));
//	EXPECT_EQ(0, MathematicaLib::DoTheMath("History"));
//}
//
//TEST(TestingDoTheMath, ValidInputs)
//{
//	EXPECT_EQ(444, MathematicaLib::DoTheMath("222 * 2 "));
//	EXPECT_EQ(23, MathematicaLib::DoTheMath("46 / 2 "));
//	EXPECT_EQ(113, MathematicaLib::DoTheMath("81 + 32 "));
//	EXPECT_EQ(-33, MathematicaLib::DoTheMath("56 - 89 "));
//	EXPECT_EQ(-2, MathematicaLib::DoTheMath("4 / -2 "));
//	EXPECT_EQ(-637, MathematicaLib::DoTheMath("2 * 2 - 8 * 4 * 20 + 1 "));
//	EXPECT_EQ(61, MathematicaLib::DoTheMath("5 * 5 + -8 + 2 * 22 "));
//}

//TEST(TestingDoTheMath, InvalidEquations)
//{
//	EXPECT_EQ(4, MathematicaLib::DoTheMath("222 * 2 "));
//	EXPECT_EQ(2, MathematicaLib::DoTheMath("46 / 2 "));
//	EXPECT_EQ(2, MathematicaLib::DoTheMath("81 + 32"));
//	EXPECT_EQ(2, MathematicaLib::DoTheMath("56 - 89 "));
//	EXPECT_EQ(2, MathematicaLib::DoTheMath("4 / -2 "));
//	EXPECT_EQ(2, MathematicaLib::DoTheMath("2 * 2 - 8 * 4 * 20 + 1"));
//	EXPECT_EQ(2, MathematicaLib::DoTheMath("4 / -2 "));
//}

//TEST(TestingDoTheMath, InvalidInputs)
//{
//	//EXPECT_EQ(0, MathematicaLib::DoTheMath("2 * "));
//	EXPECT_EQ(0, MathematicaLib::DoTheMath("2 *  "));
//	EXPECT_EQ(0, MathematicaLib::DoTheMath("2 * 0 "));
//	EXPECT_EQ(0, MathematicaLib::DoTheMath("f * 2 "));
//	EXPECT_EQ(0, MathematicaLib::DoTheMath(" / 2 "));
//	EXPECT_EQ(0, MathematicaLib::DoTheMath(" / "));
//	EXPECT_EQ(0, MathematicaLib::DoTheMath("0 / 2 "));
//	EXPECT_EQ(0, MathematicaLib::DoTheMath("dsfs"));
//	EXPECT_EQ(0, MathematicaLib::DoTheMath("000000000000000000000000000000000000000000000000000"
//		"000000000000000000000000000000000000000000000000000000000000000000000000000000000000"));
//}
//
//TEST(TestingDoTheMath, TestingExceptions)
//{
//	EXPECT_DEATH(MathematicaLib::DoTheMath("2 * "), "Exception was not handled or thrown");
//	EXPECT_ANY_THROW(MathematicaLib::DoTheMath("2 * "));
//}
