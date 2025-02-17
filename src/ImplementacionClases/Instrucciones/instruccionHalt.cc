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

#include "../../Clases/Instrucciones/instruccionHalt.h"

instruccionHalt::instruccionHalt(std::string operacion, std::string operando) : instruccion(operacion, operando) {}

/**
 * Detiene la ejecución del programa. La función devuelve -1 para indicar
 * que la ejecución debe finalizar.
 * 
 * Parámetros:
 *   contador: El contador de operaciones (no se utiliza en esta función).
 *   memoriaDatos: Memoria de datos (no se utiliza en esta función).
 *   inputUnit, outputUnit: Unidades de entrada y salida (no usadas).
 * 
 * Retorna:
 *   -1, indicando que la ejecución debe detenerse.
 */
int instruccionHalt::ejecutar(int contador, dataMemory* memoriaDatos, InputUnit* inputUnit, OutputUnit* outputUnit) {
  return -1;
}