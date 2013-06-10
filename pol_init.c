#include <gtk/gtk.h>
#include <string.h>

#include "pol_init.h"

static GtkWidget *list_window;
void card_clicked(GtkWidget *button, gpointer user_data)
{
    int i;
    strcpy(mCardNum,(char *)user_data); 
    printf("%s\n", mCardNum);
}

void card_list_init(void ){
    struct card list_tmp[256]={

        {0, "下級船乗り", 1},
        {1, "中級船乗り", 2},
        {2, "上級船乗り", 3},
        {3, "少年", 0},
        {4, "聡明な少年", 0},
        {5, "学者", 0},
        {6, "財宝+1", 0},
        {7, "財宝+2", 0},
        {8, "財宝+3", 0},
        {9, "財宝+4", 0},
        {10, "財宝+5", 0},
        {11, "財宝+6", 0},
        {12, "財宝+7", 0},
        {13, "財宝+8", 0},
        {14, "財宝+9", 0},
        {15, "見張り", 0},
        {16, "新人水夫", 0},
        {17, "荒くれ", 0},
        {18, "航海長", 0},
        {19, "船医", 0},
        {20, "大砲", 0},
        {21, "現地案内人", 0},
        {22, "ネズミ害", 0},
        {23, "しごき", 0},
        {24, "港", 1},
        {25, "散財", 0},
        {26, "カリスマ", 0},
        {27, "雇われ水夫", 0},
        {28, "乱暴者", 0},
        {29, "カトラス", 0},
        {30, "補修", 0},
        {31, "ラム酒", 0},
        {32, "娼婦", 0},
        {33, "一方的同盟", 0},
        {34, "怠惰", 0},

        {35, "食糧不足", 0},
        {36, "嵐", 0},
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

        gtk_widget_show(button);

    }
    gtk_widget_show (button);
    gtk_widget_show (table);

    gtk_widget_show (list_window);

    //gtk_main ();

    return;
}
