#pragma once

#include "GameEngine/EntitySystem/Component.h"

namespace Game
{
    class Player2MovementComponent : public GameEngine::Component
    {
	float degrees = 90.0f;
    public:
        virtual void Update() override;
        virtual void OnAddToWorld() override;
    };
}