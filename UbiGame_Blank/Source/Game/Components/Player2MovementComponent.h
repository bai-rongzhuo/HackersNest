#pragma once

#include "GameEngine/EntitySystem/Component.h"

namespace Game
{
    class Player2MovementComponent : public GameEngine::Component
    {
    public:
		float p2Deg = 90.0f;
        virtual void Update() override;
        virtual void OnAddToWorld() override;
    };
}