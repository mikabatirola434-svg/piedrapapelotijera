# CHANGELOG

Registro de cambios del proyecto **Piedra, Papel o Tijera**.

Los cambios se organizan por versión para identificar las mejoras y modificaciones realizadas durante el desarrollo.

## [1.0.0] - 2026-10-14

### Agregado
- Estructura `Partida` para almacenar los datos de cada juego.
- Menú principal con opciones para jugar, consultar el historial y salir.
- Selección aleatoria de la inteligencia artificial.
- Evaluación del resultado de cada partida.
- Guardado de partidas en `historial_partidas.txt` mediante `ofstream` e `ios::app`.
- Lectura del historial mediante `ifstream`.
- Generación de identificadores consecutivos a partir del historial existente.
- Validación de las opciones ingresadas por el usuario.
- Archivos de configuración `.gitignore` y `.gitattributes`.
- Documentación inicial del proyecto.

### Corregido
- Validación de entradas numéricas incorrectas.
- Limpieza del búfer de entrada antes de leer el nombre del jugador.
- Control de errores al abrir y guardar el archivo de historial.

### Documentación
- Creación del archivo `README.md`.
- Incorporación del archivo `LICENSE`.
- Organización de la carpeta `docs/` para los informes y manuales del proyecto.
