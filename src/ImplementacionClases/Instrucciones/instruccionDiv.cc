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

#include "../../Clases/Instrucciones/instruccionDiv.h"

instruccionDiv::instruccionDiv(std::string operacion, std::string operando) : instruccion(operacion, operando) {}


int instruccionDiv::ejecutar(int contador, dataMemory* memoriaDatos, InputUnit* inputUnit, OutputUnit* outputUnit) {
  std::string operando = getOperando();
  int acumulador = memoriaDatos->getDato(0);
  int divisor = 0;
  try {
    if (operando[0] == '=') {
      divisor = std::stoi(operando.substr(1));
    } else if (operando[0] == '*') {
      int direccion = std::stoi(operando.substr(1));
      divisor = memoriaDatos->getDato(memoriaDatos->getDato(direccion));
    } else if (esNumero(operando)) {
      divisor = memoriaDatos->getDato(std::stoi(operando));
    } else {
      throw std::invalid_argument("Error: Operando no válido");
    }
    if (divisor == 0) {
      throw std::runtime_error("Error: División por cero");
    }
    memoriaDatos->setDato(0, acumulador / divisor);
  } catch (const std::exception& e) {
    throw std::invalid_argument(std::string("Error en DIV: ") + e.what());
  }
  return ++contador;
}