//
//  stack.c
//  zhan
//
//  Created by 岳言 on 16/3/11.
//  Copyright © 2016年 岳言. All rights reserved.
//

#include "stack.h"

#define DataType int
#define MAXSIZE 1024

typedef struct {
    DataType data[MAXSIZE];
    int top;
}SeqStack;

SeqStack *Init_SeqStack()
{
    SeqStack *s;
    
    s = (SeqStack *)malloc(sizeof(SeqStack));
    if (!s) {
        return NULL;
        
    }
    
    s->top = -1;
    
    return s;
    
}
int Empty_SeqStack(SeqStack*s)//判栈空
{
    if (s->top == -1) {
        return 1;
    }
    else return 0;
}

int Push_SeqStack(SeqStack*s,DataType x)//入栈
{
    if (s->top == MAXSIZE-1) {
        return 0;//栈满不能入栈
    }else{
        s->top++;
        s->data[s->top]=x;
        return 1;
    }
}


int Pop_SeqStack(SeqStack *s,DataType *x)//出栈
{
    if (Empty_SeqStack(s)) {
        return 0;//栈空不能出栈
    }else{
        *x = s->data[s->top];
        s->top --;
        return *x;
    }
}

DataType Top_SeqStack(SeqStack*s)//取栈顶元素
{
    if (Empty_SeqStack(s)) {
        return 0;
    }
    else{
        return s->data[s->top];
        
    }
}
int Print_SeqStack(SeqStack *s)
{
    int i;
    for ( i = s->top; i>=0;i--) {
        printf("%d",s->data[i]);
        
    }
    printf("\n");
    return 0;
}