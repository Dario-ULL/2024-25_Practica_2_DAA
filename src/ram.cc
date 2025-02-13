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
	if (argc != 3) {
		std::cerr << "Error: Numero de argumentos incorrecto." << std::endl;
		std::cerr << "Uso: ./ram  <archivoEntrada> <archivoSalida>" << std::endl;
		return 1;
	}

	std::string input_file = "../CintaEntrada/";
	std::string output_file = "../CintaSalida/";
	input_file += argv[1];
	output_file += argv[2];

	lectorFichero lector(input_file);
	programMemory program_memory;
	program_memory.cargarInstrucciones(lector.leerFichero());
	//program_memory.mostrarInstrucciones();

  return 0;
}