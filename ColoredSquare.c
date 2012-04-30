#include <stdlib.h>

#include "ColoredSquare.h"

void ColoredSquare_constructor (void *this)
{
  printf ("ColoredSquare_constructor (%lu) called\n",
          (unsigned long) this);
  Square_constructor (this);
  ((ColoredSquare *) this)->color = 0;
}

void ColoredSquare_copy (void *to, void *from)
{
  printf ("ColoredSquare_copy (%lu, %lu) called\n",
          (unsigned long) to,
          (unsigned long) from);
  Square_copy (to, from);
  ((ColoredSquare *) to)->color = ((ColoredSquare *) from)->color;
}

void* ColoredSquare_clone (void *this)
{
  ColoredSquare *csquare = ColoredSquare_new ();
  printf ("ColoredSquare_clone (%lu) called\n",
          (unsigned long) this);
  ColoredSquare_copy (csquare, this);
  printf ("ColoredSquare_clone (%lu) returns %lu\n",
          (unsigned long) this,
          (unsigned long) csquare);

  return csquare;
}

const char* ColoredSquare_type (void *this)
{
  static const char *csquare_type_str = "ColoredSquare";
  printf ("ColoredSquare_type (%lu) called\n",
          (unsigned long) this);
  printf ("ColoredSquare_type (%lu) returns \"%s\"\n",
          (unsigned long) this,
          csquare_type_str);
  return csquare_type_str;
}

void ColoredSquare_draw (void *this)
{
  printf ("ColoredSquare_draw (%lu) called\n",
          (unsigned long) this);
  printf ("Drawing ColoredSquare with %f side and %d color\n",
          ((ColoredSquare *) this)->a,
          ((ColoredSquare *) this)->color);
}

void ColoredSquare_set_color (void *this, int color)
{
  printf ("ColoredSquare_draw (%lu, %d) called\n",
          (unsigned long) this,
          color);

  ((ColoredSquare *) this)->color = color;
}

/* public */
void* ColoredSquare_new ()
{
  static ColoredSquare_interface vtable =
    {
         ColoredSquare_clone,
         Square_destroy,
         ColoredSquare_type,
         ColoredSquare_draw,
         Square_area,
         Square_resize,
         Square_diag_length,
         ColoredSquare_set_color
    };
  ColoredSquare *square = malloc (sizeof (*square));

  printf ("ColoredSquare_new () returns %lu\n",
          (unsigned long) square); 

  square->vtable = (void *) &vtable;

/*goto end;
err:

end:*/

  return square;
}
