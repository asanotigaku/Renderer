#include "vector.h"

#ifndef INCLUDED_MATH
#include <math.h>
#define INCLUDED_MATH
#endif

#define SQ(x) ((x)*(x))

#define PI 3.141592

Vector::Vector(){
	x = 0;
	y = 0;
	z = 0;
}
Vector::Vector(int scalar, int xyangle, int xzangle){
	y = scalar*sin(xyangle*PI/180);
	double r = scalar*cos(xyangle*PI/180);
	z = r*sin(xzangle*PI/180);
	x = r*cos(xzangle*PI/180);
}
Vector::Vector(const Vector &o){
	x = o.getx();
	y = o.gety();
	z = o.getz();
}
Vector::Vector(double xx, double yy, double zz){
	x = xx;
	y = yy;
	z = zz;
}

double Vector::getScalar(){
	return sqrt(SQ(getx())+SQ(gety())+SQ(getz()));
}
Vector::~Vector(){}
double Vector::getx() const{
	return x;
}
double Vector::gety() const{
	return y;
}
double Vector::getz() const{
	return z;
}
