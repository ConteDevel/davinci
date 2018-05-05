#ifndef SCREENSHOT_H
#define SCREENSHOT_H

#include <QQuickWindow>
#include <QString>

class Screenshot : public QObject {
    Q_OBJECT
public:
    explicit Screenshot(QQuickWindow *parent = nullptr);

public slots:
    void capture(QString const &path) const;

private:
    QQuickWindow *mCurrentView;
};

#endif // SCREENSHOT_H
