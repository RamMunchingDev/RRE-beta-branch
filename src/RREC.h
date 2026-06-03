/*this is where all functions in the core of the engine will be defined
today is May 20th 2026 -- quick hot fix*/

#ifndef RAMCORE_H
#define RAMCORE_H

#include "RRE.h"

#define pi 3.14159265359
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
      printf("Error: %s\n", strerror(errno));
    }
    fclose(fptr);
    printf("File Made!\n");
}

void FileDelete(char Path[]) {
    PathToFile(Path);
    remove(Path);
}

//===================================================================================
//MATH
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

void Calc(char Response[]) {
    TermClear();
    char a;    //add
    int A;        //var a
    float A_float;
    int B;        //var b
    float B_float;
    int OUT;
    float OUT_float;
    int v;

    //---
    //bools
    //---
    bool VarA_pi = false;        //wip
    bool VarB_pi = false;        //wip
    bool Mode = true;            //wip
    //-----

    //v = strcmp(Response, "add");
    //if true v = 0
    while (Mode == true) {
    if (strcmp(Response, "add") == 0) {
        TermClear();

        //adding
        printf("ENTER NUMBERS\n");             //text asking
        
        printf("var A:");            //prints the name of which var they are on 
        scanf("%i", &A);    //scans for var a
        printf("var B:");            //prints the name of which var they are on
        scanf("%i", &B);    //scans for var b
        OUT = add(A,B);             //adds the 2
        
        printf("OUTPUT: %i\n", OUT);        //prints the results 

        printf("math operation: ");
        UserInput(Response);
    }

    //subtraction
    if (strcmp(Response, "sub") == 0) {
        TermClear();
        
        printf("ENTER NUMBERS TO SUBTRACT\n");
        printf("ORDER IS IMPORTANT!!\n");
        
        printf("FIRST var:");
        scanf("%i", &A);
        printf("SECOND var:");
        scanf("%i", &B);
      
        OUT = sub(A,B);
        printf("OUTPUT: %i\n", OUT);

        printf("math operation: ");
        UserInput(Response);
    } 

    //multiply
    if (strcmp(Response, "multiply") == 0) {
        TermClear();
        
        printf("ENTER NUMBERS\n");         
        printf("var A:");
        scanf("%i", &A);    //scans for var a
        printf("var B:");
        scanf("%i", &B);    //scans for var b
        
        OUT = multiply(A,B);
        printf("OUTPUT: %i\n", OUT);

        printf("math operation: ");
        UserInput(Response);
    }

    //divide
    if (strcmp(Response, "divide") == 0) {
        TermClear();

        printf("ENTER NUMBERS\n");         
        printf("var A:");
        scanf("%i", &A);    //scans for var a
        printf("var B:");
        scanf("%i", &B);    //scans for var b

        OUT = divide(A,B);
        printf("OUTPUT: %i\n", OUT);

        printf("math operation: ");
        UserInput(Response);
    }

    //half
    if (strcmp(Response, "half") == 0) {
        TermClear();

        printf("ENTER NUMBERS\n");         
        printf("var A:");
        scanf("%f", &A_float);    //scans for var a

        OUT_float = half(A_float);
        printf("OUTPUT: %f\n", OUT_float);

        printf("math operation: ");
        UserInput(Response);
    }

    //squared
    if (strcmp(Response, "squared") == 0) {
        TermClear();

        printf("ENTER NUMBERS\n");         
        printf("var A:");
        scanf("%f", &A_float);    //scans for var a

        OUT_float = squared(A_float);
        printf("OUTPUT: %f\n", OUT_float);

        printf("math operation: ");
        UserInput(Response);
    }

    //cubed
    if (strcmp(Response, "cubed") == 0) {
        TermClear();

        printf("ENTER NUMBERS\n");         
        printf("var A:");
        scanf("%f", &A_float);    //scans for var a

        OUT_float = cubed(A_float);
        printf("OUTPUT: %f\n", OUT_float);

        printf("math operation: ");
        UserInput(Response);
    }

    //list of options 
    if (strcmp(Response, "list") == 0) {
            TermClear();
            printf("options: \n");
            printf(" add\n sub\n multiply\n divide\n half\n squared\n cubed\n");
            
            printf("math operation: ");
            UserInput(Response);
        }
    }

    //broken
    if (strcmp(Response, "quit") == 0) {
        Mode = false;
        TermClear();
        printf("exiting...\n");
    }
}

//===================================================================================
//others (unsorted for now)
//===================================================================================

char UserInput(char Response[]) {
    scanf(" %99[^\n]s", Response);
    return *Response;
}

#endif
