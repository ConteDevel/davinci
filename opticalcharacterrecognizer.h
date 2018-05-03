#ifndef OPTICALCHARACTERRECOGNIZER_H
#define OPTICALCHARACTERRECOGNIZER_H

#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include <QtGui/QImage>
#include <QString>

class OpticalCharacterRecognizer{
public:
    static QString QStringTextFromQImage(QImage qImage);
    static std::string StringTextFromQImage(QImage qImage);

private:
    static PIX* _QImageToPix(QImage qImage);
};

#endif // OPTICALCHARACTERRECOGNIZER_H
