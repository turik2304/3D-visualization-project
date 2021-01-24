
#include <QApplication>
#include "widget.h"
#include <qsurfaceformat.h>
#include <QVTKOpenGLWidget.h>

int main(int argc, char *argv[])
{


    QApplication a(argc, argv);
    setlocale(LC_NUMERIC,"C");


    // needed to ensure appropriate OpenGL context is created for VTK rendering.
    QSurfaceFormat::setDefaultFormat(QVTKOpenGLWidget::defaultFormat());

    Widget w;
    w.show();
    return a.exec();
}

