//
// Parser.hpp for Parser.hpp in /home/jabbar_y/rendu/PSU_2016_zappy/includes
// 
// Made by Jabbari Yassir
// Login   <jabbar_y@epitech.net>
// 
// Started on  Mon Jun 26 14:04:36 2017 Jabbari Yassir
// Last update Wed Jun 28 13:43:46 2017 Eric Deschodt
//

#ifndef PARSER_HPP
#define PARSER_HPP
# include "Player.hpp"
# include "SocketConnection.hpp"

class                   Parser
{
public:
  
  Parser(SocketConnection *socketConnection);
  ~Parser();
  void connectToServer(std::string const &buffer);
  void launchCommand(std::string const &buffer);
  void setMapSize(std::string const &buffer);
  void setConnected(bool const &buffer);
  bool const &getConnected();
  std::string const &getBuffer();
  std::pair<int, int> const &getMapSize();
  void setMap(std::string const &buffer);
  std::vector<tile> const &getMap();
  void setTeamsName(std::string const &buffer);
  std::vector<std::string> const &getTeamsName();
  void setPlayers(std::string const &buffer);
  std::vector<Player> const &getPlayers();
  void setPlayerPos(std::string const &buffer);
  void setPlayerForcedOut(std::string const &buffer);
  void setBroadcast(std::string const &buffer);
  Player const &getPlayerBroadcast();
  std::string const &getMessageBroadcast();
  void setLaunchIncantation(std::string const &buffer);
  std::vector<Player> const &getLaunchIncantation();
  bool const &getIncantationInProgress();
  bool const &getIncantationSuccess();
  void setIncantationStatus(std::string const &buffer);
  void setLaidEgg(std::string const &buffer);
  void setThrowRessources(std::string const &buffer);
  void setAddRessources(std::string const &buffer);
  void setDeathPlayer(std::string const &buffer);
  bool const &getDeathPlayer();
  void setLaidEggByPlayer(std::string const &buffer);
  void setHatchEgg(std::string const &buffer);
  void setConnectedHatchEgg(std::string const &buffer);
  void setTime(std::string const &buffer);
  float const &getTime();
  std::string const &getWinner(std::string const &buffer);
  void setInv(std::string const &buffer);
  void setLevel(std::string const &buffer);
  
private:
  std::pair<int, int>		mapSize;
  bool				connected;
  std::vector<tile>		map;
  std::vector<std::string>	teamsName;
  std::vector<Player>		players;
  Player			playerBroadcast;
  std::string			messageBroadcast;
  std::vector<Player>		incantation;
  std::pair<int, int>		coorIncantation;
  bool				incantationInProgress;
  bool				incantationSuccess;
  bool				deathPlayer;
  float				time;
  SocketConnection		*socketConnection;

};

typedef void (Parser::*Command)(std::string const &);

#endif // PARSER_HPP
