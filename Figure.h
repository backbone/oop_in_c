#ifndef __FIGURE_H__
#define __FIGURE_H__

#include <stdio.h>

#include "Object.h"

typedef struct Figure_interface
{
  Object_interface;

  const char* (*type) (void *this);
  void (*draw) (void *this);
  double (*area) (void *this);

} Figure_interface;

typedef struct Figure
{
  Figure_interface *vtable;

} Figure;

#endif // __FIGURE_H__
