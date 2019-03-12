int count(unsigned int);
int check(unsigned int);


unsigned int f5(unsigned  int x)
{
   if(x < 0x6){
   		switch(x){
   			case 1:
   				x = x<<2;
   				break;		
   			case 2:
   				x += check(x>>2);
   				break;
   			case 4:
   				x = count(x);
   				break;
   			default:
   				x = 7;
   				break;
   		}
   		return x;	
   }
   return 3*x;
}


int count(unsigned int x){
	int y = 0;
	while(x != 0){
		x = x&0x1;
		y = y<<x;
		x = x>>1;
	}
	return y;
}


int check(unsigned int x){
	int y = 1;
	while (x != 0){
		x += x+y;
		y -= 1;
	}
	
	return x;
}
