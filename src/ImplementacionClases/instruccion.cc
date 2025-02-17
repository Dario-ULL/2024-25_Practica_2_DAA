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

#include "../Clases/instruccion.h"

instruccion::instruccion() {
  operacion_ = "";
  operando_ = "";
}

instruccion::instruccion(std::string operacion, std::string operando) {
  operacion_ = operacion;
  operando_ = operando;
}

/**
 * Obtiene la operación asociada a la instrucción.
 * 
 * Retorna:
 *   Un string que representa la operación de la instrucción.
 */
std::string instruccion::getOperacion() {
  return operacion_;
}

/**
 * Obtiene el operando asociado a la instrucción.
 * 
 * Retorna:
 *   Un string que representa el operando de la instrucción.
 */
std::string instruccion::getOperando() {
  return operando_;
}

/**
 * Establece la operación de la instrucción.
 * 
 * Parámetro:
 *   operacion: La operación que se asignará a la instrucción.
 */
void instruccion::setOperacion(std::string operacion) {
  operacion_ = operacion;
}

/**
 * Establece el operando de la instrucción.
 * 
 * Parámetro:
 *   operando: El operando que se asignará a la instrucción.
 */
void instruccion::setOperando(std::string operando) {
  operando_ = operando;
}

/**
 * Determina si una cadena de caracteres es un número válido.
 * 
 * Parámetro:
 *   numero: La cadena de caracteres a evaluar.
 * 
 * Retorna:
 *   true si la cadena representa un número válido (puede ser negativo o positivo),
 *   de lo contrario retorna false.
 */
bool instruccion::esNumero(const std::string& numero) {
  if (numero.empty()) return false;
  for (size_t i = 0; i < numero.length(); ++i) {
    if (i == 0 && (numero[i] == '-' || numero[i] == '+')) {
      continue;
    }
    if (!isdigit(numero[i])) {
      return false;
    }
  }
  return true;
}
