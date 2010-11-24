#include <gtk/gtk.h>


gboolean
on_imageUri_key_press_event            (GtkWidget       *widget,
                                        GdkEventKey     *event,
                                        gpointer         user_data);

void
on_imageUri_activate                   (GtkEntry        *entry,
                                        gpointer         user_data);

void
on_btnOpen_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_fileDialog_file_activated           (GtkFileChooser  *filechooser,
                                        gpointer         user_data);
