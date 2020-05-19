#ifndef MAP_H
#define MAP_H
#include<vector>
#include<conio.h>

using namespace std;

class map{
private:
  class Coordinates{
  public:
    Coordinates(int x, int y){m_x = x; m_y = y;};
    int m_x;
    int m_y;
  };
public:
  map();
  void updateSnake();
  bool move(char direction);
  void printList();
  void generateFood();
  char grid[26][14];
  int rows;
  int cols;
  vector<Coordinates> snake;
};
#endif
