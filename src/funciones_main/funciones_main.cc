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
  const string kHelp = "--help";
  const string kH = "-h";
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
  cout << "\nEste programa se encarga de realizar " << endl;
  cout << "El programa recibe como argumentos un entero que representa el número de instancias aleatorias que se van a crear\n Genera instancias aleatorias comprendidas entre 1 a 100" << endl;
  cout << "Usage: ./Divide_Venceras <numero de instancias> <Algoritmo> " << endl;
}

/**
 * @brief Muestra una ayuda resumida del programa
 */
void mostrar_ayuda_resumida() {
  cout << "\nUsage: ./Divide_Venceras <numero de instancias> <Algoritmo>" << endl;
  cout << "Usa el parámetro -h para más información" << endl;
}

void mostrar_ayuda_menu() {
  cout << "Introduce una de las siguientes opciones: " << endl;
  cout << "0. Salir" << endl;
  cout << "1. Mostrar ayuda" << endl;
  cout << "2. Modo normal" << endl;
  cout << "3. Modo debug" << endl;
  cout << "4. Comparación MergeSort y QuickSort" << endl;
}

/**
 * @brief Muestra los algoritmos disponibles
*/
void mostrar_algoritmos() {
  cout << "---Algoritmos disponibles---" << endl;
  cout << "1. MergeSort" << endl;
  cout << "2. QuickSort" << endl;
  cout << "3. BusquedaBinaria" << endl;
  cout << "4. Hannoi" << endl;
  cout << "---------------------------" << endl;
  cout << "Escriba el nombre del algoritmo que desea utilizar: ";
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

Algoritmo* crear_algoritmo(int numero) {
  Algoritmo* algoritmo = nullptr;
  switch (numero) {
    case 1:
      algoritmo = new MergeSort();
      break;
    case 2:
      algoritmo = new QuickSort();
      break;
    case 3:
      cout << "Introduce el objetivo: ";
      int objetivo;
      cin >> objetivo;
      algoritmo = new BusquedaBinaria(objetivo);
      break;
    case 4:
      algoritmo = new Hannoi();
      break;
    default:
      cerr << "Error: Algoritmo no válido" << endl;
      break;
  }
  return algoritmo;
}

/**
 * @brief Mostrar la instacia
 * @param instancia Instancia a mostrar
 * @return void
*/

void mostrar_instancia(vector<int> instancia) {
  for (long unsigned int i = 0; i < instancia.size(); i++) {
    cout << instancia[i] << " ";
  }
  cout << endl;
}

/**
 * @brief Mostrar el tiempo de ejecución de los algoritmos
 * @param instancias Instancias a mostrar
 * @return void
*/

void mostrar_tiempos(vector<vector<int>> instancias, Algoritmo* algoritmo) {
  for (long unsigned int i = 0; i < instancias.size(); i++) {
    auto start = chrono::high_resolution_clock::now();
    algoritmo->solve(instancias[i]);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    cout << "Tiempo (" << i + 1 << ") " << elapsed.count() << "s.  " << "Tamaño de la secuancia: " << instancias[i].size() << endl;
    cout << "Recursividad máxima: " << algoritmo->get_max_recursividad() << endl;
    algoritmo->reset_recursividad();
  }
}

/**
 * @brief Modo normal del programa
 * @return void
*/

void modo_normal() {
  int numero_instancias, numero;
  cout << "--- Modo normal ---" << endl;
  cout << "Introduce el número de instancias: ";
  cin >> numero_instancias;
  vector<vector<int>> instancias = generar_instancias(numero_instancias);
  mostrar_algoritmos();
  cin >> numero;
  Algoritmo* algoritmo = crear_algoritmo(numero);
  if (numero == 4) {
    for (long unsigned int i = 0; i < instancias.size(); i++) {
      instancias[i] = {(instancias[i][0] % 10), 1, 3, 2}; // si es para el algoritmo de hannoi me quedo solo con el primer elemento
    }
  }
  mostrar_tiempos(instancias, algoritmo);
}

/**
 * @brief Modo debug del programa
 * @return void
*/

void modo_debug() {
  int numero, tamanio;
  cout << "--- Modo debug ---" << endl;
  cout << "Instroduce el tamaño de la instancia: ";
  cin >> tamanio;
  // Creo la instancia del tamaño proporcionado
  vector<int> instancia;
  for (int i = 0; i < tamanio; i++) {
    instancia.push_back(rand() % 100 + 1);
  }
  mostrar_instancia(instancia);
  mostrar_algoritmos();
  cin >> numero;
  Algoritmo* algoritmo = crear_algoritmo(numero);
  if (numero == 3) { // Si el algoritmo es busqueda binaria
    // Ordeno la instancia
    sort(instancia.begin(), instancia.end());
    mostrar_instancia(instancia);
    cout << "Posición del objetivo: " << algoritmo->solve(instancia)[0] << endl;
    return;
  } else if (numero == 4) { // Si el algoritmo es hannoi
    cout << "Introduce el número de discos: ";
    int discos;
    cin >> discos;
    instancia = {discos, 1, 3, 2};
  }
  vector<int> ordenado = algoritmo->solve(instancia);
  cout << "Instancia ordenada: ";
  mostrar_instancia(ordenado);
  cout << "Recursividad máxima: " << algoritmo->get_max_recursividad() << endl;
  algoritmo->reset_recursividad();
}


/**
 * @brief Comparación de los algoritmos
 * @param instancias Instancias a comparar
 * @param algoritmo1 Algoritmo 1
 * @param algoritmo2 Algoritmo 2
 * @return void
*/

void comparacion(vector<vector<int>> instancias, Algoritmo* algoritmo1, Algoritmo* algoritmo2) {
  cout << "--- Comparación QuickSort y MergeSort ---" << endl;
  cout << "MergeSort: " << algoritmo1->get_recurrencia() << endl;
  cout << "QuickSort: " << algoritmo2->get_recurrencia() << endl;
  int recursividad1 = 0, recursividad2 = 0;
  for (long unsigned int i = 0; i < instancias.size(); i++) {
    // Algoritmo 1
    auto start1 = chrono::high_resolution_clock::now();
    algoritmo1->solve(instancias[i]);
    auto end1 = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed1 = end1 - start1;
    recursividad1 = algoritmo1->get_max_recursividad();
    // Algoritmo 2
    auto start2 = chrono::high_resolution_clock::now();
    algoritmo2->solve(instancias[i]);
    auto end2 = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed2 = end2 - start2;
    recursividad2 = algoritmo1->get_max_recursividad();
    
    // Muestro los resultados
    cout << "Instancia (" << i + 1 << ") "<< "Tamaño de la secuencia: " << instancias[i].size() << endl;
    cout << "MergeSort: " << elapsed1.count() << "s. Recursividad máxima: " << recursividad1 << endl;
    cout << "QuickSort: " << elapsed2.count() << "s. Recursividad máxima: " << recursividad2 << endl;
    cout << endl;
    algoritmo1->reset_recursividad();
    algoritmo2->reset_recursividad();
  }
}

/**
 * @brief implementación del menú del programa
 * @param numero_instancias
 */
void menu() { 
  int opcion;
  mostrar_ayuda_menu();
  while (true) {
    cout << endl;
    cout << "Introduzca una opción: ";
    cin >> opcion;
    switch (opcion) {
      case 0:
        return;
        break;
      case 1:
        mostrar_ayuda_menu();
        break;
      case 2:
        modo_normal();
        break;
      case 3:
        modo_debug();
        break;
      case 4: {
        int numero_instancias;
        cout << "Introduce el número de instancias: ";
        cin >> numero_instancias;
        vector<vector<int>> instancias = generar_instancias(numero_instancias);
        Algoritmo* algoritmo1 = crear_algoritmo(1);
        Algoritmo* algoritmo2 = crear_algoritmo(2);
        comparacion(instancias, algoritmo1, algoritmo2);
        break;
      }
      default:
        cerr << "Error: Opción no válida" << endl;
        break;
    }
  }
}


