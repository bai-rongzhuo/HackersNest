#include "GameBoard.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "Game/Components/Player1MovementComponent.h"
#include "Game/Components/Player2MovementComponent.h"
#include "GameEngine/GameEngineMain.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h" 


using namespace Game;

GameBoard::GameBoard()
	:player_1(nullptr), player_2(nullptr), circle(nullptr)
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

	GameEngine::GameEngineMain::GetInstance()->AddEntity(player_1);
	GameEngine::GameEngineMain::GetInstance()->AddEntity(player_2);
	GameEngine::GameEngineMain::GetInstance()->AddEntity(circle);

	player_1->SetPos(sf::Vector2f(200.f, 300.f));
	//player_1->SetSize(sf::Vector2f(10.f, 105.f));
	player_1->SetRotation(0);

	player_2->SetPos(sf::Vector2f(600.f, 300.f));
	//player_2->SetSize(sf::Vector2f(10.f, 105.f));
	player_2->SetRotation(0);

	GameEngine::SpriteRenderComponent* render = static_cast<GameEngine::SpriteRenderComponent*>(player_1->AddComponent<GameEngine::SpriteRenderComponent>());
	GameEngine::SpriteRenderComponent* render2 = static_cast<GameEngine::SpriteRenderComponent*>(player_2->AddComponent<GameEngine::SpriteRenderComponent>());
	
	render->SetTexture(GameEngine::eTexture::Player1);  // <-- Assign the texture to this entity
	render2->SetTexture(GameEngine::eTexture::Player2);  // <-- Assign the texture to this entity

	render->SetFillColor(sf::Color::White);
	render3->SetTexture(GameEngine::eTexture::circle);

	player_1->AddComponent<Game::Player1MovementComponent>();
	player_2->AddComponent<Game::Player2MovementComponent>();
}
