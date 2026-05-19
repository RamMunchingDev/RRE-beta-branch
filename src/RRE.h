// all code was and has been written by hand by RamMunchingDev, 0 use of AI was used in the code, so worry not. AI belongs nowhere in coding 
// This is (pre)release 0.0.1, many things will be altered, my typedefs will be put into a struct for ease of use, while some may not, i.e., burn damage
// This is because a function would be too annoying to make with BurnTick and such, so I will make an example for damaging
// even so, I will move burn status to a struct, and you will need to define your own functions because im still learning how to do that, sorry
//Please be kind, this is my first lib

//FUNCTIONS WILL BE ADDED. CURRENTLY IT IS JUST TYPEDEF AND STRUCT, I WILL BE FIXING THAT IM JUST LEARNING HOW TO DO FUNCTIONS

//that's all.  

//May 18th 2026, as of this file update
//added core--math and a bit of more will split into multiple H files for cleaner look eventually 



#include <stdbool.h>       //removed Raymath of now and replaced it with bool so people do not need to include themselves 
#include <stdlib.h>
#include <math.h> 
#include "RREC.h"       //function defintion 

#ifndef RAMENG_H
#define RAMENG_H

//----------------------------------------------------------------------------------
/* at the end of each section there will be their functions 
they are a bit messy rn and they are defined in the headers relating them RREC = Rams Raylib Engine Core */
//----------------------------------------------------------------------------------

//==================================================
//CORE
//==================================================
typedef struct TPS {
int Ticks;                  //how much the game updates 
int TickRate;     //how much the ticks update a second 
int MaxTicks;       //how much ticks can happen before set back to 0
} TPS;
 
int TickSpeed(int Ticks, int TickRate, int MaxTicks); //ticks increase per second, resets at MaxTick

//------------------------------------------------------------------------------------------------------
//player info-stats-limbs-data-Inv
//player data for storage ⌄⌄
//------------------------------------------------------------------------------------------------------
typedef struct Player {                     //glorrified rectangle btw 
    int x;              //Player X Pos 
    int y;              //Player y Pos 
    int width;          //Player Width 
    int height;         //player height
} Player;

//----------------------------------------------------------------------------------
//player basic stats 
//-----------------------------------------------------------------------------------
typedef struct PlayerStat {
    int Entity_ID;            //ID number
    bool Rendered;          //is player rendered  
    float Health;             //Player Health stat
    int Attack;             //Player Attack stat 
    int Defense;            //Player defense stat
    float Money;              //Amount of money
} PlayerStat;

typedef struct PlayerLevel {
    float Moral;              //player Moral stat/sanity
    int Level;              //Player Leveling stats / Player Level stat
    float XP;                 //points earned towards level / Player XP total 
    int Round;              //what round the game is on for wave/round based games 
} PlayerLevel;
    //------------------------------------------------------------------------------------------------------
    //player movement 
    //------------------------------------------------------------------------------------------------------
typedef struct PlayerData {
    float Speed;                 //Player Speed Stat 
    float SprintSpeed;             //Speed the player sprints duh 
    float CrawlSpeed;              //Speed while crawling
    float CrouchSpeed;             //Speed while crouching 
    float JumpHeight;            //Player jump height 
    } PlayerData;
    
//------------------------------------------------------------------------------------------------------
// Player status effects 
//------------------------------------------------------------------------------------------------------
typedef struct PlayerStatus {
    bool IsStanding;              //is the player standing 
    bool IsCrouching;               //is the player crouched 
    bool IsCrawling;                //is the player crawling 
    bool IsWet;                   //is the player Wet
    bool IsDry;                    //Is the player dry 
    bool IsBurning;                //is the player burning 
    bool Isinteracting;            //is the player interacting with something
    bool IsBleeding;            //is the player bleeding? 
} PlayerStatus;

    //---------------------------------------------------------------------
    //Bag WIP
    //---------------------------------------------------------------------
typedef int BagStorage;             //how much room is the bag 
typedef bool IsBagOpen;             //is the bag/inv open 

typedef struct BagSlots {            //WILL REVISE
    int ID_ITEM;                    //Which item is in the slot (will revise)
    bool Holding;                   //are you holding the item
} BagSlots;
    
    //---------------------------------------------------------------------
    //ITEM ID IS WIP 
    //---------------------------------------------------------------------
typedef struct ItemID {
 int IDNUMBER;                      //id number for an item 
 int ID_SLOT;                       //which number slot this item is in, i.e., ItemSlot 1 = ID_SLOT
} ItemID;
typedef int ItemSlot;               //the slot of which an item is under 
    
//-----------------------------------------------------------------------------------------------------
//Will be put under a struct "Inflicts"
//------------------------------------------------------------------------------------------------------

typedef struct DamageStatus {
float BurnDamage;             //Amount of damage burning inflicts
int BurnTime;               //how long burning will last
int BurnTick;               //how many ticks should go by for the damage 
//---------------
float BleedDamage;            //Damage inflicted when bleeding 
int BleedTick;              //how long bleeding will last 
//---------------
float FreezeDamage;         //Freezing damage 
int FreezeTime;             //how long till you freeze 
} DamageStatus;
//------------------------------------------------------------------------------------------------------
//PLAYER LIMB HEALTH
//------------------------------------------------------------------------------------------------------
typedef struct PlayerLimb {
    float HeadHP;                 //player Head limb health 
    float TorsoHP;                //Player Torso Health 
    float ArmRightHP;             //Player Arm Right Health 
    float ArmLeftHP;              //Player Arm Left Health
    float PelvisHP;               //Player Pelvis Health
    float LegLeftHP;              //Player Leg Left health 
    float LegRightHP;             //Player Leg Right Health 
} PlayerLimb;
//player data for storage ^^

//------------------------------------------------------------------------------------------------------
//Enemy data 
//------------------------------------------------------------------------------------------------------
typedef struct EnemyPosition {
    int x;                      //Enemy x pos 
    int y;                      //Enemy y Pos 
    int width;                  //Enemy width 
    int height;                 //Enemy Height;
} EnemyPosition;

typedef struct EnemyStat {
    float Health;           //amount of health enemy has / health stat/hp 
    float Attack;           //Amount of damage the enemy does
    float Defense;          //Amount of damage resisted 
    float Speed;            //Enemy movement speed
    float XpDropped;        //Xp dropped on death 
} EnemyStat;

//will add more
typedef struct EnemyInfliction {
bool CanBurn;           //Can the enemy burn player or objects
bool CanBleed;          //can the enemy inflict bleeding 
bool CanWet;            //Can the enemy make things wet...
bool IsRendered;        //is enemy rendered 
bool IsHit;             //is enemy hit
} EnemyInfliction; 
//------------------------------------------------------------------------------------------------------
//Weather and time 
//------------------------------------------------------------------------------------------------------

//time 
typedef struct Date {                //Day, time, hours and minutes 
int Day;
int Hour;
int Minute;
int Second;
int Time;
} Date;

int SecondsTick(int Second);
int MinuteTick(int Second, int Minute);
int HourTick(int Minute, int Hour);

//weather 
typedef enum Weather {      //Weather and wtv you call it idk 
    Raining,
    Thundering,
    Snowing,
    Hailing,
    Sunny,
    Cloudly,
    Foggy,
    Clear,
} Weather;

typedef enum Seasons {                  //all four seasions 
    Spring,
    Summar,
    Fall,
    Winter,
} Seasons;

//------------------------------------------------------------------------------------------------------
//Define states 
//------------------------------------------------------------------------------------------------------
typedef struct ObjectState {
bool IsLiquid;              //is object a liquid 
bool IsSolid;               //is object a solid 
bool IsAir;                 //is object air/can phase through
bool IsHot;                 //is object able inflict burn damage 
bool IsCold;                //is Object cold
bool IsWet;                 //is object wet 
bool IsDry;                 //is object dry, for whatever purpose
bool IsSharp;               //is object able to inflict bleed 
bool IsMoving;              //is object moving 
} ObjectState;
//---------------------------------------------------------------------------------
//Npc interactions 
//---------------------------------------------------------------------------------

//add shop here, old shop lowkey ass

//--------------------------------------------------------------------------------
//object interactions --this part is a WIP
//--------------------------------------------------------------------------------
typedef struct ObjectAttributes {
bool IsObjectDestroyed; //is object destroyed 
bool IsZonechange;      //is object changing zone when hit/interacted 
bool CanMove;           //can you move the object
bool CanInteractWithObjects; //can the object interact with other objects 
bool CanCrush;                //can it crush player 
} ObjectAttributes;

typedef struct ObjectStat {
int Entity_ID;                              //object entity ID
int ObjectHealth;       //Object health, breaks on 0 
float FallDamage;             //basically, how hard will it be if you fall on it 
bool IsObjectHit;       //is object hit 
bool IsRendered;              //is object rendered 
} ObjectStat;

//------------------------------------------------------------------------------------------------------
//TEMP NAME
//------------------------------------------------------------------------------------------------------

//add things here

//------------------------------------------------------------------------------------------------------
// Terminal/Files
//------------------------------------------------------------------------------------------------------
//fptr means file name/path
void TermClear();                               //clear terminal 
void Quit();                                    //quit terminal 
void ListDir();                                 //list directories 
void DataSave(const char *fptr, char Write[]);  //save data

#endif //RAMENG
