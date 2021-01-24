
#include "widget.h"
#include "ui_widget.h"
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkImageBlend.h>
#include <vtkImageChangeInformation.h>
#include <vtkPNGWriter.h>

Widget2::Widget2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

//    vtkSmartPointer<vtkImageActor> grenadeActor = vtkSmartPointer<vtkImageActor>::New();
//    vtkSmartPointer<vtkImageActor> explosionActor = vtkSmartPointer<vtkImageActor>::New();
    vtkSmartPointer<vtkImageActor> grenadeExplosion = vtkSmartPointer<vtkImageActor>::New();

    vtkSmartPointer<vtkPNGReader> grenadeReader = vtkSmartPointer<vtkPNGReader>::New();
    vtkSmartPointer<vtkPNGReader> explosionReader = vtkSmartPointer<vtkPNGReader>::New();

    grenadeReader->SetFileName("/home/artur/Qt_projects/ReadBMP/Grenade.png");
    explosionReader->SetFileName("/home/artur/Qt_projects/ReadBMP/Explosion.png");

//    grenadeActor->GetMapper()->SetInputConnection(grenadeReader->GetOutputPort());
//    explosionActor->GetMapper()->SetInputConnection(explosionReader->GetOutputPort());



//    vtkSmartPointer<vtkImageChangeInformation> changePortGrenade = vtkSmartPointer<vtkImageChangeInformation>::New();
//    changePortGrenade->SetInputConnection(grenadeReader->GetOutputPort());
//    changePortGrenade->CenterImageOn();
//    changePortGrenade->Update();

//    vtkSmartPointer<vtkImageChangeInformation> changePortExplosion = vtkSmartPointer<vtkImageChangeInformation>::New();
//    changePortExplosion->SetInputConnection(explosionReader->GetOutputPort());
//    changePortExplosion->CenterImageOn();
//    changePortExplosion->Update();

    vtkSmartPointer<vtkImageBlend> blend = vtkSmartPointer<vtkImageBlend>::New();
    blend->AddInputConnection(explosionReader->GetOutputPort());
    blend->AddInputConnection(grenadeReader->GetOutputPort());

//    blend->AddInputConnection(changePortExplosion->GetOutputPort());

//    grenadeExplosion->GetMapper()->SetInputData(blend->GetOutputPort());
    grenadeExplosion->GetMapper()->SetInputConnection(blend->GetOutputPort());

    //
    //Add Actor to Renderer
    //
    vtkSmartPointer<vtkRenderer> backRenderer = vtkSmartPointer<vtkRenderer>::New();
    backRenderer->AddActor( grenadeExplosion );
     //
    //Add Renderer to RenderWindow
    //
    vtkSmartPointer<vtkGenericOpenGLRenderWindow> backWindow = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
    backWindow->AddRenderer( backRenderer );
    //
    //Add RenderWindow to QVTKWigdet
    //     
    ui->qvtkWidget->SetRenderWindow( backWindow );
    ui->qvtkWidget->GetRenderWindow()->AddRenderer( backRenderer );

}

Widget2::~Widget2()
{
    delete ui;
}



