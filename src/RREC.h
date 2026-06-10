/*this is where all functions in the core of the engine will be defined
today is june 3rd -- math functs */

#ifndef RAMCORE_H
#define RAMCORE_H

#include "RRE.h"
#include "RRED.h"

#include <stdint.h>
#include <uchar.h>
#include <ctype.h>
 
#define π(x) ((x) * (3.14159265359))
//math definitions under RREP place here 

        
//-----------------------------------------------------------------------------------
//Core -> Ticks
//-----------------------------------------------------------------------------------
int TickSpeed(int Ticks, int TickRate, int MaxTicks) {
    if(Ticks >= MaxTicks) {
        Ticks = Ticks - MaxTicks;
    };
    return Ticks = Ticks + TickRate;
};

//-----------------------------------------------------------------------------------
//Time
//-----------------------------------------------------------------------------------
int SecondsTick(int Second) {
    int ticking = 1;
    if(Second >= 60) {
        Second = 0;
    } 
    while(!ticking >= 30, ticking++) {
        Second = Second - 1;
    }
    if (ticking >= 30) {ticking = 0;};

    return Second;    
}

int MinuteTick(int Second, int Minute) {
    if(Second >= 60) {
        return Minute + 1;
    }
    if(Minute >= 60) {
        Minute = 0;
    }
return Minute;
}

int HourTick(int Minute, int Hour) {
    if(Minute >= 60) {
        return Hour + 1;
    }
    return Hour;
}

//===================================================================================
//TERMINAL
//===================================================================================

//-------------
//color 
//-------------

void PRINT_RED(char *Text) {
    printf(COLOR_RED "%s" COLOR_RESET "\n", Text);
}
void PRINT_RED_BOLD(char *Text) {
    printf(COLOR_RED_BOLD "%s" COLOR_RESET "\n", Text);
}

//--

void PRINT_GREEN(char *Text) {
    printf(COLOR_GREEN "%s" COLOR_RESET "\n", Text);
}
void PRINT_GREEN_BOLD(char *Text) {
    printf(COLOR_GREEN_BOLD "%s" COLOR_RESET "\n", Text);
}

//--

void PRINT_BLUE(char *Text) {
    printf(COLOR_BLUE "%s" COLOR_RESET "\n", Text);
}
void PRINT_BLUE_BOLD(char *Text) {
    printf(COLOR_BLUE_BOLD "%s" COLOR_RESET "\n", Text);
}

//--

void PRINT_COLOR(char *Text, char *Color) {
    printf("%s%s\n", Color, Text, COLOR_RESET "\n");
}


//-------
void TermClear() {                              //(clears the terminal example > TermClear();
    system("clear");
}
void Quit() {                                           //quits engine/game/software
    exit;
}
void ListDir() {                                    // Lists current Dir
    char List[3];
    strcpy(List, "ls");
    system(List);
}

void ReadTextFile(char Read[]) {
  TermClear();  
  PathToFile(Read);
  FILE *fptr = fopen(Read, "r");
  printf("file: %s\n", Read);  
  while(fgets(Read, 80*200, fptr)){    
      printf("%99s", Read);
  }
    printf("\n");
  fclose(fptr);
  
}

void DataSave(const char *file, char Write[]){      //Save set data, for errors or other logs 
    TermClear();
    FILE *fptr;
    fptr = fopen(file, "a");
    rewind(fptr);
    fprintf(fptr, "----Data----");
    fprintf(fptr, "\n%s", Write);
    fclose(fptr);
    printf("-------------------------------------------\n");
    printf("Data Saved!\n");
}

void DataWrite(char Path[], char Write[]) {
    TermClear();
    FILE *fptr;
    fptr = fopen(Path, "a");
    rewind(fptr);
    fprintf(fptr, "%s", Write);
    fclose(fptr);
    printf("-------------------------------------------\n");
    printf("Text Saved!\n");
    if (Path == NULL) {
        printf("Error: %s\n", strerror(errno));
    }
}
char PathToFile(char Path[]) {
    printf("Enter Path: ");
    scanf("%s", Path);
    return *Path;
}

char WriteToFile(char SaveText[]) {
    printf("Enter text to save:");
    scanf(" %99[^\n]", SaveText);
    return *SaveText;
    }

void FileCreate(char FileName[]) {
    TermClear();
    FILE *fptr;
    printf("Enter name for the file you wish to create \n");
    printf("name: ");
    scanf("%s", FileName);
    fptr = fopen(FileName, "w");
    if (fptr == NULL) {
      printf(COLOR_RED "Error:" COLOR_RESET "%s", strerror(errno));
    }
    fclose(fptr);
    printf("File Made!\n");
}

void FileDelete(char Path[]) {
    PathToFile(Path);
    remove(Path);
}

void FileScan(char Path[]) {
    TermClear();
    bool Debug = false;
    int i;
    int count = 0;
    
    char Text[MAX_LENGTH];
    FILE *fptr;
    char *ptr;
    char Find;
    
    printf(COLOR_RED "\n========================" COLOR_RESET "\n");
    printf(COLOR_RED "search for (ctrl-f) in file" COLOR_RESET "\n");
    printf(COLOR_RED "========================" COLOR_RESET "\n");
    PathToFile(Path);
    printf("Find: ");
    scanf(" %99[^\n]", &Find);
    
    if (Find == NULL && Debug == true) {
        printf("Value of errno: %d\n", errno); 
    }
    
    fptr = fopen(Path, "r");
    printf("file: %s\n", Path);  
    while(fgets(Text, MAX_LENGTH, fptr))
      {    
        
        printf("%99s", Text);
          ptr = strchr(Text, Find);
          if (ptr != NULL) {
              printf("\n========================\n");
              while (i <= 10, i++) {
              count = count + 1;
              ptr = strchr(ptr+1, Find);
                  if (ptr == NULL) {break;}
              }
        
          }
          if (ptr == NULL) {
              if (Debug == true) {
              printf("end\n");
              }
              printf("Found times: %ld\n", count);
              fclose(fptr);
          }
      }
        printf("\n");
    
    if (fptr == NULL) {
      printf(COLOR_RED "Error:" COLOR_RESET "%s", strerror(errno));
    }
}

//===================================================================================
//MATH
//------
//KEY TERMS
//------
//∆ - Change (ie ∆s & ∆t is change in pos and time)
//===================================================================================

int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a*b;
}

int divide(int a, int b) {
    return a / b;
}

float half(float a) {
    return a / 2;
}

float squared(float a) {
    return a*2;
}

float cubed(float a) {
    return a * a * a;
}

float RectBaseArea(float length, float width) {
    return length * width;
}

//===================================================================================
//Math extras
//===================================================================================




//===================================================================================
//WIP MATH
//===================================================================================
//THE PHYSICS ARE WIP
//go easy on me with the physics im still learning 

//∆speed & ∆time
float AVG_velocity(float s, float t) {
    return s / t;
}

//∆velocity & ∆time 
float acceleration(float v, float t) {
    return v / t;
}

//float AVG_acceleration();

//alt acceleration
float ALT_acceleration(float speed, float Max_speed) {
    if (speed < Max_speed) {
     return speed = speed + 1;
    }
}


//===================================================================================
//others (unsorted for now)
//===================================================================================

char UserInput(char Response[]) {
    printf("input: ");
    scanf(" %99[^\n]s", Response);
    return *Response;
}



#endif
