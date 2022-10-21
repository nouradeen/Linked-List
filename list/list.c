#include <stddef.h>
#include <stdlib.h>
#include "list.h"
#include "../node.h"


// Pre: node_t list exist
// Post: Return the size of the list
int calc_size(node_t * list){ // Calculate the size of a given list
    node_t * temp = list;
    int size = 0;
    while(temp != NULL){
        size++;
        temp = temp-> next;
    }
    return size; // return the size
}


// Pre: node_t list exist
// Post: Return 1 if list is empty, Return 0 if list is not empty
int isEmpty(node_t * list){ // Check if the list is empty or not
    if(list == NULL){
        return 1; // return 1 if empty
    }else{
        return 0; // return 0 if not empty
    }
}

// Pre: Size of the list >= index >= 0
// Post: Return the address of the element at index
node_t * getNode(node_t * list, int index){ // Get the address of a given index 
    node_t * temp = list;
    for(int i = 1; i < index; i++){ // If there is 1 element, dont loop beacuse there is 1 element
        temp = temp -> next;
    } 
    return temp; // return the address of the node
}

//Pre: Size of the list >= index >= 0
//Post: Return the data of element at index
int getElement(node_t * list, int index){// get the element at index
    return getNode(list, index) -> el; // return the data in the node
}

//Pre: node_t list exist
//Post: Return 1 if element exist in the list, Return 0 if element does not exist
int elementExist(node_t * list, int element){ // Check if an element exist in the list
    node_t * temp = list;
    while(temp != NULL){
        if(temp -> el == element){
            return 1; // return 1 if element exist
        }
        temp = temp -> next;
    }
    return 0; // return 0 if element does not exist
}


//Pre: node_t list exist
//Post: return the index of the element
int indexOfElement(node_t * list, int element){ // Get the index of a given element in the list
    node_t * n = list;
    int index = 0;
    while(n != NULL){
        if(n -> el == element){
            break;
        }
        index++;
        n = n -> next;
    }
    return index; // return the index
}

//Pre: Size of the list >= index >= 0
//Post: Return the new list after appending the new element
node_t * append(node_t * list, int index, int data){ // Append new data to the list in the given index
    node_t * new = (node_t *)malloc(sizeof (node_t)); // Create new memory locatin for the new element
    new -> el = data;
    if(index == 0){ // If index 0 = begining of the list
        new -> next = list;
        list = new;
    }else{ 
        node_t * previous = getNode(list, index);
        new -> next = previous -> next;
        previous -> next = new;
    }
    return list; // return the new list
}

//Pre: Size of the list >= index >= 0
//Post: Return the new list after removing the element
node_t * removeAtIndex(node_t * list, int index){ // Remove an element in a given index
    if(index == 0){ // If index 0 = beginging of the list
        node_t * temp = list;
        list = temp -> next;
        free(temp); // Free the memory location after removing the element
    }else{
        node_t * previous = getNode(list, index);
        node_t * temp = previous -> next;
        previous -> next = temp -> next;
        free(temp);
    }
    return list; // return the element
}


// Pre: node_t exist
// Post: return the new list sorted from smallest to largest
node_t * sort(node_t * list){ // Bubble sort
    int size = calc_size(list);
    int swapped;
    node_t * n1;
    node_t * n2 = NULL;

    if (list == NULL){
        return 0;
    }
    do{
        swapped = 0;
        n1 = list;
        while(n1 -> next != n2){
            if(n1->el > n1->next->el){
                int temp = n1 -> el;
                n1 -> el = (n1 -> next) -> el;
                (n1 -> next) -> el = temp;
                swapped = 1;
            }
            n1 = n1 -> next;
        }
        n2 = n1;
    }while(swapped);

    return list;
}


node_t * reverse(node_t * list){
    node_t * n1 = list;
    node_t * n2 = n1 -> next;
    node_t * n3 = n2 -> next;
    n1 -> next = NULL;
    n2 -> next = n1;
    while(n3 != NULL){
        n1 = n2;
        n2 = n3;
        n3 = n3 -> next;
        n2 -> next = n1;
    }
    list = n2;
    return list;
}


node_t * shift(node_t * list, char direction){
    node_t * n1 = list;
    int size = calc_size(n1);
    if(direction == 'r'){
        node_t * n2 = getNode(n1, size - 1);
        node_t * n3 = n2 -> next;
        n2 -> next = NULL;
        n3 -> next = list;
        list = n3;
        return list;
    }else if(direction == 'l'){
        node_t * n2 = getNode(n1, size);
        list = n1 -> next;
        n1 -> next = NULL;
        n2 -> next = n1;
        return list;
    }
}