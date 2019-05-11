#include <graphics.h>
#include <stdio.h>
#include <conio.h> 
#include <stdlib.h> 
#include <malloc.h> /*����Cͼ����Ҫ��һЩͷ�ļ�*/ 

#define STACK_INIT_SIZE 100 /*�洢�ռ��ʼ������*/ 
#define STACKINCREMENT 10 /*�洢�ռ��������*/ 

typedef enum {false,true}bool; /*bool*/ 

typedef struct{ /*��¼���ӵ�*/ 
int x; 
int y;
}SEED; 

typedef struct { 
SEED *base; 
SEED *top; 
int stacksize; 
}STACK; 

STACK s; 
SEED e; 
int initstack() { /*����̬ջ*/ 
s.base=(SEED *)malloc(STACK_INIT_SIZE*sizeof(SEED)); 
if(!s.base) exit(0); 
s.top=s.base; 
s.stacksize=STACK_INIT_SIZE; 
return 0; } 

int push(SEED e) { 
if(s.top-s.base>=s.stacksize) { 
s.base=(SEED *)realloc(s.base,(s.stacksize+STACKINCREMENT)*sizeof(SEED)); 
if(!s.base) 
exit(0); 
s.top=s.base+s.stacksize; 
s.stacksize+=STACKINCREMENT; } 
*s.top++=e; 
return 0; } 

SEED pop() { 
if(s.top==s.base) 
exit(0); 
else { 
e=*--s.top; 
return e; } 
} 

int clearstack() { 
s.top=s.base; 
return 0; 
} 

int stackempty() { 
if(s.top==s.base) 
return 1; 
else return 0; } 
