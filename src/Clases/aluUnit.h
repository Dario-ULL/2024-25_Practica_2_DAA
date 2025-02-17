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

#ifndef ALUUNIT_H
#define ALUUNIT_H

#include "instruccion.h"
#include "dataMemory.h"
#include "programMemory.h"
#include "inputUnit.h"
#include "outputUnit.h"

class instruccion;

class aluUnit {
 private:
  int contador_;
 public:
  aluUnit();
  ~aluUnit();

  int ejecutarInstrucciones(programMemory* memoriaPrograma, dataMemory* memoriaDatos, InputUnit* inputUnit, OutputUnit* outputUnit);
};

#endif