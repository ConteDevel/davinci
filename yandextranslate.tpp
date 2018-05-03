#include <QtNetwork>
#include <QtGui>
#include <QTextStream>

/*!
 * \brief Возвращает синглтон.
 * \return
 */
YandexTranslate &YandexTranslate::SharedInstance(){
    static YandexTranslate instance;
    return instance;
}

/*!
 * \fn YandexTranslate::_SendRequest(QUrl& url, ReplyHandler replyHandler)
 * \brief Отправляет запрос
 * Отправляет запрос по \a url и обрабатывает полученный QNetworkReply* с
 * помощью \a replyHandler.
 * \return
 */
template <class ReplyHandler>
void YandexTranslate::_SendRequest(QUrl& url, ReplyHandler replyHandler) {
    qInfo() << QString("starting request...");
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    auto manager = new QNetworkAccessManager();
    auto event_loop = new QEventLoop();

    QObject::connect(manager, &QNetworkAccessManager::finished,
                     event_loop, &QEventLoop::quit);
    QNetworkReply* reply = manager->get(request);
    qInfo() << QString("staritng execution...");
    event_loop->exec();
    qInfo() << QString("handling data...");
    replyHandler(reply);
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
    _SendRequest(url, [&response](QNetworkReply* reply){
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
    _SendRequest(url, [&response](QNetworkReply* reply){
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
    _SendRequest(url, [&response](QNetworkReply* reply){
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
