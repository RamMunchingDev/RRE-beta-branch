#ifndef RamMath_H
#define RamMATH_H

#include "RRE.h"
#include "RREC.h"

//Math Define
#define add_2(a,b) ((a) + (b))
#define add_3(a,b,c) ((a) + (b) + (c))
#define add_4(a,b,c,d) ((a) + (b) + (c) + (d))
#define add_5(a,b,c,d,e) ((a) + (b) + (c) + (d) + (e))

#define sub_2(a,b) ((a) - (b))
#define sub_3(a,b,c) ((a) - (b) - (c))
#define sub_4(a,b,c,d) ((a) - (b) - (c) - (d))
#define sub_5(a,b,c,d,e) ((a) - (b) - (c) - (d) - (e))

#define multiply_2(a,b) ((a) * (b))
#define multiply_3(a,b,c) ((a) * (b) * (c))

#define divide_2(a,b) ((a) / (b))
#define divide_3(a,b,c) ((a) / (b) / (c))

#define half_1(a) ((a) / (2))

//----
//calc definitons
//----

#define MAX_CARROT 24
#define MAX_LENGTH 1028+1

//------
//calc use
//------

float Decimal_Percent(float a) {
  return a *100;
  printf("%i", a);
}

int c_add_2(int a, int b) {
  int calc_OUT;
  printf("Var A:");
  scanf("%i", &a);

  printf("Var B:");
  scanf("%i", &b);

  return add(a,b);
}

int scan_add_2() {
    int a; //always 1
    int b;  //always 2
    int OUT;
    char OUT_text;
    char Response[30+1];

    
    char *ptr;
    UserInput(Response);    //gets input

  
    ptr = strchr(Response, '+');
     
  //error check
    if (ptr == NULL) {
      printf("NULL\n");
      printf("Value of errno: %d\n", errno); 
      perror("Message from perror");
    }
      
  
      //if not null do the math 
    if (ptr != NULL) {
      //printf("NOT NULL\n");

    
      size_t plus_length = ptr - Response;
      char pBefore[plus_length + 1];
      strncpy(pBefore, Response, plus_length);

      pBefore[plus_length] = '\0';


      char* pAfter = ptr + 1;
     

      int a = atoi(pBefore);
      int b = atoi(pAfter);

      return OUT = add(a,b);

      //debugging
      printf("a: %d\n b: %d\n", a, b); //update on git
      printf("pBefore: %s\n", pBefore);
      printf("pAfter: %s\n", pAfter);
      printf("OUT: %d", OUT);
    } 
}
//---
int scan_sub() {
  char Response[30+1]; 
  printf("Enter subtraction (0 for blank)\n");
  UserInput(Response);

  char sub = '-';
  char add = '+';
  int scan = 0;
  int check = 0;
  int a = 0;
  int b = 0;
  int c = 0;
  int d = 0; 
  int OVERFLOW = 0;//overflow

  int sub_first = 0;
  int sub_mid = 0;
  int sub_thrid = 0;
  int sub_forth = 0;
  int sub_overflow = 0;    //overflow

  const char* out;
  int OUT;

  bool IsSub = false;
  bool IsAdd = false;

  if (strchr(Response, sub) != NULL) {
    out = strchr(Response, sub);
    IsSub = true;
  }
  
  if (out != NULL) {
    while(check < 4) {

      //printf("Character '%c' found at position: %ld\n",sub, out - Response + 1);
      //===================================
      //math
      //===================================
        out = strchr(out+1, sub);
      
      if (out == NULL) { break; }

      if (sub_first == 0) {
        sub_first = out - Response - 1;
        //printf("sub1: %i\n", sub_first);
      } 
      else if (sub_first != 0 && sub_mid == 0) {
        sub_mid = out - Response - 1;
        //printf("sub2 %i\n", sub_mid);
      } 
      else if (sub_mid != 0 && sub_thrid == 0) {
        sub_thrid = out - Response - 1;
       // printf("sub3 %i\n", sub_thrid);
      }
      else if (sub_thrid != 0 && sub_forth == 0) {
        sub_forth = out - Response - 1;

        //printf("sub4: %i\n", sub_forth);
      }

      if (a == 0) {
      size_t sub_length = out - Response;
      char sBefore[sub_length + 1];
      strncpy(sBefore, Response, sub_length + 1);
      sBefore[sub_length] = '\0';
      a = atoi(sBefore);
      }
      //-----

      if (a != 0 && sub_first > 0) {
        b = atoi(Response + sub_first);
    }

      //-----
      if (a != 0 && b != 0 && sub_first > 0 && sub_mid > 0) {
         c = atoi(Response + sub_mid);
      }

      //-----
      char *last_dash = strrchr(Response, '-');
      if (a != 0 && b != 0 && c != 0 && last_dash != NULL) {
          d = atoi(last_dash + 1);
      }

      scan = scan + 1;
      check = check + 1;

    }
  }
  
   //printf("NUMS:\n %i\n %i\n %i\n %i\n", a, b, c, d);
  OUT = sub_4(a,b,c,d);
  printf("SUM: %i\n", OUT);
  return 0;
}


#endif
