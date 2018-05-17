#include <QtNetwork>
#include <QtGui>
#include <QTextStream>

/*!
 * \fn RequestSender::_SendRequest(QUrl& url, ReplyHandler replyHandler)
 * \brief Отправляет запрос
 * Отправляет запрос по \a url и обрабатывает полученный QNetworkReply* с
 * помощью \a replyHandler.
 * \return
 */
template <class ReplyHandler>
void RequestSender::SendRequest(QUrl& url, ReplyHandler replyHandler) {
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
