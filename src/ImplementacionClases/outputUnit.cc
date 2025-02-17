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

#include "../Clases/outputUnit.h"

OutputUnit::OutputUnit(const std::string& outputFileName) {
  outputFile_.open(outputFileName);
}

OutputUnit::~OutputUnit() {
  closeFile();
}

/**
 * Escribe un valor en el archivo de salida, añadiendo un espacio después de él.
 * Incrementa el contador del cabezal de escritura.
 * 
 * Parámetro:
 *   value: El valor a escribir en el archivo de salida.
 */
void OutputUnit::escribir(std::string value) {
  outputFile_ << value << " ";
  cabezal_++;
}

/**
 * Cierra el archivo de salida abierto por el objeto OutputUnit.
 */
void OutputUnit::closeFile() {
  outputFile_.close();
}