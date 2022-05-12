unsigned int reverse(unsigned int n, unsigned int r){
	
    if(n == 0)
        return r;
    else
        return reverse(n >> 1, (r << 1) | (n & 1));

}
