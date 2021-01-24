
//Подключение заголовочных файлов
#include "widget.h"
#include "ui_widget.h"

//Основной конструктор класса
Lab2::Lab2(QWidget *parent) : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this); //Установка виджета визуализации QVTKWidget
//Основной алгоритм

    //
    //Создаём источник данных
    //
    vtkNew<vtkSphereSource> sun;
    vtkNew<vtkSphereSource> mercury;
    vtkNew<vtkSphereSource> venus;
    vtkNew<vtkEarthSource> earth;
    vtkNew<vtkSphereSource> mars;
    vtkNew<vtkSphereSource> jupiter;
    vtkNew<vtkSphereSource> saturn;
    vtkNew<vtkDiskSource> ring;
    vtkNew<vtkSphereSource> uranus;
    vtkNew<vtkSphereSource> neptune;
    vtkNew<vtkSphereSource> pluto;
    sun->SetRadius(696.340);
    mercury->SetRadius(2.439);
    venus->SetRadius(6.051);
    earth->SetRadius(6.371);
    mars->SetRadius(3.389);
    jupiter->SetRadius(69.911);

    saturn->SetRadius(58.232);
    ring->SetInnerRadius(92);
    ring->SetOuterRadius(136.5);
    ring->SetCircumferentialResolution(100);

    uranus->SetRadius(25.362);
    neptune->SetRadius(24.622);
    pluto->SetRadius(1.188*10);

    //
    //Создаём актёров
    //
    vtkNew<vtkActor> sunActor;
    vtkNew<vtkActor> mercuryActor;
    vtkNew<vtkActor> venusActor;
    vtkNew<vtkActor> earthActor;
    vtkNew<vtkActor> marsActor;
    vtkNew<vtkActor> jupiterActor;
    vtkNew<vtkActor> saturnActor;
    vtkNew<vtkActor> ringActor;
    vtkNew<vtkActor> uranusActor;
    vtkNew<vtkActor> neptuneActor;
    vtkNew<vtkActor> plutoActor;
    sunActor->SetPosition(-696.340, 0, 0);
    mercuryActor->SetPosition(57.9, 0, 0);
    venusActor->SetPosition(108.2, 0, 0);
    earthActor->SetPosition(149.6, 0, 0);
    marsActor->SetPosition(227.9, 0, 0);
    jupiterActor->SetPosition(778.3, 0, 0);
    saturnActor->SetPosition(1427, 0, 0);
    ringActor->SetPosition(1427, 0, 0);
    uranusActor->SetPosition(2869.6, 0, 0);
    neptuneActor->SetPosition(4496.6, 0, 0);
    plutoActor->SetPosition(5900, 0, 0);
    //
    //Создаём мэппер
    //
    vtkNew<vtkPolyDataMapper> sunMapper;
    vtkNew<vtkPolyDataMapper> mercuryMapper;
    vtkNew<vtkPolyDataMapper> venusMapper;
    vtkNew<vtkPolyDataMapper> earthMapper;
    vtkNew<vtkPolyDataMapper> marsMapper;
    vtkNew<vtkPolyDataMapper> jupiterMapper;
    vtkNew<vtkPolyDataMapper> saturnMapper;
    vtkNew<vtkPolyDataMapper> ringMapper;
    vtkNew<vtkPolyDataMapper> uranusMapper;
    vtkNew<vtkPolyDataMapper> neptuneMapper;
    vtkNew<vtkPolyDataMapper> plutoMapper;
    sunMapper->SetInputConnection( sun->GetOutputPort() );
    mercuryMapper->SetInputConnection( mercury->GetOutputPort() );
    venusMapper->SetInputConnection( venus->GetOutputPort() );
    earthMapper->SetInputConnection( earth->GetOutputPort() );
    marsMapper->SetInputConnection( mars->GetOutputPort() );
    jupiterMapper->SetInputConnection( jupiter->GetOutputPort() );
    saturnMapper->SetInputConnection( saturn->GetOutputPort() );
    ringMapper->SetInputConnection( ring->GetOutputPort() );
    uranusMapper->SetInputConnection( uranus->GetOutputPort() );
    neptuneMapper->SetInputConnection( neptune->GetOutputPort() );
    plutoMapper->SetInputConnection( pluto->GetOutputPort() );

    //
    //Add Mapper to Actor
    //
    sunActor->SetMapper(sunMapper);
    mercuryActor->SetMapper( mercuryMapper );
    venusActor->SetMapper( venusMapper );
    earthActor->SetMapper( earthMapper );
    marsActor->SetMapper( marsMapper );
    jupiterActor->SetMapper( jupiterMapper );
    saturnActor->SetMapper( saturnMapper );
    ringActor->SetMapper( ringMapper );
    uranusActor->SetMapper( uranusMapper );
    neptuneActor->SetMapper( neptuneMapper );
    plutoActor->SetMapper( plutoMapper );

    earthActor->GetProperty()->SetColor(0, 1, 0);
    //
    //Add Actor to Renderer
    //
    vtkNew<vtkRenderer> renderer;
    renderer->AddActor( sunActor );
    renderer->AddActor( mercuryActor );
    renderer->AddActor( venusActor );
    renderer->AddActor( earthActor );
    renderer->AddActor( marsActor );
    renderer->AddActor( jupiterActor );
    renderer->AddActor( saturnActor );
    renderer->AddActor( ringActor );
    renderer->AddActor( uranusActor );
    renderer->AddActor( neptuneActor );
    renderer->AddActor( plutoActor );

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
Lab2::~Lab2()
{
    delete ui;
}

