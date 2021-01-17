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
		AABBRect intersection;
		AABBRect myBox = GetWorldAABB();
		AABBRect colideBox = colComponent->GetWorldAABB();
		if (myBox.intersects(colideBox, intersection))
		{
			//sf::Vector2f pos = GetEntity()->GetPos();
			//if (intersection.width < intersection.height)
			//{
			//	if (myBox.left < colideBox.left)
			//		pos.x -= intersection.width;
			//	else
			//		pos.x += intersection.width;
			//}
			//else
			//{
			//	if (myBox.top < colideBox.top)
			//		pos.y -= intersection.height;
			//	else
			//		pos.y += intersection.height;
			//}

			float x = GetEntity()->GetPos().x;
			float y = GetEntity()->GetPos().y;

			float deltX = abs(x - 400);
			float deltY = abs(y - 400);
			//std::cout << x << std::endl;

			const float pi = 3.14159265358979323846;

			float deg = atan(x / y);
			deg = (deg * 180) / pi;
			float incidentDeg = 90 - GetEntity()->GetDeg();
			float diff = abs(deg - incidentDeg);
			float reflectDeg = 0.f;
			if (GetEntity()->GetDeg() < 90) {
				float incidentDeg = 90 - GetEntity()->GetDeg();
				float diff = abs(deg - incidentDeg);
				  reflectDeg = 180 + diff;
			}
			else if (GetEntity()->GetDeg() < 180) {
				float incidentDeg = GetEntity()->GetDeg() - 90;
				float diff = abs(deg - incidentDeg);
				 reflectDeg = diff;
			}
			else if (GetEntity()->GetDeg() < 270) {
				float incidentDeg = GetEntity()->GetDeg() - 180;
				float diff = abs(deg - incidentDeg);
				 reflectDeg = diff;
			}
			else {
				float incidentDeg = GetEntity()->GetDeg() - 270;
				float diff = abs(deg - incidentDeg);
				 reflectDeg = 180 + diff;
			}
			if (GetEntity()->GetPos().y > 700 && GetEntity()->GetPos().x > 400 && GetEntity()->GetPos().x < 800) {
				reflectDeg = 210;
			}
			if (GetEntity()->GetPos().y > 700 && GetEntity()->GetPos().x <= 400 && GetEntity()->GetPos().x > 0 ) {
				reflectDeg = 270;
			}
			if (GetEntity()->GetPos().y < 100 && GetEntity()->GetPos().x > 400 && GetEntity()->GetPos().x < 800) {
				reflectDeg = 120;
			}
			if (GetEntity()->GetPos().y < 100 && GetEntity()->GetPos().x <= 400 && GetEntity()->GetPos().x > 0) {
				reflectDeg = 70;
			}
			GetEntity()->SetDeg(reflectDeg);
		}
	}
}