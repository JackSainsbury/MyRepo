#ifndef GEOMETRYCOMPONENT_H
#define GEOMETRYCOMPONENT_H
#include "Component.h"
#include <memory>
#include <ngl/Obj.h>

class GeometryComponent : public Component
{
public:
    GeometryComponent();
    void update() override;

    ~GeometryComponent(){std::cout<<"IN DERIVED DESTRUCTOR \n";}
};

#endif // GEOMETRY_COMPONENT_H
