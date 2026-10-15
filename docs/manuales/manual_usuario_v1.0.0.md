# MANUAL TÉCNICO DEL USUARIO

**Proyecto:** Piedra, Papel o Tijera + Persistencia en Disco - Actividad 7  
**Institución:** E.E.S.T. N.° 1 "Eduardo Ader" — Vicente López  
**Asignatura:** Laboratorio de Programación (LPR) — 5° Año  
**Autor:** Mikaela Batirola  
**Fecha:** 14 de octubre de 2026 | **Versión:** v1.0.0

---

## CONTROL DE VERSIONES Y CHANGELOG

| **Versión** | **Fecha** | **Autor** | **Descripción de Cambios** |
|---|---|---|---|
| **v1.0.0** | 14/10/2026 | Mikaela Batirola | Versión inicial del manual del usuario para el juego Piedra, Papel o Tijera. |

---

## 1. INTRODUCCIÓN

### 1.1. Objetivo

Este manual explica cómo utilizar el programa Piedra, Papel o Tijera. El juego permite competir contra la computadora, ver el resultado de cada partida y guardar un historial en un archivo de texto para poder consultarlo después.

### 1.2. Requisitos

Para utilizar el programa se necesita:

- Una computadora con Windows.
- Tener el archivo ejecutable del juego.
- Contar con una consola o terminal para abrir el programa.

## 2. INICIO DEL PROGRAMA

Para iniciar el juego, se debe abrir una terminal en la carpeta principal del proyecto y ejecutar el siguiente comando:

```powershell
.\src\piedrapapelotijera.exe
```

Una vez iniciado, aparecerá un menú con las opciones disponibles.

## 3. FUNCIONAMIENTO DEL JUEGO

### 3.1. Menú principal

El menú permite elegir entre tres opciones:

1. **Jugar:** inicia una nueva partida contra la computadora.
2. **Ver historial:** muestra las partidas que se guardaron anteriormente.
3. **Salir:** cierra el programa.

Para seleccionar una opción, se debe escribir el número correspondiente y presionar Enter.

### 3.2. Jugar una partida

Al elegir la opción de jugar, el programa solicita el nombre del jugador. Después, se debe elegir una de las siguientes opciones:

- **Piedra**
- **Papel**
- **Tijera**

El programa genera una elección aleatoria para la computadora y compara las dos jugadas.

Las reglas son las siguientes:

- La piedra le gana a la tijera.
- La tijera le gana al papel.
- El papel le gana a la piedra.
- Si los dos eligen lo mismo, hay un empate.

Al finalizar, el programa muestra las elecciones realizadas y el resultado de la partida.

### 3.3. Validación de datos

El programa controla que las opciones ingresadas sean válidas. Si se escribe un número fuera del rango permitido o un dato incorrecto, solicita que se ingrese nuevamente.

Esto ayuda a evitar errores durante el uso del juego.

## 4. GUARDADO DEL HISTORIAL

### 4.1. ¿Cómo se guardan las partidas?

Cuando termina una partida, sus datos se guardan automáticamente en un archivo de texto llamado **`historial_partidas.txt`**.

El archivo se encuentra dentro de la carpeta **`src`** del proyecto, siempre que el programa se ejecute desde la carpeta principal del proyecto.

Se guarda la siguiente información:

- ID de la partida.
- Nombre del jugador.
- Elección del jugador.
- Elección de la computadora.
- Resultado final.

Los datos se almacenan separados por comas. Cada partida se guarda en una nueva línea.

### 4.2. Consultar el historial

Para consultar las partidas anteriores, se debe seleccionar la opción **2. Ver historial** en el menú principal.

El programa lee el archivo de texto y muestra los registros guardados.

Si todavía no se guardó ninguna partida o el archivo no se puede abrir, puede que no aparezcan registros para mostrar.

### 4.3. Conservación de los datos

El historial se guarda en un archivo del disco, por lo que los registros pueden mantenerse aunque se cierre el programa.

Es importante no borrar ni modificar el archivo **`historial_partidas.txt`** si se quiere conservar el historial de partidas.

## 5. POSIBLES PROBLEMAS

| **Problema** | **Posible solución** |
|---|---|
| El programa no inicia. | Verificar que el archivo ejecutable exista en la carpeta **`src`**. |
| Se ingresa una opción incorrecta. | Volver a escribir un número válido del menú. |
| No aparece el historial. | Comprobar si se jugaron partidas y si el archivo contiene registros. |
| No se guardan las partidas. | Revisar que el archivo y la carpeta **`src`** existan y que el programa se ejecute desde la carpeta principal del proyecto. |

## 6. CIERRE

El programa permite jugar Piedra, Papel o Tijera contra la computadora de una manera sencilla. Además, guarda los resultados en un archivo de texto para poder consultar las partidas realizadas anteriormente.

De esta forma, se puede utilizar el juego y conservar un registro de los resultados obtenidos.