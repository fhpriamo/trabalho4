// Enconder.h

#ifndef TRABALHO4_ENCODER_H_
#define TRABALHO4_ENCODER_H_

#include <fstream>
#include <string>

class Encoder {
protected:
	int pulsosPorVolta;				// resolução do encoder
	int numeroLeituras;				// número de leituras do sensor
	double deltaTempo;				// tempo de amostragem do encoder
	double velocidadeRoda;			// velocidade de rotação da roda em rad/s
	std::ifstream leituraEncoder;	// objeto de leitura do arquivo.
public:
	Encoder(int, std::string);		// Construtor
	int getPulsosPorVolta();
	int getNumeroLeituras();
	double getDeltaTempo();
	double getVelocidadeRoda();
	void atualizaLeitura();
};


#endif