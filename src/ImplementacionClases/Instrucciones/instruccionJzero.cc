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

#include "../../Clases/Instrucciones/instruccionJzero.h"

instruccionJzero::instruccionJzero(std::string operacion, std::string operando) : instruccion(operacion, operando) {}

/**
 * Realiza un salto condicional si el valor en la posición 0 de la memoria de datos
 * es igual a cero. Si es así, la ejecución salta a la dirección especificada por
 * el operando. Si no, se incrementa el contador y se continúa con la ejecución.
 * 
 * Parámetros:
 *   contador: Contador de operaciones, se incrementa si no se realiza el salto.
 *   memoriaDatos: Memoria de datos para obtener el valor a evaluar en la posición 0.
 *   inputUnit, outputUnit: Unidades de entrada y salida (no usadas).
 * 
 * Retorna:
 *   La dirección a la que se salta si el valor es cero, o el contador incrementado.
 */
int instruccionJzero::ejecutar(int contador, dataMemory* memoriaDatos, InputUnit* inputUnit, OutputUnit* outputUnit) {
  int direccion = stoi(getOperando());
  int valor = memoriaDatos->getDato(0);
  if (valor == 0) {
    return direccion;
  }
  return ++contador;
}