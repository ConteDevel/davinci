#ifndef GRABWINDOW_H
#define GRABWINDOW_H

#include <QImage>
#include <QOpenGLFramebufferObject>
#include <QQuickView>
#include <QScopedPointer>

class GrabWindow : public QQuickView {
    Q_OBJECT
public:
    explicit GrabWindow(QWindow *parent = nullptr);

signals:
    void changeImage(const QImage &image);

public slots:
    void beforeRendering();
    void afterRendering();

private:
    QScopedPointer<QOpenGLFramebufferObject> mFbo;
};

#endif // GRABWINDOW_H
