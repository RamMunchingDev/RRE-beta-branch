#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "RRE.h"

//warning this may not work, just have Raylib even tho you are using the terminal 


int main() {

PlayerStat player = {0};        //player struct 
player.Entity_ID = 1;               //player is ID 1
player.Health = 100.00;         //player health 
player.Attack = 10;                 //player attack stat 
player.Defense = 12;              //how much the player can block 
player.Money = 0.00;              //dolla dolla $$$$$$$

PlayerLevel progress = {0};                      //progress is lowercase to show that it is not the struct. You do not need to do this, aslong as its not the same as the structs name ie PlayerLevel cannot be PlayerLevel
progress.Level = 0;
progress.Moral = 100.00;
progress.XP = 0.00;

EnemyStat enemy = {0};
enemy.Attack = 1.3;
enemy.Health = 15.00;
enemy.Defense = 0; 
enemy.XpDropped = 12;

//------------------------------------------------------------------------------------------------------
int Input;


//remove this when developing your game 
  printf("ALL WORKS!\n");                                             //prints the def to make sure all data is imput correctly 
  printf("Ent ID: %i\n", player.Entity_ID);
  printf("Player Health: %f\n",  player.Health);
  printf("Attack Stat: %i\n", player.Attack);
  printf("Defense Stat: %i\n", player.Defense);
  printf("money: %f\n", player.Money);
  printf("Level: %i\n", progress.Level);
  printf("Moral: %f\n", progress.Moral);
  printf("XP: %f\n", progress.XP);
  printf("------------------------------------------------------\n");
  scanf("%i", &Input);

  if (Input == 1){
  TermClear();
player.Health -= 10;
player.Money += 25.25;
printf("Health: %f\n", player.Health);
printf("$: %f\n", player.Money);
  printf("------------------------------------------------------\n");
  Input - 1;
  scanf("%i", &Input);
  }

  if (Input == 2) {
progress.Level += 1;
progress.XP = 103.99;
printf("Level: %i\n XP: %f\n", progress.Level, progress.XP);
  printf("------------------------------------------------------\n");
  Input - 2;
  scanf("%i", &Input);
  }

  if (Input == 3) {
    TermClear();
   ListDir();
    return 0;
  }

  if (Input == 404){
    TermClear();
    Quit();
  }
  if (Input == 0) {
printf("Ent ID: %i\n", player.Entity_ID);
  printf("Player Health: %f\n",  player.Health);
  printf("Attack Stat: %i\n", player.Attack);
  printf("Defense Stat: %i\n", player.Defense);
  printf("money: %f\n", player.Money);
  printf("Level: %i\n", progress.Level);
  printf("Moral: %f\n", progress.Moral);
  printf("XP: %f\n", progress.XP);
  printf("------------------------------------------------------\n");
  scanf("%i", &Input);
  }
  return 0;
}