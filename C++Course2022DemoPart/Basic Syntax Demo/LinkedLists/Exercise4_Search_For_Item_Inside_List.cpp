/*
 ============================================================================

 Description : Example to demonstrate how to find item inside the Linked List.
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

//find certain item inside the list
void findItemInTheList(int item)
{
   int pos = 0;

   if(head==NULL)
   {
      printf("Linked List is empty");
      return;
   }

   // start checking from the first node
   current = head;
   while(current != NULL)
   {
      if(current->data == item)
      {
         printf("%d found at position %d\n", item, pos);
         return;
      }
      current = current->next;
      pos++;
   }
   // item not found in the list
   printf("%d does not exist in the list\n", item);
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

	// find item 1 in the list
	findItemInTheList(1);

	// find item 100 in the list
	findItemInTheList(100);

	// find item 56 in the list
	findItemInTheList(56);

	return 0;
}
