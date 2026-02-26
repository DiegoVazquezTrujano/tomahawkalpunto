/**
 * @file app.h
 * @brief Cabecera del controlador principal del programa base.
 */
#pragma once
#ifndef APP_H
#define APP_H

#include <chrono>
using namespace std::chrono;

 /**
  * @brief Funcion plantilla (template) para medir el tiempo de ejecucion en milisegundos.
  */
template<typename Func>
double medirTiempo(Func funcion) {
    auto inicio = high_resolution_clock::now();
    funcion();  
    auto fin = high_resolution_clock::now();
    return duration_cast<microseconds>(fin - inicio).count() / 1000.0; // ms
}

/**
 * @brief Funcion principal que maneja la logica del menu y las llamadas a los metodos.
 */
void ejecutarApp();

#endif