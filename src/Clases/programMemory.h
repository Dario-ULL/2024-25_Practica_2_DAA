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

#ifndef PROGRAMMEMORY_H
#define PROGRAMMEMORY_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include <functional> 

#include "instruccion.h"

class instruccion;

class programMemory {
 private:
  std::vector<instruccion*> instrucciones_;
 public:
  programMemory();
  ~programMemory();
  void cargarInstrucciones(std::vector<std::string> instrucciones);
  instruccion* getInstruccion(int direccion);
  void mostrarInstrucciones();
  int getTamano();
};

#endif