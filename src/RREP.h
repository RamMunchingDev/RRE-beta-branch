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

  
#endif