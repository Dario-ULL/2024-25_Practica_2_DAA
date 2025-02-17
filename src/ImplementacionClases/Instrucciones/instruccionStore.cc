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

#include "../../Clases/Instrucciones/instruccionStore.h"

instruccionStore::instruccionStore(std::string operacion, std::string operando) : instruccion(operacion, operando) {}


int instruccionStore::ejecutar(int contador, dataMemory* memoriaDatos, InputUnit* inputUnit, OutputUnit* outputUnit) {
  std::string operando = getOperando();
  int direccion = 0;
  try {
    if (operando[0] == '=') {  
      throw std::invalid_argument("Error: No se puede almacenar en un operando inmediato");
    } else if (operando[0] == '*') {  
      int direccionIntermedia = std::stoi(operando.substr(1));
      direccion = memoriaDatos->getDato(direccionIntermedia);
    } else if (esNumero(operando)) {  
      direccion = std::stoi(operando);
    } else {  
      throw std::invalid_argument("Error: Operando no válido");
    }
    memoriaDatos->setDato(direccion, memoriaDatos->getDato(0));
  } catch (const std::exception& e) {
    throw std::invalid_argument(std::string("Error en STORE: ") + e.what());
  }
  return ++contador;
}