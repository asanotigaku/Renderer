#ifndef INCLUDED_RAY
#include "ray.h"
#endif

#ifndef INCLUDED_CAMERA
#include "camera.h"
#endif

#define SQ(x) ((x)*(x))

Camera::Camera(OBJ obj, pointer_t light, pointer_t e){
	Ray p[360*360];
	eys = e;
	for(int i=0;i<360*360;i++){
		Ray p[i].set(1, (int)(i/360), (int)(i%360), eye);
		pointer_t crossPoint;
		Vector y;
		while(true){
			if(cross(p[i].drawHalfLine(), obj, &crossPoint)){
				y = linkDot(crossPoint, light);
				Ray q(crossPoint, y);
				while(true){
					if(cross(q.drawHalfLine(), obj)){//物体との交差判定
						q.type = SHADOWRAY;
						break;
					}else if(q.pass(light)){
						q.type = LIGHTRAY;

					}
				}
				break;
			}
		}
	
	
	
	
	
	}
}

Camera::~Camera(){}

/*※　ココには平面とレイの交差判定をする関数が書いてあります。定義はカメラのヘッダファイルへどうぞ※　*/

int cross(HalfLine_t Line, OBJ obj, pointer_t* crossPoint){
	//半直線をベクトルで受け取る
	//オブジェクトの情報を受け取る
	//交点を返す
	switch(obj.type){
	case SPHERE:
		int r;
		
	
	}




}
