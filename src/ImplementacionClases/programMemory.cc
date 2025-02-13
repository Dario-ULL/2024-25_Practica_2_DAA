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

#include "../Clases/programMemory.h"

programMemory::programMemory() {}

programMemory::~programMemory() {}

std::string programMemory::detectarEtiqueta(const std::string& linea) {
  std::istringstream stream(linea);
  std::string palabra;
  while (stream >> palabra) {
      if (!palabra.empty() && palabra.back() == ':') {
          return palabra;
      }
  }
  return "";
}

void programMemory::cargarInstrucciones(std::vector<std::string> instrucciones) {
  for (size_t i = 0; i < instrucciones.size(); i++) {
    Instruccion instruccion;
    std::stringstream ss(instrucciones[i]);
    std::string palabra;
    ss >> palabra;
    if (palabra.back() == ':') {
      instruccion.etiqueta = palabra;
      ss >> palabra;
    }
    instruccion.operacion = palabra;
    ss >> palabra;
    if (palabra == instruccion.operacion) {
      palabra = "";
    }
    instruccion.operando = palabra;
    std::cout << "Intruccion: " << instruccion.etiqueta  << "-" << instruccion.operacion << "-" << instruccion.operando << "-" << std::endl;
    instrucciones_.push_back(instruccion);
  }
}

Instruccion programMemory::getInstruccion(int direccion) {
  return instrucciones_[direccion];
}

void programMemory::mostrarInstrucciones() {
  for (size_t i = 0; i < instrucciones_.size(); i++) {
    std::cout << " '1" << instrucciones_[i].etiqueta << "' '2" << instrucciones_[i].operacion << "' '3" << instrucciones_[i].operando << "' " << std::endl;
  }
}
