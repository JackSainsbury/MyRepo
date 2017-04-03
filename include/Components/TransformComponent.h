#ifndef TRANSFORMCOMPONENT_H
#define TRANSFORMCOMPONENT_H
#include "Component.h"

class TransformComponent : public Component
{
public:
    TransformComponent();
    void update() override;

    ~TransformComponent() = default;
};

#endif // TRANSFORMCOMPONENT_H
