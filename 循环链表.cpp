
#include <stdio.h>

#include <stdlib.h>

 

typedef struct node

{

    int data;

    struct node *next;//ָ����

    int size;//ѭ������ĳ���

}node,*linklist;//linklistΪ�����ָ��ṹ�����

 

void create_list_head(linklist *l)//ͷ�巨����ѭ������

{

    int i,j,x;

    linklist p,q;

    printf("please input length");

    scanf("%d",&j);

    (*l)=(node*)malloc(sizeof(node));

    (*l)->next=NULL;//���붨�壬ȱ��error

    (*l)->size=j;

    for(i=0;i<j;i++)//ͷ�巨��������

    {

        scanf("%d",&x);

        p=(node*)malloc(sizeof(node));

        p->data=x;

        p->next=(*l)->next;

        (*l)->next=p;

    }

    //q=(node*)malloc(sizeof(node));

    q=(*l)->next;

    while(q->next!=NULL)//�ҵ����һ�����

    {

        q=q->next;

    }

    //printf("%d",q->data);

    q->next=(*l)->next;//�����һ�����ָ���һ�����

 

 

 

}

 

void create_list_tail(linklist *l)//β�巨����ѭ������

{

    int i,j,x;

    linklist p,r,t;

    printf("please input the length");

    scanf("%d",&j);

    (*l)=(node*)malloc(sizeof(node));

    (*l)->next=NULL;

    (*l)->size=j;

    t=(*l);

    for(i=0;i<j;i++)

    {

        scanf("%d",&x);

        p=(node*)malloc(sizeof(node));

        p->data=x;

        t->next=p;

        t=p;//ÿ�½�һ������ڽ���ʱ��Ϊ���һ����㣬��һ���ڵ���������������

 

    }

    t->next=NULL;

    r=(*l)->next;

    while(r->next!=NULL)

    {

        r=r->next;

    }

    r->next=(*l)->next;

}

 

void print_list_he(linklist *l)//��ӡ���

{

    int i;

    linklist p;

    p=(*l)->next;

    for(i=0;i<(*l)->size;i++)

    {

        printf("%d\n",p->data);

        p=p->next;

    }

}

 

int main()

{

    linklist a;

    create_list_head(&a);

    create_list_tail(&a);

    print_list_he(&a);

    return 0;

}

