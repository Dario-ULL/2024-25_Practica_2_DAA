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

/**
 * Realiza una operación de almacenamiento, guardando el valor de la posición 0 
 * de la memoria de datos en la dirección especificada por el operando. Si el operando
 * no es válido o si se intenta almacenar en un operando inmediato, lanza una excepción.
 * 
 * Parámetros:
 *   contador: Contador de operaciones, se incrementa y se devuelve.
 *   memoriaDatos: Memoria de datos para obtener y almacenar los valores.
 *   inputUnit, outputUnit: Unidades de entrada y salida (no usadas).
 * 
 * Retorna:
 *   El contador incrementado.
 */
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