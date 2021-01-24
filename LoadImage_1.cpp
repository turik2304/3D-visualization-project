
#include "widget.h"
#include "ui_widget.h"


Widget1::Widget1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    vtkNew<vtkImageActor> earthActor;
    vtkNew<vtkImageActor> sunActor;

    vtkNew<vtkPNGReader> earthReader;
    vtkNew<vtkPNGReader> sunReader;

    earthReader->SetFileName("/home/artur/Qt_projects/ReadBMP/Earth.png");
    sunReader->SetFileName("/home/artur/Qt_projects/ReadBMP/Sun.png");

    earthActor->GetMapper()->SetInputConnection(earthReader->GetOutputPort());
    sunActor->GetMapper()->SetInputConnection(sunReader->GetOutputPort());

    earthActor->SetPosition(1500,0,0);

    //
    //Add Actor to Renderer
    //
    vtkNew<vtkRenderer> renderer;
    renderer->AddActor( earthActor );
    renderer->AddActor( sunActor );

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

Widget1::~Widget1()
{
    delete ui;
}



