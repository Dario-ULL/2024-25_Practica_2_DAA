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

#include "../../Clases/Instrucciones/instruccionLoad.h"

instruccionLoad::instruccionLoad(std::string operacion, std::string operando) : instruccion(operacion, operando) {}


int instruccionLoad::ejecutar(int contador, dataMemory* memoriaDatos, InputUnit* inputUnit, OutputUnit* outputUnit) {
  std::string operando = getOperando();
  int valor = 0;
  try {
    if (operando[0] == '=') {  
      valor = std::stoi(operando.substr(1));
    } else if (operando[0] == '*') {  
      int direccion = std::stoi(operando.substr(1));  
      int direccionReal = memoriaDatos->getDato(direccion);
      valor = memoriaDatos->getDato(direccionReal);
    } else if (esNumero(operando)) {  
      valor = memoriaDatos->getDato(std::stoi(operando));
    } else {
      throw std::invalid_argument("Error: Operando no válido");
    }
  } catch (const std::exception& e) {
    throw std::invalid_argument(std::string("Error en LOAD: ") + e.what());
  }
  memoriaDatos->setDato(0, valor);
  return ++contador;
}