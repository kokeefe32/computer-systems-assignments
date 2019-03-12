int f3( unsigned int x){
    int count = 0;
    while(x != 0){
        if(x & 0x1){
            count += 1;
        }
        x = x>>1;
    }
    return -count;  
}
