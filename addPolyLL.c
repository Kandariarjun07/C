#include<stdio.h>
#include<stdlib.h>
#define MAX 100
struct node {
    int coeff;
    int exp;
    struct node* next;
};
typedef struct node node;
void insert(node** head, node** tail, int c, int p) {
    node* temp = (node*)malloc(sizeof(node));
    temp->coeff = c;
    temp->exp = p;
    if (*head == NULL) {
        *head = temp;
        *tail = temp;
        temp->next = NULL;
    }
    else {
        (*tail)->next = temp;
        *tail = temp;
        temp->next = NULL;
    }
}
void polyToLL(node** head, node** tail, char* poly) {
    int mul = 1;
    int i = 0;
    if (poly[0] == '-') {
        i = 1;
        mul = -1;
    }
    int num = 0, coef = 0, pow = 0;
    for (i; poly[i] != '\0'; i++) {
        if (poly[i] >= '0' && poly[i] <= '9') {
            num = num * 10 + (poly[i] - '0');
        }
        else if (poly[i] == '^') {
            coef = num * mul;
            num = 0;
            mul = 1;
        }
        else if (poly[i] == '-') {
            pow = num;
            num = 0;
            insert(head, tail, coef, pow);
            mul = -1;

        }
        if (poly[i] == '+') {
            pow = num;
            num = 0;
            insert(head, tail, coef, pow);
        }
    }
    insert(head, tail, coef, num);
}
void display(node* head, node* tail) {
    if (head == NULL) {
        printf("Nothing to show");
    }
    else {
        node* temp = head;
        printf("%d^%d", temp->coeff, temp->exp);
        temp = temp->next;
        while (temp != NULL) {
            if (temp->coeff >= 0) {
                printf("+");
            }
            printf("%dx^%d", temp->coeff, temp->exp);
            temp = temp->next;
        }
        free(temp);
    }
}
int main() {
    char poly1[MAX];
    char poly2[MAX];
    node* head1 = NULL;
    node* tail1 = NULL;
    node* head2 = NULL;
    node* tail2 = NULL;
    printf("Enter first polynomial : ");
    gets(poly1);
    printf("Enter second polynomial : ");
    gets(poly2);
    polyToLL(&head1, &tail1, poly1);
    polyToLL(&head2, &tail2, poly2);

    node* temp1 = head1;
    node* temp2 = head2;
    node* head_result = NULL;
    node* tail_result = NULL;

    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->exp == temp2->exp) {
            int result_coef = temp1->coeff + temp2->coeff;
            insert(&head_result, &tail_result, result_coef, temp1->exp);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else if (temp1->exp > temp2->exp) {
            insert(&head_result, &tail_result, temp1->coeff, temp1->exp);
            temp1 = temp1->next;
        }
        else {
            insert(&head_result, &tail_result, temp2->coeff, temp2->exp);
            temp2 = temp2->next;
        }
    }
    while (temp1 != NULL) {
        insert(&head_result, &tail_result, temp1->coeff, temp1->exp);
        temp1 = temp1->next;
    }
    while (temp2 != NULL) {
        insert(&head_result, &tail_result, temp2->coeff, temp2->exp);
        temp2 = temp2->next;
    }
    display(head_result, tail_result);
}