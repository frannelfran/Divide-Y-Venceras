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
      std::cerr << "Error: No se han introducido los argumentos necesarios" << std::endl;
      mostrar_ayuda_resumida();
      datos.correcto = false;
      return datos;
    case 2:
      if (argv[1] == kHelp || argv[1] == kH) {
        mostrar_ayuda();
        datos.correcto = true;
      }
      return datos;
    case 3:
      datos.numero_instancias = atoi(argv[1]);
      datos.algoritmo = argv[2];
      datos.correcto = true;
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

void mostrar_algoritmos(vector<Algoritmo*> algoritmos) {
  for (int i = 0; i < algoritmos.size(); i++) {
    std::cout << i << ". " << algoritmos[i]->get_nombre() << std::endl;
  }
}

/**
 * @brief implementación del menú del programa
 * @param numero_instancias
 */
void menu(int numero_instancias, vector<Algoritmo*> algoritmos) {
  int numero_algoritmo = 0; 
  mostrar_ayuda_menu();
  int opcion;
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
      case 2:
        std::cout << "Modo normal" << std::endl;
        std::cout << "" << std::endl;
        break;
      case 3:
        std::cout << "Modo debug" << std::endl;
        std::cout << "" << std::endl;
        break;
      case 4:
        std::cout << "introduce el número número de instancias: " << std::endl;
        std::cin >> numero_instancias;
        break;
      case 5:
        std::cout << "introduce el algoritmo: " << std::endl;
        std::cin >> numero_algoritmo;
        break;

      default:
        std::cerr << "Error: Opción no válida" << std::endl;
        break;
    }
  }
}


