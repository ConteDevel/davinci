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
    QString _api_key = "";
};

#endif // YANDEXTRANSLATE_H
