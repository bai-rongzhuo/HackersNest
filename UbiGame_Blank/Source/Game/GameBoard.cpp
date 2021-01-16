#include "GameBoard.h"

#include "GameEngine/GameEngineMain.h"
#include "GameEngine/EntitySystem/PlayerMovementComponent.h"



using namespace Game;



GameBoard::GameBoard()
{
	CreatePlayer(); // <-- Create Entity on Constructor

}


GameBoard::~GameBoard()
{

}


void GameBoard::Update()
{	
	
}


void GameBoard::CreatePlayer()
{
	player1 = new GameEngine::Entity();                            // <-- Create new entity
	GameEngine::GameEngineMain::GetInstance()->AddEntity(player1); // <-- Add the entity to the engine
	player1->SetPos(sf::Vector2f(10.0f, 10.0f));            // <-- Give the position 10,10 to the entity
	player1->SetSize(sf::Vector2f(10.0f, 10.0f));           // <-- Give the size 10,10 to the entity
	GameEngine::RenderComponent* renderP1 = player1->AddComponent<GameEngine::RenderComponent>();   // <-- Add a RenderComponent to the entity
	renderP1->SetFillColor(sf::Color::Red);

	//Movement
	player1->AddComponent<Game::PlayerMovementComponent>();  // <-- Added the movement component to the player


	player2 = new GameEngine::Entity();                            // <-- Create new entity
	GameEngine::GameEngineMain::GetInstance()->AddEntity(player2); // <-- Add the entity to the engine
	score1 = new GameEngine::Entity();                            // <-- Create new entity
	GameEngine::GameEngineMain::GetInstance()->AddEntity(score1); // <-- Add the entity to the engine
	score2 = new GameEngine::Entity();                            // <-- Create new entity
	GameEngine::GameEngineMain::GetInstance()->AddEntity(score2); // <-- Add the entity to the engine
	background = new GameEngine::Entity();                            // <-- Create new entity
	GameEngine::GameEngineMain::GetInstance()->AddEntity(background); // <-- Add the entity to the engine
}
