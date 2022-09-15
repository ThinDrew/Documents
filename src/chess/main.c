
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

    printf("\nPush 15\n");
    Push(&a, 15);
    Print(&a);

    printf("\nPopBack\n");
    PopBack(&a);
    Print(&a);

    printf("\nPop\n");
    Pop(&a);
    Print(&a);
    return 0;
}

