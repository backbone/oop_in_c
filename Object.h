#ifndef __OBJECT_H__
#define __OBJECT_H__

typedef struct Object
{
  struct Object_vtable
  {
    /* Object methods */
    const char* (*type) ();
    struct Object* (*clone) (const Object *this);
    void (*destroy) (struct Object *this);
  
  } *vtable;

} Object;

#endif // __OBJECT_H__
