#include <QMouseEvent>
#include <QGuiApplication>

#include "NGLScene.h"
#include <ngl/NGLInit.h>
#include <iostream>
#include "RigidBodyComponent.h"
#include "TransformComponent.h"
#include "GeometryComponent.h"
#include "Entity.h"

#include <boost/fusion/include/map.hpp>
#include <boost/fusion/include/pair.hpp>
#include <boost/fusion/container/set.hpp>

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



    myEntity = new Entity("New Entity"); //create a new entity

    myEntity->addComponent<GeometryComponent>(); //attempt adding new TransformComponent by passing type to addComponent(ComponentType::EnumType) (fails)

    GeometryComponent* EntityGeo =  myEntity->getComponent<GeometryComponent>();

    EntityGeo->loadMesh("models/objectstooof.obj","models/winder (copy).tiff");

    EntityGeo->m_mesh->createVAO();

    myEntity->update();

}

void NGLScene::paintGL()
{
    // clear the screen and depth buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glViewport(0,0,m_win.width,m_win.height);

    myEntity->getComponent<GeometryComponent>()->m_mesh->draw();
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
