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
#include "../Clases/Instrucciones/instruccionLoad.h"

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
  std::unordered_map<std::string, int> etiquetas;
  for (size_t i = 0; i < instrucciones.size(); i++) {
    std::stringstream ss(instrucciones[i]);
    std::string palabra, operacion, operando;
    ss >> palabra;
    if (palabra.back() == ':') {
      palabra.pop_back();
      etiquetas[palabra] = i;
      ss >> palabra;
    }
    operacion = palabra;
    ss >> operando;
    instruccion* instruccion = nullptr;
    if (operacion == "LOAD") {
      instruccion = new instruccionLoad(operacion, operando);
    } else {
      instruccion = new instruccionLoad(operacion, operando);
    }
    instruccion->setOperacion(operacion);
    instruccion->setOperando(operando);
    instrucciones_.push_back(instruccion);
  }
  for (size_t i = 0; i < instrucciones_.size(); i++) {
    if (instrucciones_[i]->getOperacion() == "JUMP" || instrucciones_[i]->getOperacion() == "JZERO" || instrucciones_[i]->getOperacion() == "JGTZ") {
      instrucciones_[i]->setOperando(std::to_string(etiquetas[instrucciones_[i]->getOperando()]));
    }
  }
}

instruccion* programMemory::getInstruccion(int direccion) {
  return instrucciones_[direccion];
}

void programMemory::mostrarInstrucciones() {
  for (size_t i = 0; i < instrucciones_.size(); i++) {
    std::cout << "Intruccion: " << instrucciones_[i]->getOperacion() << "-" << instrucciones_[i]->getOperando() << "-" << std::endl;
  }
}
