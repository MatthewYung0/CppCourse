/*
 ============================================================================
 Description : Example to demonstrate how to delete node from the Linked List.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct node
{
   int data;
   struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;
struct node *prev = NULL;

//Create Linked List
void insertAtLast(int data)
{
   // Allocate memory for new node
   struct node *link = (struct node*) malloc(sizeof(struct node));

   // insert the data to the new node and make the next point to null
   link->data = data;
   link->next = NULL;

   // If head is empty, create new list
   if(head==NULL)
   {
      head = link;
      return;
   }

   current = head;

   // loop until reach the last node in the old list
   while(current->next != NULL)
   {
	   current = current->next;
   }

   // Make the last node in the old list point to new node
   current->next = link;
}

//display the list
void printList(void)
{
   struct node *ptr = head;

   printf("[head] =>");

   //start looping from the head until the last node
   while(ptr != NULL)
   {
      printf(" %d =>",ptr->data);
      ptr = ptr->next;
   }

   printf(" [null]\n");
}

void removeNodeFromTheList(int data)
{
   int pos = 0;
   struct node * delete_node = NULL;

   //check if the linked list is empty
   if(head==NULL)
   {
	   printf("Linked List is empty");
	   return;
   }

   //check the first node in the linked list
   if(head->data == data)
   {
	   delete_node = head;
	   // move head to next node
	   head = head->next;
	   printf("%d found at position %d and deleted \n", data, pos);
	   free(delete_node);
	   return;
   }

   //check the rest of nodes in the linked list
   pos++;
   current = head->next;
   prev = head;
   while(current != NULL)
   {
	   if(current->data == data)
	   {
		   //element found
		   delete_node = current;
		   prev->next = current->next;
		   printf("%d found at position %d and deleted \n", data, pos);
		   free(delete_node);
		   return;
	   }
	   prev = current;
	   current = current->next;
	   pos++;
   }

   //in case the data not found in the linked list
   if(delete_node == NULL)
   {
	   printf("%d not found in the List.",data);
   }
}

int main(void)
{
	insertAtLast(10);
	insertAtLast(20);
	insertAtLast(30);
	insertAtLast(1);
	insertAtLast(40);
	insertAtLast(56);

	// print the list
	printList();

	//remove the head node
	removeNodeFromTheList(10);
	// print the list
	printList();

	//remove the node which contains 1
	removeNodeFromTheList(1);
	// print the list
	printList();

	//remove the tail node
	removeNodeFromTheList(56);
	// print the list
	printList();

	return 0;
}
