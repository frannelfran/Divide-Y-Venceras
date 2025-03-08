// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 03 : Divide_Venceras
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 03/05/25
// Archivo BusquedaBinaria.cc: Implementación de BusquedaBinaria
//        En este fichero se implementa las funciones de la clase BusquedaBinaria
//
// Historial de revisiones
//        03/05/25 - Creación (primera versión) del código

#include"BusquedaBinaria.h"

/** BusquedaBinaria::BusquedaBinaria()
  * @brief Crea el objeto de la clase BusquedaBinaria.
  * @param 
  * @return objeto de la clase BusquedaBinaria
  */
BusquedaBinaria::BusquedaBinaria(int objetivo) {
  this->objetivo_ = objetivo;
}

/**
 * @brief Función que comprueba si la secuencia es pequeña
 * @param sequence Secuencia a comprobar
 * @return bool Devuelve true si la secuencia es pequeña, false en caso contrario
*/

bool BusquedaBinaria::small(const vector<int>& sequence) {
  if (sequence.size() <= 1) {
    return true;
  }
  return false;
}

/**
 * @brief Función que resuelve la secuencia pequeña
 * @param sequence Secuencia a resolver
 * @return vector<int> Secuencia resuelta
*/

vector<int> BusquedaBinaria::solveSmall(const vector<int>& sequence) {
  vector<int> result;
  if (sequence[0] == this->objetivo_) {
    result.push_back(this->num_quitados_);
  } else {
    result.push_back(-1);
  }
  return result;
}

/**
 * @brief Función que divide la secuencia en 2 partes
 * @param secuencia Secuencia a dividir
 * @return vector<vector<int>> Vector con las dos partes de la secuencia
*/

vector<vector<int>> BusquedaBinaria::divide(const vector<int>& secuencia) {
  vector<vector<int>> parts;
  vector<int> subsequence = {};
   int medio = secuencia.size() / 2;
   if ( secuencia[medio] > this->objetivo_) {
     // hago un push_back de la primera mitad
     for (int i = 0; i < medio; i++) {
       subsequence.push_back(secuencia[i]);
     }
   } else {
     this->num_quitados_ += medio;
     for (long unsigned int i = medio; i < secuencia.size(); i++) {
       subsequence.push_back(secuencia[i]);
     }
   }
  parts.push_back(subsequence);
  return parts;
}

/**
 * @brief Función que combina las dos partes de la secuencia
 * @param subsequence1 Primera parte de la secuencia
 * @param subsequence2 Segunda parte de la secuencia
 * @return vector<int> Secuencia combinada
*/
vector<int> BusquedaBinaria::combine(const vector<vector<int>>& subsequences) {
  return subsequences[0];

}