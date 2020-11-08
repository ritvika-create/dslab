#include<stdio.h>
#define capacity 5
int front=0,rear=-1,q[capacity],i=0,item;
void main(){
    int ch;
    for(;;){
    printf("select option 1. insertfront \n  2. insertrear \n  3. deletefront \n  4. deleterear \n  5. traverse \n 6. quit ");
    scanf("%d",&ch);
        switch(ch){
            case 1: { printf("enter item to be inserted");
                    scanf("%d",&item);
                     insertrear(item);
                     break;
                    }
                 case 2: { printf("enter item to be inserted");
                    scanf("%d",&item);
                     insertfront(item);
                     break;
                         }
            case 3:
              deletefront();
              break; 
                          case 4:
              deleterear();
              break;   
                          case 5:
          traverse();
              break;
                          default: exit(0);
                          
         }}}
void insertrear(int item){
    if(rear==capacity-1)
        printf("overflow");
    else{ rear++;
        q[rear]=item;
        printf(" item serted");
        
    }
}
void deletefront(){
     if(rear==-1 && front==0)
        printf("empty");
    else{
        front++;
        printf(" item deletd");}
        }
void insertfront(int item){
    if(front!=0){
        front=front-1;
        q[front]=item;
    }
else if(front==0 && rear==-1){
rear++;
    q[rear]=item;
}
    else
        printf("insertion not possible");
}
void deleterear(){
     if(rear==-1 && front==0)
        printf("empty");
    else if(front>rear){
    front=0; rear=-1;
    } 
}
void traverse(){ 
    if(rear==-1 && front==0)
        printf("empty");
      else
          for(i=front;i<=rear;i++)
  printf("%d\n",q[i]);
}
