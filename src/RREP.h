#ifndef RamMath_H
#define RamMATH_H

//Math Define
#define add_2(a,b) ((a) + (b))
#define add_3(a,b,c) ((a) + (b) + (c))
#define add_4(a,b,c,d) ((a) + (b) + (c) + (d))
#define add_5(a,b,c,d,e) ((a) + (b) + (c) + (d)+ (e))



#define sub_2(a,b) ((a) - (b))
#define sub_3(a,b,c) ((a) - (b) - (c))

#define multiply_2(a,b) ((a) * (b))
#define multiply_3(a,b,c) ((a) * (b) * (c))

#define divide_2(a,b) ((a) / (b))
#define divide_3(a,b,c) ((a) / (b) / (c))

#define half_1(a) ((a) / (2))

//------
//calc use
//------
int c_add_2(int a, int b) {
  int calc_OUT;
  printf("Var A:");
  scanf("%i", &a);

  printf("Var B:");
  scanf("%i", &b);

  return add(a,b);
}

int scan_add() {
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
      
      printf("a: %d\n b: %d\n", a, b); //update on git
      printf("pBefore: %s\n", pBefore);
      printf("pAfter: %s\n", pAfter);
      printf("OUT: %d", OUT);
    } 
}
  
#endif
