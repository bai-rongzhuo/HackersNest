#pragma once

#include "GameEngine/EntitySystem/Component.h"

namespace Game
{
    class BallMovementComponent : public GameEngine::Component
    {
    public:
		float degrees = 0.0f;
        virtual void Update() override;
        virtual void OnAddToWorld() override;
    };
}
