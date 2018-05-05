#include "grabwindow.h"
#include "screenshot.h"
#include <QColor>
#include <QDebug>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickWindow>
#include <QSurfaceFormat>
#include <QtQml>

int main(int argc, char *argv[]) {
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

//    qmlRegisterType<GrabWindow>("daVinci", 1, 0, "GrabWindow");
//    qmlRegisterType<Screenshot>("daVinci", 1, 0, "Screenshot");

    QUrl systemTrayUrl = QUrl(QStringLiteral("qrc:/qml/SystemTray.qml"));
    QUrl screenshotUrl = QUrl(QStringLiteral("qrc:/qml/Screenshot.qml"));

    QQmlApplicationEngine engine(systemTrayUrl);

//    GrabWindow grabWnd;
//    grabWnd.setResizeMode(QQuickView::SizeViewToRootObject);
//    grabWnd.setSource(QUrl(QStringLiteral("qrc:/qml/main.qml")));
//    grabWnd.setFlags(Qt::Popup);
//    grabWnd.show();

//    Screenshot screenshot(&grabWnd);
//    grabWnd.rootContext()->setContextProperty("screenshot", &screenshot);

//    QObject *mainRoot = engine.rootObjects().value(1);
//    QObject *mainWnd = mainRoot->findChild<QObject *>("mainWindow");
//    qDebug() << "Object name: " << mainRoot->objectName();

//    Screenshot screenshot(qobject_cast<QQuickWindow *>(mainRoot));
//    QObject::connect(mainWnd, SIGNAL(capture(QString)),
//                     &screenshot, SLOT(capture(QString)));

    return app.exec();
}
