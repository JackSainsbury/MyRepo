#ifndef COMPONENT_H
#define COMPONENT_H

#include<iostream>
#include <typeinfo>

//enum type for ease of "addcomponent(ComponentyType::Type)
namespace ComponentType{
    enum EnumType
    {
        RigidBody = 0x00000001,
        Transform = 0x00000002,
        Geometry = 0x00000003

    };
}

//Virtual base class for all components
class Component
{
public:
    Component(ComponentType::EnumType _type); //constructed with type - from inherited class
    ComponentType::EnumType Type;
    bool isActive;//for later use disabling components

    virtual void update(){};//virtual update function for Entity update { for all components -> update }

    virtual ~Component(){}//virtual destructor
};

#endif // COMPONENT_H
