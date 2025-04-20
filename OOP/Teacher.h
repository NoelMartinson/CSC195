#pragma once
#include "Human.h"
using classroom = unsigned short;


class Teacher : public Human {
public:
	Teacher() {}
	Teacher(std::string name, age_t age, std::string className, classroom classRoom):
		Human(name, age),
		className{ className },
		classRoom{ classRoom }
	{

	}

	void setClassName(std::string className){
		className = className;
	}
	std::string getClassName() { return className; }

	void setClassRoom(classroom classRoom) {
		if (classRoom < 300 && classRoom > 400) return; {
			classRoom = classRoom;
		}
		classRoom = classRoom;
	}
	classroom getClassRoom() { return classRoom; }

private:
	int32_t i;
	std::string className;
	classroom classRoom;
};