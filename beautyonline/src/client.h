#ifndef BEAUTYONLINE_INCLUDE_CLIENT
#define BEAUTYONLINE_INCLUDE_CLIENT

#include <gtk/gtk.h>

int clientLoad;
GtkWidget* winMain;
GtkWidget* imgViewport;
GtkWidget* imgBox;
GtkWidget* imgUri;
GtkWidget* statusBar;

void loadClient(GtkWidget* in_winMain,
				GtkWidget* in_Viewport,
				GtkWidget* in_imgBox,
				GtkWidget* in_imgUri,
				GtkWidget* in_statusBar);

int load_image(gchar* URI);
int load_image_file(gchar* imgFile);
int load_image_pixbuf(GdkPixbuf * pixbuf);
int load_image_http(gchar* uri);
void set_status_text(gchar* text);

#endif
