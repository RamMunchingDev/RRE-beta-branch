#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include "RRE.h"

//warning this may not work, just have Raylib even tho you are using the terminal 


int main() {

  
PlayerStat player = {0};        //player struct 
player.Entity_ID = 1;               //player is ID 1
player.Health = 100.00;         //player health 
player.Rendered = true;         //is player rendered
player.Attack = 10;                 //player attack stat 
player.Defense = 12;              //how much the player can block 
player.Money = 0.00;              //dolla dolla $$$$$$$

PlayerLevel progress = {0};                      //progress is lowercase to show that it is not the struct. You do not need to do this, aslong as its not the same as the structs name ie PlayerLevel cannot be PlayerLevel
progress.Level = 0;
progress.Moral = 100.00;
progress.XP = 0.00;

PlayerStatus status = {0};
status.IsBleeding = false;            //is bleeding 
status.IsBurning = false;             //is burning  
status.IsCrawling = false;              //is crawling 
status.IsCrouching = false;
status.IsDry = true;
status.Isinteracting = false;
status.IsStanding = true;
status.IsWet = false;

PlayerData movement  = {0};
  movement.Speed = 12;
  movement.SprintSpeed = 13;
  movement.CrawlSpeed = 9;
  movement.JumpHeight = 5;
  movement.CrouchSpeed = 10;

EnemyStat enemy = {0};
enemy.Attack = 1.3;
enemy.Health = 15.00;
enemy.Defense = 0; 
enemy.XpDropped = 12;

//------------------------------------------------------------------------------------------------------
bool tUpdate= true;
int Input;
FILE *fptr;

TPS tps = {0};
tps.MaxTicks = 60;
tps.TickRate = 1;
tps.Ticks = 0;

Date date = {0};
date.Day = 0;
date.Hour = 0;
date.Minute = 0;
date.Second = 0;
date.Time = 0;
//------------------------------------------------------------------------------------------

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
  printf("1) to take damage\n");
  printf("2) to level up\n");
  printf("3) to list directory\n");
  printf("4) to save data\n");
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
    TermClear();
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

  if (Input == 5) {
    status.IsBleeding = true;
    status.IsBurning = true; 
    status.IsCrawling = true;
    status.IsCrouching = false;
    status.IsDry = false;
    status.Isinteracting = true;
    status.IsStanding = false;
    status.IsWet = true;
    Input - 5;
    scanf("%i", &Input);
  }

  if (Input == 404){
    TermClear();
    Quit();
  }
  if (Input == 0) {
    TermClear();
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

  if (Input == 8) {
    DataSave("data/test.txt", "testing \ntest2");
  }


  if (Input == 4) {
    TermClear();
    fptr = fopen("data/save.txt", "w");
    rewind(fptr);
    fprintf(fptr, "Player Data");
    fprintf(fptr, "\nID: %i", player.Entity_ID);
    fprintf(fptr, "\nHP: %f", player.Health);                         //saves health 
    fprintf(fptr, "\nATK: %i", player.Attack);                  //saves attack 
    fprintf(fptr, "\nDEF: %i", player.Defense);             //saves defense
    fprintf(fptr, "\nSpeed: %f", movement.Speed); 
    fprintf(fptr, "\nMoney: %f", player.Money);         //saves money
    fprintf(fptr, "\nLvl: %i", progress.Level);               //saves level 
    fprintf(fptr, "\nMoral: %f", progress.Moral);       //saves moral
    fprintf(fptr, "\nXP: %f", progress.XP);                   //saves xp
    fprintf(fptr, "\nbleed: %d", status.IsBleeding);          //is player bleeding saved 
    fprintf(fptr, "\nBurning: %d", status.IsBurning);         //is player burning saved 
    if (fptr == NULL) {
      printf("fail");
      return 0;
    }
    fclose(fptr);
    printf("-------------------------------------------\n");
    printf("Player Data Saved!\n");
  }

  if (Input == 6) {
    int A = 1;
    while(A == 1) {
      tps.Ticks = TickSpeed(tps.Ticks, tps.TickRate, tps.MaxTicks);
      printf("%i\n", tps.Ticks);
    }
  }

  //counts up in seconds 
  if (Input == 7) {
    int B = 1;
    TermClear();
    while(B == 1) {
      date.Second = SecondsTick(date.Second);
      date.Minute = MinuteTick(date.Second, date.Minute);
      date.Hour = HourTick(date.Minute, date.Hour);
      printf("sec: %i  min: %i hour: %i\n", date.Second, date.Minute, date.Hour);
    }
  }
  return 0;
}