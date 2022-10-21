#include "../node.h"

void printList(node_t * list); // Print the list
void printListSize(node_t * list); // Print the list size
node_t * addToEnd(node_t * list); //Add element to the list on the tail
node_t * appendToIndex(node_t * list); // Add element in index
node_t * removeData(node_t * list); //Remove data from the list
node_t * removeFromIndex(node_t * list); // Remove data in index
node_t * emptyList(node_t * list); //Empty list
node_t * revertList(node_t * list); // Revert the list
node_t * shiftToDirection(node_t * list, char direction); //Shift the elements in the list to the left
node_t * sortList(node_t * list); // Sort the list, smaller to bigger
void printStartAddress(node_t * list); // Print the start address of the list