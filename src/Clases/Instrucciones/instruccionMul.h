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

#ifndef INSTRUCCION_MUL_H
#define INSTRUCCION_ADD_H

#include "../instruccion.h"  // Incluimos primero la definición completa de Instruccion

class programMemory;
class dataMemory;

class instruccionMul : public instruccion {
 public:
  instruccionMul(std::string operacion, std::string operando);
  int ejecutar(int contador) override;
};

#endif

