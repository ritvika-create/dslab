#include<stdio.h>
#include<stdlib.h>

struct node
{
int info;
struct node *link;
};
typedef struct node *NODE;
NODE getnode()
{
NODE x;
x=(NODE)malloc(sizeof(struct node));
if(x==NULL)
{
printf("memory full\n");
exit(0);
}
return x;
}
void freenode(NODE x)
{
free(x);
}
NODE insert_front(NODE first,int item)
{
NODE temp;
temp=getnode();
temp->info=item;
temp->link=NULL;
if(first==NULL)
return temp;
temp->link=first;
first=temp;
return first;
}

NODE delete_front(NODE first)
{
NODE temp;
if(first==NULL)
{
printf("list is empty cannot delete\n");
return first;
}
temp=first;
temp=temp->link;
printf("item deleted at front-end is= %d\n",first->info);
free(first);
return temp;
}
NODE reverse(NODE first)
 {
 NODE cur,temp;
 cur=NULL;
 while(first!=NULL)
  {
   temp=first;
   first=first->link;
   temp->link=cur;
   cur=temp;
  }
 return cur;
}
NODE concat(NODE first,NODE second)
{
 NODE cur;
 if(first==NULL)
  return second;
 if(second==NULL)
  return first;
 cur=first;
 while(cur->link!=NULL)
  cur=cur->link;
 cur->link=second;
 return first;
}
void display(NODE first)
{
NODE temp;
if(first==NULL)
printf("list empty cannot display items\n");
for(temp=first;temp!=NULL;temp=temp->link)
{
printf("%d\n",temp->info);
}
}

	
void sort(NODE first){
	NODE curr,temp;
	if(first==NULL){
		return NULL;
	}
	curr = first;
	while(curr!=NULL){
		temp = curr->link;
		while(temp!=NULL){
			if(temp->info<curr->info){
				int info = curr->info;
				curr->info=temp->info;
				temp->info = info;
			}
			temp = temp->link;
		}
		curr = curr->link;
	}
	return first;
}
void main()
{
int item,choice,pos,n,i;
NODE first=NULL,a,b;
for(;;)
{
printf("\n1:Insert_front\t2:Delete_front\t3:reverse_list\t4:Concate\t5:Sort\t6:display_list\t7:Exit\n");
printf("enter the choice\n");
scanf("%d",&choice);
switch(choice)
{
case 1:printf("enter the item at front-end\n");
scanf("%d",&item);
first=insert_front(first,item);
break;
case 2:first=delete_front(first);
break;
case 3: first=reverse(first); display(first);break;
 case 4:
 if(first==NULL){
 printf("enter the no of nodes in 1:");
          scanf("%d",&n);
          a=NULL;
          for(i=0;i<n;i++)
           {
            printf("enter the item:");
            scanf("%d",&item);
            a=insert_front(a,item);
          }}else{
            a=first;
          }
           printf("enter the no of nodes in list2:");
          scanf("%d",&n);
          b=NULL;
          for(i=0;i<n;i++)
           {
            printf("enter the item:");
            scanf("%d",&item);
            b=insert_front(b,item);
           }
           a=concat(a,b);
           display(a);
          break;
case 5:sort(first);
         break;
case 6:display(first);
break;

}
}
}
