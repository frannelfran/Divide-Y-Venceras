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
 * @param size Tamaño de la secuencia
 * @return vector<int> Secuencia ordenada
*/

vector<int> Algoritmo::solve(const vector<int>& sequence, int size) {
  if (small(sequence)) {
    return solveSmall(sequence);
  } else {
    vector<vector<int>> parts = divide(sequence);
    vector<int> subsequence1 = solve(parts[0], size / 2);
    vector<int> subsequence2= solve(parts[1], size / 2);
    vector<int> result = combine(subsequence1, subsequence2);
    return result;
  }
}

/**
 * @brief Función que ordena la secuencia
 * @param sequence Secuencia a ordenar
 * @return vector<int> Secuencia ordenada
*/

vector<int> Algoritmo::solveNoBin(const vector<int>& sequence) {
  if (small(sequence)) {
    return solveSmall(sequence);
  } else {
    vector<vector<int>> parts = divide(sequence);
    vector<vector<int>> subsecuencias;
    for (int i = 0; i < parts.size(); i++) {
      subsecuencias[i] = solveNoBin(parts[i]);
    }
    vector<int> result = combineNotBin(subsecuencias);
    return result;
  }
}
