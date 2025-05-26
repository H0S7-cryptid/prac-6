#include "class_state.h"

Group* CreateDynamicClass() {
	std::string name, direction;
	short year = 0;
	int buffer;
	lvlOfPrep lvl;
	std::cout << "Enter required data: " << std::endl;
	std::cout << "Order: Group name -> study direction -> enrollment year -> \n-> level of preparation (0 - Bachelor, 1 - Master): " << std::endl;
	std::cin >> name >> direction >> year >> buffer;
	lvl = (lvlOfPrep)buffer;

	Group* g = new Group{ name, direction, year, lvl };
	return g;
}

Group::Group(std::string g, std::string s, short er, lvlOfPrep l) {
	isGroupInit done = INCRCT_INIT;
	try {
		done = Init(g, s, er, l);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
		Init(g, s, 1950, BachelorDegree);
	}
	catch (std::invalid_argument& e) {
		std::cerr << e.what() << std::endl;
		Init(g, s, 1950, l);
	}
	catch (std::logic_error& e) {
		std::cerr << e.what() << std::endl;
		Init(g, s, er, BachelorDegree);
	}
	if (done == INIT_DONE) std::cout << "Initiation complete!" << std::endl;
}

Group::Group(Group& original) :
	group_name{ original.group_name }, study_direction{ original.study_direction },
	enrollment_year{ original.enrollment_year }, lvl{ original.lvl } {
}

isGroupInit Group::Init(std::string g, std::string s, short er, lvlOfPrep l) {
	group_name = g;
	study_direction = s;

	if (!(er >= 1950 && er < 2025) && !(l == BachelorDegree || l == MastersDegree)) {
		throw std::exception("Incorrect initialization data!\n");
	}
	else if (!(er >= 1950 && er < 2025)) {
		throw std::invalid_argument("Incorrect initialization data: wrong enrollment year!\n");
	}
	else if (!(l == BachelorDegree || l == MastersDegree)) {
		throw std::logic_error("Incorrect initialization data: wrong level of preparation!\n");
	}

	enrollment_year = er;
	lvl = l;
	return INIT_DONE;
}

void Group::Print() {
	std::string format_str = lvl == BachelorDegree ? "Bachelor`s Degree" : "Master`s Degree";
	std::cout << "Group`s name: " + group_name << std::endl;
	std::cout << "Group`s study direction: " + study_direction << std::endl;
	std::cout << "Group`s enrollment year: " << enrollment_year << std::endl;
	std::cout << "Group`s level of preparation: " + format_str << std::endl;
	std::cout << std::endl;
}

void Group::Rename(std::string new_name) {
	group_name = new_name;
}
