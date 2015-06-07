//                                                                                                                                                                                                                                             
// AObject.cpp for bomberman in /home/huoyun_k/rendu/bomberman                                                                                                                                                                                 
//                                                                                                                                                                                                                                             
// Made by Kevin Huo Yung Kai                                                                                                                                                                                                                  
// Login   <huoyun_k@epitech.net>                                                                                                                                                                                                              
//                                                                                                                                                                                                                                             
// Started on  Sat Jun  6 22:13:24 2015 Kevin Huo Yung Kai                                                                                                                                                                                     
// Last update Sat Jun  6 22:56:23 2015 Kevin Huo Yung Kai                                                                                                                                                                                     
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

void  AObject::translate(glm::vec3 const &v)
{
  _position += v;
}

void  AObject::rotate(glm::vec3 const &axis, float angle)
{
  _rotation += axis * angle;
}

void  AObject::scale(glm::vec3 const &scale)
{
  _scale *= scale;
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
