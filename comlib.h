int strlen(const char * str){
	if(str==NULL)
	{
		return 0;
	}
	int len=0;
	for(;*str!='\0';len++){
		str++;
	}
	return len;
}