
#include <stdlib.h>
#include <stdio.h>
#include "func.h"

int main() {
    struct List a;
    Init(&a);

    printf("Push 10\n");
    Push(&a, 10); 
    Print(&a);
    
    printf("\nPushBack 20\n");
    PushBack(&a, 20);
    Print(&a);

    printf("\n\nthis is printf for GetElement(1) %d \n", GetElement(1, &a));
    printf("\nis is printf for GetElement(0) %d \n", GetElement(0, &a));


    printf("\nPush 15\n");
    Push(&a, 15);
    Print(&a);

    printf("\n\nWriteData\n");
    WriteToFile(&a, "src/chess/example");
    Print(&a);
    printf("\n\nReadData\n");
    ReadFromFile(&a, "src/chess/example");
    Print(&a);


    printf("\nPopBack\n");
    PopBack(&a);
    Print(&a);

    printf("\nPop\n");
    Pop(&a);
    Print(&a);

    return 0;
}

