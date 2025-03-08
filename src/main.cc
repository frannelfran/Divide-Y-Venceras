// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 03 : Divide_Venceras
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 03/05/25
// Archivo main.cc: Implementación del programa cliente
//        En este fichero se implementa la función del main
//
// Historial de revisiones
//        03/05/25 - Creación (primera versión) del código
#include"funciones_main/funciones_main.h"
#include<iostream>
#include "MergeSort/MergeSort.h"
#include "QuickSort/QuickSort.h"

using namespace std;

int main(int argc, char *argv[]) {
  //Compruebo si se han introducido los argumentos necesarios
  Dato datos = recoger_parametro(argc, argv);
  if (datos.correcto == false) {
    std::cerr << "Error no se han introducido los datos correctamente" << std::endl;
    return 1;
  }
  // creo un vector de int
  vector<int> secuencia;
  // creo un objeto de la clase MergeSort
  vector <Algoritmo*> algoritmos;
  Algoritmo* merge = new MergeSort();
  Algoritmo* quick = new QuickSort();
  algoritmos.push_back(quick);
  algoritmos.push_back(merge);
  
  // relleno el vector con numeros aleatorios
  for (int i = 0; i < datos.numero_instancias; i++) {
    secuencia.push_back(rand() % 100);
  }
  // muestro el vector sin resolver
  for (int i = 0; i < datos.numero_instancias; i++) {
    cout << "Vector sin resolver: " << secuencia[i] << " ";
  }
  cout << endl;
  // resuelvo el vector
  vector<int> resultado = algoritmos[0]->solve(secuencia, datos.numero_instancias);
  // muestro el vector resuelto
  for (int i = 0; i < datos.numero_instancias; i++) {
    cout << resultado[i] << " ";
  }
  cout << endl;
  //menu(datos.numero_instancias);
  return 0;
}