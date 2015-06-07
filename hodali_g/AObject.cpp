//
// AObject.cpp for  in /home/hodali_g/Bomberman
//
// Made by gabriel hodali
// Login   <hodali_g@epitech.net>
//
// Started on  Sun Jun  7 15:43:32 2015 gabriel hodali
// Last update Sun Jun  7 16:51:19 2015 gabriel hodali
//

#include "AObject.hh"

AObject::AObject() : _position(0, 0, 0), _rotation(0, 0, 0), _scale(1, 1, 1)
{
}

AObject::~AObject()
{
}

bool    AObject::initialize()
{
  return (true);
}

void    AObject::update(gdl::Clock const& clock, gdl::Input &input)
{
}

void	AObject::translate(glm::vec3 const &v)
{
  _position += v;
}

void	AObject::rotate(glm::vec3 const &axis, float angle)
{
  _rotation += axis * angle;
}

void	AObject::scale(glm::vec3 const &scale)
{
  _scale *= scale;
}

void	AObject::setPosition(glm::vec3 const &pos)
{
  _position = pos;
}

void	AObject::setTexture(gdl::Texture *texture)
{
  _texture = texture;
}

void	AObject::setType(Type const &newType)
{
  _type = newType;
}
glm::mat4       AObject::getTransformation()
{
  glm::mat4     transform(1);

  transform = glm::rotate(transform, _rotation.x, glm::vec3(1, 0, 0));
  transform = glm::rotate(transform, _rotation.y, glm::vec3(0, 1, 0));
  transform = glm::rotate(transform, _rotation.z, glm::vec3(0, 0, 1));

  transform = glm::translate(transform, _position);

  transform = glm::scale(transform, _scale);
  return (transform);
}

glm::vec3	AObject::getPosition()const
{
  return _position;
}

int		AObject::getPosX()const
{
  return _position.x;
}

int             AObject::getPosY()const
{
  return _position.z;
}
