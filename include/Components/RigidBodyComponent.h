#ifndef RIGIDBODYCOMPONENT_H
#define RIGIDBODYCOMPONENT_H
#include "Component.h"

class RigidBodyComponent : public Component
{
public:
    RigidBodyComponent();
    void update() override;

    ~RigidBodyComponent() = default;

private:
};

#endif // RIGIDBODYCOMPONENT_H
