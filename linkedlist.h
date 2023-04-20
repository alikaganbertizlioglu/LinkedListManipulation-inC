#ifndef ___LINKED_LIST_H___
#define ___LINKED_LIST_H___

#include<stdlib.h>

typedef struct LINKED_LIST_NODE_s *LINKED_LIST_NODE;
typedef struct LINKED_LIST_NODE_s {
    LINKED_LIST_NODE next;
    void* data;
} LINKED_LIST_NODE_t[1];

typedef struct LINKED_LIST_s *LINKED_LIST;
typedef struct LINKED_LIST_s {
    LINKED_LIST_NODE head;
} LINKED_LIST_t[1];


LINKED_LIST linked_list_init()
{
    LINKED_LIST list;
    list = (LINKED_LIST)malloc(sizeof(LINKED_LIST_t));
    if(list != NULL) {
        list->head = NULL;
    }
    return list;
}

void linked_list_free(LINKED_LIST list)
{
    free(list);
}

void linked_list_prepend(LINKED_LIST list, void *data)
{
    LINKED_LIST_NODE node;
    node = (LINKED_LIST_NODE)malloc(sizeof(LINKED_LIST_NODE_t));
    if(node != NULL) {
        node->data = data;
        node->next = list->head;
        list->head = node;
    } if(node == NULL) {

    }
}

void linked_list_append(LINKED_LIST list, void *data) {
    LINKED_LIST_NODE n=(LINKED_LIST_NODE)malloc(sizeof(LINKED_LIST_NODE_t));
    LINKED_LIST_NODE node = list;
    n->data = data;
    n->next=NULL;
    while(node->next != NULL) {
        node = node->next;
    }
    node->next = n;
}


void linked_list_insert(LINKED_LIST list, void *data, int idx)
{
    LINKED_LIST_NODE node = NULL;
    LINKED_LIST_NODE temp =list->head;
    int indexfinder=0;
    while(temp != NULL) {
        if(indexfinder == idx) {
            node = (LINKED_LIST_NODE)malloc(sizeof(LINKED_LIST_NODE_t));

            node->data = data;
            node->next = temp->next;
            temp->next = node;
        }
        indexfinder++;
        temp = temp->next;
    }

}


void *linked_list_get(LINKED_LIST list, int idx)
{
    LINKED_LIST_NODE temp = list->head;
    int positionFinder=0;
    void* returnedData=NULL;
    while (temp != NULL)
    {
        if (idx == positionFinder) {
            returnedData=(void *) (temp->data);
            return returnedData;
        }
        positionFinder++;
        temp = temp->next;
    }
    return returnedData;
}


void *linked_list_set(LINKED_LIST list, void *data, int idx)
{
    LINKED_LIST_NODE walker, tmp;
    void *olddata;
    int i;
    olddata = NULL;
    if(idx == 0 && list->head != NULL) {
        tmp = list->head;
        olddata = tmp->data;
        tmp->data = data;
    }
    else {
        walker = list->head;
        idx--;
        for(i=0; i<idx && walker->next!=NULL; i++) {
            walker = walker->next;
        }
        if(walker != NULL && walker->next != NULL) {
            tmp = walker->next;
            olddata = tmp->data;
            tmp->data = data;
        }
    }
    return olddata;
}

void deleteNode(LINKED_LIST list, int position)
{

    // Store head node
    LINKED_LIST_NODE temp = list->head;

    // If head needs to be removed
    if (position == 0) {

        // Change head
        list->head = temp->next;

        // Free old head
        free(temp);
        return;
    }

    // Find previous node of the node to be deleted
    for (int i = 0; temp != NULL && i < position - 1; i++)
        temp = temp->next;

    // If position is more than number of nodes
    if (temp == NULL || temp->next == NULL)
        return;

    // Node temp->next is the node to be deleted
    // Store pointer to the next of node to be deleted
    LINKED_LIST_NODE next = temp->next->next;

    // Unlink the node from linked list
    free(temp->next); // Free memory

    // Unlink the deleted node from list
    temp->next = next;
}


void delete_withIndex(LINKED_LIST list, int position)
{
    LINKED_LIST_NODE head_ref = list->head;
    // Store head node
    LINKED_LIST_NODE temp = head_ref;

    // If head needs to be removed
    if (position == 0) {

        // Change head
        head_ref = temp->next;

        // Free old head
        free(temp);
        return;
    }

    // Find previous node of the node to be deleted
    for (int i = 0; temp != NULL && i < position - 1; i++)
        temp = temp->next;

    // If position is more than number of nodes
    if (temp == NULL || temp->next == NULL)
        return;

    // Node temp->next is the node to be deleted
    // Store pointer to the next of node to be deleted
    LINKED_LIST_NODE next = temp->next->next;

    // Unlink the node from linked list
    free(temp->next); // Free memory

    // Unlink the deleted node from list
    temp->next = next;
}


void delete_withValue(int num, LINKED_LIST list) {
    LINKED_LIST_NODE current_node = list->head;
    LINKED_LIST_NODE prev_node;
    while ( current_node != NULL) {
        if (current_node->data == num) {
            if (current_node == list->head) {
                list->head = current_node->next;
            } else {
                prev_node->next = current_node->next;
            }
        }
        prev_node = current_node;
        current_node = current_node->next;
    }
}

void linked_list_removeall(LINKED_LIST list) {

    LINKED_LIST_NODE current = list->head;
    LINKED_LIST_NODE* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    list->head = NULL;
}

void delete_from_head(LINKED_LIST list)
{
    list->head = list->head->next;
}

void linkedlist_print(LINKED_LIST list) {
    LINKED_LIST_NODE current_node= list->head;
    printf("print : ");
    while ( current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

int linkedlist_getSize(LINKED_LIST list){
    LINKED_LIST_NODE current_node= list->head;
    int size = 0;
    while ( current_node != NULL) {
        current_node = current_node->next;
        size++;
    }
    return size;
}
LINKED_LIST_NODE removeLastNode(LINKED_LIST list)
{

    LINKED_LIST_NODE head= list->head;
    if (head == NULL)
        return NULL;

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    // Find the second last node
    LINKED_LIST_NODE second_last = head;
    while (second_last->next->next != NULL)
        second_last = second_last->next;

    // Delete last node
    free (second_last->next);

    // Change next of second last
    second_last->next = NULL;

    return head;
}
static void reverse(LINKED_LIST list)
{
    LINKED_LIST_NODE prev = NULL;
    LINKED_LIST_NODE current = list->head;
    LINKED_LIST_NODE next = NULL;
    while (current != NULL) {
        // Store next
        next = current->next;

        // Reverse current node's pointer
        current->next = prev;

        // Move pointers one position ahead.
        prev = current;
        current = next;
    }

    list->head = prev;
}
void linked_list_concatenate(LINKED_LIST list, LINKED_LIST list2){
    LINKED_LIST_NODE listA =(LINKED_LIST_NODE)list->head;
    LINKED_LIST_NODE listB =(LINKED_LIST_NODE)list2->head;

    if(listA !=NULL && listB !=NULL){
        if(listA->next==NULL){
                listA->next=listB;
            }
        } else {
            linked_list_concatenate((LINKED_LIST) listA->next, (LINKED_LIST) listB);
        }

    }

void linked_list_null_check(LINKED_LIST list){
    if(list == NULL){
        printf("linked list is null");
    }
    else
    {
        printf("linked list is not null");
    }
}

#endif