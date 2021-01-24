
#include <QApplication>
#include "widget.h"
#include <qsurfaceformat.h>
#include <QVTKOpenGLWidget.h>



int main(int argc, char *argv[])
{
    // needed to ensure appropriate OpenGL context is created for VTK rendering.
    vtkOpenGLRenderWindow::SetGlobalMaximumNumberOfMultiSamples( 0 );
    QApplication a(argc, argv);
    QSurfaceFormat::setDefaultFormat(QVTKOpenGLWidget::defaultFormat());
    //Wideget#, #=1-6
    Widget5 w;
    w.show();
    return a.exec();
}

