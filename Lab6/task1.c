#include  "goodinputs.h"
#include "diffrent_sorts.h"
#include "all_for_arrays.h"

void task_one(){
    int* array;
    printf("Input a size of array:\n>");
    int size = goodScanfInt();
    while(size<1){
        printf("You wrote an incorrect size of array. Try again!\n>");
        size = goodScanfInt();
    }
    createArray(&array,size);
    print_array(array,size);
    printf("\n Max element in this array is [%d] and his index is [%d]", array[index_of_max_element(array,size)],
           index_of_max_element(array,size));
    printf("\n");


    SelectionSortForTaskOne(array,size);
    print_array(array,size);
}


