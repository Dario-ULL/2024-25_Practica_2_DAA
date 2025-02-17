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

#include "../../Clases/Instrucciones/instruccionAdd.h"

instruccionAdd::instruccionAdd(std::string operacion, std::string operando) : instruccion(operacion, operando) {}


int instruccionAdd::ejecutar(int contador, dataMemory* memoriaDatos, InputUnit* inputUnit, OutputUnit* outputUnit) {
  std::string operando = getOperando();
  int acumulador = memoriaDatos->getDato(0);
  int valorASumar = 0;
  try {
    if (operando[0] == '=') {
      valorASumar = std::stoi(operando.substr(1));
    } else if (operando[0] == '*') {
      int direccion = std::stoi(operando.substr(1));
      valorASumar = memoriaDatos->getDato(memoriaDatos->getDato(direccion));
    } else if (esNumero(operando)) {
      valorASumar = memoriaDatos->getDato(std::stoi(operando));
    } else {
      throw std::invalid_argument("Error: Operando no válido");
    }
    memoriaDatos->setDato(0, acumulador + valorASumar);
  } catch (const std::exception& e) {
    throw std::invalid_argument(std::string("Error en ADD: ") + e.what());
  }
  return ++contador;
}