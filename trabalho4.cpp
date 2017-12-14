// trabalho4.cpp

#include <iostream>
using std::cout;

#include <string>
using std::string;

#include "RoboDiferencial.h"

int main() {

	string ame("RDE.txt");
	string amd("RDD.txt");
	string ae("log.txt");

	RoboDiferencial robo(
		"robodiferencial",
		48,
		6, // raio
		10, // largura
		ame,
		amd,
		ae);

	robo.moveRobo();

	return 0;
}
