#include "GeometryComponent.h"

GeometryComponent::GeometryComponent() : Component(ComponentType::Geometry){
}

void GeometryComponent::update(){
    std::cout<<"update geom \n";
}
