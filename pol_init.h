#ifndef PRECODE
#define PRECODE

#include <stdio.h>

#include <gtk/gtk.h>

struct card{
    int num;
    char name[1024];
    int acquisition;
    int type;
};

GdkColor red;
GdkColor green;
GdkColor gray;
GdkColor blue;
GdkColor yellow;
GdkColor color_tmp;

struct card card_list[256];
char mCardNum[1024];

int make_list_window(void);
void card_list_init(void);

enum C_Type{ GRAY, BLUE, GREEN, YELLOW, RED};
#endif
