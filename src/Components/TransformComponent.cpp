#include "TransformComponent.h"

TransformComponent::TransformComponent() : Component(ComponentType::Transform){
    m_position = ngl::Vec3::zero(); //default pos
    m_rotation = ngl::Vec3::zero(); //default rot
    m_scale = ngl::Vec3::zero();    //default sca

}

//update this component
void TransformComponent::update(){
    std::cout<<"TRANSFORMUPDATE";
}

//Move transform by _delta Pos
void TransformComponent::Translate(ngl::Vec3 _Dt_pos){
    m_position += _Dt_pos;
}

//Move transform by _delta Rot
void TransformComponent::Rotate(ngl::Vec3 _Dt_rot){
    m_rotation += _Dt_rot;
}

//Move transform by _delta Sca
void TransformComponent::Scale(ngl::Vec3 _Dt_sca){
    m_scale += _Dt_sca;
}
