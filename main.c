#include <stdio.h>

#include "Rhomb.h"

int main (void)
{
  unsigned long i = 0;
  Figure *fig[3];
  static struct point points1[] = {
    {
      3.1,
      2.8
    },
    {
      8.1,
      -3.1
    },
    {
      -1.88,
      2.11
    },
    {
      3.0,
      4.1
    },
  };
  static struct point points2[] = {
    {
      8.2,
      4.2
    },
    {
      1.1,
      2.2
    },
    {
      7.7,
      5.6
    },
    {
      -12.35,
      -8.3
    },
    {
      -11.13,
      -1.1
    },
    {
      2.3,
      -8.5
    },
  };

  fig[0] = (Figure *) Polygon_new (points2, sizeof (points2) / sizeof (points2[0]));
  fig[1] = (Figure *) Rhomb_new (points1);

  printf ("Is rhomb square? %d\n", Rhomb_is_square ((Rhomb *) fig[1]));
  printf ("Max diag = %f\n", Polygon_max_diag ((Polygon *) fig[0]));
  fig[2] = Figure_clone (fig[1]);
  printf ("Area = %f\n", Figure_area (fig[2]));

  for (i = 0; i < sizeof (fig) / sizeof (Figure *); i++)
    {
      puts ("---");

      printf ("type = %s\n", Figure_type (fig[i]));

      Figure_draw (fig[i]);

      printf ("area(%lu) = %f\n",
              (unsigned long) fig[i],
              Figure_area (fig[i]));
    }
    puts ("---");

/*goto end;
err:
end:*/
  for (i = 0; i < sizeof (fig) / sizeof (Figure *); i++)
    {
      Figure_destroy (fig[i]);
    }

  return 0;
}
