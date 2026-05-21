/*this is where all functions in the core of the engine will be defined
today is May 20th 2026 -- quick hot fix*/

#ifndef RAMCORE_H
#define RAMCORE_H

#include "RRE.h"
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
  PathToFile(Read);
  FILE *fptr = fopen(Read, "r");
  fgets(Read, 100, fptr);    
  printf("%s\n", Read);  
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
    fprintf(fptr, " %s", Write);
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
      printf("Error: %s\n", strerror(errno));
    }
    fclose(fptr);
    printf("File Made!\n");
    
}
#endif