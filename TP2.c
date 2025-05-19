//exercice 2: tp2 semestre 2AP

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Date {
	char jour [3];
	char mois [3];
	char annee[5];
}date;
typedef struct Produit {
	char *nom_produit;
	char reference [100];
	float montant ;
	date Dateachat;
}produit;
typedef struct liste {
	produit cellule ;
	struct liste *psuiv;
}liste;

liste *creer_liste_produits()
{
	liste *nv=(liste *)malloc(sizeof(liste));
	if(nv==NULL)
	{
		printf("erreur d'allocation dynamique \n");
		return NULL;
	}
	nv->psuiv=NULL;
	return nv;
}
int est_vide(liste *tete)
{
	if(tete==NULL)
	{
		return 1;
	}
	return 0;
}
liste *creer_produits (){

          char choix;
          char nom[100],ref[100];
          float prix;
          date dt;
          printf("saisir  ou passer directement(s/P) : \n");
          scanf(" %c",&choix);
          if(choix=='s')
          {
              printf("entrer le nom du produits : \n");
              scanf("%s",nom);
              printf("entrer la reference  du produits : \n");
              scanf("%s",ref);
              printf("entrer le prix du produits :\n");
              scanf("%f",&prix);
              printf("entrer la date d'achat du produits :\n");
              scanf("%s%s%s",dt.jour,dt.mois,dt.annee);
          }
	liste *nv1=(liste *)malloc(sizeof(liste));
	if(nv1== NULL)
	{
		printf("erreur d'allocation dynamique\n");
		return NULL;
	}
	nv1->cellule.nom_produit=(char *)malloc((strlen(nom)+1)*sizeof(char));
	if(nv1->cellule.nom_produit==NULL)
    {
        printf("erreur d'allocation dynamique \n");
    }
    else {
	strcpy(nv1->cellule.nom_produit,nom);
	strcpy(nv1->cellule.reference,ref);
	nv1->cellule.montant=prix;
    strcpy(nv1->cellule.Dateachat.annee,dt.annee);
    strcpy(nv1->cellule.Dateachat.jour,dt.jour);
    strcpy(nv1->cellule.Dateachat.mois,dt.mois);
    nv1->psuiv=NULL;
    }
    return nv1;

}
void afficher_produit (liste* produit )
{
    printf("=====================AFFICHAGE DU NOUVEAU PRODUITS=================\n");
	printf("nom produit : %s\n",produit->cellule.nom_produit);
	printf("reference produit: %s\n",produit->cellule.reference);
	printf("montant  produit : %f\n",produit->cellule.montant);
	printf("Date d'achat produit: %s\t %s\t %s \t",produit->cellule.Dateachat.jour ,produit->cellule.Dateachat.mois,produit->cellule.Dateachat.annee);


}
liste *ajouter_debut(liste *tete)
{
	liste *nv=creer_produits();
	afficher_produit(nv);
	if(nv!=NULL)
	{
		if(tete==NULL)
		{
			tete=nv;
		}
		else {
			nv->psuiv =tete;
			tete=nv;
		}
	}
	return tete;
}
void ajouter_fin(liste **tete){
	liste *nv=creer_produits();
	afficher_produit(nv);
	if(nv!=NULL)
	{
		if(*tete==NULL)
		{
			*tete=nv;
		}
		else {
			liste *temp=*tete;
			while(temp->psuiv!=NULL)
			{
				temp=temp->psuiv;
			}
			temp->psuiv=nv;

		}
	}

}
void afficher_produits(liste *tete)
{
	liste *i=tete;
	while(i!=NULL)
	{
		printf("nom produit : %s\n",i->cellule.nom_produit);
		printf("reference produit: %s\n",i->cellule.reference);
		printf("montant  produit : %f\n",i->cellule.montant);
		printf("Date d'achat produit: %s\t %s\t %s \n",i->cellule.Dateachat.jour ,i->cellule.Dateachat.mois,i->cellule.Dateachat.annee);
		i=i->psuiv;
	}

}
int longueur(liste *tete)
{
	liste *i=tete;
	int compteur=0;
	while(i!=NULL)
	{
	    compteur++;
		i=i->psuiv;
	}
	return compteur;
}
void filter_date(liste *tete,date dt)
{
	liste *temp=tete;
	while(temp!=NULL)
	{
		if(strcmp(temp->cellule.Dateachat.jour,dt.jour)==0&&strcmp(temp->cellule.Dateachat.mois,dt.mois)==0&&strcmp(temp->cellule.Dateachat.annee,dt.annee)==0)
		{
				printf("nom produit : %s\n",temp->cellule.nom_produit);
				printf("reference produit: %s\n",temp->cellule.reference);
				printf("montant  produit : %f\n",temp->cellule.montant);
				printf("Date d'achat produit: %s\t %s\t %s \n",temp->cellule.Dateachat.jour ,temp->cellule.Dateachat.mois,temp->cellule.Dateachat.annee);

		}
		temp=temp->psuiv;
	}
}
liste* supprimer_debut(liste *tete)
{
	if(tete==NULL)
	{
		printf("la liste est vide ");
	}
	else {
		liste *temp=tete;
		tete=tete->psuiv;
		free(temp);
	}
	return tete;
}
void supprimer_fin(liste **tete)
{
	if(*tete==NULL)
	{
		printf("la liste est vide\n");
	}
	else
	{
		liste *temp=*tete;
		liste *precedent;
		while(temp->psuiv !=NULL)
		{
			precedent =temp;
			temp=temp->psuiv;
		}
		   free(temp);
		   precedent->psuiv=NULL;
	}
}

liste *rembourser(liste *liste1 ,char *refer)
{
	liste *temp,*precedent;
	if(liste1==NULL)
	{
		printf("la liste est vide \n");
		return NULL;
	}
	else {
		 int trouver,pos,compteur;
		 pos=longueur(liste1);
		 temp=liste1;
		 precedent =liste1;
		 for(compteur=1;compteur<pos;compteur++)
		 {
		 	compteur++;
		 	if(strcmp(temp->cellule.reference,refer)==0)
		 	{
		 		    break;
			 }
			 precedent = temp ;
			 temp=temp->psuiv;
		 }
		 if(compteur==1)
		 {
		 	liste1=supprimer_debut(liste1);
		 }
		 else if(compteur == pos)
		 {
		 	supprimer_fin(&liste1);
		 }
		 else {
		 	    precedent->psuiv =temp->psuiv ;
		 	    free(temp);
		 }

	}
	return liste1;
}
int  menu()
{
    int  choix;
    printf("========================Menu=====================\n");
    printf("1-Verifier la liste est vide  \n");
    printf("2-creer produits et ajouter au d�but de la liste un produits  \n");
    printf("3-DETERMINER LA LONGUEUR DE LA LISTE DES PRODUITS \n");
    printf("4-creer produits et ajouter a la fin de la liste un produits \n");
    printf("5-afficher la liste de produits \n");
    printf("6-afficher les produits de la liste selon la date d'ajout  \n");
    printf("7-SUPPRESSION DEBUT DE LA LISTE \n");
    printf("8-SUPPRESSION FIN DE LA LISTE \n");
    printf("9-SUPPRESSION SELON LA REFERENCE DU PRODUITS DANS LA LISTES\n");
    printf("entrer votre choix :\n");
    scanf("%d",&choix);
    return choix;


}

void main()
{
	liste *tete=NULL,*nouveau;
	date dt ;
	int choix, test;
	float prix;
	 char choix2,ref[100],nom[100];
	e:
	    system("cls ");
        choix =menu();
	switch(choix)
	{

    case 1 :
         test =est_vide(tete);
        if(test ==1)
        {
            printf("liste est vide \n");
        }
        else {
             printf("liste  n' est pas vide \n");
        }

        break;
    case 2:
        tete=ajouter_debut(tete);
         break;
    case 3:
        printf("la longueur  de votre liste  est : %d\n",longueur(tete));
         break;
    case 4:
          ajouter_fin(&tete);
          break;
    case 5:
        afficher_produits(tete);
       break ;
    case 6 :
         printf("entrer la date d'ajout des produits a afficher : \n");
         scanf("%s%s%s",dt.jour,dt.mois,dt.annee);
         filter_date(tete,dt);
        break;
    case 7:
          printf("================SUPPRESSION AU DEBUT DE LA LISTE===========\n");
          tete=supprimer_debut(tete);
          break;
    case 8:
          printf("================SUPPRESSION A LA FIN DE LA LISTE===========\n");
          supprimer_fin(&tete);
          break;
    case 9:
        printf("veuiller saisir la r�f�rence du livre a supprimer : \n");
        scanf("%s",ref);
        tete=rembourser(tete,ref);
        break;
    default :
        printf("erreur de choix dans le menu \n");
        break;

	}
	if(choix>=1 && choix<=8 )
    {

        printf("souhaiter poursuivre l'une des op�rations presentes dans le menu(O/N) : \n");
        scanf(" %c",&choix2);
        if(choix2=='O')
        {
            goto e;
        }
        else
        {
           printf("FIN PROGRAMME ");
        }
    }



}
