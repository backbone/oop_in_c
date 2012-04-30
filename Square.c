#include <stdlib.h>

#include "Square.h"

void Square_constructor (Square *this, double a)
{
  printf ("Square_constructor (%lu, %f) called\n",
          (unsigned long) this,
          a);
  ((Square *) this)->a = a;
}

void Square_destructor (Square *this)
{
  printf ("Square_destructor (%lu) called\n",
          (unsigned long) this);
}

void Square_copy (Square *to, Square *from)
{
  printf ("Square_copy (%lu, %lu) called\n",
          (unsigned long) to,
          (unsigned long) from);
  ((Square *) to)->a = ((Square *) from)->a;
}

Square* Square_clone (Square *this)
{
  Square *square = Square_new (0.0);
  printf ("Square_clone (%lu) called\n",
          (unsigned long) this);
  Square_copy (square, this);
  printf ("Square_clone (%lu) returns %lu\n",
          (unsigned long) this,
          (unsigned long) square);

  return square;
}

void Square_destroy (Square *this)
{
  printf ("Square_destroy (%lu) called\n",
          (unsigned long) this);
  free (this);
}

const char* Square_type (Square *this)
{
  static const char *square_type_str = "Square";
  printf ("Square_type (%lu) called\n",
          (unsigned long) this);
  printf ("Square_type (%lu) returns \"%s\"\n",
          (unsigned long) this,
          square_type_str);

  return square_type_str;
}

void Square_draw (Square *this)
{
  printf ("Square_draw (%lu) called\n",
          (unsigned long) this);
  printf ("Drawing Square with %f side\n",
          ((Square *) this)->a);
}

double Square_area (Square *this)
{
  double area = ((Square *)this)->a * ((Square *)this)->a;
  printf ("Square_area (%lu) called\n",
          (unsigned long) this);
  printf ("Square_area (%lu) returns %f\n",
          (unsigned long) this,
          area);

  return area;
}

void Square_resize (Square *this, double a)
{
  printf ("Square_resize (%lu, %f) called\n",
          (unsigned long) this,
          a);
  ((Square *) this)->a = a;
}

double Square_diag_length (Square *this)
{
  double diag_length = ((Square *)this)->a * 1.41421356;

  printf ("Square_diag_length (%lu) called\n",
          (unsigned long) this);
  printf ("Square_diag_length (%lu) returns %f\n",
          (unsigned long) this,
          diag_length);

  return diag_length;
}

/* public */
Square* Square_new (double a)
{
  static Square_interface vtable =
    {
         Square_clone,
         Square_destroy,
         Square_type,
         Square_draw,
         Square_area,
         Square_resize,
         Square_diag_length
    };
  Square *square = malloc (sizeof (*square));

  Square_constructor (square, a);

  printf ("Square_new (%f) returns %lu\n",
          a,
          (unsigned long) square); 

  square->vtable = (Square_interface *) &vtable;

/*goto end;
err:

end:*/

  return square;
}
