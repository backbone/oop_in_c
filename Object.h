#ifndef __OBJECT_H__
#define __OBJECT_H__

typedef struct Object
{
  struct Object_vtable
  {
    /* Object methods */
    const char* (*type) ();
    struct Object* (*clone) (const struct Object *this);
    void (*destroy) (struct Object *this);
  
  } *vtable;

} Object;

static inline const char* Object_type (const Object *this)
{
  return this->vtable->type ();
}

static inline Object* Object_clone (const Object *this)
{
  return this->vtable->clone (this);
}

static inline void Object_destroy (Object *this)
{
  this->vtable->destroy (this);
}

#endif // __OBJECT_H__
