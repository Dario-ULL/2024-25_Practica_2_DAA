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

#ifndef LECTORFICHERO_H
#define LECTORFICHERO_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
#include <algorithm>

class lectorFichero {
 private:
  std::string nombreFichero;
  std::ifstream fichero;
 public:
  lectorFichero(std::string nombreFichero);
  ~lectorFichero();
  std::string limpiarEspacios(const std::string& linea);
  std::vector<std::string> leerFichero();
  void cerrarFichero();
};

#endif