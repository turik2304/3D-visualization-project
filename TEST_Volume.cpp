
#include "widget.h"
#include "ui_widget.h"

Widget8::Widget8(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    vtkSmartPointer<vtkBMPReader> reader = vtkSmartPointer<vtkBMPReader>::New();
    reader->SetFilePrefix("/home/artur/Qt_projects/ReadBMP/LampStack2/");
    reader->SetFilePattern("%s%d.bmp");
    reader->SetFileNameSliceOffset(1);
    reader->SetDataSpacing(100,100,50);
    reader->SetDataExtent(0,99,0,99,0,49);
    reader->Update();

    vtkNew<vtkContourFilter> skinExtractor;
    skinExtractor->SetInputConnection(reader->GetOutputPort());
 //   skinExtractor->SetValue(0, 0);
    skinExtractor->SetValue(0, 30);
   // skinExtractor->SetValue(1, 240);

    vtkNew<vtkPolyDataNormals> skinNormals;
    skinNormals->SetInputConnection(skinExtractor->GetOutputPort());
    skinNormals->SetFeatureAngle(60.0);

    vtkNew<vtkPolyDataMapper> skinMapper;
    skinMapper->SetInputConnection(skinNormals->GetOutputPort());
    skinMapper->ScalarVisibilityOff();

    vtkNew<vtkActor> skin;
    skin->SetMapper(skinMapper);
    skin->GetProperty()->SetColor(0, 1, 0);
    skin->SetPosition(99,0,0);

    vtkNew<vtkSTLReader> reader1;
    reader1->SetFileName("/home/artur/Qt_projects/ReadBMP/Lamp.stl");

    vtkNew<vtkPolyDataMapper> mapper1;
    mapper1->SetInputConnection(reader1->GetOutputPort());

    vtkNew<vtkActor> actor1;
    actor1->SetMapper(mapper1);
    actor1->GetProperty()->SetColor(0, 0, 1);
    actor1->SetPosition(0,0,0);

    vtkNew<vtkBooleanOperationPolyDataFilter> booleanOperation;
    booleanOperation->SetInputConnection(0, reader1->GetOutputPort() );
    booleanOperation->SetInputConnection(1, skin->GetMapper()->GetOutputPort() );
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
    vtkSmartPointer<vtkRenderer> backRenderer = vtkSmartPointer<vtkRenderer>::New();
    backRenderer->AddActor(skin);
    backRenderer->AddActor(actor1);
    backRenderer->AddActor(booleanOperationActor);
    backRenderer->SetBackground(1,1,1);
    //
    //Add Renderer to RenderWindow
    //
    vtkSmartPointer<vtkGenericOpenGLRenderWindow> backWindow = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
    backWindow->AddRenderer( backRenderer );
    //
    //Add RenderWindow to QVTKWigdet
    //
    ui->qvtkWidget->SetRenderWindow( backWindow );
}

Widget8::~Widget8()
{
    delete ui;
}




