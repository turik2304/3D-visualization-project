
#include "widget.h"
#include "ui_widget.h"
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkImageBlend.h>
#include <vtkImageChangeInformation.h>
#include <vtkJPEGReader.h>
#include <vtkImageShiftScale.h>
#include <vtkImageCast.h>
#include <vtkPNGWriter.h>

Widget3::Widget3(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    vtkSmartPointer<vtkImageActor> imageActor = vtkSmartPointer<vtkImageActor>::New();

    vtkSmartPointer<vtkJPEGReader> imageReader = vtkSmartPointer<vtkJPEGReader>::New();

    imageReader->SetFileName("/home/artur/Qt_projects/ReadBMP/index.jpeg");

    imageActor->GetMapper()->SetInputConnection(imageReader->GetOutputPort());

    vtkSmartPointer<vtkImageShiftScale> shiftScaleFilter = vtkSmartPointer<vtkImageShiftScale>::New();
    shiftScaleFilter->SetOutputScalarTypeToUnsignedChar();
    shiftScaleFilter->SetInputConnection(imageReader->GetOutputPort());
    shiftScaleFilter->SetShift(0.5);
    shiftScaleFilter->SetScale(1);
    shiftScaleFilter->Update();

    imageActor->GetMapper()->SetInputConnection(shiftScaleFilter->GetOutputPort());

    vtkSmartPointer<vtkImageCast> castFilter = vtkSmartPointer<vtkImageCast>::New();
    castFilter->SetOutputScalarTypeToUnsignedChar();
    castFilter->SetInputConnection(shiftScaleFilter->GetOutputPort());
    castFilter->Update();

    vtkSmartPointer<vtkPNGWriter> writer = vtkSmartPointer<vtkPNGWriter>::New();
    writer->SetFileName("out.png");
    writer->SetInputConnection(castFilter->GetOutputPort());
    writer->Write();

    //
    //Add Actor to Renderer
    //
    vtkSmartPointer<vtkRenderer> backRenderer = vtkSmartPointer<vtkRenderer>::New();
    backRenderer->AddActor(imageActor);
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

Widget3::~Widget3()
{
    delete ui;
}

