//
// scoring.cpp for scoring in /home/mart_m/Personnel/cpp_bomberman
// 
// Made by Amaury Martineau
// Login   <mart_m@epitech.net>
// 
// Started on  Tue Jun  2 15:56:14 2015 Amaury Martineau
// Last update Thu Jun  4 14:18:47 2015 Amaury Martineau
//

#include "scoring.hpp"

Scoring::Scoring()
{
  this->first = NULL;
}

Scoring::~Scoring()
{
  t_ranking	*first1;
  t_ranking	*tmp;
  std::ofstream	file;

  first1 = this->first;/*
  while(first1->next != NULL)
    {
      std::cout << "Nom " << first1->player << " score:" << first1->score << std::endl;
      tmp = first1->next;
      first1 = tmp;
      }*/
  file.open("scoring", std::ofstream::out | std::ofstream::trunc);
  first1->player = "TRESH";
  while (first1->next != NULL)
    {
      file << first1->player << "\n";
      file << first1->score << "\n";
      tmp = first1->next;
      first1 = tmp;
    }
  file.close();
}

void	Scoring::CreateList()
{
  std::ifstream	file;
  std::string	myline;
  t_ranking	*first1;
  t_ranking	*tmp;

  file.open("scoring");
  /*if (file.is_open() == false)
    throw myException ("Can't open the file scoring");
    else*/
  first1 = new(t_ranking);
  getline(file, myline, '\n');
  first1->player = myline;
  getline(file, myline, '\n');
  first1->score = (int)myline;
  first1->next = NULL;
  this->first = first1;
  while(file.eof() != true)
    {
      tmp = new(t_ranking);
      getline(file, myline, '\n');
      tmp->player = myline;
      getline(file, myline, '\n');
      tmp->score = (int)myline;
      tmp->next = NULL;
      first1->next = tmp;
      first1 = tmp;
    }
  file.close();
}

int	main()
{
  Scoring	thescoring;

  thescoring.CreateList();
  return(0);
}

