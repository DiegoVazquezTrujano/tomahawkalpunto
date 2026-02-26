/**
 * @file randomGen.h
 * @brief Cabecera de las funciones para generar arreglos con numeros aleatorios.
 */

//definimos
#pragma once
#ifndef RANDOMGEN_H
#define RANDOMGEN_H

void generarAleatoriosConRepeticion(int arreglo[], int& n, int tam);

void generarAleatoriosSinRepeticion(int arreglo[], int& n, int tam, int M = 0);

#endif