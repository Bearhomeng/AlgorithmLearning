#include <stdio.h>
#include <iostream>
using namespace std;
void LeftShiftOne(char *str, int len);
void LeftShiftString(char *str, int len, int shift);
int strLen(const char * str);

int main(){
	char str[] = {'a','b','c','d','e','f','g','\0'};
	//cout<< str;
	//cout << strLen(str);
	LeftShiftString(str, strlen(str), 3);
	cout << str << endl;
	cin >> str[0];
	return 0;
}

void LeftShiftOne(char *str, int len){
	assert(str != NULL);
	char t = str[0];
	for (int i = 1; i<len; i++)
	{
		str[i - 1] = str[i];
	}
	str[len - 1] = t;
}

void LeftShiftString(char *str, int len, int shift){
	for (int i = 0; i<shift; i++){
		LeftShiftOne(str, len);
	}
}


int strLen(const char * str){
	if (str == NULL)
	{
		return 0;
	}
	int len = 0;
	for (; *str != '\0'; len++){
		str++;
	}
	return len;
}
