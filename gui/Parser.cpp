//
// Parser.cpp for parser in /home/jabbar_y/rendu/PSU_2016_zappy/gui
// 
// Made by Jabbari Yassir
// Login   <jabbar_y@epitech.net>
// 
// Started on  Mon Jun 26 13:53:50 2017 Jabbari Yassir
// Last update Fri Jun 30 17:20:54 2017 Eric Deschodt
//

#include "Parser.hpp"

Parser::Parser(SocketConnection *socketConnection)
{
  this->socketConnection = socketConnection;
  this->connected = false;
}

Parser::~Parser()
{
}

void Parser::connectToServer(std::string const &buffer)
{
  if (buffer == "WELCOME")
    {
      this->connected = true;
      this->socketConnection->_send("GRAPHIC\n");
    }
}

void Parser::launchCommand(std::string const &buffer)
{
  std::vector<std::string>			availableCommands =
   {
     "msz", "bct", "tna", "pnw", "ppo", "plv", "pin", "pex", "pbc", "pfk",
     "pdr", "pgt", "sgt", "pdi"
   };
  std::vector<Command>	command =
   {
    &Parser::setMapSize, &Parser::setMap, &Parser::setTeamsName,
    &Parser::setPlayers, &Parser::setPlayerPos, &Parser::setLevel,
    &Parser::setInv, &Parser::setPlayerForcedOut, &Parser::setBroadcast,
    &Parser::setLaidEgg, &Parser::setThrowRessources,
    &Parser::setAddRessources, &Parser::setTime,
    &Parser::setDeathPlayer
   };
  if (buffer.empty() || buffer.size() < 3)
    return;
  
  for (size_t i = 0; i < availableCommands.size() ; i++)
    {
      if (availableCommands[i].substr(0, 3)
	  == buffer.substr(0, 3))
	{
	  (this->*(command[i]))(buffer);
	  break;
	}
    }

}

void Parser::setMapSize(std::string const &buffer)
{
  std::istringstream ss(buffer);
  std::string token;
  std::vector<std::string> vstring;
  
  while (std::getline(ss, token, ' '))
    vstring.push_back(token);
  this->mapSize.first = std::stoi(vstring.at(1));
  this->mapSize.second = std::stoi(vstring.at(2));
}

void Parser::setConnected(bool const &connected)
{
  this->connected = connected;
}

bool const &Parser::getConnected()
{
  return (this->connected);
}

std::pair<int, int> const &Parser::getMapSize()
{
  return (this->mapSize);
}

void Parser::setMap(std::string const &buffer)
{
  std::istringstream ss(buffer);
  std::string token;
  std::vector<std::string> vstring;
  tile currentTile;
  
  while (std::getline(ss, token, ' '))
    vstring.push_back(token);
  currentTile.x = std::stoi(vstring.at(1));
  currentTile.y = std::stoi(vstring.at(2));

  for (size_t i = 0 ; i < map.size() ; i++)
    {
      if (currentTile.x == map[i].x &&
	  currentTile.y == map[i].y)
	{
	  map[i].food = std::stoi(vstring.at(3));
	  map[i].linemate = std::stoi(vstring.at(4));
	  map[i].deraumere = std::stoi(vstring.at(5));
	  map[i].sibur = std::stoi(vstring.at(6));
	  map[i].mendiane = std::stoi(vstring.at(7));
	  map[i].phiras = std::stoi(vstring.at(8));
	  map[i].thystame = std::stoi(vstring.at(9));
	  return;
	}
    }
  currentTile.food = std::stoi(vstring.at(3));
  currentTile.linemate = std::stoi(vstring.at(4));
  currentTile.deraumere = std::stoi(vstring.at(5));
  currentTile.sibur = std::stoi(vstring.at(6));
  currentTile.mendiane = std::stoi(vstring.at(7));
  currentTile.phiras = std::stoi(vstring.at(8));
  currentTile.thystame = std::stoi(vstring.at(9));
  map.push_back(currentTile);
}

std::vector<tile> const &Parser::getMap()
{
  return (this->map);
}

void Parser::setTeamsName(std::string const &buffer)
{
  std::istringstream ss(buffer);
  std::string token;
  std::vector<std::string> vstring;
  
  while (std::getline(ss, token, ' '))
    vstring.push_back(token);
  this->teamsName.emplace_back(vstring.at(1));
}

std::vector<std::string> const &Parser::getTeamsName()
{
  return (this->teamsName);
}

void Parser::setPlayers(std::string const &buffer)
{
  Player player;
  std::istringstream ss(buffer);
  std::string token;
  std::vector<std::string> vstring;
  tile inventory;

  while (std::getline(ss, token, ' '))
    vstring.push_back(token);
  player.setId(std::stoi(vstring.at(1)));
  player.setCoor(std::stoi(vstring.at(2)), std::stoi(vstring.at(3)));
  player.setOrientation(std::stoi(vstring.at(4)));
  player.setLevel(std::stoi(vstring.at(5)));
  player.setTeamName(vstring.at(6));
  inventory.food = 0;
  inventory.linemate = 0;
  inventory.deraumere = 0;
  inventory.sibur = 0;
  inventory.mendiane = 0;
  inventory.phiras = 0;
  inventory.thystame = 0;
  player.setEgg(false);
  player.setInventory(inventory);
  this->players.push_back(player);
}
std::vector<Player> const &Parser::getPlayers()
{
  return (this->players);
}

void Parser::setPlayerPos(std::string const &buffer)
{
  (void) buffer;

 
  std::istringstream ss(buffer);
  std::string token;
  std::vector<std::string> vstring;
  
  while (std::getline(ss, token, ' '))
    vstring.push_back(token);
  for (size_t i = 0 ; i < players.size() ; i++)
    {
      if (players[i].getId() == std::stoi(vstring.at(1)))
  	{
	  players[i].setCoor(std::stoi(vstring.at(2)), std::stoi(vstring.at(3)));
	  players[i].setOrientation(std::stoi(vstring.at(4)));
  	  break;
  	}
    }
}

void Parser::setPlayerForcedOut(std::string const &buffer)
{
  std::istringstream ss(buffer);
  std::string token;
  std::vector<std::string> vstring;
  
  while (std::getline(ss, token, ' '))
    vstring.push_back(token);
  for (size_t i = 0 ; i < players.size() ; i++)
    {
      if (players[i].getId() == std::stoi(vstring.at(1)))
	{
	  players[i].setForcedOut(true);
	  break;
	}
    }
}

void Parser::setBroadcast(std::string const &buffer)
{
  std::istringstream ss(buffer);
  std::string token;
  std::vector<std::string> vstring;
  
  while (std::getline(ss, token, ' '))
    vstring.push_back(token);
  for (size_t i = 0 ; i < players.size() ; i++)
    {
      if (players[i].getId() == std::stoi(vstring.at(1)))
	{
	  this->playerBroadcast = this->players[i];
	  for (unsigned int it = 2; it != vstring.size(); ++it)
	    this->messageBroadcast = this->messageBroadcast + vstring[it];
	  break;
	}
    }
}

Player const &Parser::getPlayerBroadcast()
{
  return (this->playerBroadcast);
}

std::string const &Parser::getMessageBroadcast()
{
  return (this->messageBroadcast);
}

void Parser::setLaunchIncantation(std::string const &buffer)
{
  std::istringstream ss(buffer);
  std::string token;
  std::vector<std::string> vstring;
  
  while (std::getline(ss, token, ' '))
    vstring.push_back(token);
  this->coorIncantation.first = std::stoi(vstring.at(1));
  this->coorIncantation.second = std::stoi(vstring.at(2));
  for (unsigned int it = 4; it != vstring.size(); it++)
    {
      for (size_t i = 0 ; i < players.size() ; i++)
	{
	  if (players[i].getId() == std::stoi(vstring[it]))
	    {
	      this->players[i].setLevel(std::stoi(vstring.at(3)));
	      this->incantation.emplace_back(this->players[i]);
	      break;
	    }
	}
    }
  this->incantationInProgress = true;
}

std::vector<Player> const &Parser::getLaunchIncantation()
{
  return (this->incantation);
}

void Parser::setIncantationStatus(std::string const &buffer)
{
  std::istringstream ss(buffer);
  std::string token;
  std::vector<std::string> vstring;

  while (std::getline(ss, token, ' '))
    vstring.push_back(token);
  this->coorIncantation.first = std::stoi(vstring.at(1));
  this->coorIncantation.second = std::stoi(vstring.at(2));
  for (size_t i = 0 ; i < players.size() ; i++)
    this->players[i].setLevel((this->incantation[i].getLevel() + 1));
  for (size_t i = 0; i < players.size(); i++)
    {
      for (size_t j = 0; j < incantation.size(); j++)
	{
	  if (this->incantation[j].getId() == this->players[i].getId())
	    this->players[i].setLevel(this->incantation[j].getLevel());
	}
    }
  this->incantationInProgress = false;
  if (std::stoi(vstring.at(3)) == 0)
    this->incantationSuccess = false;
  else
    this->incantationSuccess = true;
}

void Parser::setLaidEgg(std::string const &buffer)
{
  std::istringstream ss(buffer);
  std::string token;
  std::vector<std::string> vstring;

  while (std::getline(ss, token, ' '))
    vstring.push_back(token);
  for (size_t i = 0 ; i < players.size() ; i++)
    {
      if (players[i].getId() == std::stoi(vstring.at(1)))
	{
	  players[i].setEgg(true);
	  break;
	}
    }
}

void Parser::setThrowRessources(std::string const &buffer)
{
  std::istringstream ss(buffer);
  std::string token;
  std::vector<std::string> vstring;
  
  while (std::getline(ss, token, ' '))
    vstring.push_back(token);
  for (size_t i = 0 ; i < players.size() ; i++)
    {
      if (players[i].getId() == std::stoi(vstring.at(1)))
	{
	  players[i].removeItem(std::stoi(vstring.at(2)));
	  break;
	}
    }
}

void Parser::setAddRessources(std::string const &buffer)
{
  std::istringstream ss(buffer);
  std::string token;
  std::vector<std::string> vstring;
  
  while (std::getline(ss, token, ' '))
    vstring.push_back(token);
  for (size_t i = 0 ; i < players.size() ; i++)
    {
      if (players[i].getId() == std::stoi(vstring.at(1)))
	{
	  this->players[i].setItem(std::stoi(vstring.at(2)));
	  break;
	}
    }
}

void Parser::setDeathPlayer(std::string const &buffer)
{
  std::istringstream ss(buffer);
  std::string token;
  std::vector<std::string> vstring;
  
  while (std::getline(ss, token, ' '))
    vstring.push_back(token);
  for (size_t i = 0 ; i < players.size() ; i++)
    {
      if (players[i].getId() == std::stoi(vstring.at(1)))
	{
	  this->players.erase(this->players.begin() + i);
	  this->deathPlayer = true;
	  break;
	}
    }
}

bool const &Parser::getDeathPlayer()
{
  return (this->deathPlayer);
}

void Parser::setLaidEggByPlayer(std::string const &buffer)
{
  std::istringstream ss(buffer);
  std::string token;
  std::vector<std::string> vstring;
  Player egg;
  tile inventory;
  
  while (std::getline(ss, token, ' '))
    vstring.push_back(token);
  for (size_t i = 0 ; i < players.size() ; i++)
    {
      if (players[i].getId() == std::stoi(vstring.at(2)))
	{
	  inventory.food = 0;
	  inventory.linemate = 0;
	  inventory.deraumere = 0;
	  inventory.sibur = 0;
	  inventory.mendiane = 0;
	  inventory.phiras = 0;
	  inventory.thystame = 0;
	  egg.setEgg(true);
	  egg.setConnected(false);
	  egg.setCoor(std::stoi(vstring.at(3)), std::stoi(vstring.at(4)));
	  egg.setLevel(1);
	  egg.setOrientation(this->players[i].getOrientation());
	  egg.setId(std::stoi(vstring.at(1)));
	  egg.setTeamName(this->players[i].getTeamName());
	  egg.setInventory(inventory);
	  this->players.push_back(egg);
	  break;
	}
    }
}

void Parser::setHatchEgg(std::string const &buffer)
{
  std::istringstream ss(buffer);
  std::string token;
  std::vector<std::string> vstring;
  int j;
  
  while (std::getline(ss, token, ' '))
    vstring.push_back(token);
  for (unsigned int i = 0; i != this->players.size(); ++i)
    {
      j = i;
      if (std::stoi(vstring.at(1)) == this->players.at(i).getId()
	  && this->players.at(i).getEgg() == true)
	break;
    }
  this->players.at(j).setEgg(false);
  this->players.at(j).setEggAgo(true);
}

void Parser::setConnectedHatchEgg(std::string const &buffer)
{
  std::istringstream ss(buffer);
  std::string token;
  std::vector<std::string> vstring;

  while (std::getline(ss, token, ' '))
    vstring.push_back(token);
  for (size_t i = 0 ; i < players.size() ; i++)
    {
      if (players[i].getId() == std::stoi(vstring.at(1))
	&& players[i].getEggAgo() == true)
	{
	  players[i].setConnected(true);
	  break;
	}
    }
}

void Parser::setTime(std::string const &buffer)
{
  std::istringstream ss(buffer);
  std::string token;
  std::vector<std::string> vstring;
  
  while (std::getline(ss, token, ' '))
    vstring.push_back(token);
  this->time = std::stof(vstring.at(1));
}

float const &Parser::getTime()
{
  return (this->time);
}

std::string const &Parser::getWinner(std::string const &buffer)
{
  std::istringstream ss(buffer);
  std::string token;
  std::vector<std::string> vstring;
  int j;
  
  while (std::getline(ss, token, ' '))
    vstring.push_back(token);
  for (unsigned int i = 0; i != this->teamsName.size(); i++)
    {
      j = i;
      if (this->teamsName.at(i).compare(vstring.at(1)) == 0)
	break;
    }
  return (this->teamsName.at(j));
}

void Parser::setInv(std::string const &buffer)
{
  std::istringstream ss(buffer);
  std::string token;
  std::vector<std::string> vstring;
  tile inventory;
  
  while (std::getline(ss, token, ' '))
    vstring.push_back(token);
  for (size_t i = 0 ; i < players.size() ; i++)
    {
      if (players[i].getId() == std::stoi(vstring.at(1)))
	{
	  inventory.food = std::stoi(vstring.at(2));
	  inventory.linemate = std::stoi(vstring.at(3));
	  inventory.deraumere = std::stoi(vstring.at(4));
	  inventory.sibur = std::stoi(vstring.at(5));
	  inventory.mendiane = std::stoi(vstring.at(6));
	  inventory.phiras = std::stoi(vstring.at(8));
	  inventory.thystame = std::stoi(vstring.at(9));
	  this->players[i].setInventory(inventory);
	  break;
	}
    }
}

void Parser::setLevel(std::string const &buffer)
{
  std::istringstream ss(buffer);
  std::string token;
  std::vector<std::string> vstring;

  while (std::getline(ss, token, ' '))
    vstring.push_back(token);
  for (size_t i = 0 ; i < players.size() ; i++)
    {
      if (players[i].getId() == std::stoi(vstring.at(2)))
	{
	  this->players[i].setLevel(std::stoi(vstring.at(2)));
	  break;
	}
    }
}
