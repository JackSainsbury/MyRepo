#include "GeometryComponent.h"

//set the type by default
GeometryComponent::GeometryComponent() : Component(ComponentType::Geometry){
}
//out for testing
void GeometryComponent::update(){
    std::cout<<"update geom \n";
}
