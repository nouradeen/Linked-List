#include "../node.h"

int calc_size(node_t * list); // beräkna storleken på en lista och returnera denna

int isEmpty(node_t * list); //bestämma huruvida en lista är tom eller inte och returnera resultatet

node_t * getNode(node_t * list, int index);

int getElement(node_t * list, int index); // returnera elementet på en viss plats i en lista

int elementExist(node_t * list, int element); // bestämma huruvida ett element finns i listan eller inte och returnera resultatet

int indexOfElement(node_t * list, int element); // returnera platsen för första förekomst av ett visst element i en lista ??????

node_t * append(node_t * list, int index, int data);

node_t * removeAtIndex(node_t * list, int index);

node_t * sort(node_t * list);

node_t * reverse(node_t * list);

node_t * shift(node_t * list, char direction);



