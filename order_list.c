/*************************************************************************
	> File Name: order_list.c
	> Author: XuetaoZhang
	> Mail: yselie06@gmail.com
	> Created Time: 2019年08月05日 星期一 08时53分34秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1

typedef struct Vector {
    int size, length;
    int *data;
} Vector;

void init(Vector *vector, int size) {
    vector->size = size;
    vector->length = 0;
    vector->data = (int *) malloc (sizeof(int) * size);
}

void expand(Vector *vector) {
    int *old_data = vector->data;
    vector->size *= 2;
    vector->data = (int *) malloc (sizeof(int) * vector->size);
    for (int i = 0; i < vector->length; ++i) {
        vector->data[i] = old_data[i];
    }
    free(old_data);
}

int insert(Vector *vector, int loc, int value) {
    if (loc < 0 || loc > vector->length) {
        return ERROR;
    }
    if (vector->length >= vector->size) {
        expand(vector);
    }
    for (int i = vector->length; i > loc; --i) {
        vector->data[i] = vector->data[i - 1];
    }
    vector->data[loc] = value;
    vector->length++;
    return OK;
}

int search(Vector *vector, int value) {
    for (int i = 0; i < vector->length; ++i) {
        if (vector->data[i] == value) {
            return OK; 
        }
    }
    return ERROR;
}

int delete_node(Vector *vector, int index) {
    if (index < 0 || index >= vector->length) {
        return ERROR;
    }
    for (int i = index + 1; i < vector->length; ++i) {
        vector->data[i - 1] = vector->data[i];
    }
    vector->length--;
    return OK;
}

void print(Vector *vector) {
    for (int i = 0; i < vector->length; ++i) {
        i && printf(" ");
        printf("%d", vector->data[i]);
        i == vector->length - 1 && printf("\n");
    }
}

void clear(Vector *vector) {
    free(vector->data);
    free(vector);
}

int main() {
    Vector *a = (Vector *)malloc(sizeof(Vector));
    init(a, 20);
    int n;
    scanf("%d", &n);
    while (n--) {
        int t, m, n;
        scanf("%d", &t);
        switch (t) {
            case 1: {
                scanf("%d%d", &m, &n);
                if (insert(a, m, n)) printf("success\n");
                else printf("failed\n");
            } break;
            case 2: {
                scanf("%d", &m);
                if (delete_node(a, m)) printf("success\n");
                else printf("failed\n");
            } break;   
            case 3: {
                scanf("%d", &m);
                if (search(a, m)) printf("success\n");
                else printf("failed\n");
            } break;   
            case 4: print(a); break;
        }
    }
    

    return 0;
}

