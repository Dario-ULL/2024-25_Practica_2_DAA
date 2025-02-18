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

#include "../../Clases/Instrucciones/instruccionMod.h"

instruccionMod::instruccionMod(std::string operacion, std::string operando) : instruccion(operacion, operando) {}

/**
 * Realiza una operación de división usando el operando especificado y actualiza
 * el valor en la posición 0 de la memoria de datos. Si el operando no es válido o
 * si se intenta dividir por cero, lanza una excepción.
 * 
 * Parámetros:
 *   contador: Contador de operaciones, se incrementa y se devuelve.
 *   memoriaDatos: Memoria de datos para obtener y actualizar los valores.
 *   inputUnit, outputUnit: Unidades de entrada y salida (no usadas).
 * 
 * Retorna:
 *   El contador incrementado.
 */
int instruccionMod::ejecutar(int contador, dataMemory* memoriaDatos, InputUnit* inputUnit, OutputUnit* outputUnit) {
  std::string operando = getOperando();
  int acumulador = memoriaDatos->getDato(0);
  int modulo = 0;
  try {
    if (operando[0] == '=') {
      modulo = std::stoi(operando.substr(1));
    } else if (operando[0] == '*') {
      int direccion = std::stoi(operando.substr(1));
      modulo = memoriaDatos->getDato(memoriaDatos->getDato(direccion));
    } else if (esNumero(operando)) {
      modulo = memoriaDatos->getDato(std::stoi(operando));
    } else {
      throw std::invalid_argument("Error: Operando no válido");
    }
    if (modulo == 0) {
      throw std::runtime_error("Error: Modulo por cero");
    }
    memoriaDatos->setDato(0, acumulador % modulo);
  } catch (const std::exception& e) {
    throw std::invalid_argument(std::string("Error en MOD: ") + e.what());
  }
  return ++contador;
}