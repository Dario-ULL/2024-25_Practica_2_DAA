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

int main(int argc, char* argv[]) {
	if (argc != 3) {
		std::cerr << "Error: Numero de argumentos incorrecto." << std::endl;
		std::cerr << "Uso: ./ram  <archivoEntrada> <archivoSalida>" << std::endl;
		return 1;
	}

	std::string input_file = "../CintaEntrada/";
	std::string output_file = "../CintaSalida/";
	input_file += argv[1];
	output_file += argv[2];
	std::ifstream input_stream(input_file);
	std::ofstream output_stream(output_file);

	if (!input_stream.is_open()) {
		std::cerr << "Error: No se pudo abrir el archivo de entrada." << std::endl;
		return 1;
	}
	if (!output_stream.is_open()) {
		std::cerr << "Error: No se pudo abrir el archivo de salida." << std::endl;
		return 1;
	}

	while (!input_stream.eof()) {
		std::string line;
		std::getline(input_stream, line);
		std::cout << line << std::endl;
		output_stream << line << std::endl;
	}

  return 0;
}