//
// scoring.hpp for scoring in /home/mart_m/Personnel/cpp_bomberman
// 
// Made by Amaury Martineau
// Login   <mart_m@epitech.net>
// 
// Started on  Tue Jun  2 16:00:03 2015 Amaury Martineau
// Last update Sat Jun  6 16:46:29 2015 Amaury Martineau
//

#ifndef _SCORING_HPP_
# define _SCORING_HPP_

#include <iostream>
#include <fstream>
#include <string>
#include <boost/lexical_cast.hpp>

typedef struct	s_ranking
{
  std::string	player;
  int		score;
  s_ranking	*next;
}		t_ranking;

class Scoring
{
public:
  Scoring();
  ~Scoring(); //lit la liste chainée et rempli le fichier puis delete la liste
  int		CheckRank(std::string PlayerName, int PlayerScore);
  void		DeleteLast();
  void		CreateList();
private:
  t_ranking	*first;
};

#endif /*_SCORING_HPP_*/
 
