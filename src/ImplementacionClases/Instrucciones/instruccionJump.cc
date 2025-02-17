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

#include "../../Clases/Instrucciones/instruccionJump.h"

instruccionJump::instruccionJump(std::string operacion, std::string operando) : instruccion(operacion, operando) {}

/**
 * Realiza un salto incondicional a la dirección especificada por el operando.
 * 
 * Parámetros:
 *   contador: El contador de operaciones (no se utiliza en esta función).
 *   memoriaDatos: Memoria de datos (no se utiliza en esta función).
 *   inputUnit, outputUnit: Unidades de entrada y salida (no usadas).
 * 
 * Retorna:
 *   La dirección a la que se realiza el salto.
 */
int instruccionJump::ejecutar(int contador, dataMemory* memoriaDatos, InputUnit* inputUnit, OutputUnit* outputUnit) {
  int direccion = stoi(getOperando());
  return direccion;
}