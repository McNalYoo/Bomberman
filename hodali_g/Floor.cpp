//
// Floor.cpp for  in /home/hodali_g/Bomberman
//
// Made by gabriel hodali
// Login   <hodali_g@epitech.net>
//
// Started on  Sun Jun  7 16:01:57 2015 gabriel hodali
// Last update Sun Jun  7 17:07:44 2015 gabriel hodali
//
#include "Floor.hh"

Floor::Floor(const float width, const float height)
{
  _width = width;
  _height = height;
  _type = 0;
}
Floor::~Floor()
{
}

void	Floor::update(gdl::Clock const &clock, gdl::Input &input)
{
}

void	Floor::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  (void)clock;
  _texture.bind();
  _geometry.draw(shader, getTransformation(), GL_QUADS);
}

bool	Floor::initialize()
{
  if (_texture.load("./ressources/assets/floor.tga") == false)
    {
      std::cerr << "Cannot load the floor texture" << std::endl;
      return (false);
    }
  _geometry.setColor(glm::vec4(1, 1, 1, 1));
  _geometry.pushVertex(glm::vec3(_width, -0.5, 0));
  _geometry.pushVertex(glm::vec3(_width, -0.5, _height));
  _geometry.pushVertex(glm::vec3(0, -0.5, _height));
  _geometry.pushVertex(glm::vec3(0, -0.5, 0));
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));
  _geometry.build();
  return (true);
}

