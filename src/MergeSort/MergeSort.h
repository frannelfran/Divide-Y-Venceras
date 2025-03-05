// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 03 : Divide_Venceras
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 03/05/25
// Archivo MergeSort.h : Declaración de la clase MergeSort
//        En este fichero se declara la clase MergeSort
//
// Historial de revisiones
//        03/05/25 - Creación (primera versión) del código
#ifndef C_MergeSort_H
#define C_MergeSort_H
#include "../Algoritmo/Algoritmo.h"

class MergeSort : public Algoritmo {
 public:
  MergeSort();
  bool small(const vector<int>& sequence) override; // Comprueba si la secuencia es pequeña
  vector<int> solveSmall(const vector<int>& sequence) override; // Resuelve la secuencia pequeña
  vector<vector<int>> divide(const vector<int>& secuencia) override; // Divide la secuencia en dos partes
  vector<int> combine(const vector<int>& subsequence1, const vector<int>& subsequence2) override; // Combina las dos partes de la secuencia
 
};

#endif