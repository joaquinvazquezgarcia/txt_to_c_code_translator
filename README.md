# Traductor de Código TXT a C

Este programa en C **traduce pseudocódigo o texto en español a código fuente funcional en C (en inglés)** utilizando un diccionario personalizado. Lee un archivo de texto con palabras clave, busca sus equivalencias y genera el archivo `.c` correspondiente.

## 🚀 Características
* **Diccionario dinámico:** Lee traducciones desde un archivo de texto con formato `palabra_espanol=palabra_ingles`.
* **Traducción selectiva:** Reemplaza los términos que coinciden con el diccionario y mantiene intactos los símbolos, estructuras y palabras desconocidas.
* **Generación automática:** Crea el archivo de salida `.c` si este no existe.

## 📋 Requisitos Previos
El programa utiliza rutas absolutas locales. Antes de compilar, asegúrate de **modificar las rutas de los archivos** en el código fuente para que coincidan con tu computadora:
* `dictionary.txt` (Diccionario de traducción)
* `txtfile.txt` (Archivo de origen con el texto a traducir)
* `cfile.c` (Archivo de destino del código traducido)

## 🛠️ Estructura del Diccionario (`dictionary.txt`)
El archivo de traducción debe seguir el formato `origen=destino` línea por línea. Ejemplo:
```text
entero=int
si=if
mientras=while
```
*Nota: Si agregas más palabras, recuerda actualizar la variable `dictionaryLength` en el código fuente.*

## 💻 Cómo Ejecutarlo
1. Configura tus archivos de texto en la ruta especificada.
2. Compila el archivo fuente:
   ```bash
   gcc main.c -o traductor
   ```
3. Ejecuta el programa:
   ```bash
   ./traductor
   ```
