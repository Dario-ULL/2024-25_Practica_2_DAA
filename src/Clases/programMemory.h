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

struct Instruccion {
  std::string etiqueta;
  std::string operacion;
  std::string operando;
};

class programMemory {
 private:
  std::vector<Instruccion> instrucciones_;
 public:
  programMemory();
  ~programMemory();
  std::string detectarEtiqueta(const std::string& linea);
  void cargarInstrucciones(std::vector<std::string> instrucciones);
  Instruccion getInstruccion(int direccion);
  void mostrarInstrucciones();
};

#endif