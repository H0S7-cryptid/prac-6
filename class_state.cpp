#ifndef CLASS_STATE
#define CLASS_STATE

#include <iostream>

enum lvlOfPrep { BachelorDegree = 0, MastersDegree = 1 };
enum isGroupInit { INIT_DONE = 1, INCRCT_INIT = -1};

class Group
{
private:
	std::string group_name;
	std::string study_direction;
	short enrollment_year;
	lvlOfPrep lvl;
	// Функция инициализации элементов класса
	isGroupInit Init(std::string g, std::string s, short er, lvlOfPrep l);
public:
	// Конструктор со значениями по умолчанию
	Group(std::string g = "", std::string s = "", short er = 1950, lvlOfPrep l = BachelorDegree);
	// Конструктор копирования другого экземпляра класса
	Group(Group& original);
	// Функция вывода данных об экземпляре класса
	void Print();
	// Функция изменения имени группы
	void Rename(std::string new_name);
};

// Функция создания экземпляра класса в динамической памяти.
Group* CreateDynamicClass();

#endif
