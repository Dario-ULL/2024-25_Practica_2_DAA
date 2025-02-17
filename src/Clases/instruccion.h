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

#ifndef INSTRUCCION_H
#define INSTRUCCION_H

#include <iostream>
#include <string>

#include "programMemory.h"
#include "dataMemory.h"

class programMemory;
class dataMemory;

class instruccion {
 private:
  std::string operacion_;
  std::string operando_;
 public:
  instruccion();
  instruccion(std::string operacion, std::string operando);
  virtual ~instruccion() = default;
  std::string getOperacion();
  std::string getOperando();
  void setOperacion(std::string operacion);
  void setOperando(std::string operando);
  virtual int ejecutar(int contador) = 0;
};

#endif