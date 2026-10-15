# 🎮 Piedra, Papel o Tijera

**Institución:** "Escuela de Educación Técnica N.° 1 "Eduardo Ader"" - Vicente López 
**Materia:** Laboratorio de Programación (LPR)  
**Curso:** 5.º Año  
**Actividad:** 7 — Mini juego con persistencia en disco  
**Año:** 2026

## 📌 Descripción

Este proyecto consiste en desarrollar un juego de Piedra, Papel o Tijera en C++. El jugador compite contra la inteligencia artificial (IA), que elige una opción al azar.

El programa permite jugar partidas, consultar el historial y guardar los resultados en un archivo de texto para conservarlos al cerrar el programa.

## 🎯 Objetivos

- Aplicar estructuras (`struct`) para organizar los datos.
- Utilizar funciones para organizar el código.
- Leer y escribir archivos mediante `ifstream` y `ofstream`.
- Usar `ios::app` para agregar partidas sin borrar las anteriores.
- Comprender la persistencia de datos en disco.

## 🛠️ Tecnologías utilizadas

- C++
- GCC / G++
- Visual Studio Code
- Git y GitHub

## ▶️ Compilación y ejecución

Compilar desde la carpeta principal del proyecto:

```bash
g++ -std=c++11 src/main.cpp -o src/piedrapapelotijera.exe
```

Ejecutar en Windows:

```powershell
.\src\piedrapapelotijera.exe
```

## 📂 Estructura del proyecto

```text
piedrapapelotijera/
├── .gitattributes
├── .gitignore
├── LICENSE
├── README.md
├── src/
│   ├── main.cpp
│   └── historial_partidas.txt
├── docs/
│   ├── CHANGELOG.md
│   └── manuales/
└── capturas/
```

## 💾 Persistencia de datos

Las partidas se guardan en `src/historial_partidas.txt`. Cada registro contiene el ID de la partida, el nombre del jugador, las elecciones y el resultado, separados por comas.

El programa utiliza `ios::app` para conservar los registros anteriores y agregar las nuevas partidas al final del archivo.

## 📸 Capturas

En la carpeta `capturas/` se guardan las evidencias del funcionamiento del juego y del historial almacenado en disco.

## 📄 Licencia

Este proyecto utiliza la licencia MIT. Para consultar sus condiciones, revisar el archivo `LICENSE`.
