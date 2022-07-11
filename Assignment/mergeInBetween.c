// Operations on SLL using recursion
// Code Author:Rohin Joshi(1MS20IS096)
// Section : 3-C
/**
 * Operations performed:
 * [X]Insert
 * [X]Delete
 * [X]Search
 * [X]Display
 * **/
#include <stdio.h>
#include <stdlib.h>

// Node definition
typedef struct Node
{
	int data;
	struct Node *next;
} Node;

// Global declarations
Node *head = NULL, *new_node, *ptr, *search_ptr;
int search_ptr_index = 0;
int size = 0;
// Create_Node helper function
Node *create(int val)
{
	new_node = (Node *)malloc(sizeof(Node));
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
Node *insert(Node *head, int val, int index)
{
	if (index == 0)
	{
		new_node = create(val);
		new_node->next = head;
		size++;
		return new_node;
	}
	head->next = insert(head->next, val, index - 1);
	return head;
}
/**The search function here is mainly used to detect the presence of a node
	If the user wishes to find a specific element,the FindIndexOf() function will be used
	The search function will ensure that the code remains stable even when any delete operation
	or Find operation is used on a node which does not exist
**/
Node *search(Node *head, int element)
{
	if (head == NULL)
	{
		return NULL;
	}
	if (head->data == element)
	{
		return head;
	}
	search_ptr_index++;
	head = search(head->next, element);
}
int FindIndexOf(int element)
{
	search_ptr_index = 0;
	search_ptr = search(head, element);
	if (search_ptr != NULL)
	{
		return search_ptr_index;
		return -1;
	}
}
// Deletion using recursion
/**Note:Rather than creating multiple functions for delete such as delete start, end and anywhere
 * We create a single delete function which deletes solely based on the value the user wishes to delete
 * In case of deleting the first element, the function is designed to assign head pointer to the next node
 * Deleting last can be done by putting the value of the last Node in the function,and the same follows for
 * the values of the other nodes in the list **/
Node *Delete(Node *head, int val)
{
	if (head->data == val)
	{
		Node *temp = head;
		head = head->next;
		free(temp);
		size--;
		return head;
	}

	head->next = Delete(head->next, val);
	return head;
}

void display(Node *head)
{
	if (head == NULL)
	{
		return;
	}
	printf("%d\t", head->data);
	display(head->next);
}
Node *mergeInBetween(Node *list1, int a, int b, Node *list2)
{
	Node *ptr = list1;
	for (int i = 0; i < a - 1; i++)
	{
		ptr = ptr->next;
	}
	Node *ptrLeft = ptr;
	Node *deletePtr = ptr->next;
	// ptr is at left position
	for (int i = a; i != b + 1; i++)
	{
		ptr = ptr->next;
	}
	Node *ptrRight = ptr->next;
	Node *ptr2 = list2;
	while (ptr2->next != NULL)
	{
		ptr2 = ptr2->next;
	}
	ptrLeft->next = list2;
	ptr2->next = ptrRight;
	// clear the region in between
	while (deletePtr->next != ptrRight)
	{
		Node *temp = deletePtr;
		deletePtr = deletePtr->next;
		free(temp);
	}
	return list1;
}
Node *Create_List(Node *head, int n)
{
	int i = 0;
	int val;
	// printf("debug ptr1");
	while (i < n)
	{
		printf("Enter value of node %d", i);
		scanf("%d", &val);
		head = insert(head, val, i);
		i++;
	}
	return head;
}
void main()
{
	printf("Creating lists");
	Node *head1 = NULL;
	Node *head2 = NULL;
	head1 = Create_List(head1, 5);
	// display(head1);
	head2 = Create_List(head2, 4);
	// display(head2);
	head1 = mergeInBetween(head1, 1, 3, head2);
	display(head1);
}