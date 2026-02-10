#pragma once
#include <opencv2/opencv.hpp>
#include <msclr/marshal_cppstd.h>


namespace Proyectoformulario {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// Summary for MyGui
    /// </summary>
    public ref class MyForm : public System::Windows::Forms::Form
    {
    public:
        MyForm(void)
        {
            InitializeComponent();
            //
            //TODO: Add the constructor code here
            //
        }

    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~MyForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private: PictureBox^ pictureBox1;
    private: Button^ btnCargar;


    private:
        /// <summary>
        /// Required designer variable.
        /// </summary>
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        void InitializeComponent(void)
        {
            this->components = gcnew System::ComponentModel::Container();
            this->Size = System::Drawing::Size(300, 300);
            this->Text = L"MyForm";
            this->Padding = System::Windows::Forms::Padding(0);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->pictureBox1 = gcnew PictureBox();
            this->btnCargar = gcnew Button();

            // PictureBox
            this->pictureBox1->Location = System::Drawing::Point(20, 20);
            this->pictureBox1->Size = System::Drawing::Size(400, 300);
            this->pictureBox1->SizeMode = PictureBoxSizeMode::Zoom;

            // Botón
            this->btnCargar->Location = System::Drawing::Point(20, 340);
            this->btnCargar->Text = L"Cargar Imagen";
            this->btnCargar->Click += gcnew EventHandler(this, &MyForm::btnCargar_Click);

            // Form
            this->Controls->Add(this->pictureBox1);
            this->Controls->Add(this->btnCargar);
            this->Text = L"Prueba OpenCV + WinForms";
            this->ClientSize = System::Drawing::Size(500, 400);
        }

        // Conversión básica cv::Mat -> Bitmap
        System::Drawing::Bitmap^ MatToBitmap(const cv::Mat& mat)
        {
            cv::Mat temp;
            cv::cvtColor(mat, temp, cv::COLOR_BGR2RGB);

            System::Drawing::Bitmap^ bmp = gcnew System::Drawing::Bitmap(
                temp.cols, temp.rows,
                System::Drawing::Imaging::PixelFormat::Format24bppRgb
            );

            for (int y = 0; y < temp.rows; y++)
            {
                for (int x = 0; x < temp.cols; x++)
                {
                    cv::Vec3b color = temp.at<cv::Vec3b>(y, x);
                    System::Drawing::Color c = System::Drawing::Color::FromArgb(color[0], color[1], color[2]);
                    bmp->SetPixel(x, y, c);
                }
            }
            return bmp;
        }



        // Evento del botón
        void btnCargar_Click(System::Object^ sender, System::EventArgs^ e) {
            cv::Mat imagen = cv::imread("C:/Users/parae/source/repos/Proyectoformulario/img/LogoOpenCV.jpeg");
            if (!imagen.empty()) {
                pictureBox1->Image = MatToBitmap(imagen);
            }
            else {
                MessageBox::Show("No se pudo cargar la imagen.");
            }
        }

#pragma endregion
    };
}