#include<stdio.h>
int main(){
	char str[]="ABCD";
	char *p=str;  
	printf("%d\n",*(p+4)); //���ƿ�ָ��ʮ���ƾ���\0��
	if(*(p+5)=='\0') printf("%d",'\0'); 
	return 0;
} 
