//
// Cube.hh for  in /home/hodali_g/Bomberman
//
// Made by gabriel hodali
// Login   <hodali_g@epitech.net>
//
// Started on  Sun Jun  7 17:08:06 2015 gabriel hodali
// Last update Sun Jun  7 17:08:09 2015 gabriel hodali
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
