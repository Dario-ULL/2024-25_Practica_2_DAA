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

#include "../Clases/lectorFichero.h"

lectorFichero::lectorFichero(std::string nombreFichero) {
  nombreFichero = nombreFichero;
  fichero.open(nombreFichero);
}

lectorFichero::~lectorFichero() {
  fichero.close();
}

std::string lectorFichero::limpiarEspacios(const std::string& linea) {
  std::string linea_limpia;
  bool espacioPrevio = false;
  for (char c : linea) {
    if (c == ' ' || c == '\t') {
      if (!espacioPrevio) {
        linea_limpia += ' ';
        espacioPrevio = true;
      }
    } else {
      linea_limpia += c;
      espacioPrevio = false;
    }
  }
  if (linea_limpia.front() == ' ') {
    linea_limpia.erase(0, 1);
  }
  return linea_limpia;
}


std::vector<std::string> lectorFichero::leerFichero() {
  std::string linea;
  std::vector<std::string> texto;
  while (getline(fichero, linea)) {
    linea = limpiarEspacios(linea);
    std::transform(linea.begin(), linea.end(), linea.begin(), ::toupper);
    if (linea[0] != '#' && !linea.empty() && linea.size() > 2) {
      texto.push_back(linea);
    }
  }
  return texto;
}

void lectorFichero::cerrarFichero() {
  fichero.close();
}