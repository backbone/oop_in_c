#include <stdlib.h>
#include <stdio.h>

#include "ColoredSquare.h"

void ColoredSquare_constructor (ColoredSquare *this,
                                double a,
                                int color)
{
  printf ("ColoredSquare_constructor (%lu, %f, %d) called\n",
          (unsigned long) this,
          a,
          color);
  Square_constructor ((Square *) this, a);
  this->color = color;
}

void ColoredSquare_copy (ColoredSquare *to, const ColoredSquare *from)
{
  printf ("ColoredSquare_copy (%lu, %lu) called\n",
          (unsigned long) to,
          (unsigned long) from);
  Square_copy ((Square *) to, (Square *) from);
  to->color = from->color;
}

ColoredSquare* ColoredSquare_clone (const ColoredSquare *this)
{
  ColoredSquare *csquare = ColoredSquare_new (0.0, 0);
  printf ("ColoredSquare_clone (%lu) called\n",
          (unsigned long) this);
  ColoredSquare_copy (csquare, this);
  printf ("ColoredSquare_clone (%lu) returns %lu\n",
          (unsigned long) this,
          (unsigned long) csquare);

  return csquare;
}

const char* ColoredSquare_type (const ColoredSquare *this)
{
  static const char *csquare_type_str = "ColoredSquare";
  printf ("ColoredSquare_type (%lu) called\n",
          (unsigned long) this);
  printf ("ColoredSquare_type (%lu) returns \"%s\"\n",
          (unsigned long) this,
          csquare_type_str);
  return csquare_type_str;
}

void ColoredSquare_draw (const ColoredSquare *this)
{
  printf ("ColoredSquare_draw (%lu) called\n",
          (unsigned long) this);
  printf ("Drawing ColoredSquare with %f side and %d color\n",
          this->a,
          this->color);
}

void ColoredSquare_set_color (ColoredSquare *this, int color)
{
  printf ("ColoredSquare_draw (%lu, %d) called\n",
          (unsigned long) this,
          color);

  this->color = color;
}

/* public */
ColoredSquare* ColoredSquare_new (double a, int color)
{
  static ColoredSquare_interface vtable =
    {
      {
        {
          {
            (void* (*) (const void *)) ColoredSquare_clone,
            (void (*) (void *)) Square_destroy
          },
          (const char* (*) (const Figure *)) ColoredSquare_type,
          (void (*) (const Figure *)) ColoredSquare_draw,
          (double (*) (const Figure *)) Square_area
        },
        Square_resize,
        Square_diag_length
      },
      ColoredSquare_set_color
    };
  ColoredSquare *square = malloc (sizeof (*square));

  ColoredSquare_constructor (square, a, color);

  printf ("ColoredSquare_new (%f, %d) returns %lu\n",
          a,
          color,
          (unsigned long) square); 

  square->vtable = &vtable;

/*goto end;
err:

end:*/

  return square;
}
