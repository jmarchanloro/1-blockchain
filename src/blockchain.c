#include <stdio.h>
#include <search.h>
#include "block.h"
#include "linkedlist.h"

extern hash string_hash(void *string);

void main(int argc, char const *argv[])
{  
    NODE *head;
    DATA element;
    DATA element2;
    init(&head);

    transaction genesis_transactions = {"First transaction"};
    block_t genesis_block = {0, string_hash(genesis_transactions), genesis_transactions};

    element.info = genesis_block;
    head = add(head, element);
//    print_list(head);

    transaction transactions = {"Second transaction"};
    block_t block = {genesis_block.block_hash, string_hash(transactions), transactions};

    element2.info = block;
    head = add(head, element2);
    print_list(head);
    
    //printf("Hash: %d\n", genesis_block.block_hash);
    return;
}


/*

int main() {
    int i;
    NODE* head;
    NODE* node;
    DATA element;
    printf("Add Elements to List:\n");
    init(&head);
    for (i = 53; i <= 63; i++) {
        element.info = i;
        printf("Add Element %2d To The List.\n", element.info);
        head = add(head, element);
    }
    printf("\nPrint The List:\n");
    print_list(head);
    printf("\nRemove Element From The List:\n");
    node = head->next->next;
    remove_node(node);
    printf("\nAdd Element To The List:\n");
    node = head->next->next->next;
    element.info = 2000;
    add_at(node, element);
    head = reverse(head); // Revers The List
    head = sort_list(head); // Sort The List
    head = free_list(head);
    return (EXIT_SUCCESS);
}*/