#include "Entity.h"
#include "RigidBodyComponent.h"
#include "GeometryComponent.h"

Entity::Entity(){
    m_name = "new_Game_Entity";
}

Entity::Entity(std::string _name){
    m_name = _name;
}

//used for adding a "new" components which is created via the default constructors (this seems very messy - consider revision)
void Entity::addComponent(ComponentType::EnumType _type){
    if(_type == ComponentType::Transform){
        std::cout<< m_name + " already has a component of type Transform";
    }else{
        if(getComponent(_type) == nullptr){ //if the component check returns null, the component doesn't exist (future proof multiple same type components distinguishing)
            switch(_type){
            case 0x00000001:
                components.push_back(std::shared_ptr<Component>(new RigidBodyComponent()));
                break;
            case 0x00000002:
                components.push_back(std::shared_ptr<Component>(new TransformComponent()));
                break;
            case 0x00000003:
                components.push_back(std::shared_ptr<Component>(new GeometryComponent()));
                break;
            }
        }else
            std::cout<< m_name + " already has a component of type " + typeid(_type).name();
    }
}

//copy existing component, shove to component list

void Entity::addComponent(Component* referenceComponent){
    if(referenceComponent->Type == ComponentType::Transform){
        std::cout<< m_name + " already has a component of type Transform";
    }else{
        if(getComponent(referenceComponent->Type) == nullptr){ //if the component check returns null, the doesn't exist (future proof multiple same type components distinguishing)
            components.push_back(std::shared_ptr<Component>(referenceComponent));//MESSY AND DANGEROUS MUST REVISE
        }else
            std::cout<< m_name + " already has a component of type " + typeid(referenceComponent->Type).name();
    }
}

Component *Entity::getComponent(ComponentType::EnumType _type){
    if(_type == ComponentType::Transform){
        return &*Transform;
    }else{
        for(auto& c : components){
            if(c->Type == _type){
                return &*c;
            }
        }
        return nullptr;
    }
}
