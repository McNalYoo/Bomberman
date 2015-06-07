//                                                                                                                                                                                                                                             
// GameEngine.cpp for bomberman in /home/huoyun_k/rendu/bomberman                                                                                                                                                                              
//                                                                                                                                                                                                                                             
// Made by Kevin Huo Yung Kai                                                                                                                                                                                                                  
// Login   <huoyun_k@epitech.net>                                                                                                                                                                                                              
//                                                                                                                                                                                                                                             
// Started on  Sat Jun  6 22:16:31 2015 Kevin Huo Yung Kai                                                                                                                                                                                     
// Last update Sat Jun  6 22:21:16 2015 Kevin Huo Yung Kai                                                                                                                                                                                     
//                                                                                                                                                                                                                                             

#include "GameEngine.hh"

GameEngine::GameEngine()
{
}

GameEngine::~GameEngine()
{
  for (size_t i = 0; i < _objects.size(); ++i)
    delete _objects[i];
}

bool    GameEngine::initialize()
{
  if (!_context.start(800, 600, "My bomberman!"))
    return (false);
  glEnable(GL_DEPTH_TEST);
  if (!_shader.load("./LibBomberman_linux_x64/shaders/basic.fp", GL_FRAGMENT_SHADER)
      || !_shader.load("./LibBomberman_linux_x64/shaders/basic.vp", GL_VERTEX_SHADER)
      || !_shader.build())
    return (false);

  glm::mat4   projection;
  glm::mat4   transformation;

  projection = glm::perspective(60.0f, 800.0f / 600.0f, 0.1f, 100.0f);
  transformation = glm::lookAt(glm::vec3(0, 10, -30), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));

  _shader.bind();
  _shader.setUniform("view", transformation);
  _shader.setUniform("projection", projection);

  AObject     *cube = new Cube();

  if (cube->initialize() == false)
    return (false);
  _objects.push_back(cube);

  return (true);
}

bool    GameEngine::update()
{
  if (_input.getKey(SDLK_ESCAPE) || _input.getInput(SDL_QUIT))
    return (false);
  _context.updateClock(_clock);
  _context.updateInputs(_input);

  for (size_t i = 0; i < _objects.size(); ++i)
    _objects[i]->update(_clock, _input);
  return (true);
}

void    GameEngine::draw()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  _shader.bind();
  for (size_t i = 0; i < _objects.size(); ++i)
    _objects[i]->draw(_shader, _clock);

  _context.flush();
}
