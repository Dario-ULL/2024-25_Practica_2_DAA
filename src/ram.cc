/**
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Diseño y Analisis de Complejidad
 * 
 * @author  Dario Dominguez Gonzalez
 * @date    18/02/2024
 * @brief   Implementacion de un simulador de memoria RAM,
 *          utilizando los principios SOLID y el patron de estrategia.
 *          
*/

#include <iostream>
#include <fstream>
#include <string>

#include "Clases/aluUnit.h"
#include "Clases/dataMemory.h"
#include "Clases/inputUnit.h"
#include "Clases/outputUnit.h"
#include "Clases/programMemory.h"
#include "Clases/lectorFichero.h"

int main(int argc, char* argv[]) {
	if (argc != 4) {
		std::cerr << "Error: Numero de argumentos incorrecto." << std::endl;
		std::cerr << "Uso: ./ram  <archivoEntrada> <archivoSalida>" << std::endl;
		return 1;
	}

	std::string input_file = "../Tests/";
	std::string output_chain = "../CintaSalida/";
	std::string input_chain = "../CintaEntrada/";
	input_file += argv[1];
	output_chain += argv[2];
	input_chain += argv[3];

	OutputUnit outputUnit(output_chain);
	InputUnit inputUnit(input_chain);
	lectorFichero lector(input_file);
	programMemory memoriaPrograma;
	try {
		memoriaPrograma.cargarInstrucciones(lector.leerFichero());
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
	dataMemory memoriaDatos(5);

	aluUnit alu;
	try {
		alu.ejecutarInstrucciones(&memoriaPrograma, &memoriaDatos, &inputUnit, &outputUnit);
		std::cout << "Programa ejecutado con exito." << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
  return 0;
}