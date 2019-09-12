

#include "vector_targil.h"

struct Vector {
    int *m_data;          /* array size of capacity */
    size_t m_capacity;
    size_t m_num_items;   /* num of items (numbers) in the vector */
};

Vector *vectorCreate(size_t size) {
    Vector *vec = (struct Vector *) malloc(sizeof(struct Vector));

    if (vec) {
        vec->m_num_items = 0;
        vec->m_capacity = size;
        vec->m_data = (int *) malloc(size * sizeof(int));

        if (!vec->m_data) {
            free(vec);
            vec = NULL;
        }
    }
    return vec;
}

void vectorDestroy(Vector **vector) {
    if (vector && *vector) {
        free((*vector)->m_data);
        free(*vector);
        *vector = NULL; /*mark that vector destroy*/
    }
}

void arraycopy(int *dst, int *src, size_t src_size) {
    size_t i;
    for (i = 0; i < src_size; ++i) {
        *dst = *src;
        dst++;
        src++;
    }
}

ErrorCode vectorPush(Vector *vector, int value) {

    if (!vector) {
        return E_NULL_PTR;
    } else if (vector->m_capacity > vector->m_num_items) {
        vector->m_data[vector->m_num_items++] = value;
        return E_OK;
    } else {
        int *tmp_data = vector->m_data;

        vector->m_data = realloc(vector->m_data, vector->m_capacity * 2);
        if (!vector->m_data) {
            vector->m_data = tmp_data;
            return E_ALLOCATION_ERROR;
        }
        vector->m_capacity *= 2;
        vector->m_data[vector->m_num_items++] = value;
        return E_OK;
    }
}

ErrorCode vectorInsert(Vector *vector, int value, size_t index) {
    if (!vector) {
        return E_NULL_PTR;
    }

    if (index >= vector->m_num_items) {
        return E_BAD_INDEX;
    } else if (vector->m_capacity >= vector->m_num_items) {
        size_t i = vector->m_num_items;
        while (i != index) {
            vector->m_data[i] = vector->m_data[i - 1];
            --i;
        }
        vector->m_data[i] = value;
        vector->m_num_items++;
        return E_OK;

    } else {
        int *dest;
        vector->m_capacity *= 2;
        dest = (int *) malloc(vector->m_capacity * sizeof(int));
        if (!dest) {
            return E_ALLOCATION_ERROR;
        }
        arraycopy(dest, vector->m_data, index - 1);
        dest[index] = value;
        vector->m_num_items++;
        arraycopy(dest + index + 1, vector->m_data + index, vector->m_num_items - index - 1);
        return E_OK;
    }
}

ErrorCode vectorPop(Vector *vector, int *res) {

    if (vector->m_num_items == 0) {
        return E_UNDERFLOW;
    }

    --vector->m_num_items;
    *res = vector->m_data[vector->m_num_items];
    return E_OK;
}

ErrorCode vectorRemove(Vector *vector, size_t index, int *res) {
    size_t i;
    if (index > vector->m_num_items - 1) {
        return E_BAD_INDEX;
    }

    *res = vector->m_data[index];

    for (i = index; i < vector->m_num_items; ++i) {
        vector->m_data[i] = vector->m_data[i + 1];
    }

    vector->m_num_items--;
    return E_OK;
}

ErrorCode vectorGetElement(const Vector *vector, size_t index, int *res) {
    if (!vector) {
        return E_NULL_PTR;
    }
    if (index > vector->m_num_items - 1) {
        return E_BAD_INDEX;
    }
    *res = vector->m_data[index];
    return E_OK;
}


ErrorCode vectorSetElement(Vector *vector, size_t index, int value) {
    if (index > vector->m_num_items - 1 || index < 0) {
        return E_BAD_INDEX;
    }
    vector->m_data[index] = value;
    return E_OK;
}

void printVector(Vector *vector) {
    size_t i;
    printf("vector's capacity: %lu\n", vector->m_capacity);
    printf("vector has: %lu items \n", vector->m_num_items);

    for (i = 0; i < vector->m_num_items; ++i) {
        printf("%d ", vector->m_data[i]);
    }
    printf("\n");
}

size_t vectorGetSize(const Vector *vector) {

    return vector->m_num_items;
}

size_t vectorGetCapacity(const Vector *vector) {
    return vector->m_capacity;
}

size_t vectorCount(const Vector *vector, int value) {
    size_t counter, i;
    counter = 0;

    for (i = 0; i < vector->m_num_items; ++i) {
        counter += (vector->m_data[i] == value);
    }
    return counter;
}

void vectorPrint(Vector *vector) {

}

