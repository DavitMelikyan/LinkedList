#include "list.h"

int main() {
	Node* head = NULL;
	insertAtEnd(&head, 10);
	insertAtEnd(&head, 20);
	printList(head);
	

	insertAtFront(&head, 5);
	printList(head);


	insertAt(&head, 1, 15);
	printList(head);


	deleteNode(&head, 15);
	printList(head);


	removeFront(&head);
	printList(head);


	removeBack(&head);
	printList(head);

	insertAtEnd(&head, 20);
	insertAtFront(&head, 5);
	insertAt(&head, 1, 15);
	printList(head);

	removeAt(&head, 1);
	printList(head);

		
	freeList(&head);
	printList(head);

	return 0;
}
