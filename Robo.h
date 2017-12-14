// Robo.h

#ifndef TRABALHO4_ROBO_H_
#define TRABALHO4_ROBO_H_

#define POS_X 0 // Posição x
#define POS_Y 1 // Posição y
#define POS_O 2 // Orientação do robô (θ) em relação ao eixo x em radianos

#include <string>
#include <fstream>

class Robo {
protected:
	double posicao[3];				// Posição do robõ: 0 = eixo-x, 1 = eixo-y, 2 = orientação
	double raioRoda;				// raio da roda do robô em metros
	double largura;					// largura do robô em metros
	double velocidadeLinearX;		// velocidade do robô no eixo x em m/s (frame)
	double velocidadeLinearY;		// velocidade do robô no eixo y em m/s (frame)
	double velocidadeAngular;		// velocidade de rotação do robô em m/s
	std::string robo;				// nome do robô
	std::ofstream escrevePosicao;	// stream de saída para escrever a posição do robô
public:
	Robo(std::string, double, double, std::string);
	std::string getRobo();
	virtual double* getPosicao();
	double getVelocidadeLinearX();
	double getVelocidadeLinearY();
	double getVelocidadeAngular();
	void print();
	void atualizaLeitura();
	void moveRobo();
};

#endif
