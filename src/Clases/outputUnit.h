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

#ifndef OUTPUTUNIT_H
#define OUTPUTUNIT_H

#include <fstream>
#include <iostream>
#include <string>

class OutputUnit {
 private:
  std::ofstream outputFile_;
  std::string fileName_;
  int cabezal_;
 public:
  OutputUnit(const std::string& outputFileName);
  ~OutputUnit();
  void escribir(std::string value);
  void closeFile();
};

#endif
