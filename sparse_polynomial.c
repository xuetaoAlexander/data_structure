/*************************************************************************
	> File Name: sparse_polynomial.c
	> Author: XuetaoZhang
	> Mail: yselie06@gmail.com
	> Created Time: 2019年08月29日 星期四 16时44分25秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node{
    int c;
    int e;
    struct Node *next;
} Node, *LinkedList;

int func(int c, int x, int e) {
    return c * (int)pow(x, e);
}

LinkedList insert(Node *head, Node *node, int index) {
    if (head == NULL) {
        if (index != 0) {
            return head;
        }
        head = node;
        return head;
    }
    if (index == 0) {
        node -> next = head;
        head = node;
        return head;
    }

    int count = 0;
    Node *current_node = head;
    while (current_node -> next != NULL && count < index - 1) {
        current_node = current_node -> next;
        count++;
    }

    if (count == index - 1) {
        node -> next = current_node -> next;
        current_node -> next = node;
    }
    return head;
}

int output(Node *head, int x, int (*func)(int, int, int)) {
    Node *current_node = head;
    int sum = 0;
    while (current_node != NULL) {
        sum += func(current_node -> c, x, current_node -> e);
        current_node = current_node -> next;
    }
    return sum;
}

void clear(Node *head) {
    Node *current_node = head;
    while (current_node != NULL) {
        Node *delete_node = current_node;
        current_node = current_node -> next;
        free(delete_node);
    }
}

int main() {
    int m;
    scanf("%d", &m);
    LinkedList linkedlist = NULL;
    
    for (int i = 0; i < m; i++) {
        int c, e;
        scanf("%d%d", &c, &e);
        Node *node = (Node *) malloc(sizeof(Node));
        node -> c = c;
        node -> e = e;
        node -> next = NULL;
        linkedlist = insert(linkedlist, node, i);
    }
    int x = 0;
    scanf("%d", &x);
    int sum = 0;
    sum = output(linkedlist, x, func);
    printf("%d\n", sum);
    
    clear(linkedlist);

    return 0;
}
