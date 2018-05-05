#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include <QSettings>
#include <QScopedPointer>
#include <QString>

class Settings final : public QObject {
    Q_OBJECT
public:
    static Settings &getInstance();
private:
    explicit Settings(QObject *parent = nullptr);
    ~Settings();
    Settings(Settings const &);
    Settings& operator= (Settings const &);

    class Impl;
    QScopedPointer<Impl> const mImpl;

signals:

public slots:
};

#endif // SETTINGS_H
