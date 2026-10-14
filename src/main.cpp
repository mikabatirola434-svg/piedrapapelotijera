/*
   ====================================================================
   Materia: Laboratorio de Programacion (LPR) - 5to Año
   Institución: "Escuela de Educación Técnica N.° 1 "Eduardo Ader"" - Vicente López
   Archivo: src/main.cpp
   Actividad 7: Piedra, Papel o Tijera + Persistencia en Disco
   ====================================================================
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

// Estructura para representar una partida
struct Partida {
    int idPartida;
    string jugador;
    string eleccionJugador;
    string eleccionIA;
    string resultado;
};

// Prototipos de funciones
void jugarPartida(int& contadorID);
void guardarEnDisco(const Partida& p);
void leerHistorialDisco();
int obtenerProximoID();
int leerOpcion(const string& mensaje, int minimo, int maximo);

int main() {
    srand(static_cast<unsigned int>(time(0)));

    // Recuperar el proximo ID segun el historial existente
    int contadorID = obtenerProximoID();
    int opcion = 0;

    cout << "=====================================================" << endl;
    cout << " LPR 2026 - ACTIVIDAD 7: PIEDRA, PAPEL O TIJERA" << endl;
    cout << " Estudiante / Grupo: Mikaela Batirola" << endl;
    cout << "=====================================================" << endl;

    do {
        cout << "\n--- MENU PRINCIPAL ---" << endl;
        cout << "1. Jugar partida" << endl;
        cout << "2. Ver historial de partidas" << endl;
        cout << "3. Salir del sistema" << endl;

        opcion = leerOpcion("Ingrese una opcion (1-3): ", 1, 3);

        if (opcion == -1) {
            break;
        }

        if (opcion == 1) {
            jugarPartida(contadorID);
        }
        else if (opcion == 2) {
            leerHistorialDisco();
        }
        else if (opcion == 3) {
            cout << "\n[SISTEMA] Saliendo del programa..." << endl;
        }

    } while (opcion != 3);

    return 0;
}

// Lee un numero y comprueba que este dentro del rango permitido
int leerOpcion(const string& mensaje, int minimo, int maximo) {
    int valor;

    while (true) {
        cout << mensaje;

        if (cin >> valor) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (valor >= minimo && valor <= maximo) {
                return valor;
            }

            cout << "[ERROR] Ingrese un numero entre "
                 << minimo << " y " << maximo << "." << endl;
        }
        else {
            if (cin.eof()) {
                return -1;
            }

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "[ERROR] Debe ingresar un numero valido." << endl;
        }
    }
}

// Procesa una jugada contra la inteligencia artificial
void jugarPartida(int& contadorID) {
    Partida p;
    p.idPartida = contadorID++;

    cout << "\n--- NUEVA PARTIDA #" << p.idPartida << " ---" << endl;
    cout << "Ingrese su nombre o nickname: ";

    getline(cin, p.jugador);

    if (p.jugador.empty()) {
        p.jugador = "Jugador";
    }

    // Evitar comas en el nombre porque el historial usa formato CSV
    for (char& c : p.jugador) {
        if (c == ',') {
            c = ' ';
        }
    }

    int opcJugador = leerOpcion(
        "\nElija su jugada:\n"
        "1. Piedra\n"
        "2. Papel\n"
        "3. Tijera\n"
        "Opcion (1-3): ",
        1, 3
    );

    if (opcJugador == -1) {
        return;
    }

    // Guardar la eleccion del jugador
    if (opcJugador == 1) {
        p.eleccionJugador = "Piedra";
    }
    else if (opcJugador == 2) {
        p.eleccionJugador = "Papel";
    }
    else {
        p.eleccionJugador = "Tijera";
    }

    // Eleccion aleatoria de la IA
    int opcIA = (rand() % 3) + 1;

    if (opcIA == 1) {
        p.eleccionIA = "Piedra";
    }
    else if (opcIA == 2) {
        p.eleccionIA = "Papel";
    }
    else {
        p.eleccionIA = "Tijera";
    }

    cout << "\n[JUGADA] " << p.jugador
         << " eligio: " << p.eleccionJugador << endl;

    cout << "[JUGADA] La IA eligio: "
         << p.eleccionIA << endl;

    // Evaluar el resultado
    if (p.eleccionJugador == p.eleccionIA) {
        p.resultado = "Empate";
    }
    else if (
        (p.eleccionJugador == "Piedra" &&
         p.eleccionIA == "Tijera") ||
        (p.eleccionJugador == "Papel" &&
         p.eleccionIA == "Piedra") ||
        (p.eleccionJugador == "Tijera" &&
         p.eleccionIA == "Papel")
    ) {
        p.resultado = "Victoria";
    }
    else {
        p.resultado = "Derrota";
    }

    cout << "=> RESULTADO: " << p.resultado << "!" << endl;

    // Guardar la partida en el archivo
    guardarEnDisco(p);
}

// Guarda una partida al final del archivo sin borrar las anteriores
void guardarEnDisco(const Partida& p) {
    ofstream archivo("src/historial_partidas.txt", ios::app);

    if (!archivo.is_open()) {
        cerr << "[ERROR] No se pudo abrir el archivo para guardar."
             << endl;
        return;
    }

    archivo << p.idPartida << ","
            << p.jugador << ","
            << p.eleccionJugador << ","
            << p.eleccionIA << ","
            << p.resultado << endl;

    archivo.close();

    if (archivo.fail()) {
        cerr << "[ERROR] Hubo un problema al guardar la partida."
             << endl;
    }
    else {
        cout << "[DISCO] Partida guardada correctamente." << endl;
    }
}

// Lee y muestra las partidas guardadas en disco
void leerHistorialDisco() {
    ifstream archivo("src/historial_partidas.txt");

    if (!archivo.is_open()) {
        cout << "\n[AVISO] Todavia no hay partidas guardadas." << endl;
        return;
    }

    cout << "\n=====================================================" << endl;
    cout << " HISTORIAL DE PARTIDAS" << endl;
    cout << "=====================================================" << endl;

    string idStr, jugador, elJug, elIA, resultado;
    int total = 0;

    // Leer los campos separados por comas
    while (
        getline(archivo, idStr, ',') &&
        getline(archivo, jugador, ',') &&
        getline(archivo, elJug, ',') &&
        getline(archivo, elIA, ',') &&
        getline(archivo, resultado)
    ) {
        cout << "Partida #" << idStr
             << " | Jugador: " << jugador
             << " | " << elJug << " vs " << elIA
             << " | Resultado: " << resultado << endl;

        total++;
    }

    archivo.close();

    if (total == 0) {
        cout << "[AVISO] El archivo de historial esta vacio." << endl;
    }
    else {
        cout << "\n[SISTEMA] Total de partidas leidas: "
             << total << endl;
    }

    cout << "=====================================================" << endl;
}

// Busca el ultimo ID usado para evitar repetir numeros al reiniciar
int obtenerProximoID() {
    ifstream archivo("src/historial_partidas.txt");

    if (!archivo.is_open()) {
        return 1;
    }

    string idStr;
    int idMayor = 0;

    while (getline(archivo, idStr, ',')) {
        try {
            int id = stoi(idStr);

            if (id > idMayor) {
                idMayor = id;
            }
        }
        catch (...) {
            // Ignorar registros cuyo ID no sea valido
        }

        // Saltar los otros cuatro campos de la partida
        string jugador, elJug, elIA, resultado;

        if (!getline(archivo, jugador, ',') ||
            !getline(archivo, elJug, ',') ||
            !getline(archivo, elIA, ',') ||
            !getline(archivo, resultado)) {
            break;
        }
    }

    archivo.close();
    return idMayor + 1;
}
