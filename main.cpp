#include <iostream>
#include <sstream>
#include <string>
#include<fstream>
#include "character.h"

void Punch(Character* FighterOne, Character* FighterTwo) {
	FighterTwo->Slash(FighterOne->getDmg());
}

void Fight(Character* FighterOne, Character* FighterTwo) {
	while ((FighterOne->getHp() != 0) && (FighterTwo->getHp() != 0)) {
		Punch(FighterOne, FighterTwo);
		if (FighterTwo->getHp() == 0) {
			break;
		}
		Punch(FighterTwo, FighterOne);
		if (FighterOne->getHp() == 0) {
			break;
		}
	}
}

void EndGame(Character* FighterOne, Character* FighterTwo) {
	if (FighterOne->getHp() == 0) {
		std::cout << FighterTwo->getName() << " wins. Remaining HP: " << FighterTwo->getHp() << std::endl;
	}
	if (FighterTwo->getHp() == 0) {
		std::cout << FighterOne->getName() << " wins. Remaining HP: " << FighterOne->getHp() << std::endl;
	}
}



int main(int argc, char** argv) {
	Character* FighterOne = new Character(Character::parseUnit("Units/character1.json"));
	Character* FighterTwo = new Character(Character::parseUnit("Units/character2.json"));
	if (FighterOne->getName()=="" || FighterTwo->getName() == "") {
		std::cout << "File error!!!" << std::endl;
		return 1;
	}
	else {
		Fight(FighterOne, FighterTwo);
		EndGame(FighterOne, FighterTwo);
	}
	delete FighterOne;
	delete FighterTwo;
	return 0;
}
