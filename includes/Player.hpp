//
// Player.hpp for Player in /home/jabbar_y/rendu/PSU_2016_zappy
// 
// Made by Jabbari Yassir
// Login   <jabbar_y@epitech.net>
// 
// Started on  Mon Jun 26 22:20:48 2017 Jabbari Yassir
// Last update Tue Jun 27 16:03:34 2017 Jabbari Yassir
//

#ifndef PLAYER_HPP
#define PLAYER_HPP
# include <iostream>
# include <sstream>
# include <vector>
# include <iterator>

struct          tile
{
  size_t	food;
  size_t        linemate;
  size_t        deraumere;
  size_t        sibur;
  size_t        mendiane;
  size_t        phiras;
  size_t        thystame;
  int           x;
  int           y;
  size_t	nbPlayer;
};


class		Player
{
public:
  Player();
  ~Player();
  void setCoor(int x, int y);
  std::pair<int, int> const &getCoor();
  void setOrientation(int const &orientation);
  int const &getOrientation();
  void setLevel(int const &level);
  int const &getLevel();
  void setTeamName(std::string const &teamName);
  std::string const &getTeamName();
  void setId(int const &id);
  int const &getId();
  void setForcedOut(bool const &forcedOut);
  bool const &getForcedOut();
  void setEgg(bool const &egg);
  bool const &getEgg();
  void setInventory(tile const &inventory);
  tile const &getInventory();
  void removeItem(int idItem);
  void setItem(int idItem);
  void setConnected(bool const &connected);
  bool const &getConnected();
  void setEggAgo(bool const &eggAgo);
  bool const &getEggAgo();

  protected:
  std::pair<int, int> coor;
  int orientation;
  int level;
  std::string teamName;
  int id;
  bool forcedOut;
  bool egg;
  tile inventory;
  bool connected;
  bool eggAgo;
};

#endif // PLAYER_HPP
