#include <stdio.h>
#include <stdlib.h>

#include "ColoredSquare.h"

int main (void)
{
  unsigned long i = 0;
  Figure *fig[3];

  fig[0] = (Figure *) Square_new (1);
  fig[1] = (Figure *) ColoredSquare_new (2, 2);

  ((ColoredSquare *) fig[1])->vtable->set_color ((ColoredSquare *) fig[1], 5);
  ((Square *) fig[0])->vtable->resize ((Square *) fig[0], 2);
  ((Square *) fig[1])->vtable->resize ((Square *) fig[0], 3);

  fig[2] = fig[1]->vtable->clone (fig[1]);
  ((ColoredSquare *) fig[2])->vtable->set_color ((ColoredSquare *) fig[2], 3);

  for (i = 0; i < sizeof (fig) / sizeof (Figure *); i++)
    {
      puts ("---");

      printf ("type = %s\n", fig[i]->vtable->type (fig[i]));

      fig[i]->vtable->draw (fig[i]);

      printf ("area(%lu) = %f\n",
              (unsigned long) fig[i],
              fig[i]->vtable->area (fig[i]));

      printf ("diag_length(%lu) = %f\n",
              (unsigned long) fig[i],
              ((Square *) fig[i])->vtable->diag_length ((Square *) fig[i]));
    }
    puts ("---");

/*goto end;
err:
end:*/
  for (i = 0; i < sizeof (fig) / sizeof (Figure *); i++)
    {
      fig[i]->vtable->destroy (fig[i]);
    }

  return 0;
}
