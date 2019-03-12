char f4(unsigned int i) {
	if(i < 0xa)
		return (char)i+0x40;
	if(i <= 0xf)
		return (char)i+0x60;
	return (char)0x41;

}
