#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node_struct node_t;
struct node_struct {
    int32_t content;
    node_t *next_addr;
};

node_t *create_node(const int32_t input_number) {
    node_t *new_node = (node_t *) malloc(sizeof(node_t));
    new_node->content = input_number;
    new_node->next_addr = NULL;
    return new_node;
}

void link_nodes(node_t *const prev_node, node_t *const next_node) {
    prev_node->next_addr = next_node;
}

node_t *lpop_front(node_t *passed_node){
    node_t *temp;

    if (passed_node != NULL && passed_node->next_addr != NULL){
        temp = passed_node;
        passed_node = passed_node->next_addr;
        free(temp);
        return passed_node;
    }

    printf("Can't delete one element list\n");
    return passed_node;
}

void lpop_back(const node_t *passed_node){
    node_t *prev_node;

    while (passed_node != NULL && passed_node->next_addr != NULL){
        prev_node = passed_node;
        passed_node = passed_node->next_addr;
    }

    link_nodes(prev_node, NULL);

    free(passed_node);
}

node_t *lpush_front(node_t *passed_node, int32_t input_number){
    node_t *new_head = create_node(input_number);
    link_nodes(new_head, passed_node);
    return new_head;
}

void lpush_back(node_t *passed_node, int32_t input_number){
    if(passed_node == NULL){
        return;
    }

    while (passed_node->next_addr != NULL){
        passed_node = passed_node->next_addr;
    }

    node_t *new_tail = create_node(input_number);
    link_nodes(passed_node, new_tail);
}

void lprint(const node_t *passed_node){
    while (passed_node != NULL){
        printf("%d\t", passed_node->content);
        passed_node = passed_node->next_addr;
    }
    printf("\n");
}

void lnuke(node_t *head_node){
    node_t *temp;

    while (head_node != NULL && head_node->next_addr != NULL){
        temp = head_node;
        head_node = head_node->next_addr;
        free(temp);
    }
    free(head_node);
    printf("List has been nuked");
}

int main(void) {
    printf("Initial list:\n");
    node_t *head = create_node(10);
    lprint(head);

    printf("Added element before the head of the list:\n");
    head = lpush_front(head, 0);
    lprint(head);

    printf("Added element in the end of the list:\n");
    lpush_back(head, 20);
    lprint(head);

    printf("Removed element from the beginning of the list:\n");
    head = lpop_front(head);
    lprint(head);

    printf("Removed element from the end of the list:\n");
    lpop_back(head);
    lprint(head);

    lnuke(head);

    return 0;
}