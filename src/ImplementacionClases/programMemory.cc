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

#include "../Clases/programMemory.h"
#include "../Clases/Instrucciones/instruccionLoad.h"
#include "../Clases/Instrucciones/instruccionStore.h"
#include "../Clases/Instrucciones/instruccionAdd.h"
#include "../Clases/Instrucciones/instruccionSub.h"
#include "../Clases/Instrucciones/instruccionMul.h"
#include "../Clases/Instrucciones/instruccionDiv.h"
#include "../Clases/Instrucciones/instruccionRead.h"
#include "../Clases/Instrucciones/instruccionWrite.h"
#include "../Clases/Instrucciones/instruccionJump.h"
#include "../Clases/Instrucciones/instruccionJzero.h"
#include "../Clases/Instrucciones/instruccionJgtz.h"
#include "../Clases/Instrucciones/instruccionHalt.h"
#include "../Clases/Instrucciones/instruccionMod.h"

programMemory::programMemory() {}

programMemory::~programMemory() {}

/**
 * Carga un conjunto de instrucciones en la memoria de programa. 
 * También resuelve las etiquetas de salto y las asocia con las posiciones correctas en la memoria.
 * 
 * Parámetro:
 *   instrucciones: Un vector de cadenas que representan las instrucciones a cargar en la memoria.
 * 
 * Lanza:
 *   std::runtime_error: Si se encuentra una instrucción desconocida.
 */
void programMemory::cargarInstrucciones(std::vector<std::string> instrucciones) {
  std::unordered_map<std::string, int> etiquetas; 
  std::unordered_map<std::string, std::function<instruccion*(std::string, std::string)>> tablaInstrucciones = {
    {"LOAD",  [](std::string op, std::string arg) { return new instruccionLoad(op, arg); }},
    {"STORE", [](std::string op, std::string arg) { return new instruccionStore(op, arg); }},
    {"ADD",   [](std::string op, std::string arg) { return new instruccionAdd(op, arg); }},
    {"SUB",   [](std::string op, std::string arg) { return new instruccionSub(op, arg); }},
    {"MUL",   [](std::string op, std::string arg) { return new instruccionMul(op, arg); }},
    {"DIV",   [](std::string op, std::string arg) { return new instruccionDiv(op, arg); }},
    {"READ",  [](std::string op, std::string arg) { return new instruccionRead(op, arg); }},
    {"WRITE", [](std::string op, std::string arg) { return new instruccionWrite(op, arg); }},
    {"JUMP",  [](std::string op, std::string arg) { return new instruccionJump(op, arg); }},
    {"JZERO", [](std::string op, std::string arg) { return new instruccionJzero(op, arg); }},
    {"JGTZ",  [](std::string op, std::string arg) { return new instruccionJgtz(op, arg); }},
    {"HALT",  [](std::string op, std::string arg) { return new instruccionHalt(op, arg); }},
    {"MOD",   [](std::string op, std::string arg) { return new instruccionMod(op, arg); }}
  };
  for (size_t i = 0; i < instrucciones.size(); i++) {
    std::stringstream ss(instrucciones[i]);
    std::string palabra, operacion, operando;
    ss >> palabra;
    if (palabra.back() == ':') { 
      palabra.pop_back();
      etiquetas[palabra] = i;
      ss >> palabra;
    }
    operacion = palabra;
    ss >> operando;
    instruccion* nuevaInstruccion = nullptr;
    if (tablaInstrucciones.find(operacion) != tablaInstrucciones.end()) {
      nuevaInstruccion = tablaInstrucciones[operacion](operacion, operando);
    } else {
      throw std::runtime_error("Error: Instrucción desconocida: " + operacion);
    }
    nuevaInstruccion->setOperacion(operacion);
    nuevaInstruccion->setOperando(operando);
    instrucciones_.push_back(nuevaInstruccion);
  }
  for (size_t i = 0; i < instrucciones_.size(); i++) {
    if (instrucciones_[i]->getOperacion() == "JUMP" || 
        instrucciones_[i]->getOperacion() == "JZERO" || 
        instrucciones_[i]->getOperacion() == "JGTZ") {
      instrucciones_[i]->setOperando(std::to_string(etiquetas[instrucciones_[i]->getOperando()]));
    }
  }
}

/**
 * Obtiene una instrucción de la memoria de programa en una dirección específica.
 * 
 * Parámetro:
 *   direccion: La dirección de la instrucción a recuperar.
 * 
 * Retorna:
 *   La instrucción en la dirección dada.
 */
instruccion* programMemory::getInstruccion(int direccion) {
  return instrucciones_[direccion];
}

/**
 * Muestra todas las instrucciones cargadas en la memoria de programa.
 */
void programMemory::mostrarInstrucciones() {
  for (size_t i = 0; i < instrucciones_.size(); i++) {
    std::cout << "Instrucción: " << instrucciones_[i]->getOperacion() << " - " << instrucciones_[i]->getOperando() << std::endl;
  }
}

/**
 * Obtiene el tamaño de la memoria de programa (el número de instrucciones).
 * 
 * Retorna:
 *   El tamaño de la memoria de programa.
 */
int programMemory::getTamano() {
  return instrucciones_.size();
}
