#include "Player2MovementComponent.h"
#include <SFML/Window/Keyboard.hpp>   //<-- Add the keyboard include in order to get keyboard inputs

#include "GameEngine/GameEngineMain.h" //<-- Add this include to retrieve the delta time between frames

using namespace Game;

void Player2MovementComponent::Update()
{
	Component::Update();

	const float pi = 3.14159265358979323846;

	//Grabs how much time has passed since last frame
	const float dt = GameEngine::GameEngineMain::GetTimeDelta();

	//By default the displacement is 0,0
	sf::Vector2f centre{ 400.f, 400.f };

	//The amount of speed that we will apply when input is received
	const float inputAmount = 100.0f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		p2Deg += inputAmount * dt;
		if (p2Deg > 168.f) {
			p2Deg = 168.f;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		p2Deg -= inputAmount * dt;
		if (p2Deg < 13.f) {
			p2Deg = 13.f;
		}
	}

	sf::Vector2f displacement = centre + sf::Vector2f{ 250 * sin(p2Deg*pi / 180), 250 * cos(p2Deg*pi / 180) };

	//Update the entity position
	GetEntity()->SetPos(displacement);
	GetEntity()->SetRotation(90.f - p2Deg);
}

void Player2MovementComponent::OnAddToWorld() {}