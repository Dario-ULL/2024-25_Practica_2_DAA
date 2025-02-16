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

#include "../Clases/inputUnit.h"

InputUnit::InputUnit(const std::string& inputFileName) {
  std::string fileName = inputFileName;
  inputFile_.open(fileName);
  if (!inputFile_.is_open()) {
    std::cerr << "Error: No se pudo abrir el archivo de entrada." << std::endl;
    exit(1);
  }
  cabezal_ = 0;
}

InputUnit::~InputUnit() {
  inputFile_.close();
}

std::string InputUnit::read() {
  std::string line;
  std::getline(inputFile_, line); 
  std::stringstream ss(line);
  std::string num;
  size_t contador = 0;
  while (contador <= cabezal_ && ss >> num) {
      contador++;
  }

  if (contador <= cabezal_) {
      std::cerr << "Error: Fin de la línea alcanzado.\n";
      return "";
  }

  cabezal_++;
  inputFile_.clear();
  inputFile_.seekg(0, std::ios::beg);

  return num;
}