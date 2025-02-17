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

int aluUnit::ejecutarInstruccion(instruccion* instruccion) {
  instruccion->ejecutar(contador_);
  return contador_;
}