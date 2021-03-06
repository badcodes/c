#include <gtk/gtk.h>

static void hello(GtkWidget *widget,gpointer data) 
{
    g_print("Hello, World!\n");
}

static void destroy(GtkWidget* widget,gpointer data)
{
    gtk_main_quit();
}

int main(int argc,char** argv)
{
    GtkWidget *window;
    GtkWidget *button;
    gtk_init(&argc,&argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(G_OBJECT(window),"destroy",G_CALLBACK(destroy),NULL);
    g_signal_connect(G_OBJECT(window),"delete_event",G_CALLBACK(destroy),NULL);
    button = gtk_button_new_with_label("Heloo, World!");
    g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(hello),NULL);
    gtk_container_add(GTK_CONTAINER(window),button);
    gtk_widget_show(button);
    gtk_widget_show(window);
    gtk_main();
    return 0;
}
