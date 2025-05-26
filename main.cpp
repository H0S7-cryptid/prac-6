#include "class_state.h"

int main()
{
	std::cout << "\t\tStack variables:" << std::endl;
	Group g1;
	g1.Print();
	
	Group g2{ "AVT-412", "FACE", 1000, BachelorDegree };
	g2.Print();

	Group g3{ g2 };
	g3.Print();

	g1.Rename("AVT");
	g1.Print();

	std::cout << "\t\tDynamic variables:" << std::endl;
	Group* g4 = CreateDynamicClass();
	std::cout << std::endl;
	Group* g5 = CreateDynamicClass();

	g4->Print();
	g5->Print();

	delete g4;
	delete g5;

	return 0;
}
