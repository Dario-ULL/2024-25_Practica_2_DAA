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

#include "../Clases/aluUnit.h"

aluUnit::aluUnit() {
  contador_ = 0;
}

aluUnit::~aluUnit() {}

int aluUnit::ejecutarInstrucciones(programMemory* memoriaPrograma, dataMemory* memoriaDatos, InputUnit* inputUnit, OutputUnit* outputUnit) {
  while (contador_ != -1) {
    if (contador_ >= memoriaPrograma->getTamano()) {
      return -1;
    }
    instruccion* instruccion = memoriaPrograma->getInstruccion(contador_);
    try {
      contador_ = instruccion->ejecutar(contador_, memoriaDatos, inputUnit, outputUnit);
    } catch (std::invalid_argument& e) {
      std::cerr << e.what() << std::endl;
      return -1;
    }
  }
  return contador_;
}