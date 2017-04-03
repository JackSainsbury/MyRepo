#include "RigidBodyComponent.h"

RigidBodyComponent::RigidBodyComponent() : Component(ComponentType::RigidBody){
}

void RigidBodyComponent::update(){
    std::cout << "\n";
    std::cout << "RigidBodyUpdate \n";
    std::cout << "\n";
}
