#include <gtk/gtk.h>
#include <stdio.h>
void quit ( GtkWidget *window, gpointer data){
    gtk_main_quit();
}
/* 메뉴 아이템에 대한 콜백 함수 */
void new_project_clicked(GtkWidget *widget, gpointer data){
    gtk_label_set_text(GTK_LABEL((GtkWidget *) data), "newproject!\n");
}
int main (int argc, char *argv[])
{
    GtkWidget *window;
    GtkWidget *menubar, *fileitem;
    GtkWidget *menu, *filemenu, *newitem, *openitem;
    GtkWidget *submenu, *subitem;
    GtkWidget *vbox , *message_label;

    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title (GTK_WINDOW(window), "Gtk menu");
    gtk_window_set_position (GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size (GTK_WINDOW (window), 300, 200);
    g_signal_connect ( window, "destroy", G_CALLBACK (quit), NULL);
    vbox = gtk_vbox_new ( FALSE, 0);
    menubar = gtk_menu_bar_new ();
    message_label = gtk_label_new ("first hi");
    gtk_box_pack_start (GTK_BOX (vbox), menubar,  FALSE, FALSE, 0);
    gtk_box_pack_start (GTK_BOX (vbox), 
    message_label, TRUE, FALSE, 0);
    fileitem = gtk_menu_item_new_with_mnemonic ("file");
    gtk_container_add (GTK_CONTAINER (menubar), fileitem);
    menu = gtk_menu_new ();
    gtk_menu_item_set_submenu (GTK_MENU_ITEM(fileitem), menu);
    newitem = gtk_menu_item_new_with_mnemonic ("create");
    gtk_container_add (GTK_CONTAINER (menu), newitem);
    openitem = gtk_menu_item_new_with_mnemonic ("open");
    gtk_container_add (GTK_CONTAINER (menu), openitem);
    submenu = gtk_menu_new ();
    gtk_menu_item_set_submenu (GTK_MENU_ITEM (newitem), submenu);
    subitem = gtk_menu_item_new_with_mnemonic ("proj");
    gtk_container_add (GTK_CONTAINER (submenu), subitem);
    g_signal_connect ( subitem, "activate", G_CALLBACK(new_project_clicked), message_label);
    gtk_container_add (GTK_CONTAINER(window), vbox);
    gtk_widget_show_all(window);
    gtk_main ();
    return 0;
}
