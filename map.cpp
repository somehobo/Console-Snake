#include "map.h"
#include<iostream>
#include<queue>
#include <experimental/random>
map::map(){
  //buidling the sides of the grid
  rows = sizeof(grid) / sizeof(grid[0]);
  cols = sizeof(grid[0]) / sizeof(char);
  for(int y = 0; y<cols; y++){
    for(int x = 0; x<rows; x++){

      grid[x][y] = ' ';
    }
  }
  cout<<"made it!"<<endl;
  for(int hor = 1; hor<rows-1; hor++){
    grid[hor][0] = '#';
    grid[hor][cols-1] = '#';
  }
  for(int vert = 0; vert<=cols-1; vert++){
    grid[0][vert] = '#';
    grid[rows-1][vert] = '#';
  }
  cout<<"done"<<endl;
  for(int y = 0; y<=cols-1; y++){
    for(int x = 0; x<=rows-1; x++){
      cout<<grid[x][y];
    }
    cout<<endl;
  }
  snake.push_back(*new Coordinates(rows/2,cols/2));
  generateFood();
}



void map::updateSnake(){
  int size = snake.size();
  grid[snake[0].m_x][snake[0].m_y] = 'x';
  for(int y = 0; y<=cols-1; y++){
    for(int x = 0; x<=rows-1; x++){
      cout<<grid[x][y];
    }
    cout<<endl;
  }
}

bool map::move(char direction){
  bool colision = false;
  int x = 0;
  int y = 0;
  if(direction == 'w'||direction == 'a'||direction == 's'||direction == 'd'){
    if(direction == 'w')
      y--;
    else if(direction == 'a')
      x--;
    else if(direction == 's')
      y++;
    else if(direction == 'd')
      x++;
    if((grid[snake[0].m_x+x][snake[0].m_y+y] != 'x')&&
        (grid[snake[0].m_x+x][snake[0].m_y+y] != '#')){
        if(grid[snake[0].m_x+x][snake[0].m_y+y] == '0'){
          generateFood();
        }else{
          grid[snake.back().m_x][snake.back().m_y] = ' ';
          snake.pop_back();
        }
      snake.insert(snake.begin(), Coordinates(snake[0].m_x+x, snake[0].m_y+y));
      colision = true;
    }
  }
  return colision;
}

void map::generateFood(){
  bool bPlacement = true;
  int randCol;
  int randRow;
  int tempCol = (sizeof(grid[0]) / sizeof(char));
  int tempRow = (sizeof(grid) / sizeof(grid[0]));
  while(bPlacement){
    randCol = std::experimental::fundamentals_v2::randint(1,24);
    randRow = std::experimental::fundamentals_v2::randint(1,12);
    if(grid[randCol][randRow] == 'x'){
      bPlacement = true;
    } else {
      bPlacement = false;
      }
    }
  grid[randCol][randRow] = '0';
}

void map::printList(){
  for(int i = 0; i<snake.size(); i++){
    cout<<"("<<snake[i].m_x<<", "<<snake[i].m_y<<")"<<endl;
  }
}
