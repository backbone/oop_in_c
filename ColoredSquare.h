#ifndef __COLORED_SQUARE_H__
#define __COLORED_SQUARE_H__

#include "Square.h"

typedef struct ColoredSquare_data
{
  Square_data;

  int color;

} ColoredSquare_data;

typedef struct ColoredSquare_interface
{
  Square_interface;

  void (*set_color) (void *this, int color);

} ColoredSquare_interface;

void ColoredSquare_constructor (void *this);
void ColoredSquare_copy (void *to, void *from);
void* ColoredSquare_clone (void *this);
const char* ColoredSquare_type (void *this);
void ColoredSquare_draw (void *this);
void ColoredSquare_set_color (void *this, int color);

/* public */
typedef struct ColoredSquare
{
  ColoredSquare_interface *vtable;

  ColoredSquare_data;

} ColoredSquare;

void* ColoredSquare_new ();

#endif // __COLORED_SQUARE_H__
