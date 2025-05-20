#include "class_state.h"

int main()
{
	std::cout << "\t\tStack variables:" << std::endl;
	Group g1;
	Group g2{ "AVT-412", "FACE", 2024, BachelorDegree };

	g1.Print();
	g2.Print();

	Group g3{ g2 };
	g3.Print();

	g1.Rename("AVT-412");
	g1.Print();

	std::cout << "\t\tDynamic variables:" << std::endl;
	Group* g4 = CreateDynamicClass();
	Group* g5 = CreateDynamicClass();

	g4->Print();
	g5->Print();

	delete g4;
	delete g5;

	return 0;
}
