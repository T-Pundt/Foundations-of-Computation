#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int A[], int n);
void countSort(int A[], int n);
void printArray(int A[], int n);
void generateInFile(int n);

int main()
{

    printf("Hello World");
    /*
    1. Call generateInFile function to generate integer random numbers and store them in a text file
    2. Copy the numbers from the file to an array A1 and another array A2 (A1=A2). Use dynamic allocation to declare A1 and A2
    3. Define two variables start1 and end1 of type clock_t.
    4. Keep the following code to measure the running time of the selection sort algorithm.

    start1 = clock();
    selectionSort(A, n);
    end1 = clock();
    time_spent1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
    printf("Time taken by selectionSort algorithm is %f sec.\n",time_spent1);


    5. repeat steps 3. and 4. to measure the running time of the counting sort algorithm*/

    return 0;
}

/*

//selection sort function
void selectionSort(int A[], int n) // n is the size of A
{
    //Implement selection sort algorithm here
}

//counting sort function
void countSort(int A[], int n) // n is the size of A
{
    int k, *B, *C;
    //Write a code to find the value of k that is equal to the maximum value of A

    B = (int*)malloc(n * sizeof(int)); //Dynamic allocation of two temporarily arrays B and C.
    C = (int*)malloc((k+1) * sizeof(int));

    //continue the implementation of the counting sort algorithm here.
}

//Function to print the content of an array
void printArray(int A[], int n)
{
    for(int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}

 //Function to generate n random integer numbers in the range 0 to RAND_MAX = 32767
 void generateInFile(int n)
 {
    int x;
    FILE *out;
    out = fopen("A1.txt", "r+");
    fprintf(out, "%d\n", n);
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        x = rand();
        fprintf(out, "%d ", x);
    }
    fclose(out);
 }


 */