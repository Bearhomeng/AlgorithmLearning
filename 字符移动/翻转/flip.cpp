#include<iostream>
#include<conio.h>
using namespace std;
void LeftShiftString(char *str,int len,int shift);
void reverseString(char*str,int start,int end);
int main(){
	int shift;
	char str[20];
	cout<<"INPUT String:";
	cin>>str;
	cout<<"INPUT Shift:";
	cin>>shift;
	LeftShiftString(str,strlen(str),shift);
	cout<<str<<endl;
	//system("pause");
}

void LeftShiftString(char *str,int len,int shift){
	reverseString(str,0,shift-1);
	reverseString(str,shift,len-1);
	reverseString(str,0,len-1);
}

void reverseString(char *str,int start,int end){
	while(start<end){
		char temp = str[start];
		str[start++]=str[end];
		str[end--]=temp;
	}
}