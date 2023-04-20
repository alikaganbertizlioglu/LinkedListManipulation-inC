#include <stdio.h>
#include<stdlib.h>
#include "linkedlist.h"



LINKED_LIST linked_list_slice ( LINKED_LIST list , int start , int end ){
    LINKED_LIST sliceList= linked_list_init();

    for (int i = start; i < end+1; ++i) {
        linked_list_append(sliceList, linked_list_get(list, i));
    }

//sizeof(list) vardı eskiden
    for (int i = 0; i < linkedlist_getSize(sliceList); ++i) {
        delete_withValue((int) linked_list_get(sliceList, i), list);
    }

    return sliceList;

}





void linked_list_trim(LINKED_LIST list, int left, int right) {

    //right(sondan) silme
    for (int i = 0; i < right; ++i) {
        removeLastNode(list);
    }

    //left(baştan) silme
    for (int i = 0; i < left; ++i) {
        //delete_withIndex(list,i);
        //delete_withValue(linked_list_get(list,i),list);
       // deleteNode(list,i);
        delete_from_head(list);
    }


}





void linked_list_insert_piece ( LINKED_LIST list , LINKED_LIST piece , int index ){

    int piecesize = linkedlist_getSize(piece);
    reverse(piece);
    for (int i = 0 ; i < piecesize; ++i) {
            linked_list_insert(list, linked_list_get(piece,i),index-1);
    }
}



int main() {


    //TASK1 SLICE

    printf("TASK 1 SLICE\n");
    LINKED_LIST task1list = linked_list_init();

    linked_list_append(task1list, (void *) 12);
    linked_list_append(task1list, (void *) 99);
    linked_list_append(task1list, (void *) 37);
    linked_list_append(task1list, (void *) 52);
    linked_list_append(task1list, (void *) 80);
    linked_list_append(task1list, (void *) 23);

    LINKED_LIST returned_slice = linked_list_slice(task1list,2,4);

    printf("List after slice : ");
    linkedlist_print(task1list);

    printf("Returned list : ");
    linkedlist_print(returned_slice);
    printf("************************************************\n");

    printf("TASK 2 INSERT PIECE \n");
    LINKED_LIST list = linked_list_init();
    linked_list_append(list, (void *) 12);
    linked_list_append(list, (void *) 52);
    linked_list_append(list, (void *) 80);
    linked_list_append(list, (void *) 23);

    printf("List--> ");
    linkedlist_print(list);

    LINKED_LIST piece = linked_list_init();
    linked_list_append(piece, (void *) 99);
    linked_list_append(piece, (void *) 37);

    printf("Piece--> ");
    linkedlist_print(piece);

    linked_list_insert_piece(list,piece,1);
    linkedlist_print(list);

    printf("************************************************\n");

    printf("TASK 3 TRIM\n");

    LINKED_LIST task3list = linked_list_init();

    linked_list_append(task3list, (void *) 12);
    linked_list_append(task3list, (void *) 99);
    linked_list_append(task3list, (void *) 37);
    linked_list_append(task3list, (void *) 52);
    linked_list_append(task3list, (void *) 80);
    linked_list_append(task3list, (void *) 23);


    printf("List --> ");
    linkedlist_print(task3list);


    linked_list_trim(task3list, 1, 2);

    printf("List after trim--> ");

    linkedlist_print(task3list);

}