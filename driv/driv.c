#include <stdio.h>
#include "driv.h"
#include "../list/list.h"
#include "../node.h"

void printList(node_t * list){// Print the list
    if(isEmpty(list) == 1){
        printf("\e[42mThe list is empty, choose 3 from the menu to add an element\e[0m\n");
    }else{
        node_t * n = list;
        printf("\e[42m");
        while (n != NULL){
            printf(" %d ", n -> el);
            n = n -> next;
        }
        printf("\e[0m\n");
    }
} 
void printListSize(node_t * list){// Print the list size
    int size = calc_size(list);
    printf("\e[42mThe size of the list is: %d elements\e[0m\n", size);
}


node_t * addToEnd(node_t * list){ //Add element to the list on the tail
    int index = calc_size(list);
    int data;
    printf("\e[42mWrite the data (only integers): \e[0m");
    scanf("%d", &data);
    list = append(list, index, data);
    return list;
}

node_t * appendToIndex(node_t * list){// Add element in index
    int index, data;
    int size = calc_size(list);
    printf("\e[42mWrite the data (only integers): \e[0m");
    scanf("%d", &data);
    printf("\e[42mWhere do you want to store the data, write the index: \e[0m");
    scanf("%d", &index);
    if (index > size){
        printf("\e[42mThe index is out of range\e[0m\n");
    }else{
        list = append(list,index,data);
    }
    return list;
}

node_t * removeData(node_t * list){//Remove data from the list
    if(isEmpty(list) == 1){
        printf("\e[42mThe list is empty, choose 3 from the menu to add an element\e[0m\n");
    }else{
        int data;
        printf("\e[42mWhich data do you want to remove, write the data (only integers): \e[0m");
        scanf("%d", &data);
        if(elementExist(list, data) == 1){
            int index = indexOfElement(list, data);
            list = removeAtIndex(list, index);
        }else{
            printf("\e[42mThe element does not exist in the list\e[0m\n");
        }
    }
    return list;
}        
node_t * removeFromIndex(node_t * list){// Remove data in index
    if(isEmpty(list) == 1){
        printf("\e[42mThe list is empty, choose 3 from the menu to add an element\e[0m\n");
    }else{
        int index;
        int size = calc_size(list);
        printf("\e[42mChoose the index you want to remove: \e[0m");
        scanf("%d", &index);
        if(index >= size){
            printf("Index out of range\e[0m\n");
        }else{
            list = removeAtIndex(list, index);
        }
    }
    return list;
}

node_t * emptyList(node_t * list){ //Empty list
    if(isEmpty(list) == 1){
        printf("\e[42mThe list is empty, choose 3 from the menu to add an element\e[0m\n");
    }else{
        int size = calc_size(list);
        for(int i = size - 1; i >= 0; i--){
            list = removeAtIndex(list, i);
        }
    }
    return list;
}

node_t * revertList(node_t * list){ // Revert the list
    if(isEmpty(list) == 1){
        printf("\e[42mThe list is empty, choose 3 from the menu to add an element\e[0m\n");
    }else{
        list = reverse(list);
    }
    return list;
}

node_t * shiftToDirection(node_t * list, char direction){//Shift the elements in the list to the left
    if(isEmpty(list) == 1){
        printf("\e[42mThe list is empty, choose 3 from the menu to add an element\e[0m\n");
    }else if(direction == 'l'){
        list = shift(list, 'l');
    }else if(direction == 'r'){
        list = shift(list, 'r');
    }
    return list;
}

node_t * sortList(node_t * list){ // Sort the list, smaller to bigger
    if(isEmpty(list) == 1){
        printf("\e[42mThe list is empty, choose 3 from the menu to add an element\e[0m\n");
    }else{
        list = sort(list);
    }
    return list;
}

void printStartAddress(node_t * list){ // Print the start address of the list
    if(isEmpty(list) == 1){
        printf("\e[42mThe list is empty, choose 3 from the menu to add an element\e[0m\n");
    }else{
        printf("\e[42mThe start address of the list is: %p\e[0m\n", &list -> el);
    }
}

