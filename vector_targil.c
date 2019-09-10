//
// Created by shira on 9/10/19.
//

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "vector_targil.h"


Vector *vectorCreate(Vector *vec, size_t size) {
    vec->m_capacity=size;
    vec->m_data= (int *)malloc(size * sizeof(int));
    vec->m_num_items=0;

    return vec;

}

void vectorDestroy(Vector *vector) {

    free(vector->m_data);

}

void arraycopy(int *dst, int *src, size_t src_size) {
    int i;
    for (i = 0; i < src_size; ++i) {
        *dst = *src;
        dst++;
        src++;
    }
}

ErrorCode vectorPush(Vector *vector, int value) {
    if(!vector){
        return E_NULL_PTR;
    }
    if (vector->m_capacity > vector->m_num_items) {
        vector->m_data[vector->m_num_items] = value;
        vector->m_num_items++;
        return E_OK;
    }
    if (vector->m_capacity == vector->m_num_items) {
        vector->m_capacity*=2;
        int *dest = (int *) malloc(vector->m_capacity  * sizeof(int));
        if(!dest){
            return E_ALLOCATION_ERROR;
        }
        arraycopy(dest, vector->m_data, vector->m_num_items);
        dest[vector->m_num_items]= value;
        vector->m_num_items++;
        free(vector->m_data);
        vector->m_data=dest;
        return E_OK;
    }
}

ErrorCode vectorInsert(Vector *vector, int value, size_t index) {
    if (index > vector->m_num_items-1 || index < 0){
        return E_BAD_INDEX;
    }
    if (vector->m_capacity >= vector->m_num_items+1){
        int i= vector->m_num_items;
        while(i != index){
            vector->m_data[i]=vector->m_data[i-1];
            --i;
        }
        vector->m_data[i]=value;
        return E_OK;
    }
    if (vector->m_capacity < vector->m_num_items+1) {
        vector->m_capacity*=2;
        int *dest = (int *) malloc(vector->m_capacity  * sizeof(int));
        if(!dest){
            return E_ALLOCATION_ERROR;
        }
        arraycopy(dest, vector->m_data, index-1);
        dest[index]=value;
        arraycopy(dest+index+1, vector->m_data+index, vector->m_num_items-index-1);
        return E_OK;
    }
}

ErrorCode vectorPop(Vector *vector, int *res) {
    if(vector -> m_num_items == 0){
        return  E_UNDERFLOW;
    }
    else{
        *res = vector-> m_data[vector -> m_num_items - 1];
        vector->m_num_items--;
    }
    return E_OK;
}

ErrorCode vectorRemove(Vector *vector, size_t index, int *res) {
    if (index > vector -> m_num_items - 1 || index < 0){
        return E_BAD_INDEX;
    }
    *res = vector -> m_data[index];
    size_t i;
    for (i=index; i < vector -> m_num_items; ++i) {
        vector->m_data[i] = vector -> m_data[i + 1];
    }
    vector -> m_num_items--;
    return E_OK;
}

ErrorCode vectorGetElement(const Vector *vector, size_t index, int *res) {
    if (index > vector->m_num_items - 1 || index < 0){
        return E_BAD_INDEX;
    }
    *res = vector -> m_data[index];
    return E_OK;
}

ErrorCode vectorSetElement(Vector *vector, size_t index, int value) {
    if (index > vector -> m_num_items - 1 || index < 0){
        return E_BAD_INDEX;
    }
    vector->m_data[index] = value;
    return E_OK;
}

void printVector(Vector *vector) {
    printf("vector's capacity: %lu\n",vector->m_capacity );
    printf("vector has: %lu items \n",vector->m_num_items);
    int i;
    for ( i = 0; i <vector->m_num_items ; ++i) {
        printf("%d ",vector->m_data[i]);
    }
    printf("\n");
}
