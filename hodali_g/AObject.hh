//
// AObject.hh for  in /home/hodali_g/Bomberman
//
// Made by gabriel hodali
// Login   <hodali_g@epitech.net>
//
// Started on  Sun Jun  7 15:45:08 2015 gabriel hodali
// Last update Sun Jun  7 17:11:33 2015 gabriel hodali
//

#ifndef _AOBJECT_HH_
# define _AOBJECT_HH_

/* INCLUDE */
#include <Game.hh>
#include <Clock.hh>
#include <Input.hh>
#include <SdlContext.hh>
#include <Geometry.hh>
#include <Texture.hh>
#include <BasicShader.hh>
#include <Model.hh>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <iostream>

enum Type{nothing = 0, block = 1, breakable = 2, bomb = 3, player = 4, powerup = 5};

/* CLASSE */

class   AObject
{
public:
  AObject();
  virtual ~AObject();

  virtual bool  initialize();
  virtual void  update(gdl::Clock const& clock, gdl::Input &input);
  virtual void  draw(gdl::AShader &shader, gdl::Clock const& clock) = 0;

  void  translate(glm::vec3 const &v);
  void  rotate(glm::vec3 const &axis, float angle);
  void  scale(glm::vec3 const &scale);
  void	setPosition(glm::vec3 const &pos);
  void	setTexture(gdl::Texture &texture);
  void	setType(Type const &newType);

  glm::mat4     getTransformation();
  glm::vec3	getPosition()const;
  int		getPosX()const;
  int		getPosY()const;
protected:
  glm::vec3     _position;
  glm::vec3     _rotation;
  glm::vec3     _scale;
  Type		_type;

};

#endif /* _AOBJECT_HH_ */
