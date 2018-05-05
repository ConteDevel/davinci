#include "screenshot.h"
#include <QImage>

Screenshot::Screenshot(QQuickWindow *parent)
    : QObject(nullptr), mCurrentView(parent) {

}

void Screenshot::capture(const QString &path) const {
    QImage img = mCurrentView->grabWindow();
    img.save(path);
}
