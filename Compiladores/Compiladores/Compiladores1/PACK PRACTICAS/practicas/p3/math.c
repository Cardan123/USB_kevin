#include <math.h>
#include <errno.h>
#include "hoc.h"


char And (char x, char y){
	if(x == 'f' || y == 'f'){
			return 'f';
		}else{
			return 't';
		}
}

char Or (char x, char y){
	if(x == y){
			return x;
		}else{
			return 't';
		}
}

char Not (char x){
	if(x == 't'){
		return 'f';
	}else{
		return 't';
	}
}

