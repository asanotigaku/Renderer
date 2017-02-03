#ifndef INCLUDED_CAMERA
#define INCLUDED_CAMERA

#ifndef INCLUDED_VECTOR
#include "vector.h"
#endif

#ifndef INCLUDED_RAY
#include "ray.h"
#endif

#ifndef INCLUDED_OBJ
#include "obj.h"
#endif

class Camera{
	private:
		pointer_t eye;
		Ray p[360*360];
		OBJ* obj;
	public:
		void seteye(pointer_t p);
		void setObj(OBJ*);
		Camera();
		~Camera();
};
#endif
