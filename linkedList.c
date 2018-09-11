#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

static NODE * reverse(NODE * node) {
    NODE * temp;
    NODE * previous = NULL;
    while (node != NULL) {
        temp = node->next;
        node->next = previous;
        previous = node;
        node = temp;
    }
    return previous;
}

void init(NODE** head) {
    *head = NULL;
}

NODE* add(NODE* node, DATA data) {
    NODE* temp = (NODE*) malloc(sizeof (NODE));
    if (temp == NULL) {
        exit(0); // no memory available
    }
    temp->data = data;
    temp->next = node;
    node = temp;
    return node;
}

void print_list(NODE* head) {
    head = reverse(head);
    NODE * temp;
    int indent = 0;
    printf("Print chain\n");
    printf("=========== \n");
    for (temp = head; temp; temp = temp->next, indent = indent+2)
    {
        printf("%*sPrevious hash\t%d\n", indent,"", temp->data.info.previous_block_hash);
        printf("%*sBlock hash\t%d\n", indent,"", temp->data.info.block_hash);
        printf("%*sTransaction\t%s\n", indent,"", temp->data.info.transactions);
        printf("%*s\n", indent, "");
    }

    printf("\r\n");
}

void add_at(NODE* node, DATA data) {
    NODE* temp = (NODE*) malloc(sizeof (NODE));
    if (temp == NULL) {
        exit(EXIT_FAILURE); // no memory available
    }
    temp->data = data;
    temp->next = node->next;
    node->next = temp;
}

void remove_node(NODE* head) {
    NODE* temp = (NODE*) malloc(sizeof (NODE));
    if (temp == NULL) {
        exit(EXIT_FAILURE); // no memory available
    }
    temp = head->next;
    head->next = head->next->next;
    free(temp);
}

NODE *free_list(NODE *head) {
    NODE *tmpPtr = head;
    NODE *followPtr;
    while (tmpPtr != NULL) {
        followPtr = tmpPtr;
        tmpPtr = tmpPtr->next;
        free(followPtr);
    }
    return NULL;
}