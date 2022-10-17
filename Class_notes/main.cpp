

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define randomList      0
#define reverseList     1
#define inorderList     2

void randomArray(int *theArray, int len) {
    printf("creating a random list of length %i\n", len);
    
    srand(time(NULL));
    
    for (int i = 0; i < len; i++)
        theArray[i] = rand() % len;// % 100000;
}

void inorderArray(int *theArray, int len) {
    printf("creating an ordered list of length %i\n", len);
    
    for (int i = 0; i < len; i++)
        theArray[i] = i;
}

void reverseArray(int *theArray, int len) {
    printf("creating a reverse-ordered list of length %i\n", len);
    
    for (int i = 0; i < len; i++)
        theArray[i] = len - i;
}


void printArray(int *theArray, int len) {
    for (int i = 0; i < len; i++)
        printf("%i  ", theArray[i]);
    printf("\n");
}


/* *********************************************
 //
 //      Code for the Quick Sort
 //
 ************************************************ */

void partition(int *list, int len, int *small, int *equal, int *large, int theSizes[3]) {
    theSizes[0] = theSizes[1] = theSizes[2] = 0;
    int i;
    int pivot = list[0];//len/2];
    
    for (i = 0; i < len; i++) {
        if (list[i] < pivot) {
            small[theSizes[0]] = list[i];
            theSizes[0] ++;
        }
        
        else if (list[i] == pivot) {
            equal[theSizes[1]] = list[i];
            theSizes[1] ++;
        }
        
        else {
            large[theSizes[2]] = list[i];
            theSizes[2] ++;
        }
    }
    
    //printf("sizes: %i, %i, %i\n", theSizes[0], theSizes[1], theSizes[2]);
}

void concat(int *small, int *equal, int *large, int *list, int theSizes[3]) {
    int i, count;
    count = 0;
    for (i = 0; i < theSizes[0]; i++) {
        list[count] = small[i];
        count ++;
    }
    
    for (i = 0; i < theSizes[1]; i++) {
        list[count] = equal[i];
        count ++;
    }
    
    for (i = 0; i < theSizes[2]; i++) {
        list[count] = large[i];
        count ++;
    }
}

void quickSort(int *theArray, int len) {
    int *small = new int[len];
    int *equal = new int[len];
    int *large = new int[len];
    int theSizes[3];
    
    if (len > 1) {
        partition(theArray, len, small, equal, large, theSizes);
        
        quickSort(small, theSizes[0]);
        quickSort(large, theSizes[2]);
        
        concat(small, equal, large, theArray, theSizes);
    }
    
    delete[] small;
    delete[] equal;
    delete[] large;
}

/* *********************************************
 //
 //      Code for the Merge Sort
 //
 ************************************************ */
void mergeTogether(int *array1, int len1, int *array2, int len2) {
    int *tmp = new int[len1+len2];
    
    int first=0, second=0;
    int i;
    
    for (i = 0; i < len1+len2; i++) {
        if (first >= len1) {
            tmp[i] = array2[second];
            second ++;
        }
        else if (second >= len2) {
            tmp[i] = array1[first];
            first ++;
        }
        else {
            if (array1[first] < array2[second]) {
                tmp[i] = array1[first];
                first ++;
            }
            else {
                tmp[i] = array2[second];
                second ++;
            }
        }
        
    }
    
    for (i = 0; i < len1; i++)
        array1[i] = tmp[i];
    for (i = 0; i < len2; i++)
        array2[i] = tmp[i+len1];
    
    delete[] tmp;
}

void mergeSort(int *theArray, int len) {
    // base case
    if (len <= 1)
        return;
    
    int half = len/2;
    mergeSort(theArray, half);
    mergeSort(theArray+half, len-half);
    
    mergeTogether(theArray, half, theArray+half, len-half);
}






/* *********************************************
 //
 //      Code for the Insertion Sort
 //
 ************************************************ */
void insertionSort(int *theArray, int len) {
    int i, j;
    int item;
    
    for (i = 1; i < len; i++) {  // get a new item to put in the list
        j = i;	// j = 2
        item = theArray[j];	// 0
        
        while ((j > 0) && (theArray[j-1] > item)) {
            theArray[j] = theArray[j-1];
            j --;
        }
        theArray[j] = item;
    }
}






/* *********************************************
 //
 //      Code for the Selection Sort
 //
 ************************************************ */
void selectionSort(int *theArray, int N) {
    int i, j;
    int min, tmp;
    
    for (i = 0; i < N-1; i++) {
        min = i;
        for (j = i+1; j < N; j++) {	//	N, N-1, N-2, ... , 2, 1 = n^2 / 2
            if (theArray[j] < theArray[min])	//
                min = j;						// min = 1
        }
		
		// swap theArray[i] and theArray[min]
        tmp = theArray[i];
        theArray[i] = theArray[min];
        theArray[min] = tmp;
    }
}






// ./a.out [algorithm] [listlength] [listordering = random, reversed, ordered] [verbose]
int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Not enough parameters\n");
        return 0;
    }
    
    //int alg = atoi(argv[1]);
    int len = atoi(argv[2]);
    //int dataType = atoi(argv[3]);
    int *theArray = new int[len];
    
    if (!strcmp(argv[3], "random"))
        randomArray(theArray, len);
    else if (!strcmp(argv[3], "ordered"))
        inorderArray(theArray, len);
    else if (!strcmp(argv[3], "reversed"))
        reverseArray(theArray, len);
    else {
        printf("List type %s not found\n", argv[3]);
        return 0;
    }
   
    if (argc > 4) { // assume the fourth parameter is verbose
        printf("Initial array: ");
        printArray(theArray, len);
    }
    
    long start, end;
    
    printf("start ... "); fflush(stdout);
    start = clock();
    
    if (!strcmp(argv[1], "mergesort"))
        mergeSort(theArray, len);
    else if (!strcmp(argv[1], "selectionsort"))
        selectionSort(theArray, len);
    else if (!strcmp(argv[1], "insertionsort"))
        insertionSort(theArray, len);
    else if (!strcmp(argv[1], "quicksort")) {
        quickSort(theArray, len);
        //printf("quicksort removed\n");
    }
    else {
        printf("Sorting algorithm %s not found\n", argv[1]);
        return 0;
    }
    
    end = clock();
    
    printf("done\n");
    
    printf("time required: %lf seconds\n", (float)(end - start)/CLOCKS_PER_SEC);
    
    if (argc > 4) { // assume the fourth parameter is verbose
        printf("Sorted array: ");
        printArray(theArray, len);
    }
    
    delete[] theArray;
    
    return 0;
}









