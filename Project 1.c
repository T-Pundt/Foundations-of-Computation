#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int A[], int n);
void countSort(int A[], int n);
void printArray(int A[], int n);
void generateInFile(int n);

const long AMOUNT_OF_GENERATED_NUMBERS = 10;

int main()
{
    generateInFile(AMOUNT_OF_GENERATED_NUMBERS);

        //Block of code for reading in the file and reading into a dynamic array
        //A1 creation and fill from file
            FILE *input;
            int NumberOfIntegers;
            input = fopen("A1.txt", "r");

            if (input == NULL)
            {
                printf("The input file is not able to be read in correctly");
                return 1;
            }

            fscanf(input, "%d", &NumberOfIntegers);
            printf("%d\n", NumberOfIntegers);

            int *A1; int *A2;
            A1 = (int*)malloc(NumberOfIntegers * sizeof(int));
            
            if(A1 == NULL)
            {
                printf("The memory of array A1 was not properly set up");
                return 1;
            }

            int temp;
            for(int i=0; i < NumberOfIntegers; ++i)
            {
                fscanf(input, "%d", &temp);
                A1[i] = temp;
            }
        //End of A1

        //A2 creation and copy from A1
            A2 = (int*)malloc(NumberOfIntegers * sizeof(int));
            
            if(A2 == NULL)
            {
                printf("The memory of array A1 was not properly set up");
                return 1;
            }

            for(int i=0; i < NumberOfIntegers; ++i)
            {
                A2[i] = A1[i];
            }
        //End of A2
        //End of block of code

    //Define variables, setup clock, and call selectionSort.
        // clock_t start1, end1;
        // double time_spent1;

        // start1 = clock();
        // selectionSort(A1, NumberOfIntegers);
        // end1 = clock();
        // time_spent1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
        // printf("Time taken by selectionSort algorithm is %f sec.\n",time_spent1);


    //Define variables, setup clock and call CountSort
    clock_t start2, end2;
    double time_spent2;

    start2 = clock();
    countSort(A2, NumberOfIntegers);
    end2 = clock();
    time_spent2 = (double)(end2 - start2) / CLOCKS_PER_SEC;
    printf("Time taken by countSort algorithm is %f sec.\n", time_spent2);

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





//selection sort function
void selectionSort(int A[], int n) // n is the size of A
{
    int min = A[0]; 
    int temp_index;

    //Find the min, record it, record the index its at
    for(int i=0; i<n; ++i)
    {
        if(A[i] < min)
        {
            min = A[i];
            temp_index = i;
        }
    }

    printf("Smallest found");

    //Swap the min and first index in array
    A[temp_index] = A[0];
    A[0] = min;

    //Prefrom Selection Sort algorithm for the rest of the array
    for(int i=1; i<n-1; ++i)
    {
        min = A[i];
        for(int j=i+1; j<n; ++j)
        {
            if(A[j] < min)
            {
                min = A[j];
                temp_index = j;
            }
        }

        if(A[i] != min)
        {
        A[temp_index] = A[i];
        A[i] = min;
        }

        printf("check %d\n", i);
    }
}

//counting sort function
void countSort(int A[], int n) // n is the size of A
{
    int k, *B, *C;

    //Code to find the value of k that is equal to the maximum value of A
    k = A[0];
    for(int i=1; i<n; i++)
    {
        if(A[i] > k)
        {
            k = A[i];
        }
    }



    //Allocate B and C
    B = (int*)malloc(n * sizeof(int)); 
    C = (int*)malloc((k+1) * sizeof(int));


    //Initialize all C to 0
    for(int i=0; i<=k; ++i)
    {
        C[i] = 0;
    }

    //Count the number of times an element occurs and store in C
    for(int i=0; i<n; ++i)
    {
        C[A[i]] = C[A[i]] + 1;
    }

    // Change C to hold the number of elements less than or equal to i
    for(int i=1; i<=k; ++i)
    {
        C[i] = C[i] + C[i-1];
    }

    //Arrange the output array
    for(int i=0; i<n; ++i)
    {
        B[C[A[i]] -1] = A[i];
        C[A[i]] = C[A[i]] - 1;
    }

    //A = B
    for(int i=0; i<n; ++i)
    {
        A[i] = B[i];
    }

    //printArray(A, n);
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

    if(out == NULL)
    {
        printf("File was not found");
        return;
    }

    fprintf(out, "%d\n", n);
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        x = rand(); //                         % 100 + 1; //remove the logical statemenet when done testing
        fprintf(out, "%d ", x);
    }
    fclose(out);
 }

