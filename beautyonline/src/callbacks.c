#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "client.h"

void
on_imageUri_activate                   (GtkEntry        *entry,
                                        gpointer         user_data)
{
	gchar* imgPath;
	g_object_get((GObject*)user_data,"text",&imgPath,NULL);
	if(imgPath != NULL) {
		int result;
		set_status_text(imgPath);
		if ( (result=load_image_file(imgPath))!= 0)
			result=load_image_http(imgPath);
		if (result!=0) 
			set_status_text("Can't load image.");
	}
	return;	
}


void
on_btnOpen_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
	gchar* filename;
	g_object_get(button,"text",&filename,NULL);
	
	GtkWidget* fileDialog = gtk_file_chooser_dialog_new ("Open File",
				      NULL,
				      GTK_FILE_CHOOSER_ACTION_OPEN,
				      GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
				      GTK_STOCK_OPEN, GTK_RESPONSE_ACCEPT,
				      NULL);
	
	gtk_file_chooser_set_filename((GtkFileChooser*)fileDialog,filename);
	
	if (gtk_dialog_run((GtkDialog*) fileDialog) == GTK_RESPONSE_ACCEPT) {
		filename = gtk_file_chooser_get_filename((GtkFileChooser*) fileDialog);
		g_object_set(button,"text",filename,NULL);
		set_status_text(filename);
		load_image_file(filename);
		g_free(filename);
	}
	gtk_widget_destroy(fileDialog);
}
