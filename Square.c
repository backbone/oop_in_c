#include <stdlib.h>

#include "Square.h"

void Square_constructor (void *this)
{
  printf ("Square_constructor (%lu) called\n",
          (unsigned long) this);
  ((Square *) this)->a = 0.0;
}

void Square_destructor (void *this)
{
  printf ("Square_destructor (%lu) called\n",
          (unsigned long) this);
}

void Square_copy (void *to, void *from)
{
  printf ("Square_copy (%lu, %lu) called\n",
          (unsigned long) to,
          (unsigned long) from);
  ((Square *) to)->a = ((Square *) from)->a;
}

void* Square_clone (void *this)
{
  Square *square = Square_new ();
  printf ("Square_clone (%lu) called\n",
          (unsigned long) this);
  Square_copy (square, this);
  printf ("Square_clone (%lu) returns %lu\n",
          (unsigned long) this,
          (unsigned long) square);

  return square;
}

void Square_destroy (void *this)
{
  printf ("Square_destroy (%lu) called\n",
          (unsigned long) this);
  free (this);
}

const char* Square_type (void *this)
{
  static const char *square_type_str = "Square";
  printf ("Square_type (%lu) called\n",
          (unsigned long) this);
  printf ("Square_type (%lu) returns \"%s\"\n",
          (unsigned long) this,
          square_type_str);

  return square_type_str;
}

void Square_draw (void *this)
{
  printf ("Square_draw (%lu) called\n",
          (unsigned long) this);
  printf ("Drawing Square with %f side\n",
          ((Square *) this)->a);
}

double Square_area (void *this)
{
  double area = ((Square *)this)->a * ((Square *)this)->a;
  printf ("Square_area (%lu) called\n",
          (unsigned long) this);
  printf ("Square_area (%lu) returns %f\n",
          (unsigned long) this,
          area);

  return area;
}

void Square_resize (void *this, double a)
{
  printf ("Square_resize (%lu, %f) called\n",
          (unsigned long) this,
          a);
  ((Square *) this)->a = a;
}

double Square_diag_length (void *this)
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
void* Square_new ()
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

  printf ("Square_new () returns %lu\n",
          (unsigned long) square); 

  square->vtable = (void *) &vtable;

/*goto end;
err:

end:*/

  return square;
}
