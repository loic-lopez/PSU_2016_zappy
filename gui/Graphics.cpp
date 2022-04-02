//
// Graphics.cpp for  in /home/descho_e/tek2/PSU_2016_zappy
// 
// Made by Eric Deschodt
// Login   <descho_e@epitech.net>
// 
// Started on  Tue Jun 27 11:17:03 2017 Eric Deschodt
// Last update Sat Jul  1 16:44:09 2017 Stanislas Deneubourg
//

#include "Graphics.hpp"

Graphics::Graphics(Parser *parser,
		   SocketConnection *socket, SocketReader *socketReader)
{
  _socket = socket;
  _parser = parser;
  height = _parser->getMapSize().second;
  width = _parser->getMapSize().first;
  screen = Screen::ALL;
  logPos = 0;
  this->socketReader = socketReader;
}

Graphics::~Graphics()
{

}

void		Graphics::initWin()
{
  _back = new sf::Texture();
  _back->loadFromFile("gui/back.png");
  _tile = new sf::Texture();
  _tile->loadFromFile("gui/tileLegend.png");
  _tile2 = new sf::Texture();
  _tile2->loadFromFile("gui/tile.png");
  _sprites = new sf::Texture();
  _sprites->loadFromFile("gui/sprite.png");
  _app.create(sf::VideoMode(1920, 1080), "Zappy", sf::Style::Fullscreen);
}

void		Graphics::closeWin()
{
  delete(_back);
  _app.close();
}

void		Graphics::clear()
{
  sf::Sprite    sprite;

  sprite.setTexture(*_back);
  sprite.setPosition(1080, 0);
  _app.clear();
  _app.draw(sprite);
}

void		Graphics::printArena()
{
  std::vector<tile> map = _parser->getMap();
  sf::Sprite    sprite;

  if (screen == Screen::PLAYERS_ONLY)
    sprite.setTexture(*_tile2);
  else
    sprite.setTexture(*_tile);
    
  sprite.setPosition(0, 0);
  for (size_t i = 0 ; i < map.size() ; i++)
    {

      sprite.setPosition((i % width) * (1080 / width),
      			 (i / width) * (1080 / height));
      sprite.setScale(1.0 / width, 1.0 / height);
      _app.draw(sprite);
    }
}

void		Graphics::drawTextBorder(sf::Text text)
{
  text.setFillColor(sf::Color::Black);
  text.setPosition(text.getPosition().x - 3.0,
		   text.getPosition().y - 3.0);
  _app.draw(text);
  text.setPosition(text.getPosition().x + 3.0,
		   text.getPosition().y);
  _app.draw(text);
  text.setPosition(text.getPosition().x + 3.0,
		   text.getPosition().y);
  _app.draw(text);
  text.setPosition(text.getPosition().x,
  		   text.getPosition().y + 3.0);
  _app.draw(text);
  text.setPosition(text.getPosition().x,
  		   text.getPosition().y + 3.0);
  _app.draw(text);
  text.setPosition(text.getPosition().x - 3.0,
  		   text.getPosition().y);
  _app.draw(text);
  text.setPosition(text.getPosition().x - 3.0,
  		   text.getPosition().y);
  _app.draw(text);
  text.setPosition(text.getPosition().x,
  		   text.getPosition().y - 3.0);
  _app.draw(text);
}

void		Graphics::printRessources()
{
  sf::Font      fontt;
  std::vector<tile> map = _parser->getMap();
  sf::Text      text;
  int		scale = 1080.0 / height / 10.0;

  fontt.loadFromFile("gui/berlin.ttf");
  text.setFont(fontt);
  text.setFillColor(sf::Color::White);
  text.setCharacterSize(scale);
  for (size_t i = 0 ; i < map.size() ; i++)
    {
      text.setString(std::to_string(map[i].food));
      text.setPosition(map[i].x * 1080.0 / width
		       + (1080.0 / width * 5.0 / 100)
		       +  (map[i].food < 10 ?
			   (((1080.0 / width) * 5.0) / 100) : 0),
		       map[i].y * 1080.0 / height
		       + (1080.0 / height * 82.0 / 100));
      drawTextBorder(text);
      _app.draw(text);

      text.setString(std::to_string(map[i].linemate));
      text.setPosition(map[i].x * 1080.0 / width
		       + (1080.0 / width * 25.0 / 100)
		       +  (map[i].linemate < 10 ?
			   (((1080.0 / width) * 5.0) / 100) : 0),
		       map[i].y * 1080.0 / height
		       + (1080.0 / height * 82.0 / 100));
      drawTextBorder(text);
      _app.draw(text);

      text.setString(std::to_string(map[i].deraumere));
      text.setPosition(map[i].x * 1080.0 / width
		       + (1080.0 / width * 46.0 / 100)
		       +  (map[i].deraumere < 10 ?
			   (((1080.0 / width) * 4.0) / 100) : 0),
		       map[i].y * 1080.0 / height
		       + (1080.0 / height * 82.0 / 100));
      drawTextBorder(text);
      _app.draw(text);

      text.setString(std::to_string(map[i].sibur));
      text.setPosition(map[i].x * 1080.0 / width
		       + (1080.0 / width * 66.0 / 100)
		       +  (map[i].sibur < 10 ?
			   (1080.0 / width * 2.0 / 100) : 0),
		       map[i].y * 1080.0 / height
		       + (1080.0 / height * 82.0 / 100));
      drawTextBorder(text);
      _app.draw(text);

      text.setString(std::to_string(map[i].mendiane));
      text.setPosition(map[i].x * 1080.0 / width
		       + (1080.0 / width * 86.0 / 100)
		       +  (map[i].mendiane < 10 ?
			   (1080.0 / width * 2.0 / 100) : 0),
		       map[i].y * 1080.0 / height
		       + (1080.0 / height * 82.0 / 100));
      drawTextBorder(text);
      _app.draw(text);

      text.setString(std::to_string(map[i].phiras));
      text.setPosition(map[i].x * 1080.0 / width
		       + (1080.0 / width * 86.0 / 100)
		       +  (map[i].phiras < 10 ?
			   (1080.0 / width * 2.0 / 100) : 0),
		       map[i].y * 1080.0 / height
		       + (1080.0 / height * 62.0 / 100));
      drawTextBorder(text);
      _app.draw(text);

      text.setString(std::to_string(map[i].thystame));
      text.setPosition(map[i].x * 1080.0 / width
		       + (1080.0 / width * 86.0 / 100)
		       +  (map[i].thystame < 10 ?
			   (1080.0 / width * 2.0 / 100) : 0),
		       map[i].y * 1080.0 / height
		       + (1080.0 / height * 42.0 / 100));
      drawTextBorder(text);
      _app.draw(text);
    }
}

void		Graphics::printTeams()
{
  sf::Font      fontt;
  std::vector<std::string>teams = _parser->getTeamsName();
  sf::Text      text;
  int		scale;

  scale = 50;
  fontt.loadFromFile("gui/berlin.ttf");
  text.setFont(fontt);
  text.setFillColor(sf::Color::White);
  text.setCharacterSize(scale);
  for (size_t i = 0 ; i < teams.size() ; i++)
    {
      text.setString(teams[i]);
      text.setPosition(1080 + 100, i * scale + 100);
      drawTextBorder(text);
      _app.draw(text);
    }
}

int		Graphics::findIdTeam(std::string team)
{
  std::vector<std::string>teams = _parser->getTeamsName();
  
  for (size_t i = 0 ; i < teams.size() ; i++)
    {
      if (team == teams[i])
	return (i);
    }
  return (-1);
}

sf::Color		Graphics::findColorTeam(int id)
{
  sf::Color		colors[6];

  colors[0] = sf::Color::Red;
  colors[1] = sf::Color::Blue;
  colors[2] = sf::Color::Yellow;
  colors[3] = sf::Color::Cyan;
  colors[4] = sf::Color::Magenta;
  colors[5] = sf::Color::Green;
  return (colors[id % 6] - sf::Color((id / 6) * 100,
				     (id / 6) * 100,
				     (id / 6) * 100, 0));
}

void		Graphics::printPlayers()
{
  std::vector<Player> players = _parser->getPlayers();
  sf::Sprite    sprite;
  std::vector<int> presence;

  for (int i = 0 ; i < width * height; i++)
    presence.push_back(0);
  sprite.setTexture(*_sprites);

  sprite.setScale(1080.0 / width / 5.0 / 50.0,
		  1080.0 / width / 5.0 / 50.0);

  for (size_t i = 0 ; i < players.size() ; i++)
    {
      int x = players[i].getCoor().first;
      int y = players[i].getCoor().second;
      if (screen == Screen::ALL)
	{
	  sprite.setScale(1080.0 / width / 5.0 / 50.0,
			  1080.0 / width / 5.0 / 50.0);
	}
      else
	{
	  sprite.setScale(1080.0 / width / 4.0 / 50.0,
			  1080.0 / width / 4.0 / 50.0);
	}
      sprite.setPosition(x * 1080 / width
			 + (presence[y * width + x]) % 4
			 * (50 * 1080.0 / width / 5.0 / 50.0),
			 y * 1080 / height
			 + (presence[y * width + x]) / 4
			 * (50 * 1080.0 / width / 5.0 / 50.0));
      presence[y * width + x]++;
      if (players[i].getOrientation() == 1)
	sprite.setTextureRect(sf::IntRect(0, 48 * 3, 48, 48));
      else if (players[i].getOrientation() == 2)
	sprite.setTextureRect(sf::IntRect(0, 48 * 2, 48, 48));
      else if (players[i].getOrientation() == 3)
	sprite.setTextureRect(sf::IntRect(0, 0, 48, 48));
      else if (players[i].getOrientation() == 4)
	sprite.setTextureRect(sf::IntRect(0, 48, 48, 48));
      sprite.setColor(findColorTeam(findIdTeam(players[i].getTeamName())));
      _app.draw(sprite);
    }
}

int		Graphics::getCommand()
{
  sf::Event	event;

  _app.pollEvent(event);
  return (event.key.code);
}


void Graphics::setMapSize(std::string const &buffer, sf::Text *text)
{
  std::istringstream ss(buffer);
  std::string token;
  std::vector<std::string> vstring;
   
  while (std::getline(ss, token, ' '))
    vstring.push_back(token); 
   text->setString("Map size : " + vstring.at(1) + " " + vstring.at(2));
}

void Graphics::setMap(std::string const &buffer, sf::Text *text)
{
  std::istringstream ss(buffer);
  std::string token;
  std::vector<std::string> vstring;
   
  while (std::getline(ss, token, ' '))
    vstring.push_back(token); 
  text->setString("Tile " + vstring.at(1) + " " + vstring.at(2));
}

void Graphics::setTeamsName(std::string const &buffer, sf::Text *text)
{
  std::istringstream ss(buffer);
  std::string token;
  std::vector<std::string> vstring;
   
  while (std::getline(ss, token, ' '))
    vstring.push_back(token); 
  text->setString("Team name : \"" + vstring.at(1) + "\"");
}

void Graphics::setPlayers(std::string const &buffer, sf::Text *text)
{
  std::istringstream ss(buffer);
  std::string token;
  std::vector<std::string> vstring;
   
  while (std::getline(ss, token, ' '))
    vstring.push_back(token); 
  text->setString("New Player on x:" + vstring.at(2) + " y:" + vstring.at(3)
		  + " : ID " + vstring.at(1) + " for Team \"" + vstring.at(6) + "\"");
}

void Graphics::setPlayerPos(std::string const &buffer, sf::Text *text)
{
  (void)buffer;
  (void)text;
}

void Graphics::setLevel(std::string const &buffer, sf::Text *text)
{
  (void)buffer;
  (void)text;
}

void Graphics::setInv(std::string const &buffer, sf::Text *text)
{
  (void)buffer; (void)text;
}

void Graphics::setPlayerForcedOut(std::string const &buffer, sf::Text *text)
{
  std::istringstream ss(buffer);
  std::string token;
  std::vector<std::string> vstring;
   
  while (std::getline(ss, token, ' '))
    vstring.push_back(token); 
  text->setString("Player " + vstring.at(1) + " ejects people");
}

void Graphics::setBroadcast(std::string const &buffer, sf::Text *text)
{
  std::istringstream ss(buffer);
  std::string token;
  std::vector<std::string> vstring;
  std::string tmp;

  while (std::getline(ss, token, ' '))
    vstring.push_back(token);
  text->setString("Player " + vstring.at(1) + " says : \"" + buffer.substr(6) + "\"");
}

void Graphics::setLaidEgg(std::string const &buffer, sf::Text *text)
{
  std::istringstream ss(buffer);
  std::string token;
  std::vector<std::string> vstring;

  while (std::getline(ss, token, ' '))
    vstring.push_back(token);
  text->setString("Player " + vstring.at(1) + " lays an egg");
}

void Graphics::setThrowRessources(std::string const &buffer, sf::Text *text)
{
  std::istringstream ss(buffer);
  std::string token;
  std::vector<std::string> vstring;
  std::vector<std::string>  ressources =
    {
      "food", "linemate", "deraumere", "sibur", "mendiane", "phiras", "thystame"
    };

  while (std::getline(ss, token, ' '))
    vstring.push_back(token);
  text->setString("Player " + vstring.at(1) + " puts " + ressources[std::stoi(vstring.at(2))] + " on the ground");
}

void Graphics::setAddRessources(std::string const &buffer, sf::Text *text)
{
  std::istringstream ss(buffer);
  std::string token;
  std::vector<std::string> vstring;
  std::vector<std::string>  ressources =
    {
      "food", "linemate", "deraumere", "sibur", "mendiane", "phiras", "thystame"
    };

  while (std::getline(ss, token, ' '))
    vstring.push_back(token);
  text->setString("Player " + vstring.at(1) + " takes " + ressources[std::stoi(vstring[2])]);
}

void Graphics::setTime(std::string const &buffer, sf::Text *text)
{
  std::istringstream ss(buffer);
  std::string token;
  std::vector<std::string> vstring;
  while (std::getline(ss, token, ' '))
    vstring.push_back(token);
  text->setString("Frequency of the server : " + vstring.at(1));
}

void	Graphics::setDeathPlayer(std::string const &buffer, sf::Text *text)
{
  std::istringstream ss(buffer);
  std::string token;
  std::vector<std::string> vstring;
  while (std::getline(ss, token, ' '))
    vstring.push_back(token);
  text->setString("Player " + vstring.at(1) + " is dead");
}

void	Graphics::setStartIncant(std::string const &buffer, sf::Text *text)
{
  std::istringstream ss(buffer);
  std::string token;
  std::vector<std::string> vstring;
  while (std::getline(ss, token, ' '))
    vstring.push_back(token);
  text->setString("Player " + vstring.at(4) + " starts incantation for lvl "
		  + vstring.at(3) + " on position x:" + vstring.at(1) + " y:" + vstring.at(2));
}

void	Graphics::setEndIncant(std::string const &buffer, sf::Text *text)
{
  std::istringstream ss(buffer);
  std::string token;
  std::vector<std::string> vstring;
  while (std::getline(ss, token, ' '))
    vstring.push_back(token);
  text->setString("Incantation on x:" + vstring.at(1) + " y:" + vstring.at(2)
		  + ((vstring.at(3) == "1") ? " succeded" : " failed") );
}

void	Graphics::printLog()
{
  std::vector<std::string> log = _socket->getLog();
  sf::Font      fontt;
  std::vector<tile> map = _parser->getMap();
  sf::Text      text;
  size_t	limit = 0;

  std::vector<std::string>                      availableCommands =
   {
     "msz", "bct", "tna", "pnw", "ppo", "plv", "pin", "pex", "pbc", "pfk",
     "pdr", "pgt", "sgt", "pdi", "pic", "pie"
   };
  std::vector<LogCommand>  command =
   {
    &Graphics::setMapSize, &Graphics::setMap, &Graphics::setTeamsName,
    &Graphics::setPlayers, &Graphics::setPlayerPos, &Graphics::setLevel,
    &Graphics::setInv, &Graphics::setPlayerForcedOut, &Graphics::setBroadcast,
    &Graphics::setLaidEgg, &Graphics::setThrowRessources,
    &Graphics::setAddRessources, &Graphics::setTime, &Graphics::setDeathPlayer,
    &Graphics::setStartIncant, &Graphics::setEndIncant
   };
  fontt.loadFromFile("gui/berlin.ttf");
  text.setFont(fontt);
  text.setFillColor(sf::Color::White);
  text.setCharacterSize(30);  
  for (size_t i = logPos ; i < log.size() ; i++)
    {
      text.setString("");
      for (size_t j = 0; j < availableCommands.size() ; j++)
	  {
	    if (availableCommands[j].substr(0, 3)
		== log[i].substr(0, 3))
	      {
		(this->*(command[j]))(log[i], &text);
		break;
	      }
	  }
      text.setPosition(1080 + 50, 1080 - 50 - (limit * 30));
      drawTextBorder(text);
      _app.draw(text);
      limit++;
      if (limit == 21)
      	break;
    }
}

void	Graphics::update()
{
  std::vector<Player> players = _parser->getPlayers();
  int sd = _socket->getSd();

  for (size_t i = 0 ; i < players.size(); i++)
    dprintf(sd, "ppo %d\n",  players[i].getId());
}

void	Graphics::mainloop()
{
  std::chrono::time_point<std::chrono::system_clock> start, end;
  int			cmd;
  int                   elapsed_seconds;
  bool			stop;

  stop = false;
  start = std::chrono::system_clock::now();
  initWin();
  cmd = getCommand();
  while (stop == false)
    {
      cmd = getCommand();
      if (cmd == sf::Keyboard::A)
	screen = Screen::ALL;
      else if (cmd == sf::Keyboard::Z)
	screen =  Screen::PLAYERS_ONLY;
      else if (cmd == sf::Keyboard::Escape)
	{
	  this->socketReader->stopSocketReader();
	  this->_socket->_send("QUIT");
	  stop = true;
	}
      else if (cmd == sf::Keyboard::PageUp && logPos < _socket->getLog().size())
	logPos++;
      else if (cmd == sf::Keyboard::PageDown && logPos > 0)
	logPos--;
      end = std::chrono::system_clock::now();
      elapsed_seconds =
	std::chrono::duration_cast<std::chrono::milliseconds>
	(end-start).count();
      if (elapsed_seconds >= (1000 / _parser->getTime()) * 3)
	{
	  start = end;
	  clear();
	  printArena();
	  printTeams();
	  printPlayers();
	  printLog();
	  if (screen == Screen::ALL)
	    printRessources();
	  _app.display();
	  update();
	}
    }
  closeWin();
}
