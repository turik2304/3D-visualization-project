
//Подключение заголовочных файлов
#include "widget.h"
#include "ui_widget.h"

//Основной конструктор класса
Lab0::Lab0(QWidget *parent) : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this); //Установка виджета визуализации QVTKWidget
//Основной алгоритм

    //
    //Создаём источник данных
    //
    vtkNew<vtkSphereSource> sphere;
    vtkNew<vtkConeSource> cone;
    vtkNew<vtkCubeSource> cube;
    //
    //Создаём актёров
    //
    vtkNew<vtkActor> sphereActor;
    vtkNew<vtkActor> coneActor;
    vtkNew<vtkActor> cubeActor;
    sphereActor->SetPosition(1,0,0);
    coneActor->SetPosition(0,1,0);
    cubeActor->SetPosition(0,0,1);
    //
    //Создаём мэппер
    //
    vtkNew<vtkPolyDataMapper> sphereMapper;
    vtkNew<vtkPolyDataMapper> coneMapper;
    vtkNew<vtkPolyDataMapper> cubeMapper;
    sphereMapper->SetInputConnection( sphere->GetOutputPort() );
    coneMapper->SetInputConnection( cone->GetOutputPort() );
    cubeMapper->SetInputConnection( cube->GetOutputPort() );
    //
    //Add Mapper to Actor
    //
    sphereActor->SetMapper( sphereMapper );
    coneActor->SetMapper( coneMapper );
    cubeActor->SetMapper( cubeMapper );
    sphereActor->GetProperty()->SetColor(1, 0, 0);
    coneActor->GetProperty()->SetColor(0, 1, 0);
    cubeActor->GetProperty()->SetColor(0, 0, 1);
    //
    //Add Actor to Renderer
    //
    vtkNew<vtkRenderer> renderer;
    renderer->AddActor( sphereActor );
    renderer->AddActor( coneActor );
    renderer->AddActor( cubeActor );
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

//Деструктор класса
Lab0::~Lab0()
{
    delete ui;
}


