#include <string.h>

#include "pol_init.h"

static GtkWidget *list_window;
void card_clicked(GtkWidget *button, gpointer user_data)
{
    int i;
    strcpy(mCardNum,(char *)user_data); 
    //printf("%s\n", mCardNum);
}

void card_list_init(void ){
    struct card list_tmp[256]={

        {0, "下級船乗り", 1, 1},
        {1, "中級船乗り", 2, 1},
        {2, "上級船乗り", 3, 1},
        {3, "少年", 0, 2},
        {4, "聡明な少年", 0, 2},
        {5, "学者", 0, 2},
        {6, "財宝+1", 0, 3},
        {7, "財宝+2", 0, 3},
        {8, "財宝+3", 0, 3},
        {9, "財宝+4", 0, 3},
        {10, "財宝+5", 0, 3},
        {11, "財宝+6", 0, 3},
        {12, "財宝+7", 0, 3},
        {13, "財宝+8", 0, 3},
        {14, "財宝+9", 0, 3},
        {15, "見張り", 0, 2},
        {16, "新人水夫", 0, 2},
        {17, "荒くれ", 0, 2},
        {18, "航海長", 0, 2},
        {19, "船医", 0, 2},
        {20, "大砲", 0, 2},
        {21, "現地案内人", 0, 2},
        {22, "ネズミ害", 0, 2},
        {23, "しごき", 0, 2},
        {24, "港", 1, 2},
        {25, "散財", 0, 2},
        {26, "カリスマ", 0, 2},
        {27, "雇われ水夫", 0, 2},
        {28, "乱暴者", 0, 2},
        {29, "カトラス", 0, 2},
        {30, "補修", 0, 2},
        {31, "ラム酒", 0, 2},
        {32, "娼婦", 0, 2},
        {33, "一方的同盟", 0, 2},
        {34, "怠惰", 0, 2},

        {35, "食糧不足", 0, 4},
        {36, "嵐", 0, 4},
        {37, "怪我人", 0},

        {38, " ", 0},
        {999, "", 0}
    };
    memcpy(card_list, list_tmp, sizeof(list_tmp));
    *card_list=*list_tmp;
}

int make_list_window(){

    GtkWidget *list_window;
    GtkWidget *button;
    GtkWidget *table;
    int i;

    list_window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title (GTK_WINDOW (list_window), "Card List");

    gtk_container_border_width (GTK_CONTAINER (list_window), 10);

    table = gtk_table_new (5, 5, TRUE);
    gtk_container_add (GTK_CONTAINER (list_window), table);

    //ボタン作成
    for(i=0;card_list[i].num<999;i++){
        button = gtk_button_new_with_label (card_list[i].name);
        gtk_signal_connect (GTK_OBJECT (button), "clicked",
                GTK_SIGNAL_FUNC (card_clicked), (gpointer)card_list[i].name);  
        
        gtk_table_attach_defaults (GTK_TABLE(table), button, i/5, (i/5)+1, i%5, (i%5)+1);
    switch(card_list[i].type){
        case GRAY:
gtk_widget_modify_bg(button, GTK_STATE_NORMAL, &gray);
break;
        case BLUE:
gtk_widget_modify_bg(button, GTK_STATE_NORMAL, &blue);
break;
        case GREEN:
gtk_widget_modify_bg(button, GTK_STATE_NORMAL, &green);
break;
        case YELLOW:
gtk_widget_modify_bg(button, GTK_STATE_NORMAL, &yellow);
break;
        case RED:

gtk_widget_modify_bg(button, GTK_STATE_NORMAL, &red);
break;
    }        
        gtk_widget_show(button);
    }
    gtk_widget_show (table);

    gtk_widget_show (list_window);

    return;
}

GdkColor set_color(int num){
    return gray;    
}
