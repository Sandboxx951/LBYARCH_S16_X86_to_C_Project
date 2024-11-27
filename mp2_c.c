#include <stdio.h>
#include <stdlib.h>
extern float asmGetDistance(float vec1, float vec2, float vec3, float vec4);

int main(){
	int i = 0;
	int nLen = 4;
	float fVecX1[] = {1.5, 4.0, 3.5, 2.0};
	float fVecX2[] = {3.0, 2.5, 2.5, 1.0};
	float fVecY1[] = {4.0, 3.0, 3.5, 3.0};
	float fVecY2[] = {2.0, 2.5, 1.0, 1.5};
	float fVecZ[] = {0.0, 0.0, 0.0, 0.0};
	
	
	
	for(i = 0; i < nLen; i++){
		
		fVecZ[i] = asmGetDistance(fVecX1[i], fVecX2[i], fVecY1[i], fVecY2[i]);
		
	}
	
	for (i = 0; i < 10; i++){
		printf("%f  ", fVecZ[i]);
	}
	return 0;
}
