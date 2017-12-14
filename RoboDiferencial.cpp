// RoboDiferencial.cpp

#include "RoboDiferencial.h"

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

#include "Encoder.h"

#include <cmath> // Para importar as funções trigonométricas cin e cos

RoboDiferencial::RoboDiferencial(
	string _robo,
	int _pulsosPorVolta,
	double _raioRoda,
	double _largura,
	string arquivoLeituraMotorEsquerdo,
	string arquivoLeituraMotorDireito,
	string arquivoEscrita
	) : Robo(_robo, _raioRoda, _largura, arquivoEscrita),
		motorDireito(_pulsosPorVolta, arquivoLeituraMotorDireito),
		motorEsquerdo(_pulsosPorVolta, arquivoLeituraMotorEsquerdo) {}

double RoboDiferencial::getVelocidadeAngular() {
	// Abreviações
	double vmd = motorDireito.getVelocidadeRoda();
	double vme = motorEsquerdo.getVelocidadeRoda();
	double& rr = raioRoda;  
	double& l = largura;

	return (velocidadeAngular = (rr * (vmd - vme))/(2 * l));
}

double RoboDiferencial::getVelocidadeLinearX() {
	// Abreviações
	double vmd = motorDireito.getVelocidadeRoda();
	double vme = motorEsquerdo.getVelocidadeRoda();
	double& rr = raioRoda;

	return (velocidadeLinearX = (rr * (vmd + vme))/2);
}

double RoboDiferencial::getVelocidadeLinearY() {
	return velocidadeLinearY; // Retorna 0.0
}

double* RoboDiferencial::getPosicao() {

	double vlx = getVelocidadeLinearX();
	// cout << "\tvlx<" << vlx << ">" << endl;
	double va = getVelocidadeAngular();
	// cout << "\tvla<" << va << ">" << endl;
	// TODO: deltaTempo vem de qual dos encoders????
	double dT = motorDireito.getDeltaTempo();
	// cout << "\tdT<" << dT << ">" << endl;
	double dS = vlx * dT;
	// cout << "\tdS<" << dS << ">" << endl;
	double dO = va * dT;
	// cout << "\td0<" << dO << ">" << endl;
	double& x = posicao[POS_X];
	double& y = posicao[POS_Y];
	double& o = posicao[POS_O];

	x = x + (dS * cos(o + dO));
	y = y + (dS * sin(o + dO));
	o = o + dO;

	return posicao;
}

void RoboDiferencial::atualizaLeitura() {
	motorEsquerdo.atualizaLeitura();
	motorDireito.atualizaLeitura();
}

void RoboDiferencial::moveRobo() {
	escrevePosicao << getRobo() << endl;
	Encoder& me = motorEsquerdo;
	Encoder& md = motorDireito;

	int i;

	for (i = 0; i < me.getNumeroLeituras() || i < me.getNumeroLeituras(); i++) {
		double *p = getPosicao();
		double x, y, o;
		x = *(p + POS_X);
		y = *(p + POS_Y);
		o = *(p + POS_O);

		atualizaLeitura();
		//escrevePosicao << x << " " << y << " " << o << endl; 
		escrevePosicao << "(" << x << "," << y << ")" <<  endl; 
		print();
	}
}
