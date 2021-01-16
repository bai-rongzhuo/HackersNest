#include "GameBoard.h"

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

	player_1->SetPos(sf::Vector2f(150.f, 300.f));
	player_1->SetSize(sf::Vector2f(10.f, 200.f));

	player_2->SetPos(sf::Vector2f(650.f, 300.f));
	player_2->SetSize(sf::Vector2f(10.f, 200.f));

	circle->SetPos(sf::Vector2f(400.f, 300.f));
	circle->SetSize(sf::Vector2f(200.f, 200.f));

	GameEngine::RenderComponent* render = static_cast<GameEngine::RenderComponent*>(player_1->AddComponent<GameEngine::RenderComponent>());
	GameEngine::RenderComponent* render2 = static_cast<GameEngine::RenderComponent*>(player_2->AddComponent<GameEngine::RenderComponent>());
	GameEngine::SpriteRenderComponent* render3 = circle->AddComponent<GameEngine::SpriteRenderComponent>();

	render->SetFillColor(sf::Color::White);
	render3->SetTexture(GameEngine::eTexture::circle);

	player_1->AddComponent<Game::Player1MovementComponent>();
	player_2->AddComponent<Game::Player2MovementComponent>();
}
