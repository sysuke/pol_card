#include <stdio.h>

struct card{
    int num;
    char name[1024];
    int acquisition;
};

struct card card_list[256];
char mCardNum[1024];

int make_list_window(void);
void card_list_init(void);
