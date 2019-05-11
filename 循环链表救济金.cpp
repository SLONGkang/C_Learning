
#include<stdio.h>

#include<malloc.h>

 

struct Node

{

 int data;

 Node *next;

 Node *prior;      

};

 

Node* CreateList(Node* &head, int n);

Node* searchk(Node *ptr, Node* &head, int k);

Node* rsearchm(Node *ptr, Node* &head, int m);

void deletenode(Node *ptr);

void show(Node* ptr);

 

int main()

{

 int n,k,m;

 while(scanf("%d%d%d",&n,&k,&m)==3 && (n||k||m))   

 {

  Node *head=NULL;

  Node *mnode=CreateList(head,n); //show(head);

  Node *knode=head->next;

  bool flag=0;

  while(head->next!=head)

  {

   if(flag) printf(",");

   knode=searchk(knode,head,k); //printf("%d\n",knode->data);

   mnode=rsearchm(mnode,head,m);

   bool b=1;//标记最后两个deletenode别重复free 

   if(knode!=mnode) printf("%3d%3d",knode->data,mnode->data);

   else { printf("%3d",knode->data); b=0;}  

   flag=1;   

   Node *sk=knode,*sm=mnode;//下面两句考虑到next位置会不会恰好是要删除的结点 

   knode=knode->next; while(knode==sm) knode=knode->next;

   mnode=mnode->prior; while(mnode==sk) mnode=mnode->prior;

   

   deletenode(sk);

   if(b) deletenode(sm);                

  }  

  printf("\n");

  free(head);                               

 }//while

 return 0;

}

 

void show(Node* ptr)

{

 Node *p=ptr->next;

 while(p!=ptr)

 {

  printf("%d\n",p->data);                 

  p=p->next;

 }

}

 

void deletenode(Node *ptr)

{

 if(ptr==NULL) return;

 ptr->prior->next=ptr->next;

 ptr->next->prior=ptr->prior;

 free(ptr);    

 ptr=NULL;

}

 

Node* rsearchm(Node *ptr, Node* &head, int m)

{//逆序移动到当前位置的第m个元素，返回该元素位置 

 int i=1;

 Node *p=ptr;

 while(i<m)

 {

  if(p==head) p=p->prior;

  p=p->prior;

  i++;         

 }

 if(p==head) p=p->prior;

 return p;/*

 while(p!=head && i<m)

 {

  p=p->prior;

  i++;             

 }    

 if(p==head) p=p->prior;

 while(i<m)

 {

  p=p->prior;

  i++;         

 } 

 if(p==head) p=p->prior;

 return p;*/

}

 

Node* searchk(Node *ptr, Node* &head, int k)

{//顺序移动到当前位置ptr的第k个元素，返回该元素位置 (即数的这k个位置包括当前位置)

 int i=1;

 Node *p=ptr;

 while(i<k)

 {

  if(p==head) p=p->next;  //!!! if里面的== 

  p=p->next;

  i++;         

 }

 if(p==head) p=p->next;

 return p;

}

 

Node* CreateList(Node* &head, int n)

{//顺序创建n个结点，head为头指针，next指向头结点；并返回尾结点指针 

 head=(Node*)malloc(sizeof(Node));

 head->next=NULL; head->data=0;

 head->prior=NULL;

 Node* ptr=head;

 for(int i=1;i<=n;++i)

 {

  Node* p=(Node*)malloc(sizeof(Node));

  ptr->next=p;

  p->data=i;

  p->next=NULL;

  p->prior=ptr;

  ptr=p;       

 }  

 //ptr->next=head->next;//n的后一个结点是1 

 //head->next->prior=ptr;//1的前一个结点是n 

 head->prior=ptr;

 ptr->next=head;//n的后一个结点是头指针 

 return ptr;

}

