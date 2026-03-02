#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int pow;
    struct Node* next;
};
struct Node* insertTerm(struct Node* head, int coeff, int pow) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->pow = pow;
    newNode->next = NULL;

    if (head == NULL || head->pow < pow) {
        newNode->next = head;
        return newNode;
    }

    struct Node* temp = head;

    while (temp->next != NULL && temp->next->pow > pow) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}
void display(struct Node* head) {
    while (head != NULL) {
        printf("%dx^%d", head->coeff, head->pow);
        if (head->next != NULL)
            printf(" + ");
        head = head->next;
    }
    printf("\n");
}
struct Node* addPolynomial(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;

    while (poly1 != NULL && poly2 != NULL) {

        if (poly1->pow > poly2->pow) {
            result = insertTerm(result, poly1->coeff, poly1->pow);
            poly1 = poly1->next;
        }
        else if (poly1->pow < poly2->pow) {
            result = insertTerm(result, poly2->coeff, poly2->pow);
            poly2 = poly2->next;
        }
        else {
            int sum = poly1->coeff + poly2->coeff;
            result = insertTerm(result, sum, poly1->pow);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    while (poly1 != NULL) {
        result = insertTerm(result, poly1->coeff, poly1->pow);
        poly1 = poly1->next;
    }

    while (poly2 != NULL) {
        result = insertTerm(result, poly2->coeff, poly2->pow);
        poly2 = poly2->next;
    }

    return result;
}