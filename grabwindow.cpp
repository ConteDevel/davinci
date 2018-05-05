#include "grabwindow.h"
#include <limits>

GrabWindow::GrabWindow(QWindow *parent) : QQuickView(parent) {
    setClearBeforeRendering(false);
    setPosition(std::numeric_limits<unsigned short>::max(),
                std::numeric_limits<unsigned short>::max());
    connect(this, SIGNAL(afterRendering()),
            SLOT(afterRendering()), Qt::DirectConnection);
    connect(this, SIGNAL(beforeRendering()),
            SLOT(beforeRendering()), Qt::DirectConnection);
}

void GrabWindow::beforeRendering() {
    if (!mFbo) {
        auto fbo = new QOpenGLFramebufferObject(
                    size(), QOpenGLFramebufferObject::NoAttachment);
        mFbo.reset(fbo);
        setRenderTarget(mFbo.data());
    }
}

void GrabWindow::afterRendering() {
    if(!mFbo.isNull()) {
        emit changeImage(mFbo->toImage());
    }
}
