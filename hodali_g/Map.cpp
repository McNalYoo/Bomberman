//
// Map.cpp for  in /home/hodali_g/Bomberman
//
// Made by gabriel hodali
// Login   <hodali_g@epitech.net>
//
// Started on  Sun Jun  7 16:26:22 2015 gabriel hodali
// Last update Mon Jun  8 17:04:56 2015 gabriel hodali
//
#include "Map.hh"
#include <ctime>
#include <cstdlib>
#include <iostream>

Map::Map(std::string const &name) //rajouter le param Option pour config la map
{
  int x = 0;
  int y = 0;
  int size_x;
  int size_y;
  //trouver la taille en x et y + remplir une liste Type<int x, int y>

  while (y < _size_y)
    {
      while (x < _size_x)
	{
	  //utiliser addObject avec le x,y,type de la liste
	  x++;
	}
      x = 0;
      y++;
    }
  //placer les joueurs
}

Map::Map(int size = 21)
{
  int x = 0;
  int y = 0;
  std::srand(std::time(0));
  if (size < 4)
    size = 21;
  _size_x = size;
  _size_y = size;

  while (y < _size_y)
    {
      while (x < _size_x)
	{
	  if (y == 0 || y == size - 1)
	    {
	      AObject *newObj = new Cube();
	      newObj->setPosition(new glm::vec3(x, 0, y));
	      _objects.push_back(newObj);
	    }
	  else if (x == 0 || x == size - 1)
	    {
	      AObject *newObj = new Cube();
	      newObj->setPosition(new glm::vec3(x, 0, y));
	      _objects.push_back(newObj);
	    }
	  else
	    addRandomly(x, y);
	    //sinon creer aleatoirement un objet a telle position0
	  x++;
	}
      x = 0;
      y++;
    }
  //placer les joueurs
}

void	Map::addRandomly(const int x, const int y)
{
  int random = std::rand();
  if (random % 2 == 0)
    {
      AObject *newObj = new Cube();
      newObj->setPosition(new glm::vec3(x, 0, y));
      _objects.push_back(newObj);
    }
}

std::vector<AObject*>	Map::getMap()
{
  return _objects;
}

AObject*	getCase(const int x, const int y)const
{
  for (size_t i = 0; i < _objects.size(); ++i)
    {
      if (_objects[i].getPosX() == x && _objects[i].getPosY() == y)
	return _objects[i];
    }
  return null;
}

bool	Map::addObject(const int x, const int y, const Type newType)
{
  AObject *newObj;
  glm::vec3 newPos;
  newPos.x = x;
  newPos.z = y;
  newPos.y = 0;
  if (newObj->initialize() == false)
    return (false);
  newObj->translate(newPos);
  newObj->setType(newType);
  _objects.push_back(newObj);
  return (true);
}

bool	Map::deleteObject(const int x, const int y)
{
  for (size_t i = 0; i < _objects.size(); i++)
    {
      if (_objects[i].getPosX == x && _objects[i].getPosY == y)
	{
	  delete  _objects[i];
	  return (true);
	}
    }
  return (false);
}

Map::~Map()
{
  for (int i =0; i < _objects.size(); i++)
    delete _objects[i];
}
