//
// GameEngine.hh for  in /home/hodali_g/Bomberman
//
// Made by gabriel hodali
// Login   <hodali_g@epitech.net>
//
// Started on  Sun Jun  7 16:15:26 2015 gabriel hodali
// Last update Sun Jun  7 17:02:21 2015 gabriel hodali
//

#ifndef _GAMEENGINE_HH_
# define _GAMEENGINE_HH_

#pragma once

/* INCLUDE */

#include <Game.hh>
#include <SdlContext.hh>
#include <vector>
#include "AObject.hh"
#include "Cube.hh"

/* CLASSE */

class   GameEngine : public gdl::Game
{
public:
  GameEngine();
  ~GameEngine();

  bool  initialize();
  bool  update();
  void  draw();

private:
  gdl::SdlContext       _context;
  gdl::Clock            _clock;
  gdl::Input            _input;
  gdl::BasicShader      _shader;
  std::vector<AObject*> _objects;
  Map			_map;
};

#endif /* _GAMEENGINE_HH_ */
