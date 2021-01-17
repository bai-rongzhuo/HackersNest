#include "BallMovementComponent.h"

#include "GameEngine/GameEngineMain.h" //<-- Add this include to retrieve the delta time between frames

using namespace Game;

void BallMovementComponent::Update()
{
	Component::Update();
	//if (collision == true) {
	//	degrees = 90;
	//}
	//collision = false;

	//Grabs how much time has passed since last frame
	const float dt = GameEngine::GameEngineMain::GetTimeDelta();
	const float pi = 3.14159265358979323846;

	//By default the displacement is 0,0

	//The amount of speed that we will apply when input is received
	const float inputAmount = 100.0f;
	float hypotenuse = inputAmount * dt;

	float absDeg = ballDegree;
	if (ballDegree > 90 && ballDegree <= 180) {
		absDeg = 180 - ballDegree;
	}
	else if (ballDegree > 180 && ballDegree <= 270) {
		absDeg = ballDegree - 180;
	} 
	else if (ballDegree > 270) {
		absDeg = 360 - ballDegree;
	}

	sf::Vector2f displacement = { hypotenuse * cos(absDeg * pi / 180), hypotenuse * sin(absDeg * pi / 180) };
	    
	if (ballDegree <= 90) {
		displacement.y *= -1;
	}
	else if (ballDegree <= 180) {
		displacement.x *= -1;
		displacement.y *= -1;
	}
	else if (ballDegree <= 270) {
		displacement.x *= -1;
	}

	//Update the entity position
	GetEntity()->SetPos(GetEntity()->GetPos() + displacement);
}

void BallMovementComponent::OnAddToWorld() {}