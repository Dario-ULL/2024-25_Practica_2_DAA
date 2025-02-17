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

#include "../../Clases/Instrucciones/instruccionRead.h"

instruccionRead::instruccionRead(std::string operacion, std::string operando) : instruccion(operacion, operando) {}

/**
 * Realiza una operación de lectura de un valor y lo guarda en la dirección especificada.
 * Si el operando no es válido, lanza una excepción.
 * 
 * Parámetros:
 *   contador: Contador de operaciones, se incrementa y se devuelve.
 *   memoriaDatos: Memoria de datos para obtener y actualizar los valores.
 *   inputUnit, outputUnit: Unidades de entrada y salida para leer y escribir.
 * 
 * Retorna:
 *   El contador incrementado.
 */
int instruccionRead::ejecutar(int contador, dataMemory* memoriaDatos, InputUnit* inputUnit, OutputUnit* outputUnit) {
  std::string operando = getOperando();
  try {
    if (operando[0] == '=') {
      throw std::invalid_argument("Error: No se puede leer en una dirección de memoria constante");
    } else if (operando[0] == '*') {
      int direccion = std::stoi(operando.substr(1));
      int segundaDireccion = memoriaDatos->getDato(direccion);
      if (segundaDireccion == 0) {
        throw std::invalid_argument("Error: Dirección no válida, no se puede leer en la dirección 0");
      }
      memoriaDatos->setDato(segundaDireccion, inputUnit->leer());
    } else if (esNumero(operando)) {
      int direccion = std::stoi(operando);
      if (direccion == 0) {
        throw std::invalid_argument("Error: Dirección no válida, no se puede leer en la dirección 0");
      }
      memoriaDatos->setDato(direccion, inputUnit->leer());
    } else {
      throw std::invalid_argument("Error: Operando no válido");
    }
  } catch (const std::exception& e) {
    throw std::invalid_argument(std::string("Error en READ: ") + e.what());
  }
  return ++contador;
}