#include <stdio.h>
#include <stdlib.h>
#include "driv/driv.h"
#include "node.h"




int main(){
    node_t * list = (node_t *)malloc(sizeof (node_t));
    list = NULL;
    int val;

    while (1){

        printf("0: Avsluta\n");
        printf("1: Skriv ut listan\n");
        printf("2: Skriv ut listans storlek\n");
        printf("3: Lägg till ett heltal sist i listan\n");
        printf("4: Lägg till ett heltal (valfri palts)\n");
        printf("5: Ta bort ett givet heltal\n");
        printf("6: Ta bort ett heltal (valfri plats)\n");
        printf("7: Töm listan\n");
        printf("8: Vänd på listan\n");
        printf("9: Skifta listan ett steg åt vänster (och lägg första heltalet sist)\n");
        printf("10: Skifta listan ett steg åt höger (och lägg sista heltalet först\n");
        printf("11: Sortera listan (lägsta heltalet först)\n");
        printf("12: Skriv ut startadress för listan\n"); 
        printf("Gör ditt val: ");
        scanf("%d", &val);

        switch (val){
            case 0:
                node_t * temp;
                while(list != NULL){
                    temp = list;
                    list = list -> next;
                    free(temp);
                }
                exit(0);
                break;
            case 1:
                printList(list);
                break;
            case 2:
                printListSize(list);
                break;
            case 3:
                list = addToEnd(list);
                break;
            case 4:
                list = appendToIndex(list);
                break;
            case 5:
                list = removeData(list);
                break;
            case 6:
                list = removeFromIndex(list);
                break;
            case 7:
                list = emptyList(list);
                break;
            case 8:
                list = revertList(list);
                break;
            case 9:
                list = shiftToDirection(list, 'l');
                break;
            case 10:
                list = shiftToDirection(list, 'r');
                break;
            case 11:
                list = sortList(list);
                break;
            case 12:
                printStartAddress(list);
                break;

            default:
                break;
        }
    }

    return 0;

}