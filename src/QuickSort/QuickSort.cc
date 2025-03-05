// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 03 : Divide_Venceras
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 03/05/25
// Archivo QuickSort.cc: Implementación de QuickSort
//        En este fichero se implementa las funciones de la clase QuickSort
//
// Historial de revisiones
//        03/05/25 - Creación (primera versión) del código

#include"QuickSort.h"

/** QuickSort::QuickSort()
  * @brief Crea el objeto de la clase QuickSort.
  * @param 
  * @return objeto de la clase QuickSort
  */
QuickSort::QuickSort() {

}

/** QuickSort::small(const vector<int>& sequence)
  * @brief Comprueba si la secuencia es pequeña
  * @param sequence: secuencia a comprobar
  * @return booleano que indica si la secuencia es pequeña
  */
 bool QuickSort::small(const vector<int>& sequence) {
  return sequence.size() <= 1;
}

/** QuickSort::solveSmall(const vector<int>& sequence)
  * @brief Resuelve la secuencia pequeña
  * @param sequence: secuencia a resolver
  * @return secuencia resuelta
  */
vector<int> QuickSort::solveSmall(const vector<int>& sequence) {
  return sequence;
}

/** QuickSort::divide(const vector<int>& secuencia)
  * @brief Divide la secuencia en dos partes
  * @param secuencia: secuencia a dividir
  * @return vector con las dos partes de la secuencia
  */
vector<vector<int>> QuickSort::divide(const vector<int>& secuencia) {
  vector<vector<int>> result;
  vector<int> subsequence1;
  vector<int> subsequence2;
  int size = secuencia.size();
  int pivot = secuencia[size / 2];
  for (int i = 0; i < size; i++) {
    if (i != size / 2) {
      if (secuencia[i] < pivot) {
        subsequence1.push_back(secuencia[i]);
      } else {
        subsequence2.push_back(secuencia[i]);
      }
    } 
  }
  result.push_back(subsequence1);
  result.push_back(subsequence2);
  this->pivotes_.push_front(pivot);
  return result;
}

/** QuickSort::combine(const vector<int>& subsequence1, const vector<int>& subsequence2)
  * @brief Combina las dos partes de la secuencia
  * @param subsequence1: primera parte de la secuencia
  * @param subsequence2: segunda parte de la secuencia
  * @return secuencia combinada
  */
vector<int> QuickSort::combine(const vector<int>& subsequence1, const vector<int>& subsequence2) {
  vector<int> result;
  int size1 = subsequence1.size();
  int size2 = subsequence2.size();
  int i = 0;
  int j = 0;
  while (i < size1) {
    result.push_back(subsequence1[i]);
    i++;
  }
  result.push_back(this->pivotes_.front()); // Añado el pivote
  // quito el pivote de la lista de pivotes
  this->pivotes_.pop_front();
  while (j < size2) {
    result.push_back(subsequence2[j]);
    j++;
  }
  return result;
}

/** QuickSort::get_recurrencia()
  * @brief Devuelve la recurrencia del algoritmo
  * @return string con la recurrencia del algoritmo
  */
string QuickSort::get_recurrencia() {
  return "T(n) = 2T(n/2) + n";
}