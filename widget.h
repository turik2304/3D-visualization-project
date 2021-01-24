#ifndef WIDGET_H
#define WIDGET_H

#include <QApplication>
#include <QWidget>

#include <vtkAutoInit.h>

#define vtkRenderingCore_AUTOINIT 2(vtkRenderingOpenGL2, vtkInteractionStyle)

VTK_MODULE_INIT(vtkRenderingVolumeOpenGL2)
VTK_MODULE_INIT(vtkRenderingFreeType)
VTK_MODULE_INIT(vtkRenderingOpenGL2);
VTK_MODULE_INIT(vtkRenderingContextOpenGL2);
VTK_MODULE_INIT(vtkInteractionStyle)

#include <vtkBMPReader.h>
#include <vtkCylinderSource.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkProperty.h>
#include <vtkCamera.h>
#include <vtkSmartPointer.h>
#include <vtkSphereSource.h>
#include <vtkConeSource.h>
#include <vtkNew.h>
#include <vtkTIFFReader.h>
#include <vtkImageData.h>

#include <vtkSmartPointer.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkMetaImageReader.h>
#include <vtkVolume.h>
#include <vtkFixedPointVolumeRayCastMapper.h>
#include <vtkVolumeProperty.h>
#include <vtkColorTransferFunction.h>
#include <vtkPiecewiseFunction.h>
#include <vtkCamera.h>
#include <vtkBMPReader.h>
#include <vtkGPUVolumeRayCastMapper.h>
#include <vtkCutter.h>
#include <vtkOpenGLRayCastImageDisplayHelper.h>
#include <vtkRenderingOpenGL2Module.h>
#include <vtkRenderingOpenGL2ObjectFactory.h>
#include <vtkRenderingOpenGLConfigure.h>
#include <vtkRenderingVolumeOpenGL2Module.h>
#include <vtkRenderingVolumeOpenGL2ObjectFactory.h>
#include <vtkRenderingVolumeModule.h>
#include <vtkRayCastImageDisplayHelper.h>
#include <vtkImageViewer2.h>
#include <vtkDataSetMapper.h>
#include <vtkVolumeMapper.h>
#include <vtkImageData.h>
#include <vtkUnsignedShortArray.h>
#include <vtkPointData.h>
#include <vtkVolumeProperty.h>
#include <vtkCubeSource.h>
#include <vtkPlaneSource.h>
#include <vtkFileOutputWindow.h>

#include <vtkImageMapper3D.h>
#include <vtkAbstractMapper3D.h>
#include <vtkVolumeMapper.h>

#include "vtkBoxWidget.h"
#include "vtkCamera.h"
#include "vtkCommand.h"
#include "vtkColorTransferFunction.h"
#include "vtkDICOMImageReader.h"
#include "vtkImageData.h"
#include "vtkImageResample.h"
#include "vtkMetaImageReader.h"
#include "vtkPiecewiseFunction.h"
#include "vtkPlanes.h"
#include "vtkProperty.h"
#include <vtkProperty2D.h>
#include "vtkRenderer.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkVolume.h"
#include "vtkVolumeProperty.h"
#include "vtkXMLImageDataReader.h"
#include "vtkSmartVolumeMapper.h"
#include <vtkLight.h>

#include <vtkImageMagnitude.h>
#include <vtkBarChartActor.h>
#include "vtkImageAlgorithm.h"
#include "vtkImageAccumulate.h"
#include "vtkImageGaussianSmooth.h"
#include "vtkNamedColors.h"
#include "vtkBarChartActor.h"

#include <vtkCornerAnnotation.h>
#include <vtkTextProperty.h>
#include <vtkTextActor.h>
#include "vtkTextRenderer.h"

#include <vtkImageCanvasSource2D.h>
#include <vtkAVIWriter.h>
#include <vtkWindowToImageFilter.h>

#include "vtkDataArray.h"
#include "vtkAbstractArray.h"
#include "vtkRenderingVolumeOpenGL2Module.h"
#include "vtkGPUInfoList.h"
#include "vtkGPUInfo.h"
#include "vtkContourFilter.h"
#include "vtkMarchingCubes.h"
#include "vtkMarchingCubesTriangleCases.h"
#include "vtkPolyDataMapper.h"

#include <vtkActor2D.h>
#include <vtkTextActor.h>
#include <vtkTextProperty.h>
#include <vtkPNGReader.h>
#include <vtkImageMapper.h>
#include <vtkImageActor.h>

#include <QVTKOpenGLWidget.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkImageBlend.h>
#include <vtkImageChangeInformation.h>
#include <vtkJPEGReader.h>
#include <vtkImageAnisotropicDiffusion2D.h>
#include <vtkImageMedian3D.h>
#include <vtkImageCast.h>
#include <vtkSTLReader.h>
#include <vtkVolumeReader.h>
#include <vtkBooleanOperationPolyDataFilter.h>
#include <vtkStripper.h>
#include <vtkOutlineFilter.h>
#include <vtkFillHolesFilter.h>

#include <vtkTable.h>
#include <vtkContextView.h>
#include <vtkContextActor.h>
#include <vtkChartXY.h>
#include <vtkPen.h>
#include <vtkPlot.h>
#include <vtkPlotPoints.h>
#include <vtkDoubleArray.h>

#include <vtkVoxelModeller.h>
#include <vtkPolyDataNormals.h>
#include <vtkImageThreshold.h>


namespace Ui {
class Widget;
}

class Widget1 : public QWidget
{
    Q_OBJECT

public:
    explicit Widget1(QWidget *parent = 0);
    ~Widget1();

private:
    Ui::Widget *ui;
};

class Widget2 : public QWidget
{
    Q_OBJECT

public:
    explicit Widget2(QWidget *parent = 0);
    ~Widget2();

private:
    Ui::Widget *ui;
};

class Widget3 : public QWidget
{
    Q_OBJECT

public:
    explicit Widget3(QWidget *parent = 0);
    ~Widget3();

private:
    Ui::Widget *ui;
};

class Widget4 : public QWidget
{
    Q_OBJECT

public:
    explicit Widget4(QWidget *parent = 0);
    ~Widget4();

private:
    Ui::Widget *ui;
};

class Widget5 : public QWidget
{
    Q_OBJECT

public:
    explicit Widget5(QWidget *parent = 0);
    ~Widget5();

private:
    Ui::Widget *ui;
};

class Widget6 : public QWidget
{
    Q_OBJECT

public:
    explicit Widget6(QWidget *parent = 0);
    ~Widget6();

private:
    Ui::Widget *ui;
};

class Widget7 : public QWidget
{
    Q_OBJECT

public:
    explicit Widget7(QWidget *parent = 0);
    ~Widget7();

private:
    Ui::Widget *ui;
};

class Widget8 : public QWidget
{
    Q_OBJECT

public:
    explicit Widget8(QWidget *parent = 0);
    ~Widget8();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
