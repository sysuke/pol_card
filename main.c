#include <gtk/gtk.h>
#include "pol_init.h"




void button_clicked(GtkButton *button, gpointer user_data)
{
    //make_list_window();
    gtk_button_set_label(button,mCardNum);
}

void make_window(){


    GtkWidget *window;
    GtkWidget *button;
    GtkWidget *table;
    int i;

    /* 新しいウィンドウを作成 */
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);

    /* ウィンドウのタイトル */
    gtk_window_set_title (GTK_WINDOW (window), "Deck View");

    /* このウィンドウのボーダ幅を設定 */
    gtk_container_border_width (GTK_CONTAINER (window), 10);

    /*コンテナに配置(ボタンを垂直に配置している)*/
    table = gtk_table_new (5, 5, TRUE);
    gtk_container_add (GTK_CONTAINER (window), table);   
    //ボタン作成
{
    //下級船乗り
    for(i=0;i<5;i++){
        button = gtk_button_new_with_label (card_list[0].name);
        gtk_signal_connect (GTK_OBJECT (button), "clicked",
                GTK_SIGNAL_FUNC (button_clicked), (gpointer)card_list[0].name);
        gtk_table_attach_defaults (GTK_TABLE(table), button, 0,1, i,i+1);
        gtk_widget_show(button);
    }

    //カリスマ
    for(i=0;i<2;i++){
        button = gtk_button_new_with_label (card_list[26].name);
        gtk_signal_connect (GTK_OBJECT (button), "clicked",
                GTK_SIGNAL_FUNC (button_clicked), (gpointer)card_list[0].name);
        gtk_table_attach_defaults (GTK_TABLE(table), button, 1,2, i,i+1);
        gtk_widget_show(button);
    }
    for(i;i<5;i++){
        button = gtk_button_new_with_label (card_list[38].name);
        gtk_signal_connect (GTK_OBJECT (button), "clicked",
                GTK_SIGNAL_FUNC (button_clicked), (gpointer)card_list[0].name);
        gtk_table_attach_defaults (GTK_TABLE(table), button, 1,2, i,i+1);
        gtk_widget_show(button);
    }
    //樽
    for(i=0;i<3;i++){
        button = gtk_button_new_with_label (card_list[6].name);
        gtk_signal_connect (GTK_OBJECT (button), "clicked",
                GTK_SIGNAL_FUNC (button_clicked), (gpointer)card_list[0].name);
        gtk_table_attach_defaults (GTK_TABLE(table), button, 2,3, i,i+1);
        gtk_widget_show(button);
    }
    for(i;i<5;i++){
        button = gtk_button_new_with_label (card_list[38].name);
        gtk_signal_connect (GTK_OBJECT (button), "clicked",
                GTK_SIGNAL_FUNC (button_clicked), (gpointer)card_list[0].name);
        gtk_table_attach_defaults (GTK_TABLE(table), button, 2,3, i,i+1);
        gtk_widget_show(button);
    }

    //トラブル
    for(i=0;i<2;i++){
        button = gtk_button_new_with_label (card_list[35].name);
        gtk_signal_connect (GTK_OBJECT (button), "clicked",
                GTK_SIGNAL_FUNC (button_clicked), (gpointer)card_list[0].name);
        gtk_table_attach_defaults (GTK_TABLE(table), button, 3,4, i,i+1);
        gtk_widget_show(button);
    }
    for(i;i<4;i++){
        button = gtk_button_new_with_label (card_list[36].name);
        gtk_signal_connect (GTK_OBJECT (button), "clicked",
                GTK_SIGNAL_FUNC (button_clicked), (gpointer)card_list[0].name);
        gtk_table_attach_defaults (GTK_TABLE(table), button, 3,4, i,i+1);
        gtk_widget_show(button);
    }
    for(i;i<5;i++){
        button = gtk_button_new_with_label (card_list[38].name);
        gtk_signal_connect (GTK_OBJECT (button), "clicked",
                GTK_SIGNAL_FUNC (button_clicked), (gpointer)card_list[0].name);
        gtk_table_attach_defaults (GTK_TABLE(table), button, 3,4, i,i+1);
        gtk_widget_show(button);
    }

    //予備
    for(i=0;i<5;i++){
        button = gtk_button_new_with_label (card_list[38].name);
        gtk_signal_connect (GTK_OBJECT (button), "clicked",
                GTK_SIGNAL_FUNC (button_clicked), (gpointer)card_list[0].name);
        gtk_table_attach_defaults (GTK_TABLE(table), button, 4,5, i,i+1);
        gtk_widget_show(button);
    }
}

    gtk_widget_show (button);
    gtk_widget_show (table);

    gtk_widget_show (window);
    
    make_list_window();

    gtk_main ();

    return;

}

int main (int argc, char *argv[])
{
    gtk_init (&argc, &argv);

    card_list_init();
    make_window();
    return 0;
}

