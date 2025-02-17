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

#ifndef INPUTUNIT_H
#define INPUTUNIT_H

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

class InputUnit {
 private:
  std::ifstream inputFile_;
  int cabezal_;
 public:
  InputUnit();
  InputUnit(const std::string& inputFileName);
  ~InputUnit();
  std::string read();
};

#endif
