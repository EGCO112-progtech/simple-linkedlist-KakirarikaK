//
//  main.c
//  simple linkedlist
//
//  Created by Mingmanas Sivaraksa on 4/2/2566 BE.
//

#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int main(int argc, const char * argv[]) {
    int z=5;
    struct node a,b,*head,c,d ;
    a.value = 2;
    a.next=&b;
    d.next=NULL;
    head=&a;
    b.value=z;
    b.next=&c;
    c.next=&d;
    c.value=head->next->value+3;
    d.value=head->next->next->value+3;

    printf("%d\n", head ->value ); //what value for 5
    printf("%d\n", head ->next->value ); //what value for 8
    printf("%d\n", head->next->next->value);
    printf("%d\n", head ->next->next->next->value );
/*  Exercise I
    1. Add 1 more than at the end
    2. Add value(11)
    3. Make next become NULL
 */

/*  Exercise II
        1. Add 1 more than at the begining!!!!
        2. Add value (2)
        
*/
    typedef struct node* NodePtr;
    NodePtr tmp=head; //add temp value to faciliate
        
    /*  Exercise III Use loop to print everything
        int i,n=5;
        for(i=0;i<n;i++){
            printf("%3d", tmp->value);
          // What is missing???
        }
    */
    int i,n=4;
    for(i=0;i<n;i++){
        printf("%4d",tmp->value);
        tmp=tmp->next;
    }
    printf("\n");
   /*  Exercise IV change to while loop!! (you can use NULL to help)
       
         while(){
            printf("%3d", tmp->value);
           // What is missing???
        }
    */
    //เอาtempกลับมาก่อน
    tmp=head;
    while(tmp){
        printf("%4d",tmp->value);
        tmp = tmp->next;
    }
 /*  Exercise V Use malloc to create all nodes, instead of create a struct!!
         //use a loop to help
          
     */
    head=(struct node*) malloc(sizeof(struct node));
    tmp=head;

    for(i=2;i<=11;i+=3){//2 5 8 11
    tmp->value=i;
    if(i==11)tmp->next=NULL;
    else{
    tmp->next=(struct node*) malloc(sizeof(struct node));
    tmp=tmp->next;
        }
    }

    tmp->value=2;
    tmp->next=(struct node*) malloc(sizeof(struct node));

    //ใช้tempอันเก่าของnodeที่แล้วมาชี้ที่tempของnodeอันถัดไป
    tmp=tmp->next;
    tmp->value=5;
    tmp->next=(struct node*) malloc(sizeof(struct node));

    tmp=tmp->next;
    tmp->value=8;
    tmp->next=(struct node*) malloc(sizeof(struct node));

    /*  Exercise VI Free all node !!
         //use a loop to help
          
     */
    while(head!=NULL){
    tmp=head;
    head=head->next;
    printf("%5d",tmp->value);
    free(tmp);
    }
    printf("\n");


    /*head=head->next;
    free(tmp);
    tmp=head;

    head=head->next;
    free(tmp);
    tmp=head;

    head=head->next;
    free(tmp);*/
    
    return 0;
}
