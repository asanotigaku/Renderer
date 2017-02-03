#ifndef INCLUDED_RAY
#define INCLUDED_RAY

#ifndef INCLUDED_VECTOR
#include "vector.h"
#endif

enum {LIGHTRAY, SHADOWRAY, REFRACTIONRAY, REFLECTIONRAY};

class Ray{
	private:
		pointer_t start;
		Vector start_v;
		Vector direction; 
		int pram;
		bool flag;//初期化されているかのフラグ
	public:
		int type;
		int cross(OBJ* obj, pointer_t* p);
		int pass(pointer_t);//通過判定
		Ray();
		Ray(int, int, int, Vector);
		Ray(int, int, int, pointer_t);
		Ray(pointer_t, Vector);
		void Set(int, int, int, Vector);
		~Ray();
};

#endif
