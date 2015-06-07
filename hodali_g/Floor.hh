//
// Floor.hh for  in /home/hodali_g/Bomberman
//
// Made by gabriel hodali
// Login   <hodali_g@epitech.net>
//
// Started on  Sun Jun  7 15:58:30 2015 gabriel hodali
// Last update Sun Jun  7 17:07:21 2015 gabriel hodali
//

#ifndef _FLOOR_HH_
#define _FLOOR_HH_

#include "AObject.hh"

Class Floor: public AObject
{
 public:
  Floor(const float width, const float height);
  ~Floor();
  bool	initialize();
  void	update(gdl::Clock const &clock, gdl::Input &input);
  void	draw(gdl::AShader &shader, gdl::Clock const &clock);

 private:
  gdl::Geometry _geometry;
  gdl::Texture	_texture;
  float		_width;
  float		_height;
};

#endif /*!_FLOOR_HH_*/
