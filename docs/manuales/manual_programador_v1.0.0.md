# 📘 MANUAL TÉCNICO DEL PROGRAMADOR

**Proyecto:** Piedra, Papel o Tijera + Persistencia en Disco - Actividad 7  
**Institución:** E.E.T. N.° 1 "Escuela de Educación Técnica N.° 1 'Eduardo Ader'" — Vicente López  
**Asignatura:** Laboratorio de Programación (LPR) — 5° Año  
**Autor:** Mikaela Batirola  
**Fecha:** 14 de octubre de 2026 | **Versión:** v1.0.0

## CONTROL DE VERSIONES Y CHANGELOG

| **Versión** | **Fecha** | **Autor** | **Descripción de Cambios** |
|---|---|---|---|
| **v1.0.0** | 14/10/2026 | Mikaela Batirola | Versión inicial del juego con menú interactivo, validación de entradas y almacenamiento del historial de texto. |

## 1. ARQUITECTURA DEL SISTEMA Y ENTORNO DE DESARROLLO

### Requisitos del entorno

- **Lenguaje:** C++.
- **Compilador:** g++ compatible con el estándar C++11 o superior.
- **IDE recomendado:** Visual Studio Code con la extensión C/C++.
- **Sistema operativo:** Windows con PowerShell.
- **Almacenamiento:** archivo de texto `historial_partidas.txt` para conservar los registros de las partidas.

### Estructura de directorios del repositorio

```text
piedrapapelotijera/
├── .gitattributes
├── .gitignore
├── LICENSE
├── README.md
├── docs/
│   ├── CHANGELOG.md
│   ├── InformeEEST1_LPR2026_ACT07_G03_Informe_v1.0.0.pdf
│   └── manuales/
│       ├── manual_programador_v1.0.0.md
│       ├── manual_programador_v1.0.0.pdf
│       ├── manual_usuario_v1.0.0.md
│       └── manual_usuario_v1.0.0.pdf
├── src/
│   ├── main.cpp
│   └── historial_partidas.txt
└── capturas/
    ├── jugada_consola.png
    └── archivo_disco.png
```

**Nota:** los nombres de los archivos de documentación deben coincidir con los que realmente se encuentren en el repositorio. El archivo `historial_partidas.txt` se utiliza para almacenar las partidas y puede comenzar vacío.

## 2. DOCUMENTACIÓN DE MÓDULOS Y FUNCIONES (`src/main.cpp`)

### Módulo 1: `struct Partida`

- **Propósito:** agrupar los datos correspondientes a una partida.
- **Campos:** `idPartida`, `jugador`, `eleccionJugador`, `eleccionIA` y `resultado`.
- **Funcionamiento:** permite mantener organizada la información de cada jugada y pasarla a otras funciones mediante una única estructura.

### Módulo 2: `int main()`

- **Propósito:** controlar el flujo principal del programa.
- **Funcionamiento:** inicializa el generador de números aleatorios, recupera el próximo identificador disponible y presenta el menú principal.
- **Opciones:** jugar una partida, consultar el historial o salir del sistema.
- **Persistencia:** utiliza `obtenerProximoID()` para continuar la numeración a partir de los registros existentes.

### Módulo 3: `int leerOpcion(const string& mensaje, int minimo, int maximo)`

- **Propósito:** validar los datos ingresados por el usuario.
- **Mecánica:** comprueba que la entrada sea numérica y que se encuentre dentro del rango permitido.
- **Manejo de errores:** utiliza `cin.clear()` para recuperar el estado de entrada y `cin.ignore()` para descartar caracteres pendientes.
- **Resultado:** devuelve la opción válida o `-1` cuando se alcanza el fin de la entrada.

### Módulo 4: `void jugarPartida(int& contadorID)`

- **Propósito:** ejecutar una partida contra la inteligencia artificial.
- **Funcionamiento:** solicita el nombre del jugador, recibe su elección, genera una jugada aleatoria para la IA y compara ambas elecciones.
- **Evaluación:** determina si el resultado es `Victoria`, `Derrota` o `Empate`.
- **Paso de parámetros:** recibe el contador por referencia para actualizar el identificador de las partidas.
- **Almacenamiento:** al finalizar una jugada válida, llama a `guardarEnDisco(p)` para registrar los datos.

### Módulo 5: `void guardarEnDisco(const Partida& p)`

- **Propósito:** almacenar una partida en un archivo de texto.
- **Apertura:** utiliza `ofstream` con `ios::app` para agregar información al final del archivo sin eliminar los registros anteriores.
- **Formato:** guarda los campos separados por comas, siguiendo una estructura similar al formato CSV:

```text
ID,Jugador,EleccionJugador,EleccionIA,Resultado
```

- **Control de errores:** comprueba si el archivo se abrió correctamente y muestra un mensaje cuando ocurre un problema.
- **Importancia:** permite conservar el historial aunque se cierre el programa.

### Módulo 6: `void leerHistorialDisco()`

- **Propósito:** recuperar y mostrar las partidas almacenadas.
- **Lectura:** utiliza `ifstream` para abrir el archivo y `getline()` para separar los campos delimitados por comas.
- **Resultado:** muestra el identificador, el jugador, las elecciones y el resultado de cada partida.
- **Control:** informa si el archivo no se pudo abrir o si no contiene registros.

### Módulo 7: `int obtenerProximoID()`

- **Propósito:** evitar que se repitan los identificadores al reiniciar el programa.
- **Funcionamiento:** recorre los registros del archivo, obtiene el ID de cada partida y conserva el mayor valor encontrado.
- **Retorno:** devuelve el identificador máximo más uno. Si no puede abrir el archivo, devuelve `1`.

### Consideraciones técnicas

- El archivo se abre mediante la ruta relativa `src/historial_partidas.txt`; por eso, la ejecución desde la carpeta raíz del proyecto permite utilizar la ubicación prevista.
- El historial se guarda como texto plano, por lo que puede consultarse con cualquier editor de texto.
- El formato utiliza comas como separadores. El código reemplaza las comas del nombre del jugador por espacios para evitar que se mezclen los campos.
- La validación de entradas reduce los errores al utilizar el menú y seleccionar una jugada.

## 3. INSTRUCCIONES DE COMPILACIÓN Y DEPURACIÓN

### Compilación desde PowerShell

Ubicándose en la raíz del proyecto, ejecutar:

```powershell
g++ -std=c++11 src/main.cpp -o src/piedrapapelotijera.exe
```

### Ejecución del programa

```powershell
.\src\piedrapapelotijera.exe
```

### Diagnóstico de errores frecuentes

1. **Error: `g++` no se reconoce como comando.**
   - **Causa:** el compilador no está instalado o su carpeta no está incluida en la variable de entorno `PATH`.
   - **Solución:** verificar la instalación de MinGW-w64 o MSYS2, configurar el `PATH` correspondiente y abrir una nueva terminal.

2. **Error al abrir el archivo de historial.**
   - **Causa:** la ruta relativa no coincide con la ubicación desde la que se ejecuta el programa.
   - **Solución:** ejecutar desde la raíz del proyecto y comprobar que exista la carpeta `src`.

3. **El historial aparece vacío.**
   - **Causa:** todavía no se guardaron partidas o se está consultando un archivo distinto del utilizado por el programa.
   - **Solución:** jugar una partida, comprobar el mensaje de guardado y revisar `src/historial_partidas.txt`.

4. **La entrada del menú no es válida.**
   - **Causa:** se ingresaron letras, caracteres adicionales o números fuera del rango permitido.
   - **Solución:** ingresar un número válido según las opciones que muestra el programa.

## 4. REFERENCIAS

### Enlaces Técnicos de Referencia (Links de Consulta)

- [GeeksforGeeks — Structs y Estructuras de Datos en C++](https://www.geeksforgeeks.org/cpp/structures-in-cpp/?utm_source=gemini)
- [Microsoft Learn — Flujos de Archivos en C++ (fstream, ofstream, ifstream)](https://learn.microsoft.com/es-es/cpp/standard-library/basic-fstream-class?utm_source=gemini)
- [cppreference — Modos de Apertura de Archivos (ios::app, ios::in, ios::out)](https://es.cppreference.com/w/cpp/io/basic_ofstream?utm_source=gemini)
- [GeeksforGeeks — Manejo de Búfer de Entrada (cin.ignore())](https://www.geeksforgeeks.org/cpp/cin-ignore-function-in-cpp/)
- [Git Documentation — Git Remote & Dual Push Configurations](https://git-scm.com/docs/git-remote?utm_source=gemini)