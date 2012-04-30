#ifndef __COLORED_SQUARE_H__
#define __COLORED_SQUARE_H__

#include "Square.h"

typedef struct ColoredSquare_data
{
  Square_data;

  int color;

} ColoredSquare_data;

struct ColoredSquare;

typedef struct ColoredSquare_interface
{
  Square_interface;

  void (*set_color) (struct ColoredSquare *this, int color);

} ColoredSquare_interface;

void ColoredSquare_constructor (struct ColoredSquare *this,
                                double a,
                                int color);
void ColoredSquare_copy (struct ColoredSquare *to, struct ColoredSquare *from);
struct ColoredSquare* ColoredSquare_clone (struct ColoredSquare *this);
const char* ColoredSquare_type (struct ColoredSquare *this);
void ColoredSquare_draw (struct ColoredSquare *this);
void ColoredSquare_set_color (struct ColoredSquare *this, int color);

/* public */
typedef struct ColoredSquare
{
  ColoredSquare_interface *vtable;

  ColoredSquare_data;

} ColoredSquare;

ColoredSquare* ColoredSquare_new (double a, int color);

#endif // __COLORED_SQUARE_H__
