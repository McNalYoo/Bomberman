//
// scoring.cpp for scoring in /home/mart_m/Personnel/cpp_bomberman
// 
// Made by Amaury Martineau
// Login   <mart_m@epitech.net>
// 
// Started on  Tue Jun  2 15:56:14 2015 Amaury Martineau
// Last update Sat Jun  6 16:54:36 2015 Amaury Martineau
//

#include "scoring.hpp"

int my_atoi(char const *s)
{
  int i;
  int n;

  n = 0;
  for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
    n = 10 * n + (s[i] - '0');
  return (n);
}

Scoring::Scoring()
{
  this->first = NULL;
}

Scoring::~Scoring()
{
  t_ranking	*first1;
  t_ranking	*tmp;
  std::ofstream	file;

  first1 = this->first;
  file.open("scoring", std::ofstream::out | std::ofstream::trunc);
  while (first1->next != NULL)
    {
      file << first1->player << "\n";
      file << first1->score << "\n";
      tmp = first1->next;
      first1 = tmp;
    }
  file.close();
  first1 = this->first;
  while (first1->next != NULL)
    {
      tmp = first1->next;
      delete(first1);
      first1 = tmp;
    }
}

void	Scoring::CreateList()
{
  std::ifstream		file;
  std::string		myline;
  t_ranking		*first1;
  t_ranking		*tmp;

  file.open("scoring");
  /*if (file.is_open() == false)
    throw myException ("Can't open the file scoring");
    else*/
  first1 = new(t_ranking);
  getline(file, myline, '\n');
  first1->player = myline;
  getline(file, myline, '\n');
  first1->score = my_atoi(myline.c_str());
  first1->next = NULL;
  this->first = first1;
  while(file.eof() != true)
    {
      tmp = new(t_ranking);
      getline(file, myline, '\n');
      tmp->player = myline;
      getline(file, myline, '\n');
      tmp->score = my_atoi(myline.c_str());
      tmp->next = NULL;
      first1->next = tmp;
      first1 = tmp;
    }
  file.close();
}

void	Scoring::DeleteLast()
{
  t_ranking             *first1;
  t_ranking             *tmp;

  first1 = this->first;
  while (first1->next->next != NULL)
    {
      tmp = first1->next;
      first1 = tmp;
    }
  delete(first1->next);
  first1->next = NULL;
}

int	Scoring::CheckRank(std::string PlayerName, int PlayerScore)
{
  t_ranking             *first1;
  t_ranking             *tmp;
  t_ranking		*tmp2;

  first1 = this->first;
  if (first1->score <= PlayerScore)
    {
      tmp = new(t_ranking);
      tmp->player = PlayerName;
      tmp->score = PlayerScore;
      tmp->next = first1;
      this->first = tmp;
      DeleteLast();
      return(0);
    }
  while (first1->next != NULL)
    {
      if (first1->next->score <= PlayerScore)
	{
	  tmp = new(t_ranking);
	  tmp->player = PlayerName;
	  tmp->score = PlayerScore;
	  tmp2 = first1->next;
	  tmp->next = tmp2;
	  first1->next = tmp;
	  DeleteLast();
	  return(0);
	}
      tmp = first1->next;
      first1 = tmp;
    }
  return(0);
}
