#ifndef YANDEXTRANSLATE_H
#define YANDEXTRANSLATE_H

#include <QString>
#include <QJsonObject>
#include <QtNetwork>
#include <QMap>

class YandexTranslate {
public:
    YandexTranslate(YandexTranslate& other) = delete;

    void operator=(YandexTranslate& other) = delete;

    static YandexTranslate& SharedInstance();

    QMap<QString, QString> SupportedLanguagesRequest();

    QString DetectLanguageRequest(const QString& text);

    QStringList TranslateTextRequest(const QString& text,
                                     const QString& source_language_code,
                                     const QString& output_language_code);

private:
    YandexTranslate() = default;

#warning Нельзя оставлять пустым
    QString _api_key = "trnsl.1.1.20180501T193302Z.e1161db67beb260f.4a21b8418a84c0b60f7f142c8e8f1432e9aee3a5";
};

#endif // YANDEXTRANSLATE_H
