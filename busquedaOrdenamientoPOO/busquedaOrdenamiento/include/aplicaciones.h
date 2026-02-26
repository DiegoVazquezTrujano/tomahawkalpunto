/**
 * @file App.h
 * @brief Definicion de la clase App que controla el flujo principal del programa POO.
 */
#pragma once
#ifndef APP_H
#define APP_H

#include "Arreglo.h"
#include <chrono>
#include <utility>

 /**
  * @brief Funcion plantilla para medir tiempo en microsegundos.
  */
template<typename Func, typename... Args>
double medirTiempo(Func funcion, Args&&... args) {
    auto inicio = std::chrono::high_resolution_clock::now();
    funcion(std::forward<Args>(args)...);
    auto fin = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> duracion = fin - inicio;
    return duracion.count();
}

/**
 * @class App
 * @brief Clase controladora que maneja la interaccion con el usuario y encapsula el Arreglo.
 */
class App {
private:
    Arreglo miArreglo; ///< Instancia principal del arreglo que se va a manipular.

public:
    /**
     * @brief Inicia la ejecucion del ciclo principal del programa (Menu interactivo).
     */
    void ejecutar();
};

#endif