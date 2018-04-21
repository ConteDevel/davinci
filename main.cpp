#include <QCoreApplication>
#include <QTextStream>
#include <QDebug>
#include <QtGui/QImage>
#include <iostream>
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>

#include "opticalcharacterrecognizer.h"

int main(int argc, char *argv[]){
    QCoreApplication app(argc, argv);

    std::cout << "Image location: ";

    std::string image_name;
    std::cin >> image_name;

    std::cout << image_name << '\n';
    QImage image = QImage(image_name.c_str());

    std::string output_text = OpticalCharacterRecognizer::StringTextFromQImage(image);
    std::cout << output_text << '\n';

    return app.exec();
}
