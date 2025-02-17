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

programMemory::programMemory() {}

programMemory::~programMemory() {}

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
    {"HALT",  [](std::string op, std::string arg) { return new instruccionHalt(op, arg); }}
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
    if (instrucciones_[i]->getOperacion() == "JUMP" || instrucciones_[i]->getOperacion() == "JZERO" || instrucciones_[i]->getOperacion() == "JGTZ") {
      instrucciones_[i]->setOperando(std::to_string(etiquetas[instrucciones_[i]->getOperando()]));
    }
  }
}

instruccion* programMemory::getInstruccion(int direccion) {
  return instrucciones_[direccion];
}

void programMemory::mostrarInstrucciones() {
  for (size_t i = 0; i < instrucciones_.size(); i++) {
    std::cout << "Intruccion: " << instrucciones_[i]->getOperacion() << "-" << instrucciones_[i]->getOperando() << "-" << std::endl;
  }
}

int programMemory::getTamano() {
  return instrucciones_.size();
}