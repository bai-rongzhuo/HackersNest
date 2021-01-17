#include "BallMovementComponent.h"

#include "GameEngine/GameEngineMain.h" //<-- Add this include to retrieve the delta time between frames

using namespace Game;

void BallMovementComponent::Update()
{
	Component::Update();

	//Grabs how much time has passed since last frame
	const float dt = GameEngine::GameEngineMain::GetTimeDelta();
	const float pi = 3.14159265358979323846;

	//By default the displacement is 0,0

	//The amount of speed that we will apply when input is received
	const float inputAmount = 100.0f;
	float hypotenuse = inputAmount * dt;

	float absDeg = degrees;
	if (degrees > 90 && degrees <= 180) {
		absDeg = 180 - degrees;
	}
	else if (degrees > 180 && degrees <= 270) {
		absDeg = degrees - 180;
	} 
	else if (degrees > 270) {
		absDeg = 360 - degrees;
	}

	sf::Vector2f displacement = { hypotenuse * cos(absDeg * pi / 180), hypotenuse * sin(absDeg * pi / 180) };
	    
	if (degrees <= 90) {
		displacement.y *= -1;
	}
	else if (degrees <= 180) {
		displacement.x *= -1;
		displacement.y *= -1;
	}
	else if (degrees <= 270) {
		displacement.x *= -1;
	}

	//Update the entity position
	GetEntity()->SetPos(GetEntity()->GetPos() + displacement);
}

void BallMovementComponent::OnAddToWorld() {}