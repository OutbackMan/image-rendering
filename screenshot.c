#include <X11/Xlib.h>
#include <stdio.h>
#include <stddef.h>

void list_open_windows(Display *display_connection, Window window_to_search)
{
	Window root_window;
	Window parent_window;
	Window *child_windows;
	unsigned int child_window_count;

	if (XQueryTree(display_connection, window_to_search, &root_window, &parent_window, &child_windows, &child_window_count)) {
			
		XWindowAttributes window_attributes;		
		int window_width, window_height;
		int window_x, window_y;
		char *window_name;

		for (int i = 0; i < child_window_count; i++) {
			XGetWindowAttributes(display_connection, child_windows[i], &window_attributes);

			if (XFetchName(display_connection, child_windows[i], &window_name)) {
				printf("Window name: %s\n", window_name);
				XFree(window_name);
			}
			
			printf("Window name: NOT SET\n");
			printf("Window x: %d, y: %d\n", window_x, window_y);
			printf("Window width: %d, height: %d\n", window_width, window_height);
		}
		XFree(child_windows);	
	} else {
		printf("FAILED TO RETRIEVE LIST\n");
	}

}

int main(void)
{
	Display *display = XOpenDisplay("");
	Window root = DefaultRootWindow(display);

	list_open_windows(display, root);

	XImage *image = XGetImage(display, root, 0, 0, <root.width>, <root.height>, AllPlanes, ZPixmap);

	unsigned long red_mask = image->red_mask;
	unsigned long green_mask = image->green_mask;
	unsigned long blue_mask = image->blue_mask;

	unsigned char arr[width * height][3] = { 0 };

	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			unsigned long pixel = XGetPixel(image, x, y);

			unsigned char red = pixel & red_mask;
			unsigned char green = pixel & green_mask;
			unsigned char blue = pixel & blue_mask;

			

		}
	}

	XCloseDisplay(display);

	return 0;
}
