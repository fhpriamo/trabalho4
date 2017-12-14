// Encoder.cpp

#define _USE_MATH_DEFINES

#include "Encoder.h"

#include <string>
using std::string;

#include <fstream>
using std::ifstream;

// TODO: APAGAR
#include <iostream>
using std::cout;
using std::endl;

#include <cmath> // Para usar M_PI (número pi)


Encoder::Encoder(int _pulsosPorVolta, string arquivoLeitura) {
	pulsosPorVolta = _pulsosPorVolta;

	leituraEncoder.open(arquivoLeitura.c_str());
	
	velocidadeRoda = 0.0;

	leituraEncoder >> deltaTempo;
	leituraEncoder >> numeroLeituras;  
}

int Encoder::getPulsosPorVolta() {
	return pulsosPorVolta;
}

int Encoder::getNumeroLeituras() {
	return numeroLeituras;
}

double Encoder::getDeltaTempo() {
	return deltaTempo;
}

double Encoder::getVelocidadeRoda() {
	return velocidadeRoda;
}

void Encoder::atualizaLeitura() {
	double pulsos;

	leituraEncoder >> pulsos;
	velocidadeRoda = ((pulsos * M_PI_2)/pulsosPorVolta)/deltaTempo;
}
