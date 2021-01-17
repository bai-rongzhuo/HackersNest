#include "Player1MovementComponent.h"
#include <SFML/Window/Keyboard.hpp>   //<-- Add the keyboard include in order to get keyboard inputs
#include <math.h>  
#include "GameEngine/GameEngineMain.h" //<-- Add this include to retrieve the delta time between frames

using namespace Game;

void Player1MovementComponent::Update()
{
    Component::Update();

	const float pi = 3.14159265358979323846;

    //Grabs how much time has passed since last frame
    const float dt = GameEngine::GameEngineMain::GetTimeDelta();

    //By default the displacement is 0,0
	sf::Vector2f centre{ 400.f, 400.f };

    //The amount of speed that we will apply when input is received
    const float inputAmount = 100.0f;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
		degrees += inputAmount * dt;
		if (degrees > 165.f) {
			degrees = 165.f;
		}
	}

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
		degrees -= inputAmount * dt;
		if (degrees < 15.f) {
			degrees = 15.f;
		}
	}

	sf::Vector2f displacement = centre + sf::Vector2f{ 200 * -sin(degrees*pi / 180), 200 * cos(degrees*pi / 180) };
	//std::cout << displacement.x << " " << displacement.y << std::endl;

    //Update the entity position
    GetEntity()->SetPos(displacement);
	GetEntity()->SetRotation(90.f + degrees);
}

void Player1MovementComponent::OnAddToWorld() {}