// Opncv_Test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

/**
  Código de prueba: Carga, conversión a Escala de Grises y Redimensionado.
*/
int main() {
    // Declaración de matrices
    Mat img, img_resized;

    // 1. Cargar la imagen (Asegúrate que la ruta y extensión .png sean correctas)
    img = imread("../img/logoOpenCV.png");

    // 2. Validación de seguridad
    if (img.empty()) {
        cout << "Error: No se pudo cargar la imagen. Verifica la ruta." << endl;
        return -1;
    }

    // --- OPCIÓN 1: Conversión a Blanco y Negro ---
    // Usamos COLOR_BGR2GRAY para transformar de 3 canales (Color) a 1 canal (Gris)
    // Al pasar 'img' como entrada y salida, sobrescribimos la original.
    cvtColor(img, img, COLOR_BGR2GRAY);
    // ---------------------------------------------

    // 3. Redimensionar
    // Como 'img' ya fue convertida a grises arriba, el resultado aquí también será gris.
    resize(img, img_resized, Size(636, 316));

    // 4. Mostrar ambas ventanas
    imshow("Imagen Original (Grises)", img);
    imshow("Imagen Redimensionada (Grises)", img_resized);

    // Esperar tecla para salir
    waitKey(0);
    return 0;
}