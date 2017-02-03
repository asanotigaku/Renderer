#ifndef INCLUDED_VECTOR
#define INCLUDED_VECTOR

typedef struct{
	int x,y,z;
}pointer_t;

class Vector{
	private:
		double x,y,z;//ベクトルの要素
	
	public:
		double getScalar();
		double getx() const;
		double gety() const;
		double getz() const;
		Vector& operator=(const Vector vct){
			this->x = vct.getx();
			this->y = vct.gety();
			this->z = vct.getz();
			return *this;
		}
		Vector operator+(Vector vct){
			this->x += vct.getx();
			this->y += vct.gety();
			this->z += vct.getz();
			return *this;
		}
		Vector operator-(){
			this->x = -this->x;
			this->y = -this->y;
			this->z = -this->z;
			return *this;
		}
		Vector operator-(Vector vct){
			vct = -vct;
			this->x -= vct.x;
			this->y -= vct.y;
			this->z -= vct.z;
			return *this;
		}
		friend Vector operator*(int n, Vector &vct){
			vct.x *= n;
			vct.y *= n;
			vct.z *= n;
			return vct;
		}
		double operator*(Vector p){
			return (this->x*p.getx() + this->y*p.gety() + this->z*p.getz());
		}
		Vector operator%(Vector p){
			Vector vct;
			vct.x=this->y*p.getz() - this->z*p.gety();
			vct.y=this->z*p.getx() - this->x*p.getz();
			vct.z=this->x*p.gety() - this->y*p.getx();
			return vct;
		}
		pointer_t operator+(pointer_t p){
			p.x += (int)this->x;
			p.y += (int)this->y;
			p.z += (int)this->z;
			return p;
		}
		pointer_t operator-(pointer_t p){
			p.x -= (int)this->x;
			p.y -= (int)this->y;
			p.z -= (int)this->z;
			return p;
		}
		Vector();
		Vector(int scalar, int xyangle, int xzangle);
		Vector(const Vector &o);
		Vector(double x, double y, double z);
		~Vector();
};

Vector linkDot(pointer_t start, pointer_t end){
	end.x -= start.x;
	end.y -= start.y;
	end.z -= start.z;
	Vector p(end.x, end.y, end.z);
	return p;
}

#endif
