//                                                                                                                                                                                                                                             
// AObject.hh for bomberman in /home/huoyun_k/rendu/bomberman                                                                                                                                                                                  
//                                                                                                                                                                                                                                             
// Made by Kevin Huo Yung Kai                                                                                                                                                                                                                  
// Login   <huoyun_k@epitech.net>                                                                                                                                                                                                              
//                                                                                                                                                                                                                                             
// Started on  Sat Jun  6 22:29:29 2015 Kevin Huo Yung Kai                                                                                                                                                                                     
// Last update Sat Jun  6 22:54:49 2015 Kevin Huo Yung Kai                                                                                                                                                                                     
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
  glm::mat4     getTransformation();

protected:
  glm::vec3     _position;
  glm::vec3     _rotation;
  glm::vec3     _scale;

};

#endif /* _AOBJECT_HH_ */
