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

#include "../../Clases/Instrucciones/instruccionLoad.h"

instruccionLoad::instruccionLoad(std::string etiqueta, std::string operacion, std::string operando) : instruccion(etiqueta, operacion, operando) {}


void instruccionLoad::ejecutar() {
}