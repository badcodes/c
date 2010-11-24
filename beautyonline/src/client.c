
#include <stdio.h>
#include <gtk/gtk.h>
#include "client.h"
#include "internet.h"


void loadClient(GtkWidget* in_winMain,
				GtkWidget* in_Viewport,
				GtkWidget* in_imgBox,
				GtkWidget* in_imgUri,
				GtkWidget* in_statusBar) {
	clientLoad=0;
	winMain = in_winMain;
	imgViewport = in_Viewport;
	imgBox = in_imgBox;
	imgUri = in_imgUri;
	statusBar = in_statusBar;
	return;
}

int load_image(gchar *URI) {
	if (g_strncasecmp(URI,"http:",5)==0)
		return load_image_http(URI);
	else
		return load_image_file(URI);
}

int load_image_http(gchar* uri) {
	gchar* imgFile = tempnam(NULL,"beautyonline");
	FILE* imgStream;
	if (imgFile == NULL) {
		return -1;
	}
	imgStream = fopen(imgFile,"w");
	int result= download(uri,imgStream);
	fclose(imgStream);
	return load_image_file(imgFile);
}

int load_image_file(gchar* imgFile) {
	if (clientLoad!=0) return;
	GdkPixbuf* pixbuf;
	pixbuf = gdk_pixbuf_new_from_file(imgFile,NULL);
	if (pixbuf == NULL) 
		return -1;
	return load_image_pixbuf(pixbuf);
}

int load_image_pixbuf(GdkPixbuf * pixbuf) {
	if (clientLoad!=0) return -1;
	if (pixbuf == NULL) return -1;
	int maxWidth = imgViewport->allocation.width-50;
	int pixWidth = gdk_pixbuf_get_width(pixbuf);
	
	if (maxWidth>0 && maxWidth<pixWidth) {
		int pixHeight = gdk_pixbuf_get_height(pixbuf);
		double factor = ((double)maxWidth/(double)pixWidth);
		pixWidth = pixWidth*factor;
		pixHeight = pixHeight*factor;
		pixbuf=gdk_pixbuf_scale_simple(pixbuf,pixWidth,pixHeight,GDK_INTERP_BILINEAR);
	}
	gtk_image_set_from_pixbuf((GtkImage*)imgBox,pixbuf);
	return 0;
}

void set_status_text(gchar* text) {
	if (clientLoad!=0) return;
	guint id = gtk_statusbar_get_context_id((GtkStatusbar*)statusBar,"simpletext");
	gtk_statusbar_push((GtkStatusbar*)statusBar,id,text);
}
