//
// load_map.cpp for load_map in /home/mart_m/Personnel/Bomberman
//
// Made by Amaury Martineau
// Login   <mart_m@epitech.net>
//
// Started on  Sun Jun  7 11:56:13 2015 Amaury Martineau
// Last update Sun Jun  7 12:54:45 2015 Amaury Martineau
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int my_atoi(char const *s)
{
  int i;
  int n;

  n = 0;
  for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
    n = 10 * n + (s[i] - '0');
  return (n);
}


void	CheckMap(std::string file)
{
  std::string	myline;
  std::ifstream	myfile;
  int		size;

  myfile.open(file.c_str());
  /*if (file.is_open() == false)
    throw myException ("Can't load the map"); 
    else*/
  getline(myfile, myline, '\n');
  size = myline.length();
  while (myfile.eof() != true)
    {
      getline(myfile, myline, '\n');
      /*if (size != myline.length())
	throw myException ("Wrong Map");*/
    }
  myfile.close();
}

std::vector<int>	LoadMap(std::string myfile)
{
  size_t			pos;
  std::ifstream			file;
  std::string			line;
  std::string			token;
  std::vector<int>		map;

  CheckMap(myfile);
  file.open(myfile.c_str());
  while (file.eof() != true)
    {
      getline(file, line, '\n');
      while ((pos = line.find(' ')) != std::string::npos)
	{
	  token = line.substr(0, pos);
	  line.erase(0, pos + 1);
	  map.push_back(my_atoi(token.c_str()));
	}
    }
  file.close();
  return(map);
}
