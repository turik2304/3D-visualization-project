
#include "widget.h"
#include "ui_widget.h"

Widget5::Widget5(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    vtkNew<vtkBMPReader> reader;
    reader->SetFilePrefix("/home/artur/Qt_projects/ReadBMP/LampStack/");
    reader->SetFilePattern("%s%d.bmp");
    reader->SetFileNameSliceOffset(1);
    reader->SetDataSpacing(100,100,50);
    reader->SetDataExtent(0,99,0,99,0,49);

    vtkNew<vtkPiecewiseFunction> volumeGradientOpacity;
    volumeGradientOpacity->AddPoint(0, 0);
    volumeGradientOpacity->AddPoint(30, 0);
    volumeGradientOpacity->AddPoint(240, 1);

    vtkNew<vtkVolumeProperty> volumeProperty;
    volumeProperty->SetGradientOpacity(volumeGradientOpacity);
    volumeProperty->SetInterpolationTypeToLinear();
    volumeProperty->ShadeOn();
  //  volumeProperty->SetAmbient(0.4);
 //  volumeProperty->SetDiffuse(0.8);
 //   volumeProperty->SetSpecular(0.2);

    vtkNew<vtkGPUVolumeRayCastMapper> volumeMapper;
    volumeMapper->SetInputConnection(reader->GetOutputPort());

    vtkNew<vtkVolume> volume;
    volume->SetMapper(volumeMapper);
    volume->SetProperty(volumeProperty);
    //
    //Add Actor to Renderer
    //
    vtkNew<vtkRenderer> renderer;
    renderer->AddActor(volume);
    renderer->SetBackground(1,1,1);
    //
    //Add Renderer to RenderWindow
    //
    vtkNew<vtkGenericOpenGLRenderWindow> renderWindow;
    renderWindow->AddRenderer( renderer );
    //
    //Add RenderWindow to QVTKWigdet
    //     
    ui->qvtkWidget->SetRenderWindow( renderWindow );

}

Widget5::~Widget5()
{
    delete ui;
}

