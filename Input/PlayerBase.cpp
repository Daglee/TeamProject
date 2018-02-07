#include "PlayerBase.h"




PlayerBase::PlayerBase()
{

}

PlayerBase::PlayerBase(std::vector<InputRecorder*> allRecorders)
{
	initializePlayers(allRecorders);
}

PlayerBase::~PlayerBase()
{
	//delete all players
	if (!connectedPlayers.empty())
		for each (auto it in connectedPlayers)
		{
			delete it.second;
		}
}

void PlayerBase::initializePlayers(std::vector<InputRecorder*> allRecorders)
{
	if (!connectedPlayers.empty())
	{
		for each (auto it in connectedPlayers)
		{
			delete it.second;
		}

		connectedPlayers.clear();
	}

	for each (InputRecorder* i in allRecorders)
	{
		addNewPlayer(i);
	}
}

Player* PlayerBase::addNewPlayer(InputRecorder* recorder)
{
	int playerID = generateNewID();
	Player* playerRef = new Player(playerID, recorder);
	connectedPlayers.emplace(std::make_pair<>(playerRef, recorder));
	players.push_back(playerRef);

	return playerRef;
}

void PlayerBase::removePlayer(int playerID)
{

	for (unsigned int i = 0; i < players.size(); ++i)
	{
		if (players[i]->getPlayerID() == playerID)
		{
			delete players[i];
			players.erase(players.begin() + i);
		}
	}
}

void PlayerBase::removePlayer(Player* playerRef)
{
	//todo 
}

int PlayerBase::generateNewID()
{
	if (connectedPlayers.empty())
	{
		return 0;
	}
	else
	{
		return players.size() + 1;
	}
}