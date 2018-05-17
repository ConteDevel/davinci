#ifndef GRAB_WINDOW_H
#define GRAB_WINDOW_H

#include <QQuickView>
#include <QQuickWindow>
#include <QString>

class GrabWindow : public QQuickView {
    Q_OBJECT
    Q_PROPERTY(QQuickWindow * window READ window WRITE setWindow NOTIFY windowChanged)
public:
    explicit GrabWindow(QQuickView *parent = nullptr);
    void setWindow(QQuickWindow *wnd);
    QQuickWindow *window() const;

public slots:
    void capture(QString const &path);

signals:
    void windowChanged();
private:
    QQuickWindow *mWndPtr;
};

#endif // GRAB_WINDOW_H
