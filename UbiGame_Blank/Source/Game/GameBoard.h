#pragma once
#include "GameEngine/EntitySystem/Entity.h"

#include <SFML/System/Vector2.hpp>
#include <vector>

namespace Game
{
	//Used for storing and controlling all game related entities, as well as providing an entry point for the "game" side of application	
	class PlayerEntity;	

	class GameBoard
	{
	public:
		GameBoard();
		virtual ~GameBoard();

		void Update();
		bool IsGameOver() { return false; }

	private:
		void CreatePlayer();          // <-- Added Function
		GameEngine::Entity* player1; // <-- Added Member
		GameEngine::Entity* player2; // <-- Added Member
		GameEngine::Entity* score1; // <-- Added Member
		GameEngine::Entity* score2; // <-- Added Member
		GameEngine::Entity* background; // <-- Added Member
	};
}

