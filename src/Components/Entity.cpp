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
    //if attempting to add of type Transform, return that transform already exists. (by default)
    if(_type == ComponentType::Transform){
        std::cout<< m_name + " already has a component of type Transform; it is a default Entity Component.";
    }else{
        //otherwise check if the incoming type is already in the components vector via get component (if null it doesn't exist)

        if(getComponent(_type) == nullptr){ //if the component check returns null, the component doesn't exist (future proof multiple same type components distinguishing)
            switch(_type){
            case 0x00000001:
                std::cout<<"adding new RigidBodyComponent";
                components.push_back(std::shared_ptr<Component>(new RigidBodyComponent()));//std::vector<std::shared_ptr<Component> components, pushed Component new RBC?
                break;
            case 0x00000002:
                std::cout<<"adding new TransformComponent";
                components.push_back(std::shared_ptr<Component>(new TransformComponent()));//consider review - make_shared?
                break;
            case 0x00000003:
                std::cout<<"adding new GeometryComponent";
                components.push_back(std::shared_ptr<Component>(new GeometryComponent()));//Issue exists here as new GeometryComponent has dynamic attributes (don't know why
                break;                                                                    //this is a problem; is this not allocated Base|Derived?
            }
        }else
            std::cout<< m_name + " already has a component of type " + typeid(_type).name();//component already exists so return this info (need to revise - this returns CompType)
    }
}

//pass exisingComponent add, messy messy messy. delete ptr?
void Entity::addComponent(Component* referenceComponent){
    if(referenceComponent->Type == ComponentType::Transform){ //similar default transform check
        std::cout<< m_name + " already has a component of type Transform";
    }else{
        if(getComponent(referenceComponent->Type) == nullptr){ //if the component check returns null, the doesn't exist (future proof multiple same type components distinguishing)
            components.push_back(std::shared_ptr<Component>(referenceComponent));//MESSY AND DANGEROUS MUST REVISE. std::shared_ptr<Component>(Component*) feels ghastly
        }else
            std::cout<< m_name + " already has a component of type " + typeid(referenceComponent->Type).name(); //similar other exists check
    }
}

//pass a type and check if component exists - return pointer so null can be tested or Component
Component *Entity::getComponent(ComponentType::EnumType _type){
    if(_type == ComponentType::Transform){
        return &*Transform;
    }else{
        for(auto& c : components){ //search vector<sharedptr<Comonent>> components
            if(c->Type == _type){
                return &*c;
            }
        }
        return nullptr;//component doesn't exist return null
    }
}
