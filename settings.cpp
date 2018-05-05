#include "settings.h"

const QString FILENAME = ":/raw/settings.ini";

class Settings::Impl final {

};

Settings& Settings::getInstance() {
    static Settings sInstance;
    return sInstance;
}

Settings::Settings(QObject *parent) : QObject(parent),
    mImpl(new Impl) {

}

Settings::~Settings() {

}
