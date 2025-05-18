# Practica-3---Mariana-Patiño-y-Juan-Sebastian-Cortes-(Grassmann-Tremblay)

## Descripción

Este proyecto consiste en construir un contrato ACSL para el *Ejemplo 9.17* del libro Logic and Discrete Mathematics de *Winfried K. Grassmann* y *Jean-Paul Tremblay, utilizando la herramienta **Frama-C* para verificación formal del código. El objetivo es comprobar que la función que calcula impuestos cumple con su especificación matemática.

## Integrantes del grupo

- *Juan Sebastián Cortes Montoya*
- *Mariana Patiño Arboleda*

## Versiones utilizadas

- *Sistema operativo base*: Windows 11
- *Subsistema Linux (WSL)*: Ubuntu 22.04 LTS
- *Instalación de Frama-C*:
  1. Instalación inicial a través de *Windows PowerShell*
  2. Configuración de *WSL* (Windows Subsystem for Linux)
  3. Instalación de *Opam* (gestor de paquetes OCaml)
  4. Instalación de Frama-C mediante Opam
- *Versiones del software*:
  - Frama-C: 26.1 (Calcium)
  - GCC: 11.4.0
  - Opam: 2.1.x

## Explicación de la Solución

### Contexto
Implementamos y verificamos formalmente el **Ejemplo 9.17** del libro "Logic and Discrete Mathematics" (Grassmann, Tremblay), que consiste en:
- Un programa que calcula impuestos:
  - Si ingresos < 6000: impuestos = 0
  - Si ingresos ≥ 6000: impuestos = 0.4 * ingresos

### Implementación
Usamos **ACSL (ANSI/ISO C Specification Language)** para:
1. **Precondiciones**:
   - Validar puntero (`\valid`)
   - Asegurar valores finitos (`\is_finite`)
   - Restringir a ingresos no negativos

2. **Postcondición**:
   ```math
   (ingresos < 6000 ⇒ impuestos = 0) ∧ (ingresos ≥ 6000 ⇒ impuestos = 0.4×ingresos)

3. **Manejo de precisión**:
    Usamos \round_float para control explícito de redondeo
    Constantes tipadas (0.4f, 6000.0f)


## Recursos utilizados

- *Libro base*:  
  Logic and Discrete Mathematics, Grassmann y Tremblay (Ejemplo 9.17)
- *Documentación oficial*:
  - [Frama-C](https://frama-c.com)
  - ACSL by Example
- *Asistente de IA*:
  - ChatGPT (para asesoría en anotaciones ACSL y redacción de documentación)


## Resultados de Verificación

    [wp] Proved goals:   12 / 12
  Terminating:       1
  Unreachable:       1
  Qed:               7 (0.77ms-0.70ms-5ms) 
  Alt-Ergo 2.6.1:    3 (96ms-208ms-282ms)

## Verificar:
  frama-c -wp -wp-rte ejemplo.c

