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
  for (size_t i = 0; i < instrucciones.size(); i++) {
    std::stringstream ss(instrucciones[i]);
    std::string palabra, etiqueta, operacion, operando;

    ss >> palabra;
    if (palabra.back() == ':') {
      etiqueta = palabra;
      ss >> palabra;
    }
    
    operacion = palabra;
    ss >> operando;
    
    instruccion* instr = nullptr;
    if (operacion == "LOAD") {
      instr = new instruccionLoad(etiqueta, operacion, operando);
    } else {
      instr = new instruccionLoad(etiqueta, operacion, operando);
    }

    instr->setEtiqueta(etiqueta);
    instr->setOperacion(operacion);
    instr->setOperando(operando);

    instrucciones_.push_back(instr);
  }
}

instruccion* programMemory::getInstruccion(int direccion) {
  return instrucciones_[direccion];
}

void programMemory::mostrarInstrucciones() {
  for (size_t i = 0; i < instrucciones_.size(); i++) {
    std::cout << "Intruccion: " << instrucciones_[i]->getEtiqueta()  << "-" << instrucciones_[i]->getOperacion() << "-" << instrucciones_[i]->getOperando() << "-" << std::endl;
  }
}
