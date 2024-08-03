// #include<stdio.h>
// #include<stdlib.h>
// #include<string.h>
// #define Max 255
// /*定长顺序存储结构*/
// typedef struct{
//     char ch[Max];
//     int len;
// }SString;
// // 初始化字符串
// void initString(SString *str){
//     str->len=0;
//     return;
// }
// // ababaaababaa
// void GetNext(SString T, int next[]){
//     int i=1, j=0; // 从1开始匹配
//     next[1]=0;
//     while(i<=T.len){  //遍历模式串
//         if(j==0||T.ch[i]==T.ch[j]){
//             ++i;   //当前处理模式串的位置，从1开始
//             ++j;   //当前匹配的最长前缀的长度
//             next[i]=j;  //记录当前位置的最长前缀
//         }
//         else{
//             j=next[j];
//         }
//     }
// }
// // KMP模式匹配算法 --- 获取匹配成功的起始位置

// int main(){
//     SString S, T;
//     // 使用strcpy进行字符串赋值
//     strcpy(S.ch, "liangguidong");
//     strcpy(T.ch, "aaab"); //   ababa  ababaaababaa

//     // 设置字符串长度
//     S.len = strlen(S.ch);
//     T.len = strlen(T.ch);
//     printf("%d\n", T.len);
//     int next[5]={0};
//     GetNext(T, next);
//     for(int i=1;i<=T.len;i++) printf("%d ",next[i]);
//     return 0;
    
// }    


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Max 255

/* 定长顺序存储结构 */
typedef struct {
    char ch[Max];
    int len;
} SString;

// 初始化字符串
void initString(SString *str) {
    str->len = 0;
    return;
}

void GetNext(SString T, int next[]) {
    int i = 0, j = -1; // 修改为从0开始
    next[0] = -1;
    while (i < T.len - 1) {  // 遍历模式串
        if (j == -1 || T.ch[i] == T.ch[j])
            next[++i] = ++j;  // 记录当前位置的最长前缀
        else {
            j = next[j];
        }
    }
}

void NextVal(SString T, int next[]) {
    int i = 1; // 修改为从0开始
    while (i < T.len) {  // 遍历模式串
        if (T.ch[next[i]]==T.ch[i]) next[i]=next[next[i]];
        i++;
    }
    return;
}

// KMP模式匹配算法 --- 获取匹配成功的起始位置
int KMP(SString S, SString T, int next[]) {
    int i = 0, j = 0;
    while (i < S.len && j < T.len) {
        if (j == -1 || S.ch[i] == T.ch[j]) {
            i++;
            j++;
        } else {
            j = next[j];
        }
    }
    if (j == T.len) {
        return i - j; // 返回匹配的起始位置
    } else {
        return -1; // 匹配失败
    }
}

int main() {
    SString S, T;
    // 使用strcpy进行字符串赋值
    strcpy(S.ch, "ababababaaababaa");
    strcpy(T.ch, "ababaaababaa");

    // 设置字符串长度
    S.len = strlen(S.ch);
    T.len = strlen(T.ch);
    printf("Pattern length: %d\n", T.len);

    int next[Max];
    int nextval[Max];
    GetNext(T, next);
    
    printf("Next array: ");
    for (int i = 0; i < T.len; i++) {
        printf("%d ", next[i]);
    }
    printf("\n");

    NextVal(T, next);
    printf("Nextval array: ");
    for (int i = 0; i < T.len; i++) {
        printf("%d ", next[i]);
    }
    printf("\n");

    int pos = KMP(S, T, next);
    if (pos != -1) {
        printf("Pattern found at index: %d\n", pos);
    } else {
        printf("Pattern not found.\n");
    }

    return 0;
}


