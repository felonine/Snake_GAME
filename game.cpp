#include <iostream>
#include <iomanip>
#include "gameHider.h"
#include <vector>
#include <conio.h>
#include <ctime>
#include <synchapi.h>

void show_field(const std::vector<coords>& snake, coords& food) {
    char field[HEIGHT][WIDTH];
      for(int i = 0; i < HEIGHT; ++i) { 
        for(int j = 0; j < WIDTH; ++j) { 
            if(i == 0 || i == HEIGHT - 1 || j == 0 || j == WIDTH - 1) 
            field[i][j] = '#';
            else 
            field[i][j] = ' ';
        }
      }
      
      for(const auto& idx : snake) { 
        field[idx.coords::y][idx.coords::x] = 'o';
      }

     field[food.y][food.x] = '*';

      for(int i = 0; i < HEIGHT; ++i) { 
        for(int j = 0; j < WIDTH; ++j) { 
           std::cout << field[i][j];
        }
        std::cout << "\n";
      }
        //  for(const auto& i : field) { 
        //     for(const auto& j : i) { 
        //         std::cout << j ;
        //     }
        //     std::cout << std::endl;
        //  }
}

  void run(std::vector<coords>& snake, char dir, coords& food) {
             coords& head = snake.front();
        coords new_head = head;
         
                switch(dir) { 
                    case 'w':
                    case 'W':
                    new_head.y--;
                    break;
                    case 's':
                    case 'S':
                    new_head.y++;
                    break;
                    case 'a':
                    case 'A':
                    new_head.x--;
                    break;
                    case 'd':
                    case 'D':
                    new_head.x++;
                    break;
                    default:
                    break;
                }

          if(new_head.y < 1 || new_head.y >= HEIGHT - 1){
            std::cout << "game over, you went abroad" << "\n";
            exit(0);
          }
          if(new_head.x < 1 || new_head.x >= WIDTH - 1)
          {
            std::cout << "game over, you went abroad" << "\n";
            exit(0);
          }      
            if(new_head.y == food.y && new_head.x == food.x) {
              spawn_food(snake, food);
            } else {
              snake.pop_back();
            }  
             for(const auto& path : snake) { 
                        if(path.x == new_head.x && path.y == new_head.y) {        
                            std::cout <<std::endl << " _GAME OVER_ \n";
                            std::cout <<std::endl << " Collision with your body( \n";
                            exit(0); 
                        }
                       }
          
           snake.insert(snake.begin(), new_head);      
  }

  void spawn_food(std::vector<coords>& snake, coords& food) { 
      bool flag = true;
      do {
        flag = false;
       food.y = rand() % (HEIGHT - 2) + 1;
      food.x = rand() % (WIDTH - 2) + 1;
         for(const auto& s : snake) { 
          if(s.y == food.y && s.x == food.x){
          flag = true;
          break;
        }
          }
      }while(flag);
  }
   


int main() { 
    srand(time(nullptr));
    std::vector<coords> snake = { { WIDTH / 2, HEIGHT / 2}};
    coords food;
    char dir = 'W';
    spawn_food(snake, food);
    while(true) { 
  system("cls");
  show_field(snake, food);
      if(_kbhit()) {
        dir = _getch();
      }
      run(snake, dir, food);
    Sleep(170);
    }


    return 0;    
}
   