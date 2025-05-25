#include<stdio.h>
#include<stdlib.h>

typedef struct Noeud {
    int data;
    struct Noeud *Next;
} Noeud;
typedef Noeud *list;
list head = NULL;

Noeud *cree(int _value) {
    Noeud *newE = (Noeud *)malloc(sizeof(Noeud));
    newE->data = _value;
    newE->Next = NULL;
    return newE;
}

void affiche(Noeud *head) {
    if (head == NULL) {
        printf("La liste est vide\n");
        return;
    }
    Noeud *courant = head;
    printf("l'adresse de head est %p\n", head);
    do {
        printf("valeur: %d | adresse: %p | Next: %p\n", courant->data, courant, courant->Next);
        courant = courant->Next;
    } while (courant != head);
}

void afficheW(Noeud *head) {
    if (head == NULL) {
        printf("La liste est vide.\n");
        return;
    }

    Noeud *courant = head;
    printf("Liste circulaire :\n");

    while (courant->Next != head) {
        printf("valeur: %d | adresse: %p | Next: %p\n", courant->data, courant, courant->Next);
        courant = courant->Next;
    }

    printf("Valeur : %d -> (retour au head)\n", courant->data);
}

Noeud *ajouterD(Noeud *head, int val) {
    Noeud *newE = cree(val);
    if (head == NULL) {
        newE->Next = newE;
        return newE;
    } else {
        Noeud *ptr = head;
        while (ptr->Next != head)
            ptr = ptr->Next;
        ptr->Next = newE;
        newE->Next = head;
        head = newE;
        return head;
    }
}

Noeud *ajouterF(Noeud *head, int val) {
    Noeud *newE = cree(val);
    if (head == NULL) {
        newE->Next = newE;
        return newE;
    } else {
        Noeud *ptr = head;
        while (ptr->Next != head)
            ptr = ptr->Next;
        ptr->Next = newE;
        newE->Next = head;
        return head;
    }
}

int taille(Noeud* head) {
    if (head == NULL) return 0;
    int i = 1;
    Noeud* ptr = head;
    while (ptr->Next != head) {
        i++;
        ptr = ptr->Next;
    }
    return i;
}

Noeud *ajouterM(Noeud *head, int pos, int val) {
    if (head == NULL && pos != 1) {
        printf("Position invalide\n");
        return head;
    }
    if (head != NULL && (pos < 1 || pos > taille(head)+1)) {
        printf("Position invalide\n");
        return head;
    }
    if (pos == 1) return ajouterD(head, val);

    Noeud *newE = cree(val);
    Noeud *ptr = head;
    for (int j = 1; j < pos - 1; j++)
        ptr = ptr->Next;

    newE->Next = ptr->Next;
    ptr->Next = newE;
    return head;
}

Noeud *supprimerD(Noeud *head) {
    if (head == NULL) return NULL;
    if (head->Next == head) {
        free(head);
        return NULL;
    }
    Noeud *ptr = head;
    while (ptr->Next != head)
        ptr = ptr->Next;
    Noeud *temp = head;
    ptr->Next = head->Next;
    head = head->Next;
    free(temp);
    return head;
}

Noeud *supprimerF(Noeud *head) {
    if (head == NULL) return NULL;
    if (head->Next == head) {
        free(head);
        return NULL;
    }
    Noeud *ptr = head;
    while (ptr->Next->Next != head)
        ptr = ptr->Next;
    free(ptr->Next);
    ptr->Next = head;
    return head;
}

Noeud *supprimerM(Noeud *head, int pos) {
    if (head == NULL || pos < 1 || pos > taille(head)) {
        printf("Position invalide ou liste vide\n");
        return head;
    }

    if (pos == 1) return supprimerD(head);

    Noeud *ptr = head;
    for (int j = 1; j < pos - 1; j++)
        ptr = ptr->Next;

    Noeud *temp = ptr->Next;
    ptr->Next = temp->Next;

    if (temp == head) {
        head = ptr->Next;
    }

    free(temp);
    return head;
}

int main() {
    Noeud *head = NULL;

    Noeud *P = cree(10);
    Noeud *D = cree(20);
    Noeud *T = cree(30);

    printf("adresse du noeud head : %p\n", head);
    printf("adresse du noeud P : %p\n", P);
    printf("adresse du noeud D : %p\n", D);
    printf("adresse du noeud T :  %p\n", T);

    head = P;
    P->Next = D;
    D->Next = T;
    T->Next = head;
    printf("----------------------\n");
    printf("adresse du noeud %p\n", head);
    printf("adresse du noeud P Next %p\n", P->Next);
    printf("adresse du noeud D Next %p\n", D->Next);
    printf("adresse du noeud T Next %p\n", T->Next);

    printf("---------------Affichage----------------------\n");

    printf("---------------Ajouter au head----------------------\n");
    head = ajouterD(head, 40);
    affiche(head);

    printf("---------------Ajouter a la fin----------------------\n");
    head = ajouterF(head, 400);
    affiche(head);

    printf("---------------Ajouter a une position----------------------\n");
    head = ajouterM(head, 3, 2400);
    affiche(head);

    printf("---------------Supprimer D----------------------\n");
    head = supprimerD(head);
    affiche(head);

    printf("---------------Supprimer F----------------------\n");
    head = supprimerF(head);
    affiche(head);

    printf("---------------Supprimer M----------------------\n");
    head = supprimerM(head, 3);
    affiche(head);

    return 0;
}