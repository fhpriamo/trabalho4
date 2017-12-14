// Robo.cpp

#define _USE_MATH_DEFINES

#include "Robo.h"

#include <string>
using std::string;

#include <fstream>
using std::ofstream;

#include <iostream>
using std::cout;
using std::endl;

#include <cmath> // Para usar M_PI_2 (número pi/2)


Robo::Robo(
	string _robo,
	double _raioRoda,
	double _largura,
	string arquivoEscrita)
	: robo(_robo),
	  raioRoda(_raioRoda),
	  largura(_largura),
	  velocidadeLinearX(.0),
	  velocidadeLinearY(.0),
	  velocidadeAngular(.0)
{
	escrevePosicao.open(arquivoEscrita.c_str());

	posicao[POS_X] = .0;
	posicao[POS_Y] = .0;
	posicao[POS_O] = M_PI_2; // M_PI_2 é o mesmo que pi/2
}

std::string Robo::getRobo() {
	return robo;
}

double* Robo::getPosicao() {
	cout << "\t<Robo::getPosicao>" << endl;
	return posicao;
}

double Robo::getVelocidadeLinearX() {
	return velocidadeLinearX;
}

double Robo::getVelocidadeLinearY() {
	return velocidadeLinearY;
}

double Robo::getVelocidadeAngular() {
	return velocidadeAngular;
}

void Robo::print() {
	double *p = getPosicao();
	cout
		<< "[" << robo << "] "
	 	<< "Posição: X(" << p[POS_X]
		<< "), Y(" << p[POS_Y] 
		<< "), O(" << p[POS_O]
		<< ")" << endl;
}
