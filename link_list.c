/*************************************************************************
	> File Name: link_list.c
	> Author: XuetaoZhang
	> Mail: yselie06@gmail.com
	> Created Time: 2019年08月29日 星期四 13时09分21秒
 ************************************************************************/

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
        if (index == 0) {
            head = node;
            printf("success\n");
            return head;
        }
    }
    if (index == 0) {
        node -> next = head;
        head = node;
        printf("success\n");
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
        printf("success\n");
        return head;
    }
    printf("failed\n");
    return head;
}

void output(LinkedList head) {
    Node *current_node = head;
    while (current_node != NULL) {
        current_node == head || printf(" ");
        printf("%d", current_node -> data);
        current_node = current_node -> next;
    }
}

void clear(LinkedList head) {
    Node *current_node = head;
    while (current_node != NULL) {
        Node *delete_node = current_node;
        current_node = current_node -> next;
        free(delete_node);
    }

}

int main() {
    LinkedList linkedlist = NULL;
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int p, q;
        scanf("%d%d", &p, &q);
        Node *node = (Node *) malloc(sizeof(Node));
        node -> data = q;
        node -> next = NULL;
        linkedlist = insert(linkedlist, node, p);
    }
    
    output(linkedlist);
    clear(linkedlist);

    return 0;
}

