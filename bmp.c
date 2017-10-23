#include <stdint.h>

struct BMPFileHeader {
	uint16_t file_type;
	uint32_t file_size;
	// These values depend on the application creating them
	int16_t reserved_field_1;
	int16_t reserved_field_2;
	uint32_t bitmap_offset;
};

struct BitmapHeader {
	uint32_t size;
	int32_t width;
	int32_t height;
	uint16_t planes;
	uint16_t bits_per_pixel;
	uint32_t compression;
	uint32_t size_of_bitmap;
	uint32_t horizontal_resolution;
	uint32_t vertical_resolution;
	uint32_t colours_used;
	uint32_t important_colours;
};

struct ColourTable {
	uint8_t blue;
	uint8_t green;
	uint8_t red;
};

// P.G 392 for read functions

// If allocating memory for parameter, add a level of indirection
void read_bmp(char *filename, short **img_array)
{
	
}

// Look at start ...
void write_bmp()
{

}

void read_bmp_file_header(char *filename, struct BMPFileHeader *bmp_file_header)
{
	
}
