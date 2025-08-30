#ifndef GAME_H
#define GAME_H
#include <vector>

extern const int HEIGHT = 20;
extern const int WIDTH = 20;


struct coords{
int x,y;
};
  void show_field(const std::vector<coords>& snake, coords& food);
  void run(std::vector<coords>& snake, char dir, coords& food);
  void spawn_food(std::vector<coords>& snake, coords& food);

#endif