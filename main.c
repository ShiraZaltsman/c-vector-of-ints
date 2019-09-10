#include <stdio.h>
#include "vector_targil.h"

int main() {

    Vector v;
    Vector *vec = vectorCreate(&v,20);
    vectorPush(vec, 6);
    vectorPush(vec, 20);
    vectorPush(vec, 30);
    vectorPush(vec, 300);
    vectorPush(vec, 500);
    vectorPush(vec, 89);
    vectorPush(vec, -9);
    vectorPush(vec, 30);
    vectorPush(vec, -30);
    vectorPush(vec, 12);
    vectorPush(vec, 30);
    vectorPush(vec, 4);

    printVector(vec);

    printf("\n----------------\ndelete index 4:\n");
    int* res;
    int kuku;
    res=&kuku;
    vectorRemove(vec,4, res);
    printVector(vec);

    printf("\n----------------\nInsert 18 to index 3:\n");
    vectorInsert(vec, 18, 3 );
    printVector(vec);

    vectorPop(vec, res );
    printf(" \n----------------\npop: %d\n", *res);
    printVector(vec);

    printf("\n----------------\ncount 30 in vector:\n");

    printf("30 present in the vector %lu times\n", vectorCount(vec, 30));


    return 0;
}