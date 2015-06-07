//                                                                                                                                                                                                                                             
// Cube.hh for bomberman in /home/huoyun_k/rendu/bomberman                                                                                                                                                                                     
//                                                                                                                                                                                                                                             
// Made by Kévin Huo Yung Kai                                                                                                                                                                                                                  
// Login   <huoyun_k@epitech.net>                                                                                                                                                                                                              
//                                                                                                                                                                                                                                             
// Started on  Wed May 27 17:43:23 2015 Kévin Huo Yung Kai                                                                                                                                                                                     
// Last update Sat Jun  6 22:57:16 2015 Kevin Huo Yung Kai                                                                                                                                                                                     
//                                                                                                                                                                                                                                             

#ifndef _CUBE_HH_
# define _CUBE_HH_

#include <Texture.hh>
#include <Geometry.hh>
#include "AObject.hh"

class   Cube : public AObject
{
private:
  gdl::Texture  _texture;
  gdl::Geometry _geometry;
  float         _speed;

public:
  Cube();
  virtual ~Cube();

  virtual bool  initialize();
  virtual void  update(gdl::Clock const &clock, gdl::Input &input);
  virtual void  draw(gdl::AShader &shader, gdl::Clock const &clock);
};

#endif /* _CUBE_HH_ */
