#include <QMouseEvent>
#include <QGuiApplication>

#include "NGLScene.h"
#include <ngl/NGLInit.h>
#include <iostream>
#include "RigidBodyComponent.h"
#include "TransformComponent.h"
#include "GeometryComponent.h"
#include "Entity.h"

NGLScene::NGLScene()
{
    // re-size the widget to that of the parent (in this case the GLFrame passed in on construction)
    setTitle("100% original, certainly not Blank NGL");
}


NGLScene::~NGLScene()
{
    std::cout<<"Shutting down NGL, removing VAO's and Shaders\n";
}



void NGLScene::resizeGL(int _w , int _h)
{
    m_win.width  = static_cast<int>( _w * devicePixelRatio() );
    m_win.height = static_cast<int>( _h * devicePixelRatio() );
}


void NGLScene::initializeGL()
{
    // we need to initialise the NGL lib which will load all of the OpenGL functions, this must
    // be done once we have a valid GL context but before we call any GL commands. If we dont do
    // this everything will crash
    ngl::NGLInit::instance();
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);			   // Grey Background
    // enable depth testing for drawing
    glEnable(GL_DEPTH_TEST);
    // enable multisampling for smoother drawing
    glEnable(GL_MULTISAMPLE);


    //Begining of clusterbomb

    Entity myEntity("New Entity"); //create a new entity

    Component* myRB = new RigidBodyComponent();

    myEntity.addComponent(ComponentType::Transform); //attempt adding new TransformComponent by passing type to addComponent(ComponentType::EnumType)

    myEntity.addComponent(myRB); //attempt adding RigidBodyComponent to components vector by passing myRB pointer { base myRb = new derived(); }
    //does this method of dynamic polymorphism require a virtual cloning method or downcasting?

    myEntity.addComponent(ComponentType::Geometry); //attempt adding new GeometryComponent by passing type to addComponent(ComponentType::EnumType)

    //cerr -> when the program does bomb out (the std::cout<<) in Entity::Addcomponent (Entity.cpp) is called however adding a "new GeometryNode" as a Component shared_ptr kills it.

    //<pathetic lack of ability, with regards to string concatination>
    std::cout<<"\n\nComponents list is currently holding: ";
    std::cout<< myEntity.components.size();
    std::cout<<" components. \n\n";
    //</pathetic lack of ability, with regards to string concatination>

    //size should be 2 as Transform Component already exists though not as components[0].

    myEntity.update();
    //The virtual update cycling through the vector of shared pointers is working a charm,
    //issues arise when more heap-allocated member variable are added to a derived Component class (in this cas I'm trying GeometryComponent) betweem compilations


    //End of clusterbomb
}



void NGLScene::paintGL()
{
    // clear the screen and depth buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glViewport(0,0,m_win.width,m_win.height);
}

//----------------------------------------------------------------------------------------------------------------------

void NGLScene::keyPressEvent(QKeyEvent *_event)
{
    // this method is called every time the main window recives a key event.
    // we then switch on the key value and set the camera in the GLWindow
    switch (_event->key())
    {
    // escape key to quite
    case Qt::Key_Escape : QGuiApplication::exit(EXIT_SUCCESS); break;
    case Qt::Key_Space :
        m_win.spinXFace=0;
        m_win.spinYFace=0;
        m_modelPos.set(ngl::Vec3::zero());

        break;
    default : break;
    }
    // finally update the GLWindow and re-draw

    update();
}
