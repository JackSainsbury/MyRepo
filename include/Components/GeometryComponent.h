#ifndef GEOMETRYCOMPONENT_H
#define GEOMETRYCOMPONENT_H
#include "Component.h"
#include <memory>
#include <ngl/Obj.h>

class GeometryComponent : public Component
{
public:
    GeometryComponent();//constructor passes a component type back to Component by default
    void update() override;//override virtual update function

    ~GeometryComponent(){}//virtual destructor (though I believe it would be virtual anyway)

private:
    //if compiled currently - will run, after this, if more ptrs/std::strings/vectors are added, the project must be cleaned befor it can
    //recompile. Currently this "GeometryComponent" is only ever being created/called from NGLScene.cpp in the InitializeGL
    std::unique_ptr<ngl::Obj> m_mesh;//heap-allocated attribute - leak?
    std::unique_ptr<ngl::Obj> m_mesh2;//heap-allocated attribute - leak?
    std::unique_ptr<ngl::Obj> m_mesh3;//heap-allocated attribute - leak?
    std::unique_ptr<ngl::Obj> m_mesh4;//heap-allocated attribute - leak?
    std::unique_ptr<ngl::Obj> m_mesh5;//heap-allocated attribute - leak?
};

#endif // GEOMETRY_COMPONENT_H
