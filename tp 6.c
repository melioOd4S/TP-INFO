#include <stdio.h>
#include <stdlib.h>

typedef struct Noeud {
    int data;
    struct Noeud* next;
} Noeud;

void push(Noeud** top, int val) {
    Noeud* NVNoeud = (Noeud*)malloc(sizeof(Noeud));
    if (NVNoeud == NULL) {
        printf("Erreur : allocation memoire echouee\n");
        return;
    }
    NVNoeud->data = val;
    NVNoeud->next = *top;
    *top = NVNoeud;
    printf("Element %d empile.\n", val);
}

void pop(Noeud** top) {
    if (*top == NULL) {
        printf("Erreur : pile vide, rien a depiler.\n");
        return;
    }
    Noeud* temp = *top;
    *top = (*top)->next;
    printf("Element %d depile.\n", temp->data);
    free(temp);
}

void peek(Noeud** top) {
    if (*top == NULL) {
        printf("La pile est vide.\n");
    } else {
        printf("Sommet de la pile : %d\n", (*top)->data);
    }
}

void display(Noeud** top) {
    if (*top == NULL) {
        printf("La pile est vide.\n");
        return;
    }
    Noeud* courant = *top;
    printf("Elements de la pile : ");
    while (courant != NULL) {
        printf("%d ", courant->data);
        courant = courant->next;
    }
    printf("\n");
}

int main() {
    Noeud* top = NULL;

    push(&top, 10);
    push(&top, 20);
    push(&top, 30);
    display(&top);
    peek(&top);

    pop(&top);
    display(&top);
    peek(&top);

    pop(&top);
    pop(&top);
    pop(&top);

    return 0;
}