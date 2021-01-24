
//Подключение заголовочных файлов
#include "widget.h"
#include "ui_widget.h"

//Основной конструктор класса
Lab3::Lab3(QWidget *parent) : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this); //Установка виджета визуализации QVTKWidget
//Основной алгоритм

    //
    //Создаём источник данных
    //
    vtkNew<vtkSphereSource> innerCore;
    vtkNew<vtkSphereSource> outerCore;
    vtkNew<vtkSphereSource> mantle;
    vtkNew<vtkSphereSource> earthCrust;
    vtkNew<vtkEarthSource> earthSurface;
    innerCore->SetRadius(1300);
    outerCore->SetRadius(3500);
    mantle->SetRadius(5537);
    earthCrust->SetRadius(6387);
    earthSurface->SetRadius(6388);

    innerCore->SetPhiResolution(100);
    innerCore->SetThetaResolution(100);

    outerCore->SetPhiResolution(100);
    outerCore->SetThetaResolution(100);
    outerCore->SetStartTheta(230);
    outerCore->SetEndTheta(160);

    mantle->SetPhiResolution(100);
    mantle->SetThetaResolution(100);
    mantle->SetStartTheta(230);
    mantle->SetEndTheta(160);

    earthCrust->SetPhiResolution(100);
    earthCrust->SetThetaResolution(100);
    earthCrust->SetStartTheta(230);
    earthCrust->SetEndTheta(160);

    earthSurface->SetOnRatio(1);
   // earthSurface->OutlineOff();
    //
    //Создаём актёров
    //
    vtkNew<vtkActor> innerCoreActor;
    vtkNew<vtkActor> outerCoreActor;
    vtkNew<vtkActor> mantleActor;
    vtkNew<vtkActor> earthCrustActor;
    vtkNew<vtkActor> earthSurfaceActor;

    earthSurfaceActor->GetProperty()->SetColor(0, 0.9, 0);

    earthCrustActor->GetProperty()->SetOpacity(0.3);
    earthCrustActor->GetProperty()->SetColor(0, 0, 1);

    mantleActor->GetProperty()->SetColor(1, 0.27, 0);

    outerCoreActor->GetProperty()->SetColor(1, 1, 0);

    innerCoreActor->GetProperty()->SetColor(1, 1, 0.82);
    //
    //Создаём мэппер
    //
    vtkNew<vtkPolyDataMapper> innerCoreMapper;
    vtkNew<vtkPolyDataMapper> outerCoreMapper;
    vtkNew<vtkPolyDataMapper> mantleMapper;
    vtkNew<vtkPolyDataMapper> earthCrustMapper;
    vtkNew<vtkPolyDataMapper> earthSurfaceMapper;
    innerCoreMapper->SetInputConnection( innerCore->GetOutputPort() );
    outerCoreMapper->SetInputConnection( outerCore->GetOutputPort() );
    mantleMapper->SetInputConnection( mantle->GetOutputPort() );
    earthCrustMapper->SetInputConnection( earthCrust->GetOutputPort() );
    earthSurfaceMapper->SetInputConnection( earthSurface->GetOutputPort() );
    //
    //Add Mapper to Actor
    //
    innerCoreActor->SetMapper(innerCoreMapper);
    outerCoreActor->SetMapper( outerCoreMapper );
    mantleActor->SetMapper( mantleMapper );
    earthCrustActor->SetMapper( earthCrustMapper );
    earthSurfaceActor->SetMapper( earthSurfaceMapper );


    //
    //Add Actor to Renderer
    //
    vtkNew<vtkRenderer> renderer;
    renderer->AddActor( innerCoreActor );
    renderer->AddActor( outerCoreActor );
    renderer->AddActor( mantleActor );
    renderer->AddActor( earthCrustActor );
    renderer->AddActor( earthSurfaceActor );

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
Lab3::~Lab3()
{
    delete ui;
}

