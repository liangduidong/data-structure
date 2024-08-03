#include<stdio.h>
int main(){
	char str[]="ABCD";
	char *p=str;  
	printf("%d\n",*(p+4)); //估计空指针十进制就是\0吧
	if(*(p+5)=='\0') printf("%d",'\0'); 
	return 0;
} 
