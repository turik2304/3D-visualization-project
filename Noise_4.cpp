
#include "widget.h"
#include "ui_widget.h"

Widget4::Widget4(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    vtkNew<vtkBMPReader> imageReader;
    imageReader->SetFileName("/home/artur/Qt_projects/ReadBMP/SHUMNIY.bmp");

    vtkNew<vtkImageActor> originalActor;
    vtkNew<vtkImageActor> diffusionActor;
    vtkNew<vtkImageActor> gaussianActor;
    vtkNew<vtkImageActor> medianActor;
    //
    //Anisotripic Diffusion Filter
    //
    vtkNew<vtkImageAnisotropicDiffusion2D> diffusionFilter;
    diffusionFilter->SetInputConnection(imageReader->GetOutputPort());
    diffusionFilter->SetNumberOfIterations(3);
    diffusionFilter->SetDiffusionThreshold(35);
    //
    //Gaussian Filter
    //
    vtkNew<vtkImageGaussianSmooth> gaussianFilter;
    gaussianFilter->SetInputConnection(imageReader->GetOutputPort());
    gaussianFilter->SetDimensionality(2);
    gaussianFilter->SetStandardDeviations(1.1, 1.1);
    gaussianFilter->SetRadiusFactors(2, 2);
    //
    //Median Filter
    //
    vtkNew<vtkImageMedian3D> medianFilter;
    medianFilter->SetInputConnection(imageReader->GetOutputPort());
    medianFilter->SetKernelSize(3, 3, 1);
    //
    //Add filters to Actors and set positions
    //
    originalActor->GetMapper()->SetInputConnection(imageReader->GetOutputPort());
    diffusionActor->GetMapper()->SetInputConnection(diffusionFilter->GetOutputPort());
    diffusionActor->SetPosition(200,0,0);
    gaussianActor->GetMapper()->SetInputConnection(gaussianFilter->GetOutputPort());
    gaussianActor->SetPosition(400,0,0);
    medianActor->GetMapper()->SetInputConnection(medianFilter->GetOutputPort());
    medianActor->SetPosition(600,0,0);
    //
    //Add Actor to Renderer
    //
    vtkNew<vtkRenderer> renderer;
    renderer->AddActor(originalActor);
    renderer->AddActor(diffusionActor);
    renderer->AddActor(gaussianActor);
    renderer->AddActor(medianActor);
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

Widget4::~Widget4()
{
    delete ui;
}



