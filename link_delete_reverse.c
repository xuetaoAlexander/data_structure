/*************************************************************************
	> File Name: link_delete_reverse.c
	> Author: XuetaoZhang
	> Mail: yselie06@gmail.com
	> Created Time: 2019年08月29日 星期四 13时11分56秒
 ************************************************************************/

#include<stdio.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node, *LinkedList;

LinkedList insert(LinkedList head, Node *node, int index) {
    if (head == NULL) {
        if (index != 0) {
            printf("failed\n");
            return head;
        }
        head = node;
        printf("success\n");
        return head;
    }
    if (index == 0) {
        node->next = head;
        head = node;
        printf("success\n");
        return head;
    }
    Node *current_node = head;
    int count = 0;
    while (current_node->next != NULL && count < index - 1) {
        current_node = current_node->next;
        count++;
    }
    if (count == index - 1) {
        node->next = current_node->next;
        current_node->next = node;
        printf("success\n");
        return head;
    }
    printf("failed\n");
    return head;
}

void output(LinkedList head) {
    if (head == NULL) {
        return;
    }
    Node *current_node = head;
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

LinkedList delete_node(LinkedList head, int index) {
    if (head == NULL) {
        printf("failed\n");
        return head;
    }
    if (index == 0) {
        Node *current_node = head;
        head = head -> next;
        free(current_node);
        printf("success\n");
        return head;
    }
    int count = 0;
    Node *current_node = head;
    while (current_node -> next != NULL && count < index - 1) {
        current_node = current_node -> next;
        count++;
    }
    if (count == index - 1 && current_node -> next != NULL) {
        Node *delete_node = current_node -> next;
        current_node -> next = delete_node -> next;
        free(delete_node);
        printf("success\n");
        return head;
    }
    printf("failed\n");
    return head;
}

LinkedList reverse(LinkedList head) {
    if (head == NULL) return head;
    Node *next_node, *current_node;
    current_node = head -> next;
    head -> next = NULL;
    while (current_node != NULL) {
        next_node = current_node -> next;
        current_node -> next = head;
        head = current_node;
        current_node = next_node;
    }
    return head;
}

void clear(LinkedList head) {
    Node *current_node = head;
    while (current_node != NULL) {
        Node *delete_node = current_node;
        current_node = current_node->next;
        free(delete_node);
    }
}

int main() {
    LinkedList linkedlist = NULL;
    int m;
    scanf("%d", &m);
    while (m--) {
        int t;
        scanf("%d", &t);
        switch (t) {
            case 1: {
                int a, b;
                scanf("%d%d", &a, &b);
                Node *node = (Node *) malloc(sizeof(Node));
                node -> data = b;
                node -> next = NULL;
                linkedlist = insert(linkedlist, node, a);
                break;
            }
            case 2: {
                output(linkedlist);
                break;
            }
            case 3: {
                int a;
                scanf("%d", &a);
                linkedlist = delete_node(linkedlist, a);
                break;
            }
            case 4: {
                linkedlist = reverse(linkedlist);
                break;
            }
        }
        
    }

    return 0;
}

