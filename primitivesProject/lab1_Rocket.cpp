
//Подключение заголовочных файлов
#include "widget.h"
#include "ui_widget.h"

//Основной конструктор класса
Lab1::Lab1(QWidget *parent) : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this); //Установка виджета визуализации QVTKWidget
//Основной алгоритм

    //
    //Создаём источник данных
    //

    vtkNew<vtkConeSource> head;
    head->SetDirection(0, 1, 0);
    head->SetHeight(3);
    head->SetResolution(100);
    head->SetRadius(1);

    vtkNew<vtkCylinderSource> body;
    body->SetHeight(14);
    body->SetResolution(100);
    body->SetRadius(1);

    vtkNew<vtkConeSource> engine1;
    engine1->SetDirection(0, 1, 0);
    engine1->SetHeight(8);
    engine1->SetResolution(100);
    engine1->SetRadius(0.7);

    vtkNew<vtkConeSource> engine2;
    engine2->SetDirection(0, 1, 0);
    engine2->SetHeight(8);
    engine2->SetResolution(100);
    engine2->SetRadius(0.7);

    vtkNew<vtkConeSource> engine3;
    engine3->SetDirection(0, 1, 0);
    engine3->SetHeight(8);
    engine3->SetResolution(100);
    engine3->SetRadius(0.7);

    vtkNew<vtkConeSource> engine4;
    engine4->SetDirection(0, 1, 0);
    engine4->SetHeight(8);
    engine4->SetResolution(100);
    engine4->SetRadius(0.7);
    //
    //Создаём актёров
    //
    vtkNew<vtkActor> headActor;
    headActor->SetPosition(0, 8.5, 0);
    headActor->GetProperty()->SetColor(1, 1, 1);

    vtkNew<vtkActor> bodyActor;
    bodyActor->GetProperty()->SetColor(1, 1, 1);

    vtkNew<vtkActor> engine1Actor;
    engine1Actor->SetPosition(1, -3.1, 0);
    engine1Actor->GetProperty()->SetColor(0.6, 0.6, 0.6);
    vtkNew<vtkActor> engine2Actor;
    engine2Actor->SetPosition(-1, -3.1, 0);
    engine2Actor->GetProperty()->SetColor(0.6, 0.6, 0.6);
    vtkNew<vtkActor> engine3Actor;
    engine3Actor->SetPosition(0, -3.1, 1);
    engine3Actor->GetProperty()->SetColor(0.6, 0.6, 0.6);
    vtkNew<vtkActor> engine4Actor;
    engine4Actor->SetPosition(0, -3.1, -1);
    engine4Actor->GetProperty()->SetColor(0.6, 0.6, 0.6);
    //
    //Создаём мэппер
    //
    vtkNew<vtkPolyDataMapper> headMapper;
    headMapper->SetInputConnection( head->GetOutputPort() );

    vtkNew<vtkPolyDataMapper> bodyMapper;
    bodyMapper->SetInputConnection( body->GetOutputPort() );

    vtkNew<vtkPolyDataMapper> engine1Mapper;
    engine1Mapper->SetInputConnection( engine1->GetOutputPort() );
    vtkNew<vtkPolyDataMapper> engine2Mapper;
    engine2Mapper->SetInputConnection( engine1->GetOutputPort() );
    vtkNew<vtkPolyDataMapper> engine3Mapper;
    engine3Mapper->SetInputConnection( engine1->GetOutputPort() );
    vtkNew<vtkPolyDataMapper> engine4Mapper;
    engine4Mapper->SetInputConnection( engine1->GetOutputPort() );
    //
    //Add Mapper to Actor
    //
    headActor->SetMapper( headMapper );

    bodyActor->SetMapper( bodyMapper );

    engine1Actor->SetMapper( engine1Mapper );
    engine2Actor->SetMapper( engine2Mapper );
    engine3Actor->SetMapper( engine3Mapper );
    engine4Actor->SetMapper( engine4Mapper );
    //
    //Add Actor to Renderer
    //
    vtkNew<vtkRenderer> renderer;
    renderer->AddActor( headActor );

    renderer->AddActor( bodyActor );

    renderer->AddActor( engine1Actor );
    renderer->AddActor( engine2Actor );
    renderer->AddActor( engine3Actor );
    renderer->AddActor( engine4Actor );
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
Lab1::~Lab1()
{
    delete ui;
}


