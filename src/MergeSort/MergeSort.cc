// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 03 : Divide_Venceras
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 03/05/25
// Archivo MergeSort.cc: Implementación de MergeSort
//        En este fichero se implementa las funciones de la clase MergeSort
//
// Historial de revisiones
//        03/05/25 - Creación (primera versión) del código

#include"MergeSort.h"

/** MergeSort::MergeSort()
  * @brief Crea el objeto de la clase MergeSort.
  * @param 
  * @return objeto de la clase MergeSort
  */
MergeSort::MergeSort() {

}


/** MergeSort::small(const vector<int>& sequence)
  * @brief Comprueba si la secuencia es pequeña
  * @param sequence: secuencia a comprobar
  * @return booleano que indica si la secuencia es pequeña
  */
bool MergeSort::small(const vector<int>& sequence) {
  return sequence.size() <= 1;
}

/** MergeSort::solveSmall(const vector<int>& sequence)
  * @brief Resuelve la secuencia pequeña
  * @param sequence: secuencia a resolver
  * @return secuencia resuelta
  */
vector<int> MergeSort::solveSmall(const vector<int>& sequence) {
  return sequence;
}

/** MergeSort::divide(const vector<int>& secuencia)
  * @brief Divide la secuencia en dos partes
  * @param secuencia: secuencia a dividir
  * @return vector con las dos partes de la secuencia
  */
vector<vector<int>> MergeSort::divide(const vector<int>& secuencia) {
  vector<vector<int>> result;
  vector<int> subsequence1;
  vector<int> subsequence2;
  int size = secuencia.size();
  for (int i = 0; i < size / 2; i++) {
    subsequence1.push_back(secuencia[i]);
  }
  for (int i = size / 2; i < size; i++) {
    subsequence2.push_back(secuencia[i]);
  }
  result.push_back(subsequence1);
  result.push_back(subsequence2);
  return result;
}

/** MergeSort::combine(const vector<int>& subsequence1, const vector<int>& subsequence2)
  * @brief Combina las dos partes de la secuencia
  * @param subsequence1: primera parte de la secuencia
  * @param subsequence2: segunda parte de la secuencia
  * @return secuencia combinada
  */
vector<int> MergeSort::combine(const vector<int>& subsequence1, const vector<int>& subsequence2) {
  vector<int> result;
  int size1 = subsequence1.size();
  int size2 = subsequence2.size();
  int i = 0;
  int j = 0;
  while (i < size1 && j < size2) {
    if (subsequence1[i] < subsequence2[j]) {
      result.push_back(subsequence1[i]);
      i++;
    } else {
      result.push_back(subsequence2[j]);
      j++;
    }
  }
  while (i < size1) {
    result.push_back(subsequence1[i]);
    i++;
  }
  while (j < size2) {
    result.push_back(subsequence2[j]);
    j++;
  }
  return result;
}