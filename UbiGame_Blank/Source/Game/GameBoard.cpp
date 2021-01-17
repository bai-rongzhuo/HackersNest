#include "GameBoard.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "Game/Components/Player1MovementComponent.h"
#include "Game/Components/Player2MovementComponent.h"
#include "Game/Components/BallMovementComponent.h"
#include "GameEngine/GameEngineMain.h"
#include "GameEngine/EntitySystem/Components/CollidableComponent.h"
#include "GameEngine/EntitySystem/Components/CollidablePhysicsComponent.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h" 


using namespace Game;

GameBoard::GameBoard()
	:player_1(nullptr), player_2(nullptr), circle(nullptr), ball(nullptr), count1(nullptr), count2(nullptr)
{
	CreatePlayers();
}


GameBoard::~GameBoard()
{

}


void GameBoard::Update()
{	
	
}

void Game::GameBoard::CreatePlayers()
{
	player_1 = new GameEngine::Entity();
	player_2 = new GameEngine::Entity();
	circle = new GameEngine::Entity();
	ball = new GameEngine::Entity();
	count1 = new GameEngine::Entity();
	count2 = new GameEngine::Entity();

	GameEngine::GameEngineMain::GetInstance()->AddEntity(player_1);
	GameEngine::GameEngineMain::GetInstance()->AddEntity(player_2);
	GameEngine::GameEngineMain::GetInstance()->AddEntity(circle);
	GameEngine::GameEngineMain::GetInstance()->AddEntity(ball);
	GameEngine::GameEngineMain::GetInstance()->AddEntity(count1);
	GameEngine::GameEngineMain::GetInstance()->AddEntity(count2);

	player_1->SetPos(sf::Vector2f(200.f, 400.f));
	player_1->SetSize(sf::Vector2f(10.f, 105.f));
	player_1->SetRotation(0);

	player_2->SetPos(sf::Vector2f(600.f, 400.f));
	player_2->SetSize(sf::Vector2f(10.f, 105.f));
	player_2->SetRotation(0);

	circle->SetPos(sf::Vector2f(400.f, 400.f));
	circle->SetSize(sf::Vector2f(800.f, 800.f));

	ball->SetPos(sf::Vector2f(400.f, 400.f));
	ball->SetSize(sf::Vector2f(20.f, 20.f));

	count1->SetPos(sf::Vector2f(200.f, 100.f));
	count1->SetSize(sf::Vector2f(41.f, 58.f));

	count2->SetPos(sf::Vector2f(600.f, 100.f));
	count2->SetSize(sf::Vector2f(41.f, 58.f));

	GameEngine::SpriteRenderComponent* render = static_cast<GameEngine::SpriteRenderComponent*>(player_1->AddComponent<GameEngine::SpriteRenderComponent>());
	GameEngine::SpriteRenderComponent* render2 = static_cast<GameEngine::SpriteRenderComponent*>(player_2->AddComponent<GameEngine::SpriteRenderComponent>());
	GameEngine::SpriteRenderComponent* render3 = circle->AddComponent<GameEngine::SpriteRenderComponent>();
	GameEngine::SpriteRenderComponent* render4 = static_cast<GameEngine::SpriteRenderComponent*>( ball->AddComponent<GameEngine::SpriteRenderComponent>());
	GameEngine::SpriteRenderComponent* render5 = static_cast<GameEngine::SpriteRenderComponent*>(count1->AddComponent<GameEngine::SpriteRenderComponent>());
	GameEngine::SpriteRenderComponent* render6 = static_cast<GameEngine::SpriteRenderComponent*>(count2->AddComponent<GameEngine::SpriteRenderComponent>());

	render->SetFillColor(sf::Color::Transparent);
	render->SetTexture(GameEngine::eTexture::Player1);

	// <-- Assign the texture to this entity
	render2->SetFillColor(sf::Color::Transparent);
	render2->SetTexture(GameEngine::eTexture::Player2);  // <-- Assign the texture to this entity

	render3->SetFillColor(sf::Color::Transparent);
	render3->SetTexture(GameEngine::eTexture::circle);
	render3->SetZLevel(-10);

	render4->SetFillColor(sf::Color::Transparent);
	render4->SetTexture(GameEngine::eTexture::ball);

	render5->SetFillColor(sf::Color::Transparent);
	render5->SetTexture(GameEngine::eTexture::count);

	render6->SetFillColor(sf::Color::Transparent);
	render6->SetTexture(GameEngine::eTexture::count);

	player_1->AddComponent<Game::Player1MovementComponent>();
	player_1 ->AddComponent<GameEngine::CollidableComponent>();

	player_2->AddComponent<Game::Player2MovementComponent>();
	player_2->AddComponent<GameEngine::CollidableComponent>();

	ball->AddComponent<Game::BallMovementComponent>();
	//ball->AddComponent<GameEngine::CollidableComponent>();
	ball->AddComponent<GameEngine::AnimationComponent>();
	ball->AddComponent<GameEngine::CollidablePhysicsComponent>();
}
