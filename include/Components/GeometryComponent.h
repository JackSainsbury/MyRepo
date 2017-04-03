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
    //recompile. See NGLScene::InitializeGL
    std::unique_ptr<ngl::Obj> m_mesh;//heap-allocated attribute - leak?

    //on 2nd compile, uncomment these nglObj pointers and attempt a recompile without cleaning project,
    //I am receiving "The program has unexpectedly finished."

    //std::unique_ptr<ngl::Obj> m_mesh2;//
    //std::unique_ptr<ngl::Obj> m_mesh3;//
    //std::vector<std::unique_ptr<ngl::Obj>> m_mesh_vector1;//
    //std::string m_String1//heap-allocated attribute - leak?
};

#endif // GEOMETRY_COMPONENT_H
