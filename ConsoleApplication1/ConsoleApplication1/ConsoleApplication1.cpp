#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    // ==========================================
    // PARTE 1: PROCESAMIENTO ESTÁTICO DE IMAGEN
    // ==========================================

    // 1. Cargar Imagen
    string path = "../img/logoOpenCV.png"; // Ajusta tu ruta si es necesario
    Mat img = imread(path);

    if (img.empty()) {
        cout << "Error: No se encuentra la imagen en " << path << endl;
        return -1;
    }

    // 2. Mostrar Dimensiones (Consola)
    // Nota: rows = alto, cols = ancho
    cout << "=== INFORMACION DE LA IMAGEN ===" << endl;
    cout << "Ancho (cols)   : " << img.cols << endl;
    cout << "Alto (rows)    : " << img.rows << endl;
    cout << "Canales        : " << img.channels() << endl;
    cout << "================================" << endl;

    // 3. Redimensionar (Resize)
    Mat img_resized;
    // Redimensionamos a 1024x1024 como solicitaste
    resize(img, img_resized, Size(1024, 1024));

    // 4. Dibujar Figuras (Sobre la imagen redimensionada para mejor visualización)
    // A) Rectángulo Rojo (BGR: 0, 0, 255) alrededor de la imagen
    // Point(x, y) -> Esquina superior izquierda (0,0) a esquina inferior derecha
    int thickness = 5;
    rectangle(img_resized, Point(0, 0), Point(img_resized.cols, img_resized.rows), Scalar(0, 0, 255), thickness);

    // B) Círculo Verde en el centro
    Point centro(img_resized.cols / 2, img_resized.rows / 2);
    int radio = 100;
    circle(img_resized, centro, radio, Scalar(0, 255, 0), -1); // -1 rellena el círculo

    // C) Texto en la parte inferior
    putText(img_resized, "DieguitoPai - OpenCV", Point(50, img_resized.rows - 50),
        FONT_HERSHEY_SIMPLEX, 1.5, Scalar(255, 0, 0), 3);

    // Mostrar resultados estáticos
    imshow("Original", img);
    imshow("Redimensionada y Editada", img_resized);

    cout << "Presiona cualquier tecla para iniciar la CAMARA..." << endl;
    waitKey(0); // Espera tecla para continuar
    destroyAllWindows(); // Limpia ventanas anteriores

    // ==========================================
    // PARTE 2: VIDEO EN TIEMPO REAL (WEBCAM)
    // ==========================================

    VideoCapture cap(0); // 0 suele ser la webcam predeterminada
    if (!cap.isOpened()) {
        cout << "Error: No se puede abrir la camara." << endl;
        return -1;
    }

    Mat frame, gray;
    cout << "Iniciando camara. Presiona 'ESC' para salir." << endl;

    while (true) {
        cap >> frame; // Captura frame por frame
        if (frame.empty()) break; // Si no hay frame, rompe el ciclo

        // Convertir a escala de grises
        cvtColor(frame, gray, COLOR_BGR2GRAY);

        // Mostrar video
        imshow("Webcam en Vivo (Color)", frame);
        imshow("Webcam en Vivo (Grises)", gray);

        // Salir si se presiona ESC (código 27)
        char c = (char)waitKey(25);
        if (c == 27) break;
    }

    cap.release();
    destroyAllWindows();
    return 0;
}