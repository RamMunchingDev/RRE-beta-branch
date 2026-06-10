#ifndef RamDefine_H
#define RamDefine_H

#include "RRE.h"
#include "RREC.h"
#include <uchar.h>

//==================================================
//files
//==================================================

#define FILE_LENGTH 1028+1
#define MAX_LENGTH 1000+1

//==================================================
//MATH
//==================================================

//string / calc
#define MAX_CARROT 24

#define DELTA "\u2206"

char16_t delta = u'\u2206'; 


//used for in functions these are optional 
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
#define multiply_4(a,b,c,d) ((a) * (b) * (c) * (d))

#define divide_2(a,b) ((a) / (b))
#define divide_3(a,b,c) ((a) / (b) / (c))
#define divide_4(a,b,c,d) ((a) / (b) / (c) / (d))

#define half_1(a) ((a) / (2))

//==================================================
//COLOR
//==================================================

#define COLOR_RED     "\x1b[31m"
#define COLOR_RED_BOLD     "\x1b[1;31m"
#define COLOR_RED_UNDERLINE     "\x1b[4;31m"

#define COLOR_GREEN   "\x1b[32m"
#define COLOR_GREEN_BOLD   "\x1b[1;32m"
#define COLOR_GREEN_UNDERLINE   "\x1b[4;32m"

#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_YELLOW_BOLD "\x1b[1;33m"
#define COLOR_YELLOW_UNDERLINE "\x1b[4;33m"

#define COLOR_BLUE    "\x1b[34m"
#define COLOR_BLUE_BOLD    "\x1b[1;34m"
#define COLOR_BLUE_UNDERLINE    "\x1b[4;34m"

#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_MAGENTA_BOLD "\x1b[1;35m"
#define COLOR_MAGENTA_UNDERLINE "\x1b[4;35m"

#define COLOR_CYAN    "\x1b[36m"
#define COLOR_CYAN_BOLD    "\x1b[1;36m"
#define COLOR_CYAN_UNDERLINE    "\x1b[4;36m"

#define COLOR_RESET   "\x1b[0m"

#endif