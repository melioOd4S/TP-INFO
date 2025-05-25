#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Produit {
    int id;
    char nom[50];
    float prix;
    int quantite;
    struct Produit* suivant;
} Produit;

Produit* creerProduit(int id, const char* nom, float prix, int quantite) {
    Produit* nouveauProduit = (Produit*)malloc(sizeof(Produit));
    if (nouveauProduit == NULL) {
        printf("Erreur d'allocation de mémoire\n");
        exit(EXIT_FAILURE);
    }
    
    nouveauProduit->id = id;
    strncpy(nouveauProduit->nom, nom, 49);
    nouveauProduit->nom[49] = '\0';
    nouveauProduit->prix = prix;
    nouveauProduit->quantite = quantite;
    nouveauProduit->suivant = NULL;
    
    return nouveauProduit;
}

Produit* ajouterProduit(Produit* tete, int id, const char* nom, float prix, int quantite) {
    Produit* temp = tete;
    while (temp != NULL) {
        if (temp->id == id) {
            printf("Erreur: Un produit avec l'ID %d existe déjà\n", id);
            return tete;
        }
        temp = temp->suivant;
    }
    
    Produit* nouveauProduit = creerProduit(id, nom, prix, quantite);
    
    if (tete == NULL) {
        return nouveauProduit;
    }
    
    temp = tete;
    while (temp->suivant != NULL) {
        temp = temp->suivant;
    }
    temp->suivant = nouveauProduit;
    
    return tete;
}

Produit* chercherProduit(Produit* tete, int id) {
    Produit* temp = tete;
    
    while (temp != NULL) {
        if (temp->id == id) {
            return temp;
        }
        temp = temp->suivant;
    }
    
    return NULL;
}

Produit* supprimerProduit(Produit* tete, int id) {
    if (tete == NULL) {
        printf("La liste est vide\n");
        return NULL;
    }
    
    if (tete->id == id) {
        Produit* temp = tete->suivant;
        free(tete);
        printf("Produit avec ID %d supprimé avec succès\n", id);
        return temp;
    }
    
    Produit* courant = tete;
    Produit* precedent = NULL;
    
    while (courant != NULL && courant->id != id) {
        precedent = courant;
        courant = courant->suivant;
    }
    
    if (courant == NULL) {
        printf("Produit avec ID %d non trouvé\n", id);
        return tete;
    }
    
    precedent->suivant = courant->suivant;
    free(courant);
    printf("Produit avec ID %d supprimé avec succès\n", id);
    
    return tete;
}

void afficherProduits(Produit* tete) {
    if (tete == NULL) {
        printf("La liste des produits est vide\n");
        return;
    }
    
    printf("\n===== LISTE DES PRODUITS =====\n");
    printf("ID\tNOM\t\tPRIX\tQUANTITE\n");
    printf("--------------------------------\n");
    
    Produit* temp = tete;
    while (temp != NULL) {
        printf("%d\t%-15s\t%.2f\t%d\n", temp->id, temp->nom, temp->prix, temp->quantite);
        temp = temp->suivant;
    }
    printf("===============================\n\n");
}

Produit* modifierProduit(Produit* tete, int id, const char* nouveauNom, float nouveauPrix, int nouvelleQuantite) {
    Produit* produit = chercherProduit(tete, id);
    
    if (produit == NULL) {
        printf("Produit avec ID %d non trouvé\n", id);
        return tete;
    }
    
    strncpy(produit->nom, nouveauNom, 49);
    produit->nom[49] = '\0';
    produit->prix = nouveauPrix;
    produit->quantite = nouvelleQuantite;
    
    printf("Produit avec ID %d modifié avec succès\n", id);
    return tete;
}

void libererListe(Produit* tete) {
    Produit* temp;
    
    while (tete != NULL) {
        temp = tete;
        tete = tete->suivant;
        free(temp);
    }
}

int main() {
    Produit* listeProduits = NULL;
    int choix, id, quantite;
    char nom[50];
    float prix;
    
    do {
        printf("\n===== GESTION DE PRODUITS =====\n");
        printf("1. Ajouter un produit\n");
        printf("2. Chercher un produit\n");
        printf("3. Supprimer un produit\n");
        printf("4. Afficher tous les produits\n");
        printf("5. Modifier un produit\n");
        printf("0. Quitter\n");
        printf("Votre choix: ");
        scanf("%d", &choix);
        
        switch (choix) {
            case 1:
                printf("ID du produit: ");
                scanf("%d", &id);
                printf("Nom du produit: ");
                scanf(" %49[^\n]", nom);
                printf("Prix du produit: ");
                scanf("%f", &prix);
                printf("Quantité du produit: ");
                scanf("%d", &quantite);
                listeProduits = ajouterProduit(listeProduits, id, nom, prix, quantite);
                break;
                
            case 2:
                printf("Entrez l'ID du produit à chercher: ");
                scanf("%d", &id);
                Produit* trouve = chercherProduit(listeProduits, id);
                if (trouve != NULL) {
                    printf("\nProduit trouvé:\n");
                    printf("ID: %d\n", trouve->id);
                    printf("Nom: %s\n", trouve->nom);
                    printf("Prix: %.2f\n", trouve->prix);
                    printf("Quantité: %d\n", trouve->quantite);
                } else {
                    printf("Produit avec ID %d non trouvé\n", id);
                }
                break;
                
            case 3:
                printf("Entrez l'ID du produit à supprimer: ");
                scanf("%d", &id);
                listeProduits = supprimerProduit(listeProduits, id);
                break;
                
            case 4:
                afficherProduits(listeProduits);
                break;
                
            case 5:
                printf("Entrez l'ID du produit à modifier: ");
                scanf("%d", &id);
                printf("Nouveau nom: ");
                scanf(" %49[^\n]", nom);
                printf("Nouveau prix: ");
                scanf("%f", &prix);
                printf("Nouvelle quantité: ");
                scanf("%d", &quantite);
                listeProduits = modifierProduit(listeProduits, id, nom, prix, quantite);
                break;
                
            case 0:
                printf("Au revoir!\n");
                break;
                
            default:
                printf("Choix invalide, veuillez réessayer\n");
        }
        
    } while (choix != 0);
    
    libererListe(listeProduits);
    
return 0;
}