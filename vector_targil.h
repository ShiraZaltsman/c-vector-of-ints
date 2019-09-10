//
// Created by shira on 9/10/19.
//

#ifndef C_VECTOR_OF_INTS_SHIRAZALTSMAN_VECTOR_TARGIL_H
#define C_VECTOR_OF_INTS_SHIRAZALTSMAN_VECTOR_TARGIL_H

#include <glob.h>
typedef enum
{
    E_OK,
    E_NULL_PTR,
    E_UNDERFLOW,
    E_ALLOCATION_ERROR,
    E_BAD_INDEX
} ErrorCode;

typedef struct Vector{
    int *m_data;          /* array size of capacity */
    size_t m_capacity;
    size_t m_num_items;   /* num of items (numbers) in the vector */
}Vector;


Vector *vectorCreate(Vector *vector, size_t size);

void vectorDestroy(Vector *vector);

/* copy values to new array */
void arraycopy(int *des, int *src, size_t src_size);

void printVector(Vector *vector);

/* Adds an item at the end. Grows if needed (by * 2) */
ErrorCode vectorPush(Vector *vector, int value);

/* Adds an item at a certain position and shifts. Grows if needed (by * 2) */
ErrorCode vectorInsert(Vector *vector, int value, size_t index);

/* Clears the item at the end. Grows if needed (by * 2) */
ErrorCode vectorPop(Vector *vector, int *res);

/* Clears an item at a certain position and shifts. */
ErrorCode vectorRemove(Vector *vector, size_t index, int *res);

ErrorCode vectorGetElement(const Vector *vector, size_t index, int *res);
ErrorCode vectorSetElement(Vector *vector, size_t index, int value);

size_t vectorGetSize(const Vector *vector);
size_t vectorGetCapacity(const Vector *vector);

/* Counts how many instances of a given value there are. */
size_t vectorCount(const Vector *vector, int value);

#ifdef _DEBUG
void vectorPrint(Vector *vector);
#endif /* _DEBUG */
#endif //C_VECTOR_OF_INTS_SHIRAZALTSMAN_VECTOR_TARGIL_H
