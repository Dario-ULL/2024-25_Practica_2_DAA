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

#include "../Clases/instruccion.h"

instruccion::instruccion() {
  operacion_ = "";
  operando_ = "";
}

instruccion::instruccion(std::string operacion, std::string operando) {
  operacion_ = operacion;
  operando_ = operando;
}

std::string instruccion::getOperacion() {
  return operacion_;
}

std::string instruccion::getOperando() {
  return operando_;
}

void instruccion::setOperacion(std::string operacion) {
  operacion_ = operacion;
}

void instruccion::setOperando(std::string operando) {
  operando_ = operando;
}