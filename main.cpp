#include<iostream>
#include<conio.h>
#include "map.h"

int main(){
  map game;
  char direction = 'w';

    while(true==true){
      if(kbhit()){
        char temp = getch();
        if((!(direction == 's'&&temp == 'w'))&&(!(direction == 'w'&&temp == 's'))
            &&(!(direction == 'a'&&temp == 'd'))&&(!(direction == 'd'&&temp == 'a'))){
              direction = temp;
          }
        }
      if(!game.move(direction))
        break; //if it detects a colision it kicks you out of the loop (game over)
      game.updateSnake();
      // game.printList();
      _sleep(200);
    }
    cout<<"you lost fucker"<<endl;
    return 0;

}
