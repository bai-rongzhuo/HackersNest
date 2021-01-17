#include "CollidablePhysicsComponent.h"
#include "Game/Components/BallMovementComponent.h"
#include "Game/Components/Player1MovementComponent.h"
#include "Game/Components/Player2MovementComponent.h"

#include "GameEngine/Util/CollisionManager.h"
#include "GameEngine/EntitySystem/Entity.h"
#include <iostream>
#include <cmath>
#include <vector>

using namespace GameEngine;

CollidablePhysicsComponent::CollidablePhysicsComponent()
{

}


CollidablePhysicsComponent::~CollidablePhysicsComponent()
{

}


void CollidablePhysicsComponent::OnAddToWorld()
{
	CollidableComponent::OnAddToWorld();
}


void CollidablePhysicsComponent::OnRemoveFromWorld()
{
	CollidableComponent::OnRemoveFromWorld();
}


void CollidablePhysicsComponent::Update()
{
	//For the time being just a simple intersection check that moves the entity out of all potential intersect boxes
	std::vector<CollidableComponent*>& collidables = CollisionManager::GetInstance()->GetCollidables();

	for (int a = 0; a < collidables.size(); ++a)
	{
		CollidableComponent* colComponent = collidables[a];
		if (colComponent == this)
			continue;

		const float pi = 3.14159265358979323846;

		sf::Vector2f pos = GetEntity()->GetPos();
		float angle = (pos.y - 400 || pos.x - 400) ? atan2(pos.x - 400, 400 - pos.y) * 180 / pi : 0; // errorproofing this if the ball ends up in the middle because atan2 throws errors in that case
		//also note the coords are rotated ccw 90 degrees to make existing angle coordinates easier to work with
		float distance = sqrt(pow(pos.y - 400, 2) + pow(pos.x - 400, 2));
		std::cout << angle << " " << distance << std::endl;
		//change these if dimensions change
		float circleRadius = 200;
		float ballRadius = 10;
		float bounceAngleFactor = 1; // increase to exaggerate the bounce angle
		if (distance >= circleRadius - ballRadius && distance <= circleRadius) {
			if (colComponent->GetEntity()->GetComponent< Game::Player1MovementComponent >() != nullptr) {
				float diff = colComponent->GetEntity()->GetComponent< Game::Player1MovementComponent >()->degrees + angle;
				if (diff >= -15 && diff <= 15) {
					// collision happens; let it bounce
					// positive diff means ccw bounce
					GetEntity()->GetComponent< Game::BallMovementComponent >()->degrees += diff * bounceAngleFactor; 
				}
			}

			if (colComponent->GetEntity()->GetComponent< Game::Player2MovementComponent >() != nullptr) {
				float diff = colComponent->GetEntity()->GetComponent< Game::Player2MovementComponent >()->degrees - angle;
				if (diff >= -15 && diff <= 15) {
					// collision happens; let it bounce
					// positive diff means cw bounce
					GetEntity()->GetComponent< Game::BallMovementComponent >()->degrees -= diff * bounceAngleFactor;
				}
			}
		}

		/*AABBRect intersection;
		AABBRect myBox = GetWorldAABB();
		AABBRect colideBox = colComponent->GetWorldAABB();
		if (myBox.intersects(colideBox, intersection))
		{
			sf::Vector2f pos = GetEntity()->GetPos();
			if (intersection.width < intersection.height)
			{
				if (myBox.left < colideBox.left)
					pos.x -= intersection.width;
				else
					pos.x += intersection.width;
			}
			else
			{
				if (myBox.top < colideBox.top)
					pos.y -= intersection.height;
				else
					pos.y += intersection.height;
			}

			GetEntity()->SetPos(pos);
		}*/
	}
}