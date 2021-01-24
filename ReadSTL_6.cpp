
#include "widget.h"
#include "ui_widget.h"

Widget6::Widget6(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    vtkNew<vtkSTLReader> reader1;
    vtkNew<vtkSTLReader> reader2;
    reader1->SetFileName("/home/artur/Qt_projects/ReadBMP/CubeOrig.stl");
    reader2->SetFileName("/home/artur/Qt_projects/ReadBMP/CubeBrok2.stl");

    vtkNew<vtkPolyDataMapper> mapper1;
    vtkNew<vtkPolyDataMapper> mapper2;
    mapper1->SetInputConnection(reader1->GetOutputPort());
    mapper2->SetInputConnection(reader2->GetOutputPort());

    vtkNew<vtkActor> actor1;
    actor1->SetMapper(mapper1);
    actor1->GetProperty()->SetColor(0, 0, 1);
    actor1->SetPosition(0,0,0);

    vtkNew<vtkActor> actor2;
    actor2->SetMapper(mapper2);
    actor2->GetProperty()->SetColor(0, 1, 0);
    actor2->SetPosition(12,0,0);

    vtkNew<vtkBooleanOperationPolyDataFilter> booleanOperation;
    booleanOperation->SetInputConnection(0, reader1->GetOutputPort() );
    booleanOperation->SetInputConnection(1, reader2->GetOutputPort() );
 //   booleanOperation->SetOperationToDifference();
  //  booleanOperation->SetReorientDifferenceCells(true);

    vtkNew<vtkPolyDataMapper> booleanOperationMapper;
    booleanOperationMapper->SetInputConnection( booleanOperation->GetOutputPort() );
    booleanOperationMapper->ScalarVisibilityOff();

    vtkNew<vtkActor> booleanOperationActor;
    booleanOperationActor->SetMapper( booleanOperationMapper );
    booleanOperationActor->GetProperty()->SetColor(1, 0, 1);
    booleanOperationActor->SetPosition(24,0,0);
    //
    //Add Actor to Renderer
    //
    vtkNew<vtkRenderer> renderer;
    renderer->AddActor(actor1);
    renderer->AddActor(actor2);
    renderer->AddActor(booleanOperationActor);
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

Widget6::~Widget6()
{
    delete ui;
}

