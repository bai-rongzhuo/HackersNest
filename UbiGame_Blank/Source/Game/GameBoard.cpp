#include "GameBoard.h"

#include "Game/Components/Player1MovementComponent.h"
#include "Game/Components/Player2MovementComponent.h"
#include "GameEngine/GameEngineMain.h"


using namespace Game;

GameBoard::GameBoard()
	:player_1(nullptr), player_2(nullptr)
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
	GameEngine::GameEngineMain::GetInstance()->AddEntity(player_1);
	GameEngine::GameEngineMain::GetInstance()->AddEntity(player_2);

	player_1->SetPos(sf::Vector2f(200.f, 300.f));
	player_1->SetSize(sf::Vector2f(10.f, 200.f));

	player_2->SetPos(sf::Vector2f(600.f, 300.f));
	player_2->SetSize(sf::Vector2f(10.f, 200.f));

	GameEngine::RenderComponent* render = static_cast<GameEngine::RenderComponent*>(player_1->AddComponent<GameEngine::RenderComponent>());
	GameEngine::RenderComponent* render2 = static_cast<GameEngine::RenderComponent*>(player_2->AddComponent<GameEngine::RenderComponent>());

	render->SetFillColor(sf::Color::White);
	player_1->AddComponent<Game::Player1MovementComponent>();
	player_2->AddComponent<Game::Player2MovementComponent>();
}
