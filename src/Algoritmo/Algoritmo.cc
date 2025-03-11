// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 03 : Divide_Venceras
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 03/05/25
// Archivo Algoritmo.cc: Implementación de Algoritmo
//        En este fichero se implementa las funciones de la clase Algoritmo
//
// Historial de revisiones
//        03/05/25 - Creación (primera versión) del código

#include"Algoritmo.h"

/** Algoritmo::Algoritmo()
  * @brief Crea el objeto de la clase Algoritmo.
  * @param 
  * @return objeto de la clase Algoritmo
*/

Algoritmo::Algoritmo() {

}

/**
 * @brief Función que ordena la secuencia
 * @param sequence Secuencia a ordenar
 * @return vector<int> Secuencia ordenada
*/

vector<int> Algoritmo::solve(const vector<int>& sequence, int recursividad) {
  this->set_max_recursividad(recursividad);
  if (small(sequence)) {
    vector<int> result = solveSmall(sequence);
    return result;
  } else {
    vector<vector<int>> parts = divide(sequence);
    vector<vector<int>> subsecuencias(parts.size());
    for (long unsigned int i = 0; i < parts.size(); i++) {
      subsecuencias[i] = solve(parts[i], recursividad + 1);
    }
    vector<int> result = combine(subsecuencias);
    return result;
  }
}


/**
 * @brief Establece el máximo número de recursividad del algoritmo.
 * @param recursividad número de recursividad del algoritmo.
 * @return void
*/

void Algoritmo::set_max_recursividad(int recursividad) {
  if (recursividad > this->recursividad) {
    this->recursividad = recursividad;
  }
}


/**
 * @brief Devuelve el máximo número de recursividad del algoritmo.
 * @param 
 * @return int número de recursividad del algoritmo.
*/

int Algoritmo::get_max_recursividad() {
  return recursividad;
}


/**
 * @brief Resetea el número de recursividad del algoritmo.
 * @param 
 * @return void
*/

void Algoritmo::reset_recursividad() {
  this->recursividad = 0;
}