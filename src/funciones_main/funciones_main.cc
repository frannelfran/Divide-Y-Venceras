// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: DAA
// Curso: 3º
// Práctica 03 : Divide_Venceras
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 03/05/25
// Archivo funciones_main.cc: Implementación de las funciones del main
//        En este fichero se implementa las funciones utilizadas en el main
//
// Historial de revisiones
//        03/05/25 - Creación (primera versión) del código

#include"funciones_main.h"

/**
 * @brief Recoge los parámetros que se han enviado por linea del comando. Comprobando si los parámetros son correctos.
 * @param numero_argumentos 
 * @param argv 
 * @return retorna un booleano que indica si se ha recogido correctamente los parámetros (true si es correcto, false si no)
 */
Dato recoger_parametro(int numero_argumentos, char *argv[]) {
  Dato datos;
  const std::string kHelp = "--help";
  const std::string kH = "-h";
  switch (numero_argumentos) {
    case 1:
      datos.correcto = true;
      return datos;
    case 2:
      if (argv[1] == kHelp || argv[1] == kH) {
        mostrar_ayuda();
        datos.correcto = true;
      }
      datos.correcto = false;
      return datos;
    default:
      datos.correcto = false;
      return datos;
  }
}
/**
 * @brief Muestra una ayuda detallada del programa
 */
void mostrar_ayuda() {
  std::cout << "\nEste programa se encarga de realizar " << std::endl;
  std::cout << "El programa recibe como argumentos un entero que representa el número de instancias aleatorias que se van a crear\n Genera instancias aleatorias comprendidas entre 1 a 100" << std::endl;
  std::cout << "Usage: ./Divide_Venceras <numero de instancias> <Algoritmo> " << std::endl;
}

/**
 * @brief Muestra una ayuda resumida del programa
 */
void mostrar_ayuda_resumida() {
  std::cout << "\nUsage: ./Divide_Venceras <numero de instancias> <Algoritmo>" << std::endl;
  std::cout << "Usa el parámetro -h para más información" << std::endl;
}

void mostrar_ayuda_menu() {
  std::cout << "Introduce una de las siguientes opciones: " << std::endl;
  std::cout << "0. Salir" << std::endl;
  std::cout << "1. Mostrar ayuda" << std::endl;
  std::cout << "2. Modo normal" << std::endl;
  std::cout << "3. Modo debug" << std::endl;
  std::cout << "4. Modificar el número de instancias" << std::endl;
}

/**
 * @brief Muestra los algoritmos disponibles
*/
void mostrar_algoritmos() {
  std::cout << "---Algoritmos disponibles---" << std::endl;
  std::cout << "MergeSort" << std::endl;
  std::cout << "QuickSort" << std::endl;
  std::cout << "---------------------------" << std::endl;
  std::cout << "Escriba el nombre del algoritmo que desea utilizar: ";
}

/**
 * @brief Generar las intancias aleatorias
 * @param numero_instancias
 * @return vector<vector<int>> 
*/
vector<vector<int>> generar_instancias(int numero_instancias) {
  vector<vector<int>> instancias;
  for (int i = 0; i < numero_instancias; i++) {
    vector<int> instancia;
    int size = rand() % 100 + 1;
    for (int j = 0; j < size; j++) {
      instancia.push_back(rand() % 100 + 1);
    }
    instancias.push_back(instancia);
  }
  return instancias;
}

/**
 * @brief Crear el algoritmo
 * @param nombre Nombre del algoritmo
 * @return Algoritmo* 
*/

Algoritmo* crear_algoritmo(const string& nombre) {
  Algoritmo* algoritmo = nullptr;
  string nombreFixed;
  for (auto& c : nombre) {
    nombreFixed += toupper(c); // Convertir a mayúsculas
  }
  if (nombreFixed == "MERGESORT") {
    //algoritmo = new MergeSort();
  } else if (nombreFixed == "QUICKSORT") {
    //algoritmo = new QuickSort();
  }
  return algoritmo;
}

/**
 * @brief implementación del menú del programa
 * @param numero_instancias
 */
void menu() { 
  mostrar_ayuda_menu();
  int opcion, tamanio;
  string nombre;
  int numero_instancias;
  while (true) {
    std::cout << std::endl;
    std::cout << "Introduzca una opción: ";
    std::cin >> opcion;
    switch (opcion) {
      case 1:
        mostrar_ayuda_menu();
        break;
      case 0:
        return;
        break;
      case 2: {
        std::cout << "Modo normal" << std::endl;
        cout << "Introduce el número de instancias: ";
        cin >> numero_instancias;
        vector<vector<int>> instancias = generar_instancias(numero_instancias);
        mostrar_algoritmos();
        cin >> nombre;
        Algoritmo* algoritmo = crear_algoritmo(nombre);
        for (long unsigned int i = 0; i < instancias.size(); i++) {
          auto start = std::chrono::high_resolution_clock::now();
          algoritmo->solve(instancias[i], instancias[i].size());
          auto end = std::chrono::high_resolution_clock::now();
          std::chrono::duration<double> elapsed = end - start;
          std::cout << "Tiempo de ejecución: " << elapsed.count() << "s" << std::endl;
        }
        break;
      }
      case 3: {
        std::cout << "Modo debug" << std::endl;
        mostrar_algoritmos();
        cin >> nombre;
        Algoritmo* algoritmo = crear_algoritmo(nombre);
        cout << "Instroduce el tamaño de la instancia: ";
        cin >> tamanio;
        vector<int> instancia;
        for (int i = 0; i < tamanio; i++) {
          instancia.push_back(rand() % 100 + 1);
        }
        vector<int> ordenado = algoritmo->solve(instancia, tamanio);
        cout << "Secuencia ordenada: ";
        for (long unsigned int i = 0; i < ordenado.size(); i++) {
          std::cout << ordenado[i] << " ";
        }
        break;
      }
      default:
        std::cerr << "Error: Opción no válida" << std::endl;
        break;
    }
  }
}


