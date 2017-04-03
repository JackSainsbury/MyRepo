#ifndef COMPONENT_H
#define COMPONENT_H

#include<iostream>
#include <typeinfo>

namespace ComponentType{
    enum EnumType
    {
        RigidBody = 0x00000001,
        Transform = 0x00000002,
        Geometry = 0x00000003

    };
}

class Component
{
public:
    Component(ComponentType::EnumType _type);
    ComponentType::EnumType Type;
    bool isActive;

    virtual void update(){};

    virtual ~Component(){std::cout<<"IN BASE DESTRUCTOR \n \n";}
};

#endif // COMPONENT_H
