#include "opticalcharacterrecognizer.h"

#include <memory>

QString OpticalCharacterRecognizer::QStringTextFromQImage(QImage qImage){
    tesseract::TessBaseAPI *ocr = new tesseract::TessBaseAPI();

    ocr->Init(nullptr, "eng");
    ocr->SetPageSegMode(tesseract::PSM_AUTO);

    PIX* pix_image = _QImageToPix(qImage);
    ocr->SetImage(pix_image);
    pixDestroy(&pix_image);

    std::string output_text = ocr->GetUTF8Text();
    QString output_text_qstring = ocr->GetUTF8Text();

    return output_text_qstring;
}

std::string OpticalCharacterRecognizer::StringTextFromQImage(QImage qImage){
    return QStringTextFromQImage(qImage).toUtf8().constData();
}

PIX *OpticalCharacterRecognizer::_QImageToPix(QImage qImage){
    PIX * pixs;
    l_uint32 *lines;

    qImage = qImage.rgbSwapped();
    int width = qImage.width();
    int height = qImage.height();
    int depth = qImage.depth();
    int wpl = qImage.bytesPerLine() / 4;

    pixs = pixCreate(width, height, depth);
    pixSetWpl(pixs, wpl);
    pixSetColormap(pixs, NULL);
    l_uint32 *datas = pixs->data;

    for (int y = 0; y < height; y++) {
        lines = datas + y * wpl;
        QByteArray a((const char*)qImage.scanLine(y), qImage.bytesPerLine());
        for (int j = 0; j < a.size(); j++) {
            *((l_uint8 *)lines + j) = a[j];
        }
    }
    return pixEndianByteSwapNew(pixs);
}
