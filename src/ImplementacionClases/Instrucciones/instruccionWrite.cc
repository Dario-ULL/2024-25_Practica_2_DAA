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

#include "../../Clases/Instrucciones/instruccionWrite.h"

instruccionWrite::instruccionWrite(std::string operacion, std::string operando) : instruccion(operacion, operando) {}


int instruccionWrite::ejecutar(int contador, dataMemory* memoriaDatos, InputUnit* inputUnit, OutputUnit* outputUnit) {
  std::string operando = getOperando();
  try {
    if (operando[0] == '=') {
      outputUnit->escribir(operando.substr(1));
    } else if (operando[0] == '*') {
      int direccion = std::stoi(operando.substr(1));
      int segundaDireccion = memoriaDatos->getDato(direccion);
      outputUnit->escribir(std::to_string(memoriaDatos->getDato(segundaDireccion)));
    } else if (esNumero(operando)) {
      int direccion = std::stoi(operando);
      if (direccion == 0) {
        throw std::invalid_argument("Error: Dirección no válida, no se puede escribir en la dirección 0");
      }
      outputUnit->escribir(std::to_string(memoriaDatos->getDato(direccion)));
    } else {
      throw std::invalid_argument("Error: Operando no válido");
    }
  } catch (const std::exception& e) {
    throw std::invalid_argument(std::string("Error en WRITE: ") + e.what());
  }
  return ++contador;
}