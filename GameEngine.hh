//                                                                                                                                                                                                                                             
// GameEngine.hh for bomberman in /home/huoyun_k/rendu/bomberman                                                                                                                                                                               
//                                                                                                                                                                                                                                             
// Made by Kévin Huo Yung Kai                                                                                                                                                                                                                  
// Login   <huoyun_k@epitech.net>                                                                                                                                                                                                              
//                                                                                                                                                                                                                                             
// Started on  Wed May 27 18:42:49 2015 Kévin Huo Yung Kai                                                                                                                                                                                     
// Last update Sat Jun  6 22:55:03 2015 Kevin Huo Yung Kai                                                                                                                                                                                     
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
};

#endif /* _GAMEENGINE_HH_ */
