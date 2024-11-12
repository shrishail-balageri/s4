#include<stdio.h>
typedef struct{
    int PROMPT;
    int STORE;
    int COMPUTE;
    int DISPLAY;
}keywords;
int main(){
    char ch;
    FILE *fp=fopen("pseudocode.txt","r");
    if(fp==NULL){
        printf("ERROR IN OPENING FILES ");
    }
    while((ch=fgetc(fp))!=EOF){
        printf("%c",ch);
    }
}