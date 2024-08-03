#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Max 255
/*定长顺序存储结构*/
typedef struct{
    char ch[Max];
    int len;
}SString;
// 初始化字符串
void initString(SString *str){
    str->len=0;
    return;
}
// 简单模式匹配算法 --- 获取匹配成功的起始位置
int indexstr(SString S, SString T){
    int i=0,j=0; // i和j分别指向S，T的当前匹配位置
    while(i<S.len&&j<T.len){
        if(S.ch[i]==T.ch[j]){
            i++;
            j++;
        }
        else{
            i=i-j+1;
            j=0;
        }
    }
    if(j>=T.len) return i-j;
    return -1;
}
void print(int position, int len, SString S){
    for(int i=0;i<len;i++) printf("%c", S.ch[i+position]);
    return;
}
int main(){
    SString S, T;
    // 使用strcpy进行字符串赋值
    strcpy(S.ch, "liangguidong");
    strcpy(T.ch, "dong");

    // 设置字符串长度
    S.len = strlen(S.ch);
    T.len = strlen(T.ch);
    int position=indexstr(S,T);
    if(position<0){
        printf("查找失败!\n");
        return 0;
    }
    printf("position=%d\n", position);
    print(position, T.len, S);
    return 0;
}    