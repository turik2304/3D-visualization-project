
#include <iostream>
#include "widget.h"
#include "ui_widget.h"
//#include <vtkChartXY.h>
//#include <vtkTable.h>
//#include <vtkPlot.h>
#include <vtkFloatArray.h>
//#include <vtkContextView.h>
#include <vtkContextScene.h>
//#include <vtkPen.h>

void print(const int &i) {
    std::cout << i << ' ';
}

Widget7::Widget7(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //--------------------------------------------------------------------------

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

    vtkNew<vtkGPUVolumeRayCastMapper> volumeMapper;
    volumeMapper->SetInputConnection(reader->GetOutputPort());

    vtkNew<vtkVolume> volume;
    volume->SetMapper(volumeMapper);
    volume->SetProperty(volumeProperty);

    //--------------------------------------------------------------

    float tablee[255];
    volumeGradientOpacity->GetTable(0,255,255, tablee, 1);

    std::for_each(std::begin(tablee), std::end(tablee), print);

    vtkNew<vtkTable> table;
    table->AddColumn(vtkSmartPointer<vtkDoubleArray>::New());
    table->AddColumn(vtkSmartPointer<vtkDoubleArray>::New());
    table->GetColumn(0)->SetName("Density");
    table->GetColumn(1)->SetName("Opacity");

    int numberOfPoints = volumeGradientOpacity->GetSize();
    table->SetNumberOfRows(numberOfPoints);
    for(int i = 0; i < numberOfPoints; ++i)
    {
        table->SetValue(i, 0, i);
        table->SetValue(i, 1, i*i);
    }

    // Create chart, view and widget

    auto chart = vtkSmartPointer<vtkChartXY>::New();
    auto line = chart->AddPlot(vtkChart::LINE);
    line->SetInputData(table, 0, 1);

    chart->SetAutoSize(false);
    chart->SetSize(vtkRectf(0.0, 0.0, 320, 220));

    vtkNew<vtkContextActor> act;
    act->GetScene()->AddItem(chart);


    //
    //Add Actor to Renderer
    //
    vtkNew<vtkRenderer> renderer;
    renderer->AddActor(act);
    renderer->AddActor(volume);
    renderer->SetBackground(1,1,1);
 //   chartScene->SetRenderer(renderer);
    //
    //Add Renderer to RenderWindow
    //
  vtkNew<vtkGenericOpenGLRenderWindow> renderWindow;
 //   renderWindow->SetMultiSamples(4);
    renderWindow->AddRenderer( renderer );
    //
    //Add RenderWindow to QVTKWigdet
    //     
  //  view->SetInteractor(ui->qvtkWidget->GetInteractor());
    //view->SetRenderWindow(ui->qvtkWidget->GetRenderWindow());
    ui->qvtkWidget->SetRenderWindow( renderWindow );
}

Widget7::~Widget7()
{
    delete ui;
}


