/*                                                                                                                                                                                                                                             
** main.cpp for bomberman in /home/huoyun_k/rendu/bomberman                                                                                                                                                                                    
**                                                                                                                                                                                                                                             
** Made by Kévin Huo Yung Kai                                                                                                                                                                                                                  
** Login   <huoyun_k@epitech.net>                                                                                                                                                                                                              
**                                                                                                                                                                                                                                             
** Started on  Wed May 20 16:40:14 2015 Kévin Huo Yung Kai                                                                                                                                                                                     
// Last update Sat Jun  6 22:53:11 2015 Kevin Huo Yung Kai                                                                                                                                                                                     
*/

#include <cstdlib>

#include "GameEngine.hh"

int     main()
{
  GameEngine    engine;

  if (engine.initialize() == false)
    return (EXIT_FAILURE);
  while (engine.update() == true)
    engine.draw();
  return (EXIT_SUCCESS);
