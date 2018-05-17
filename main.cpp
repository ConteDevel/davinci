#include <QCoreApplication>
#include <QTextStream>
#include <QtGui>

#include "opticalcharacterrecognizer.h"
#include "yandextranslate.h"
#include "spellchecker.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo() << "Image location: ";

    SpellChecker spell_checker(QString("/usr/share/hunspell/en_US.aff"),
                               QString("/usr/share/hunspell/en_US.dic"));

    QString test = spell_checker.CorrectedString("lavva flowq from mounta|n");
    qInfo() << test;

    QTextStream text_stream(stdin);

    QString image_name = text_stream.readLine();

    qInfo() << image_name << '\n';
    QImage image = QImage(image_name);

    QString output_text = OpticalCharacterRecognizer::QStringTextFromQImage(image);
    output_text = output_text.simplified();
    qInfo() << output_text << '\n';

    qInfo() << YandexTranslate::SharedInstance().TranslateTextRequest(output_text, "en", "ru");

    return a.exec();
}
