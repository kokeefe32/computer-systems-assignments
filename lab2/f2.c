long f2(int x){
	long y = 0x11;
	int i;
	x = (x<<3)-x;
	for(i = 0; i < x; i++){
		y+=i;
	} 
	return y;
 }
