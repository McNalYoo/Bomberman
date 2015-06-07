//
// Map.hh for  in /home/hodali_g/Bomberman
//
// Made by gabriel hodali
// Login   <hodali_g@epitech.net>
//
// Started on  Sun Jun  7 16:06:38 2015 gabriel hodali
// Last update Sun Jun  7 17:12:38 2015 gabriel hodali
//
#ifndef _MAP_HH_
#define _MAP_HH_
#include <iostream>
#include <fstream>
#include "AObject.hh"

Class Map
{
public:
Map(int size);
Map(std::string const  &name);
~Map();

std::vector<AObject*> getMap();
AObject *getCase(const int, const int) const;
bool addObject(const int, const int, const type);
bool deleteObject(const int, const int);
private:
int			_size_x;
int			_size_y;
std::vector<AObject*>	_objects;
};
#endif
