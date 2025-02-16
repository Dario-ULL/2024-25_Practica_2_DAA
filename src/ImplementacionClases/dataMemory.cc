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

#include "../Clases/dataMemory.h"

dataMemory::dataMemory(int tamano) {
  memoriaDatos_.resize(tamano);
}

dataMemory::~dataMemory() {}

void dataMemory::cargarDatos(std::vector<int> datos) {
  for (size_t i = 0; i < datos.size(); i++) {
    memoriaDatos_.push_back(datos[i]);
  }
}

int dataMemory::getDato(int direccion) {
  return memoriaDatos_[direccion];
}

void dataMemory::setDato(int direccion, int dato) {
  memoriaDatos_[direccion] = dato;
}

int dataMemory::getAcumulador() {
  return memoriaDatos_[0];
}

void dataMemory::mostrarDatos() {
  for (size_t i = 0; i < memoriaDatos_.size(); i++) {
    std::cout << "Dato: " << memoriaDatos_[i] << std::endl;
  }
}
