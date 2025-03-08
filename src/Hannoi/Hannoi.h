// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 03 : Divide_Venceras
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 03/05/25
// Archivo Hannoi.h : Declaración de la clase Hannoi
//        En este fichero se declara la clase Hannoi
//
// Historial de revisiones
//        03/05/25 - Creación (primera versión) del código
#ifndef C_Hannoi_H
#define C_Hannoi_H

#include "../Algoritmo/Algoritmo.h"

class Hannoi : public Algoritmo {
 public:
  Hannoi();
  bool small(const vector<int>& sequence) override; // Comprueba si la secuencia es pequeña
  vector<int> solveSmall(const vector<int>& sequence) override; // Resuelve la secuencia pequeña
  vector<vector<int>> divide(const vector<int>& secuencia) override; // Divide la secuencia en dos partes
  vector<int> combine(const vector<vector<int>>& secuencia) override; // Combina las dos partes de la secuencia
  string get_recurrencia() override {return "T(n) = 2T(n/2) + O(1)";}
};

#endif