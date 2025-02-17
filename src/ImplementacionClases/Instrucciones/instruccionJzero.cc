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

#include "../../Clases/Instrucciones/instruccionJzero.h"

instruccionJzero::instruccionJzero(std::string operacion, std::string operando) : instruccion(operacion, operando) {}


int instruccionJzero::ejecutar(int contador, dataMemory* memoriaDatos, InputUnit* inputUnit, OutputUnit* outputUnit) {
  int direccion = stoi(getOperando());
  int valor = memoriaDatos->getDato(0);
  if (valor == 0) {
    return direccion;
  }
  return ++contador;
}