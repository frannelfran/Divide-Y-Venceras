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
#include "BusquedaBinaria/BusquedaBinaria.h"

using namespace std;

int main(int argc, char *argv[]) {
  //Compruebo si se han introducido los argumentos necesarios
  Dato datos = recoger_parametro(argc, argv);
  if (datos.correcto == false) {
    std::cerr << "Error no se han introducido los datos correctamente" << std::endl;
    return 1;
  }
  
  cout << "secuencia: " << endl;
  Algoritmo* algoritmo = new BusquedaBinaria(5);
  vector<int> secuencia = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  for (long unsigned int i = 0; i < secuencia.size(); i++) {
    cout << secuencia[i] << endl;
  }
  algoritmo->solveNoBin(secuencia);
  cout << "pos: ";
  // for (int i = 0; i < resultado.size(); i++) {
  //   std::cout << resultado[i] << " ";
  // }



  // Muestro el menú del programa
  //menu();
  return 0;
}