//
// Player.cpp for Player in /home/jabbar_y/rendu/PSU_2016_zappy
// 
// Made by Jabbari Yassir
// Login   <jabbar_y@epitech.net>
// 
// Started on  Mon Jun 26 22:32:53 2017 Jabbari Yassir
// Last update Tue Jun 27 16:05:12 2017 Jabbari Yassir
//

#include "Player.hpp"

Player::Player()
{
  this->forcedOut = false;
  this->egg = false;
  this->connected = true;
}

Player::~Player()
{
}

void Player::setCoor(int x, int y)
{
  this->coor.first = x;
  this->coor.second = y;
}

std::pair<int, int> const &Player::getCoor()
{
  return (this->coor);
}

void Player::setOrientation(int const &orientation)
{
  this->orientation = orientation;
}

int const &Player::getOrientation()
{
  return (this->orientation);
}

void Player::setLevel(int const &level)
{
  this->level = level;
}

int const &Player::getLevel()
{
  return (this->level);
}

void Player::setTeamName(std::string const &teamName)
{
  this->teamName = teamName;
}

std::string const &Player::getTeamName()
{

  return (this->teamName);
}

void Player::setId(int const &id)
{
  this->id = id;
}

int const &Player::getId()
{
  return (this->id);
}

void Player::setForcedOut(bool const &forcedOut)
{
  this->forcedOut = forcedOut;
}

bool const &Player::getForcedOut()
{
  return (this->forcedOut);
}

void Player::setEgg(bool const &egg)
{
  this->egg = egg;
}

bool const &Player::getEgg()
{
  return (this->egg);
}

void Player::setInventory(tile const &inventory)
{
  this->inventory = inventory;
}

tile const &Player::getInventory()
{
  return (this->inventory);
}

void Player::removeItem(int idItem)
{
  idItem == 0 ? this->inventory.food-- : 0;
  idItem == 1 ? this->inventory.linemate-- : 0;
  idItem == 2 ? this->inventory.deraumere-- : 0;
  idItem == 3 ? this->inventory.sibur-- : 0;
  idItem == 4 ? this->inventory.mendiane-- : 0;
  idItem == 5 ? this->inventory.phiras-- : 0;
  idItem == 6 ? this->inventory.thystame-- : 0;
}

void Player::setItem(int idItem)
{
  idItem == 0 ? this->inventory.food++ : 0;
  idItem == 1 ? this->inventory.linemate++ : 0;
  idItem == 2 ? this->inventory.deraumere++ : 0;
  idItem == 3 ? this->inventory.sibur++ : 0;
  idItem == 4 ? this->inventory.mendiane++ : 0;
  idItem == 5 ? this->inventory.phiras++ : 0;
  idItem == 6 ? this->inventory.thystame++ : 0;
}

void Player::setConnected(bool const &connected)
{
  this->connected = connected;
}

bool const &Player::getConnected()
{
  return (this->connected);
}

void Player::setEggAgo(bool const &eggAgo)
{
  this->eggAgo = eggAgo;
}

bool const &Player::getEggAgo()
{
  return (this->eggAgo);
}
