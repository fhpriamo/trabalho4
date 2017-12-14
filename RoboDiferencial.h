// Enconder.h

#ifndef TRABALHO4_ROBO_DIFERENCIAL_H_
#define TRABALHO4_ROBO_DIFERENCIAL_H_

#include "Robo.h"
#include "Encoder.h"

#include <string>

class RoboDiferencial : public Robo {
protected:
	Encoder motorEsquerdo;
	Encoder motorDireito;
public:
	RoboDiferencial(
		std::string,
		int,
		double,
		double,
		std::string,
		std::string,
		std::string
		);
	double getVelocidadeAngular();
	double getVelocidadeLinearX();
	double getVelocidadeLinearY();
	double* getPosicao();
	void atualizaLeitura();
	void moveRobo();
};

#endif
