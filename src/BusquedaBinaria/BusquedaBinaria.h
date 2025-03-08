// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 03 : Divide_Venceras
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 03/05/25
// Archivo BusquedaBinaria.h : Declaración de la clase BusquedaBinaria
//        En este fichero se declara la clase BusquedaBinaria
//
// Historial de revisiones
//        03/05/25 - Creación (primera versión) del código
#ifndef C_BusquedaBinaria_H
#define C_BusquedaBinaria_H
#include "../Algoritmo/Algoritmo.h"

class BusquedaBinaria : public Algoritmo {
 public:
  // Constructor
  BusquedaBinaria(int objetivo);

  // Métodos
  virtual bool small(const vector<int>& sequence) override; // Comprueba si la secuencia es pequeña
  virtual vector<int> solveSmall(const vector<int>& sequence) override; // Resuelve la secuencia pequeña
  virtual vector<vector<int>> divide(const vector<int>& secuencia) override; // Divide la secuencia en dos partes
  virtual vector<int> combine(const vector<vector<int>>& secuencia) override;// Combina las dos partes de la secuencia
  virtual string get_recurrencia() override {return "T(n) = T(n/2) + O(1)";}

 private:
  int objetivo_;
  int num_quitados_ = 0;
};

#endif