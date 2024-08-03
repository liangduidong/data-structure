#include<stdio.h>
#include<stdlib.h>
#define INT_MAX 0x7fffffff 

int cur_min(int a,int b,int c){  //¼ÆËã¾àÀë 
	int s=0;
	if(a>b) s+=a-b;
	else    s+=b-a;
	if(a>c) s+=a-c;
	else    s+=c-a;
	if(b>c) s+=b-c;
	else    s+=c-b;
	return s;
}

bool is_min(int a,int b,int c){
	if(a<=b&&a<=c) return true;
	return false;
}

int main(){
	int a[]={-1,0,9},b[]={-25,-10,10,11},c[]={2,9,17,30,41},n1=3,n2=4,n3=5;
	int cura=0,curb=0,curc=0,min=INT_MAX,curmin;
	while(cura<n1&&curb<n2&&curc<n3){
		curmin=cur_min(a[cura],b[curb],c[curc]);
	    if(min>curmin) min=curmin;
		if(is_min(a[cura],b[curb],c[curc])) cura++;
		else if(is_min(b[curb],a[cura],c[curc])) curb++;
		else curc++;
		printf("a=%d,b=%d,c=%d,curmin=%d\t\n",a[cura],b[curb],c[curc],curmin);
	}
	printf("\n%d",min);
	return 0;
}


//#include<stdio.h>
//#include<stdlib.h>
////#define INT_MAX 0x7fffffff
//int max_num(int a,int b,int c){  
//	int temp=a;
//	if(b>temp) temp=b;
//	if(c>temp) temp=c;
//	return temp;
//}
//
//int cur_min(int a,int b,int c){  //¼ÆËã¾àÀë 
//	int s=0;
//	if(a>b) s+=a-b;
//	else    s+=b-a;
//	if(a>c) s+=a-c;
//	else    s+=c-a;
//	if(b>c) s+=b-c;
//	else    s+=c-b;
//	return s;
//}
//int main(){
//	int a[]={-1,0,9},b[]={-25,-10,10,11},c[]={2,9,17,30,41},n1=3,n2=4,n3=5;
//	int cura=0,curb=0,curc=0,min=999999,curmin;
//	while(cura<n1&&curb<n2&&curc<n3){
//		int max=max_num(a[cura],b[curb],c[curc]);
//		int s1=cura,s2=curb,s3=curc;
//		while(cura<n1&&a[cura]<max) cura++; 
//		while(curb<n2&&b[curb]<max) curb++;
//		while(curc<n3&&c[curc]<max) curc++;
//		if(cura>s1) s1=cura-1;
//		if(curb>s2) s2=curb-1;
//		if(curc>s3) s3=curc-1;
//		curmin=cur_min(a[s1],b[s2],c[s3]);
//		printf("a=%d,b=%d,c=%d,curmin=%d\t\n",a[s1],b[s2],c[s3],curmin);
//		if(min>curmin) min=curmin;
//	}
//	printf("\n%d",min);
//	return 0;
//}











