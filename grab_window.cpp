#include "grab_window.h"
#include <QImage>

GrabWindow::GrabWindow(QQuickView *parent) : QQuickView(parent) {

}

void GrabWindow::setWindow(QQuickWindow *wnd) {
    mWndPtr = wnd;
    emit windowChanged();
}

QQuickWindow *GrabWindow::window() const {
    return mWndPtr;
}

void GrabWindow::capture(const QString &path) {
    QImage img = mWndPtr->grabWindow();
    img.save(path);
}
