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

    QTextStream text_stream(stdin);

    QString image_name = text_stream.readLine();

    qInfo() << image_name << '\n';
    QImage image = QImage(image_name);

    QString output_text = OpticalCharacterRecognizer::QStringTextFromQImage(image);
    output_text = output_text.simplified();
    qInfo() << output_text << '\n';

    SpellChecker spell_checker(QString("/usr/share/hunspell/en_US.aff"),
                               QString("/usr/share/hunspell/en_US.dic"));

    QString corrected_string = spell_checker.SpecialCharacterFreeString(output_text);
    qInfo() << corrected_string << '\n';

    qInfo() << YandexTranslate::SharedInstance().TranslateTextRequest(corrected_string, "en", "ru");

    return a.exec();
}
