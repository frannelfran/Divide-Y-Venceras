// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 03 : Divide_Venceras
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 03/05/25
// Archivo Algoritmo.h : Declaración de la clase Algoritmo
//        En este fichero se declara la clase Algoritmo
//
// Historial de revisiones
//        03/05/25 - Creación (primera versión) del código
#ifndef C_Algoritmo_H
#define C_Algoritmo_H
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Algoritmo {
 public:
  Algoritmo();

  virtual bool small(const vector<int>& sequence) = 0; // Comprueba si la secuencia es pequeña
  virtual vector<int> solveSmall(const vector<int>& sequence) = 0; // Resuelve la secuencia pequeña
  virtual vector<vector<int>> divide(const vector<int>& secuencia) = 0; // Divide la secuencia en dos partes
  virtual vector<int> combine(const vector<vector<int>>& subsecuencias) = 0; // Combina las partes de la secuencia

  vector<int> solve(const vector<int>& secuencia, int recursividad = 0); // Resuelve la secuencia
  void set_max_recursividad(int recursividad); // Establece el máximo número de recursividad del algoritmo.
  int get_max_recursividad(); // Devuelve el máximo número de recursividad del algoritmo.
  void reset_recursividad(); // Resetea el número de recursividad del algoritmo.

  virtual string get_recurrencia() = 0;
 protected:
  int recursividad = 0;
};

#endif