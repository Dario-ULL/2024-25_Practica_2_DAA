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

#include "../Clases/dataMemory.h"

dataMemory::dataMemory(int tamano) {
  memoriaDatos_.resize(tamano);
}

dataMemory::~dataMemory() {}

/**
 * Carga un conjunto de datos en la memoria de datos. Los datos se añaden al final de la memoria.
 * 
 * Parámetros:
 *   datos: Un vector de enteros con los datos a cargar en la memoria.
 */
void dataMemory::cargarDatos(std::vector<int> datos) {
  for (size_t i = 0; i < datos.size(); i++) {
    memoriaDatos_.push_back(datos[i]);
  }
}

/**
 * Obtiene el dato almacenado en una dirección específica de la memoria.
 * 
 * Parámetros:
 *   direccion: La dirección de la memoria desde la cual se obtiene el dato.
 * 
 * Retorna:
 *   El dato almacenado en la dirección especificada.
 */
int dataMemory::getDato(int direccion) {
  return memoriaDatos_[direccion];
}

/**
 * Establece un valor en una dirección específica de la memoria.
 * 
 * Parámetros:
 *   direccion: La dirección en la que se debe almacenar el dato.
 *   dato: El valor a almacenar en la memoria en la dirección especificada.
 */
void dataMemory::setDato(int direccion, int dato) {
  memoriaDatos_[direccion] = dato;
}

/**
 * Obtiene el valor almacenado en el acumulador (registro 0 de la memoria).
 * 
 * Retorna:
 *   El valor almacenado en el acumulador.
 */
int dataMemory::getAcumulador() {
  return memoriaDatos_[0];
}

/**
 * Muestra el contenido de la memoria de datos, imprimiendo cada registro y su valor.
 */
void dataMemory::mostrarDatos() {
  for (size_t i = 0; i < memoriaDatos_.size(); i++) {
    std::cout << "Registro " << i << ": " << memoriaDatos_[i] << std::endl;
  }
}
