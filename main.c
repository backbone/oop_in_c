#include <stdio.h>
#include <stdlib.h>

#include "ColoredSquare.h"

int main (int argc, char *argv[])
{
  Figure *fig[2];

  fig[0] = Square_new ();
  fig[1] = ColoredSquare_new ();

  ((ColoredSquare *) fig[1])->vtable->set_color (fig[1], 5);
  ((Square *) fig[0])->vtable->resize (fig[0], 2);
  ((Square *) fig[1])->vtable->resize (fig[0], 3);

  fig[0]->vtable->draw (fig[0]);
  fig[1]->vtable->draw (fig[1]);

  printf ("area(%lu) = %f\n",
          (unsigned long) fig[0],
          fig[0]->vtable->area (fig[0]));
  printf ("area(%lu) = %f\n",
          (unsigned long) fig[1],
          fig[1]->vtable->area (fig[1]));

  printf ("diag_length(%lu) = %f\n",
          (unsigned long) fig[0],
          ((Square *) fig[0])->vtable->diag_length (fig[0]));

/*goto end;
err:
end:*/
  fig[0]->vtable->destroy (fig[0]);
  fig[1]->vtable->destroy (fig[1]);

  return 0;
}
