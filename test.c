#include <assert.h>
#include "test.h"
#include "vector_targil.h"

void testVectorCreat() {
    ErrorCode e;
    Vector *vec ;
    int *res;
    int kuku;
    int num;
    size_t cap;
    size_t size;
    vec = vectorCreate(18);
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

    res = &kuku;
    e = vectorRemove(vec, 4, res);
    printVector(vec);

    printf("\n----------------\nInsert 18 to index 3:\n");
    e = vectorInsert(vec, 18, 3);
    printVector(vec);

    vectorPop(vec, res);
    printf("\n----------------\npop: %d\n", *res);
    printVector(vec);

    num= 30;
    printf("\n----------------\ncount %d in vector:\n", num);
    printf("%d present in the vector %lu times\n", num, vectorCount(vec, 30));


    cap = vectorGetCapacity(vec);
    printf("\n----------------\nget capacity: %lu\n", cap);


    size= vectorGetSize(vec);
    printf("\n----------------\nget size: %lu\n", size);


    e=vectorGetElement(vec, 5, res);
    printf("\n----------------\nget elment in index 5: %d\n", *res);

    e=vectorSetElement(vec, 5, 17);
    printf("\n----------------\nset 17 in index 5: \n");
    printVector(vec);



    vectorDestroy(&vec);
    printf("error return: %d", e);

}
