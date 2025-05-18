#include "list.h"

Node* createNode(int value) {
        Node* nd = (Node *) malloc(sizeof(Node));
        if (!nd) {
                perror("Error: node was not allocated");
                return NULL;
        }
        nd->val = value;
        nd->next = NULL;
        return nd;
}

void insertAtEnd(Node **head, int value) {
        if (!(*head)) {
                *head = createNode(value);
                return;
        }
        Node *tmp = *head;
        while (tmp->next) {
                tmp = tmp->next;
        }
        tmp->next = createNode(value);
}

void insertAtFront(Node **head, int value) {
	Node* nd = createNode(value);
	nd->next = *head;
	*head = nd;
}

void insertAt(Node **head, int index, int value) {
	if (index == 0) {
		insertAtFront(head, value);
	}
	Node *tmp = *head;
	while (index > 1) {
                if (!tmp) {
                        return;
                }
                tmp = tmp->next;
                index--;
        }
	Node* nd = createNode(value);
	nd->next = tmp->next;
	tmp->next = nd;
}

void deleteNode(Node **head, int value) {
	if (!(*head)) {
		return;
	}
	if (value == (*head)->val) {
		Node* tmp = *head;
       		*head = (*head)->next;
        	free(tmp);
		return;
	}
	Node *tmp = *head;
	while(tmp->next) {
		if ((tmp->next)->val == value) {
			Node* dltmp = tmp->next;
			tmp->next = dltmp->next;
			free(dltmp);
			return;
		}
		tmp = tmp->next;
	}
	printf("Value not found");
}

void removeFront(Node **head) {
	if (!(*head)) {
        	return;
        }
	Node* tmp = *head;
	*head = (*head)->next;
	free(tmp);
}

void removeBack(Node **head) {
	if (!(*head)) {
        	return;
        }
	if ((*head)->next == NULL) {
     		free(*head);
        	*head = NULL;
       		return;
   	}
	Node* tmp = *head;
	while ((tmp->next)->next) {
		tmp = tmp->next;
	}
	free(tmp->next);
	tmp->next = NULL;
}


void removeAt(Node **head, int index) {
	if (index == 0) {
                removeFront(head);
        }
	Node* tmp = *head;
	while (index > 1) {
		if (!tmp) {
			return;
		}
		tmp = tmp->next;
		index--;
	}
	if (!tmp->next) {
		return;
	}
	Node* dlnd = tmp->next;
	tmp->next = (tmp->next)->next;
}

void printList(Node* head) {
	if (!head) {
		printf("The list is empty\n");
		return;
	}
	Node* tmp = head;
	while (tmp) {
		printf("%d ", tmp->val);
		tmp = tmp->next;
	}
	printf("\n");
}

void freeList(Node **head) { 
	Node* tmp = *head;
	Node* nxt = NULL;
        while (tmp) {
		nxt = tmp->next;
		free(tmp);
		tmp = nxt;
	}
	*head = NULL;
}
