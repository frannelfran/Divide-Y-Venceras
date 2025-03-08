// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 03 : Divide_Venceras
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 03/05/25
// Archivo Hannoi.cc: Implementación de Hannoi
//        En este fichero se implementa las funciones de la clase Hannoi
//
// Historial de revisiones
//        03/05/25 - Creación (primera versión) del código

#include"Hannoi.h"

/** Hannoi::Hannoi()
  * @brief Crea el objeto de la clase Hannoi.
  * @param 
  * @return objeto de la clase Hannoi
  */
Hannoi::Hannoi() {

}
/**
 * @brief Comprueba si la secuencia es pequeña
 * @param sequence Secuencia a comprobar
 * @return bool Devuelve true si la secuencia es pequeña, false en caso contrario
 */
bool Hannoi::small(const vector<int>& sequence) {
  return sequence[0] == 1; // mira si n(número de discos) es igual a 1
}

/**
 * @brief Resuelve la secuencia pequeña
 * @param sequence Secuencia a resolver
 * @return vector<int> Secuencia resuelta
 */
vector<int> Hannoi::solveSmall(const vector<int>& sequence) {
  return {sequence[1], sequence[2]}; // al solo haber un disco, se mueve de la torre source a la torre target
}

/**
 * @brief Divide la secuencia en 2 partes
 * @param secuencia Secuencia a dividir
 * @return vector<vector<int>> Vector con las dos partes de la secuencia
 */
vector<vector<int>> Hannoi::divide(const vector<int>& sequence) {
  int n = sequence[0];
  int source = sequence[1];
  int target = sequence[2];
  int auxiliary = sequence[3];

  vector<vector<int>> parts; // divido la secuencia en 3 partes 
  // mover n-1 discos de la torre source a la torre auxiliary
  parts.push_back({n - 1, source, auxiliary, target});
  // mover el disco restante de la torre source a la torre target 
  parts.push_back({1, source, target, auxiliary});
  // mover los n-1 discos de la torre auxiliary a la torre target
  parts.push_back({n - 1, auxiliary, target, source});

  return parts;
}

/**
 * @brief Combina las dos partes de la secuencia
 * @param subsecuencias Vector con las dos partes de la secuencia
 * @return vector<int> Secuencia combinada
 */
vector<int> Hannoi::combine(const vector<vector<int>>& subsecuencias) {
  vector<int> result;
  for (const auto& sub : subsecuencias) { // combino las 3 partes de la secuencia
    result.insert(result.end(), sub.begin(), sub.end());
  }
  return result;
}