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

#ifndef DATAMEMORY_H
#define DATAMEMORY_H

#include <iostream>
#include <vector>

class dataMemory {
 private:
  std::vector<int> memoriaDatos_;
 public:
  dataMemory(int tamano);
  ~dataMemory();
  void cargarDatos(std::vector<int> datos);
  int getDato(int direccion);
  void setDato(int direccion, int dato);
  int getAcumulador();
  void mostrarDatos();
};

#endif