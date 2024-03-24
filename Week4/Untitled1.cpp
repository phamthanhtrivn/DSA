#include <stdio.h>
#include <stdlib.h>

// Ð?nh nghia c?u trúc cho m?t h?ng t? trong da th?c
struct Term {
    int coefficient; // H? s?
    int exponent;    // S? mu
    struct Term* next;
};

// Hàm d? thêm m?t h?ng t? vào danh sách liên k?t
void addTerm(struct Term** head, int coefficient, int exponent) {
    struct Term* newTerm = (struct Term*)malloc(sizeof(struct Term));
    newTerm->coefficient = coefficient;
    newTerm->exponent = exponent;
    newTerm->next = *head;
    *head = newTerm;
}

// Hàm d? in da th?c t? danh sách liên k?t
void printPolynomial(struct Term* head) {
    int isFirstTerm = 1;
    while (head != NULL) {
        if (head->coefficient != 0) {
            if (!isFirstTerm) {
                if (head->coefficient > 0) {
                    printf(" + ");
                } else {
                    printf(" - ");
                }
            }
            isFirstTerm = 0;

            printf("%d*x^%d", abs(head->coefficient), head->exponent);
        }
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Term* polynomial = NULL;

    // Thêm các h?ng t? vào da th?c
    addTerm(&polynomial, 6, 7);
    addTerm(&polynomial, -3, 5);
    addTerm(&polynomial, 9, 2);
    addTerm(&polynomial, -1, 0);

    printf("Ða th?c: ");
    printPolynomial(polynomial);

    // Gi?i phóng b? nh? sau khi s? d?ng
    while (polynomial != NULL) {
        struct Term* temp = polynomial;
        polynomial = polynomial->next;
        free(temp);
    }

    return 0;
}

