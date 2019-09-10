#include <stdio.h>
#include "vector_targil.h"

int main() {
    Vector v;
    Vector *vec = vectorCreate(&v,40);
    vectorPush(vec, 6);
    vectorPush(vec, 6);
    vectorPush(vec, 6);
    printVector(vec);

    return 0;
}