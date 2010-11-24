#include <gtk/gtk.h>
#include <gdk/gdkkeysyms.h>
#include <stdlib.h>

void action (const gchar* text) {
    if(*text) {
        g_print("execute:%s\n",text);
        system(text);
    }
}

static int
on_key_press(GtkWidget *widget, GdkEventKey *event, gpointer user_data)
{
    switch(event->keyval) {
        case GDK_Return:
        case GDK_KP_Enter:
            action(gtk_entry_get_text(GTK_ENTRY(user_data))); 
            return 1;
            break;
        case GDK_Escape:
            gtk_entry_set_text(GTK_ENTRY(user_data),"");
            return 1;
            break;
        default:
            break;
    }
    return 0;
}


static void hello(GtkWidget *widget,gpointer data) 
{
    gchar* text;
    text = gtk_combo_box_get_active_text(GTK_COMBO_BOX(data));
    action(text);
}

static void destroy(GtkWidget* widget,gpointer data)
{
    gtk_main_quit();
}

int main(int argc,char** argv)
{
    GtkWidget *window;
    GtkWidget *combox;
    GtkWidget *button;
    GtkWidget *hbox;
    GtkWidget *entry;
    gtk_init(&argc,&argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(G_OBJECT(window),"destroy",G_CALLBACK(destroy),NULL);
    g_signal_connect(G_OBJECT(window),"delete_event",G_CALLBACK(destroy),NULL);
    hbox = gtk_hbox_new(0,4);
    combox = gtk_combo_box_entry_new();
    entry = gtk_bin_get_child(GTK_BIN(combox));
    g_signal_connect(G_OBJECT(entry),"key_press_event",G_CALLBACK(on_key_press),entry);
    button = gtk_button_new_with_label("Start");
    g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(hello),combox);
    gtk_container_add(GTK_CONTAINER(hbox),combox);
    gtk_container_add(GTK_CONTAINER(hbox),button);
    gtk_container_add(GTK_CONTAINER(window),hbox);
    gtk_widget_show(combox);
    gtk_widget_show(button);
    gtk_widget_show(hbox);
    gtk_widget_show(window);
    gtk_main();
    return 0;
}
