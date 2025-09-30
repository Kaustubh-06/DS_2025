#include <stdio.h>
#include <stdlib.h>

// Node structure for polynomial term
struct PolyNode {
    int coeff;
    int exp;
    struct PolyNode* next;
};

// Function to create new node
struct PolyNode* createNode(int coeff, int exp) {
    struct PolyNode* node = (struct PolyNode*)malloc(sizeof(struct PolyNode));
    node->coeff = coeff;
    node->exp = exp;
    node->next = NULL;
    return node;
}

// Insert node in descending order of exponent
void insertTerm(struct PolyNode** head, int coeff, int exp) {
    struct PolyNode* newNode = createNode(coeff, exp);

    if (*head == NULL || (*head)->exp < exp) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct PolyNode* temp = *head;
        while (temp->next != NULL && temp->next->exp > exp) {
            temp = temp->next;
        }
        if (temp->next != NULL && temp->next->exp == exp) {
            // If term already exists, add coefficients
            temp->next->coeff += coeff;
            free(newNode);
        } else {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

// Add two polynomials
struct PolyNode* addPolynomials(struct PolyNode* a, struct PolyNode* b) {
    struct PolyNode* result = NULL;
    struct PolyNode* p1 = a;
    struct PolyNode* p2 = b;

    while (p1 != NULL && p2 != NULL) {
        if (p1->exp > p2->exp) {
            insertTerm(&result, p1->coeff, p1->exp);
            p1 = p1->next;
        } else if (p1->exp < p2->exp) {
            insertTerm(&result, p2->coeff, p2->exp);
            p2 = p2->next;
        } else {
            // Same exponent, add coefficients
            insertTerm(&result, p1->coeff + p2->coeff, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    // Add remaining terms
    while (p1 != NULL) {
        insertTerm(&result, p1->coeff, p1->exp);
        p1 = p1->next;
    }

    while (p2 != NULL) {
        insertTerm(&result, p2->coeff, p2->exp);
        p2 = p2->next;
    }

    return result;
}

// Display polynomial
void displayPolynomial(struct PolyNode* head) {
    struct PolyNode* temp = head;
    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->exp);
        if (temp->next != NULL)
            printf(" + ");
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int numTerms1, numTerms2;
    scanf("%d", &numTerms1);

    struct PolyNode* poly1 = NULL;
    int coeff, exp;
    for (int i = 0; i < numTerms1; i++) {
        scanf("%d %d", &coeff, &exp);
        insertTerm(&poly1, coeff, exp);
    }

    scanf("%d", &numTerms2);

    struct PolyNode* poly2 = NULL;
    for (int i = 0; i < numTerms2; i++) {
        scanf("%d %d", &coeff, &exp);
        insertTerm(&poly2, coeff, exp);
    }

    // Display first polynomial
    displayPolynomial(poly1);

    // Display second polynomial
    displayPolynomial(poly2);

    // Display sum
    struct PolyNode* sum = addPolynomials(poly1, poly2);
    displayPolynomial(sum);

    return 0;
}
