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

#include "../Clases/aluUnit.h"

aluUnit::aluUnit() {
  contador_ = 0;
}

aluUnit::~aluUnit() {}

/**
 * Ejecuta las instrucciones del programa almacenadas en la memoria de programa.
 * 
 * Parámetros:
 *   memoriaPrograma: Memoria de programa con las instrucciones a ejecutar.
 *   memoriaDatos: Memoria de datos para almacenar y recuperar los valores.
 *   inputUnit, outputUnit: Unidades de entrada y salida para leer y escribir.
 * 
 * Retorna:
 *   La dirección de la siguiente instrucción a ejecutar, o -1 si se ha producido un error.
 */
int aluUnit::ejecutarInstrucciones(programMemory* memoriaPrograma, dataMemory* memoriaDatos, InputUnit* inputUnit, OutputUnit* outputUnit) {
  while (contador_ != -1) {
    if (contador_ >= memoriaPrograma->getTamano()) {
      throw std::invalid_argument("Programa finalizado. Se llego a la ultima instruccion sin encontrar un HALT.");
    }
    instruccion* instruccion = memoriaPrograma->getInstruccion(contador_);
    try {
      contador_ = instruccion->ejecutar(contador_, memoriaDatos, inputUnit, outputUnit);
    } catch (std::invalid_argument& e) {
      throw std::invalid_argument(e.what() + std::string(" en la linea ") + std::to_string(contador_));
    }
  }
  return contador_;
}