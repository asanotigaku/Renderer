#include "ray.h"

#ifndef INCLUDED_STDLIB
#include <stdlib.h>
#define INCLUDED_STDLIB
#endif

#ifndef INCLUDED_IOSTREAM
#include <iostream>
#define INCLUDED_IOSTREAM
#endif

#define SQ(x) ((x)*(x))

int Ray::cross(OBJ* obj, pointer_t* p){
	switch(obj.type){
	case SPHERE:
		double A = SQ(direction.getScalar());
		double B = (start_v - obj.center) * direction;
		double C = SQ((obj.center - start_v).getScalar()) - obj.radius;
		double t1,t2;
		if((SQ(B) - A * C) > 0){
			t1 = (-B + sqrt(SQ(B)-AC))/A;
			t2 = (-B - sqrt(SQ(B)-AC))/A;
			if(t1<t2){
				p->x = start_v.x + t1*direction.x;
				p->y = start_v.y + t1*direction.y;
				p->z = start_v.z + t1*direction.z;
				break;
			}else{
				p->x = start_v.x + t2*direction.x;
				p->y = start_v.y + t2*direction.y;
				p->z = start_v.z + t2*direction.z;
				break;
			}
		}else if((SQ(B) - A * C) == 0){
			t1 = -B / A;
			p->x = start_v.x + t1*direction.x;
			p->y = start_v.y + t1*direction.y;
			p->z = start_v.z + t1*direction.z;
		}else return -1;
		break;
	default:
		return -2;
	}
	return 0;
}

Ray::Ray(int x, int y, int z, Vector p){
	start.x = x;
	start.y = y;
	start.z = z;
	direction = p;
	pram = 0;
}

Ray::Ray(int scalar, int xyangle, int xzangle, pointer_t s){
	start = s;
	Vector direction(scalar, xyangle, xzangle);
	pram = 0;
}

Ray::Ray(pointer_t s, Vector d){
	start = s;
	direction = d;
	pram = 0;
}

Ray::Ray(){
	start.x = 0;
	start.y = 0;
	start.z = 0;
	pram = 0;
}

Ray::Ray(const Ray &obj){
	start = obj.start;
	start_v = obj.start_v;
	direction = obj.direction;
	pram = obj.pram;
	flag = obj.flag;
}

void Ray::Set(int x, int y, int z, Vector direction){
	start.x = x;
	start.y = y;
	start.z = z;
	direction = p;
	return;
}

void Ray::Set(int scalar, int xyangle, int xzangle, pointer_t s){
	start = s;
	Vector direction(scalar, xyangle, xzangle);
	pram = 0;
}

int Ray::pass(pointer_t p){
	Vector line = (pram * direction);
	if(double(p.x/line.x == p.y/line.y) && double(p.x/line.x == p.z/line.z)){
		return 1;
	}
	return 0;
}

Ray::~Ray(){
}
