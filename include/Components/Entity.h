#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <memory>
#include <vector>
#include "Component.h"
#include "TransformComponent.h"

class Entity
{
public:
    Entity();
    Entity(std::string _name);

    //all entities are going to have a transform - world game objects by default (doesn't exist in the component vector but the get and set component are designed to handle this.)
    Component* Transform = new TransformComponent();

    //search for the component of "type" return a pointer to it and return a null ptr if it couldn't be found. Returning a pointer? maybe not being deleted
    Component *getComponent(ComponentType::EnumType _type);

    //pass an existing component to the vector
    void addComponent(Component *referenceComponent);
    //create a new component of component type on the vector
    void addComponent(ComponentType::EnumType _type);


    //update the entity's components
    void update(){Transform->update(); for(auto& c: components) c->update();}

//private:
    //vector of all this entities components (usually private but for NGLScene::InitializeGL std::cout<<MyEntity.components.size(); made public
    std::vector<std::shared_ptr<Component>> components;


protected:
    std::string m_name;//non unique name of the entity instance
};

#endif // ENTITY_H
