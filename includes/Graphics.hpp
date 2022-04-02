//
// Graphics.hpp for  in /home/descho_e/tek2/PSU_2016_zappy
// 
// Made by Eric Deschodt
// Login   <descho_e@epitech.net>
// 
// Started on  Tue Jun 27 11:11:23 2017 Eric Deschodt
// Last update Fri Jun 30 14:09:38 2017 Eric Deschodt
//

#ifndef			GRAPHICS
# define		GRAPHICS

# include		<chrono>
# include		<SFML/Graphics.hpp>
# include		"Parser.hpp"
# include		"SocketConnection.hpp"
# include 		"SocketReader.hpp"

enum class		Screen
  {
    ALL,
    PLAYERS_ONLY
  };

class			Graphics
{
private:
  sf::RenderWindow	_app;
  sf::Texture		*_back;
  sf::Texture		*_tile;
  sf::Texture		*_tile2;
  sf::Texture		*_sprites;
  Parser		*_parser;
  SocketConnection	*_socket;
  int			width;
  int			height;
  Screen		screen;
  SocketReader		*socketReader;
  size_t		logPos;

public:
  Graphics(Parser *parser, SocketConnection *socket, SocketReader *socketReader);
  ~Graphics();
  void			initWin();
  void			mainloop();
  int			getCommand();
  void			closeWin();
  void			clear();
  void			printArena();
  void			printTeams();
  void			printPlayers();
  int			findIdTeam(std::string team);
  sf::Color             findColorTeam(int id);
  void			printRessources();
  void			drawTextBorder(sf::Text text);
  void			printLog();
  void			update();

  void setMapSize(std::string const &buffer, sf::Text *text);
  void setMap(std::string const &buffer, sf::Text *text);
  void setTeamsName(std::string const &buffer, sf::Text *text);
  void setPlayers(std::string const &buffer, sf::Text *text);
  void setPlayerPos(std::string const &buffer, sf::Text *text);
  void setLevel(std::string const &buffer, sf::Text *text);
  void setInv(std::string const &buffer, sf::Text *text);
  void setPlayerForcedOut(std::string const &buffer, sf::Text *text);
  void setBroadcast(std::string const &buffer, sf::Text *text);
  void setLaidEgg(std::string const &buffer, sf::Text *text);
  void setThrowRessources(std::string const &buffer, sf::Text *text);
  void setAddRessources(std::string const &buffer, sf::Text *text);
  void setTime(std::string const &buffer, sf::Text *text);
  void setDeathPlayer(std::string const &buffer, sf::Text *text);
  void setStartIncant(std::string const &buffer, sf::Text *text);
  void setEndIncant(std::string const &buffer, sf::Text *text);
};

typedef void (Graphics::*LogCommand)(std::string const &, sf::Text *);

#endif
