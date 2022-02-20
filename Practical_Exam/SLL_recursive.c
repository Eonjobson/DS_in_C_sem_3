//Operations on SLL using recursion
//Code Author:Rohin Joshi(1MS20IS096) 
//Section : 3-C
/**
 * Operations performed:
 * [X]Insert
 * [X]Delete
 * [X]Search
 * [X]Display
 * **/
#include <stdio.h>
#include <stdlib.h>

//Node definition
typedef struct  Node
{
	int data;
	struct Node* next;
}Node;

//Global declarations
Node *head=NULL,*new_node,*ptr,*search_ptr;
int search_ptr_index=0;
int size=0;
//Create_Node helper function
Node* create(int val){
	new_node = (Node*)malloc(sizeof(Node));
	new_node->data = val;
	new_node->next = NULL;
	return new_node;
}


/**Insert:
 * The insert function is designed in such a way that it can insert anywhere on the list, including the head
 * In case of inserting at the head,we need to put index value to 0 and if we need to assign at the tail
 * We need to assign index value to 'size'
 * Both of these can be taken care of in the main function as different cases according to what the user requires
**/
Node* insert(Node* head,int val,int index){
	if(index==0){
		 new_node = create(val);
		 new_node->next = head;
		 size++;
		 return new_node;
	}
	head->next = insert(head->next,val,index-1);
return head;
}
/**The search function here is mainly used to detect the presence of a node
	If the user wishes to find a specific element,the FindIndexOf() function will be used
	The search function will ensure that the code remains stable even when any delete operation
	or Find operation is used on a node which does not exist
**/
Node* search(Node* head,int element){
	if(head==NULL){
		return NULL;
	}
	if(head->data==element){
		return head;
	}
	search_ptr_index++;
	head = search(head->next,element);


}
int FindIndexOf(int element){
	search_ptr_index=0;
	search_ptr = search(head,element);
	if(search_ptr!=NULL){
		return search_ptr_index;
	return -1;

	}
}
//Deletion using recursion
/**Note:Rather than creating multiple functions for delete such as delete start, end and anywhere
 * We create a single delete function which deletes solely based on the value the user wishes to delete
 * In case of deleting the first element, the function is designed to assign head pointer to the next node
 * Deleting last can be done by putting the value of the last Node in the function,and the same follows for 
 * the values of the other nodes in the list **/
Node* Delete(Node* head,int val){
	if(head->data==val){
		Node* temp = head;
		head = head->next;
		free(temp);
		size--;
		return head;}

	head->next = Delete(head->next,val);
	return head;
}

void display(Node* head){
	if(head==NULL){
		return;
	}
	printf("%d\t",head->data);
	display(head->next);	
}
void main()
{
	int choice, element;
    while(1)
    {
        printf("\n1 - Insert Begin\n2 - Insert End\n3 - Insert node anywhere\n4 - Delete\n5 - Find Index of a node\n6 - Display\n7 - Exit\n");
        printf("Enter your choice :- ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: 
		        printf("\nEnter value\t");
		        int ni;
		        scanf("%d",&ni);
		        head= insert(head,ni,0);
            		break;
            case 2: 
            		printf("\nEnter value\t");
		        int ne;
		        scanf("%d",&ne);
		        head= insert(head,ne,size);
            		break;
            case 3: 
            		printf("\nEnter value\t");
		        int n,idx;
		        scanf("%d",&n);
		        printf("\nEnter Index to be inserted\t");
		        scanf("%d",&idx);
		        if(idx<=size)
		        	head= insert(head,n,idx);
		        else
		        	printf("\nindex out of bounds");
            		break;
            case 4: 
            		printf("\nEnter value to be deleted\t");
            		int delval;
            		scanf("%d",&delval);
            		if(search(head,delval)!=NULL){
            		head = Delete(head,delval);
            		}
            		else{
            		printf("Element does not exist\n");
            		}
            		break;
            case 5:
		    	printf("\nEnter the element to be searched\t");
		    	int sval ;
		    	scanf("%d",&sval);
		    	if(search(head,sval)!=NULL){
		    		printf("\nIndex of %d is %d",sval,FindIndexOf(sval));
		    	}
		    	else{
		    		printf("\nIndex Not found");
		    	}
		    	break;
            case 6: display(head);
            break;
            case 7: exit(0);
            default: printf("Wrong input.");
            break;
        }
    }
 
}
