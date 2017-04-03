#include "TransformComponent.h"

TransformComponent::TransformComponent() : Component(ComponentType::Transform){
}

void TransformComponent::update(){
    std::cout << "\n";
    std::cout << "TransformUpdate \n";
    std::cout << "\n";
}
