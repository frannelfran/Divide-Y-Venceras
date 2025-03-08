// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 03 : Divide_Venceras
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 03/05/25
// Archivo funciones_main.h: Declaración de las funciones del main
//        En este fichero se declara las funciones que se utilizan en el main.cc
//
// Historial de revisiones
//        03/05/25 - Creación (primera versión) del código
#ifndef C_funciones_main_H
#define C_funciones_main_H
#include"../Algoritmo/Algoritmo.h"
#include"../MergeSort/MergeSort.h"
#include"../QuickSort/QuickSort.h"
#include"../BusquedaBinaria/BusquedaBinaria.h"
#include"../Hannoi/Hannoi.h"
#include<iostream>
#include<string>
#include<vector>
#include<chrono>
#include<algorithm>
using namespace std;

struct Dato {
  bool correcto;
  int numero_instancias;
  std::string algoritmo;
};

Dato recoger_parametro(int argc, char *argv[]);
// Funciones de ayuda
void mostrar_ayuda();
void mostrar_ayuda_resumida();
// Funciones para el menú
void menu();
void mostrar_ayuda_menu();
// Modos del programa
void modo_normal();
void modo_debug();
// Funciones para los modos normal y debug
void mostrar_tiempos(vector<vector<int>> instancias, Algoritmo* algoritmo);
void mostrar_algoritmos();
void mostrar_instancia(vector<int> instancia);
// Funciones auxiliares
Algoritmo* crear_algoritmo(int numero);
vector<vector<int>> generar_instancias(int numero_instancias);

#endif