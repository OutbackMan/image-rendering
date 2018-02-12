#include <X11/Xlib.h>
#include <stdio.h>
#include <stddef.h>

void list_open_windows(Display *display_connection, Window window_to_search)
{
	Window root_window;
	Window parent_window;
	Window *child_windows;
	unsigned int child_window_count;
	// use basic regex parser to handle window text name

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

// incorporate OCR
void run_bot()
{
	teleport_to_start_location();
	reset_view();
	// factor in lag with sleep()
	travel_to_end_location(); // This consists of a series of mouse clicks at particular locations with appropriate pauses for travel duration
	while (last_inventory_space_is_empty()) { // This will check whether the item's colour is found in the last position of inventory
		if (find_pixels(&bubbles_coordinates, x1, x2, y1, y2, bubble_hex_colour) == FOUND) { // x1-y2 are coordinates of area to search for pixels
			click(bubbles_coordinates.x, bubbles_coordinates.y)
			sleep(fishing_duration);
		}
	}
	// Work through each piece of functionality in a sequential order, commenting previous functionality.
	teleport_to_start_location();
	move_to_oven();
	cook_at_oven();
	sell_to_cook();
	
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
