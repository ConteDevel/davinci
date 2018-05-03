#include "yandextranslate.h"

#include <QtNetwork>
#include <QtGui>
#include <QTextStream>

#include "requestsender.h"

/*!
 * \brief Возвращает синглтон.
 * \return
 */
YandexTranslate &YandexTranslate::SharedInstance(){
    static YandexTranslate instance;
    return instance;
}

/*!
 * \brief Отправляет запрос на получение доступных языков
 * Возращает QMap<QString, QString>, в котором коду языка соответствует
 * полное название языка
 *
 * Например response["en"] = "English"
 * \return
 */
QMap<QString, QString> YandexTranslate::SupportedLanguagesRequest(){
    QUrl url = QUrl(QString("https://translate.yandex.net/api/v1.5/tr.json/getLangs?")
                    + QString("key=") + _api_key
                    + QString("&ui=") + QString("en")
                    );
    QMap<QString, QString> response;
    RequestSender::SendRequest(url, [&response](QNetworkReply* reply){
        QJsonObject obj = QJsonDocument::fromJson(reply->readAll()).object();
        if(!obj.contains("langs")) {
            qDebug() << QString("Error getting json");
        }
        QJsonObject langs = obj.value("langs").toObject();
        for(const QString& code : langs.keys()){
            QString lang = langs.value(code).toString();
            response[code] = "lang";
        }
    });

    return response;
}

/*!
 * \brief Отправляет запрос на определение языка \a text
 * \param text Текст, язык которого необходимо определить
 * \return
 */
QString YandexTranslate::DetectLanguageRequest(const QString &text){
    QUrl url = QUrl(QString("https://translate.yandex.net/api/v1.5/tr.json/detect?")
                    + QString("key=") + _api_key
                    + QString("&text=") + text
                    );
    QString response;
    RequestSender::SendRequest(url, [&response](QNetworkReply* reply){
        QJsonObject obj = QJsonDocument::fromJson(reply->readAll()).object();
        if(!obj.contains("lang")) {
            qDebug() << QString("Error getting json");
        }
        response = obj.value("lang").toString();
    });

    return response;
}

/*!
 * \brief Отправляет запрос на перевод \a text
 * Отправляет запрос на перевод \a text с языка \a source_language_code на
 * язык \a output_language_code
 * \param text Текст, который необходимо перевести
 * \param source_language_code Код языка исходного текста (например, "en")
 * \param output_language_code Код языка выходного текста (например, "ru")
 * \return
 */
QStringList YandexTranslate::TranslateTextRequest(const QString &text,
                                                   const QString &source_language_code,
                                                   const QString &output_language_code){
    QUrl url = QUrl(QString("https://translate.yandex.net/api/v1.5/tr.json/translate?")
                        + QString("key=") + _api_key
                        + QString("&lang=")
                        + source_language_code + "-" + output_language_code
                        + QString("&text=") + text
                        );
    QStringList response;
    RequestSender::SendRequest(url, [&response](QNetworkReply* reply){
        QJsonObject obj = QJsonDocument::fromJson(reply->readAll()).object();
        if(!obj.contains("text")) {
            qDebug() << QString("Error getting json");
        }
        QJsonArray text = obj.value("text").toArray();
        for(QJsonValue json_value : text) {
            response.append(json_value.toString());
        }
    });

    return response;
}
