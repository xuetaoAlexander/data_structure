/*************************************************************************
	> File Name: circulation_left_shift.c
	> Author: XuetaoZhang
	> Mail: yselie06@gmail.com
	> Created Time: 2019年08月29日 星期四 14时20分45秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct Vector{
    int size, length;
    int *data;
} Vector;

void init(Vector *vector, int size) {
    vector -> size = size;
    vector -> length = 0;
    vector -> data = (int *) malloc(sizeof(int) * size);
}

int insert(Vector *vector, int loc, int a) {
    if (loc < 0 || loc > vector -> length) {
        return 0;
    }
    if (vector -> length >= vector -> size) {
        return 0;
    }
    for (int i = vector -> length; i > loc; i--) {
        vector -> data[i] = vector -> data[i - 1];
    }
    vector -> data[loc] = a; 
    vector -> length++;
    return 1;

}

void left_shift(Vector *vector, int k, int size) {
    for (int i = 0; i < k; i++) {
        int temp;
        temp = vector -> data[0];
        for (int j = 1; j < size; j++) {
            vector -> data[j - 1] = vector -> data[j];
        }
        vector -> data[size - 1] = temp;
    }
}

void output(Vector *vector) {
    for (int i = 0; i <vector -> length; i++) {
        i && printf(" ");
        printf("%d", vector -> data[i]);
    }
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    Vector *vector = (Vector *) malloc(sizeof(Vector));
    init(vector, n);
    int tmp;
    for (int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        insert(vector, i, tmp);
    }

    left_shift(vector, k, n);
    output(vector);

    return 0;
}
