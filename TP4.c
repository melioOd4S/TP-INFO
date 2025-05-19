#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Etudiant {
	int id ;
	char nom[50];
	float moyenne;
	struct Etudiant *suivant;
	struct Etudiant  *precedent;
	
}Etudiant;
typedef Etudiant* liste;
Etudiant *creer_etudiant()
{
  		liste nv=(liste)malloc(sizeof(Etudiant));
  		if(nv==NULL)
  		{
  			printf("erreur d'allocation dynamique\n");
  			exit(01);
		  }
		printf("entrer l'id de l'etudiant: \n");
		scanf("%d",&nv->id);
		printf("entrer le nom de l'etudiant: \n");
		scanf("%s",nv->nom);
		printf("entrer la moyenne  de l'etudiant %s: \n",nv->nom);
		scanf("%f",&nv->moyenne);
		nv->precedent=NULL;
		nv->suivant=NULL;
	 return nv;
	
}
int longueur (liste tete)
{
    int compteur=0;
    while(tete!=NULL)
    {
    	compteur++;
    	tete=tete->suivant;
	}
	return compteur;
}
liste ajoutD(liste tete,liste nouveau)
{
	if(tete==NULL)
	{
	     tete=nouveau;
	}
	else {
		    nouveau->suivant=tete;
		    tete->precedent=nouveau;
		    tete=nouveau;
	}
	return tete;
}
liste Ajout_position(liste tete,liste nouveau,int position)
{
	  if(tete==NULL || position >longueur(tete)+1)
	  {
	  	printf("element introuvable\n");
	  }
	  else if (position==1)
	  {
	     tete=ajoutD(tete,nouveau);
	
	  }
	  else {
	  	    liste temp=tete;
	  	    int compteur=1;
	  	    while(temp->suivant!=NULL && compteur<position)
	  	    {
	  	    	temp=temp->suivant;
			}

				 nouveau->suivant=temp;
				 temp->precedent->suivant=nouveau;
				 nouveau->precedent=temp->precedent;
				 temp->precedent=nouveau;
			
	  }
	
	return tete;
	
}
liste supprimer_position(liste tete ,int position )
{
	liste temp;
	int compteur;
	 if(tete==NULL || position>longueur(tete)+1|| position <1)
	 {
	 	printf("suppression impossible \n");
	 }
	 else if (position ==1)
	 {
	 	temp=tete;
	 	tete=tete->suivant;
	 	free(temp);
	 	tete->precedent=NULL;
	 }
	 else {
	 	    temp=tete;
	 	    compteur=1;
	 	    while(temp->suivant!=NULL && compteur<position)
	 	    {
	 	    	   compteur++;
	 	    	   temp=temp->suivant;
			 }
			 if(temp->suivant==NULL)
			 {
			 	  temp->precedent->suivant=NULL;
			 	  free(temp);
			 }
			 else {
			 	    temp->suivant->precedent=temp->precedent;
			 	    temp->precedent->suivant=temp->suivant;
			 }
	 }
	 return tete;
}
void afficher(liste tete)
{
	liste temp=tete;
	while(temp!=NULL)
	{
		printf("nom : %s\n",temp->nom);
		printf("id:%d\n",temp->id);
		printf("moyenne:%f\n",temp->moyenne);
		temp=temp->suivant;
	}
}
liste derniere_cellule(liste tete)
{
	if(tete=NULL)
	{
		printf("la liste est vide \n");
		return NULL;
	}
		  liste temp=tete;
		  while(temp->suivant!=NULL)
		  {
		  	temp=temp->suivant;
		  }

	return tete;
}
int chercher_etudiant(liste tete,int d)
{
	liste temp=tete;
	int test=0;
	while(temp!=NULL)
	{
		 if(temp->id==id)
		 {
		 	test=1;
		 	break;
		 }
	}
	return test;
}
void affichage_inverse(liste tete)
{
	liste temp=tete;
	while(temp->suivant!=NULL)
	{
		temp=temp->suivant;
	}
	while(temp!=NULL)
	{
		printf("nom : %s\n",temp->nom);
		printf("id:%d\n",temp->id);
		printf("moyenne:%f\n",temp->moyenne);
		temp=temp->precedent;
	}
}
liste tri(liste tete)
{
	float reserve;
	if(tete!=NULL)
	{
		liste temp=tete;
		liste temp1=tete->suivant;
		while(temp->suivant!=NULL)
		{
			while(temp1->suivant!=NULL)
			{
				if(temp1->moyenne<temp->moyenne)
				{
				   reserve=temp1->moyenne;
				   temp1->moyenne=temp->moyenne;
				   temp->moyenne=reserve;
				}
				temp1=temp1->suivant;
			}
			temp=temp->suivant;
		}
	}
}
void main()
{
	liste tete=NULL,nouveau;
	int compteur=0,position;
	for(compteur;compteur<2;compteur++)
	{
		printf("==================Saisie information %d utilisateur====================\n",compteur+1);
		nouveau=creer_etudiant();
		tete=ajoutD(tete,nouveau);
	
	}
	printf("============affichage dans le bon ordre =====================\n");
	afficher(tete);
	printf("\n ==================affichage sens inverse====================\n");
	affichage_inverse(tete);
	printf("\n la longueur de votre liste d'étudiant est  :%d \n",longueur(tete));
	printf("===========INSERTION A UNE POSITION DONNE =================\n");
	printf("entrer la position au quel vous souhaiter insérer : \n");
	scanf("%d",&position);
	nouveau=creer_etudiant();
    tete=Ajout_position(tete,nouveau,position);
   	printf("\n ============affichage dans le bon ordre =====================\n");
	afficher(tete);
//	printf("\n la derniere cellule de la liste est : %p\n",derniere_cellule(tete));
	printf("===============SUPPRESSION A UNE POSITION DONNEE====================\n");
	printf("entrer la position au quel vous souhaiter insérer : \n");
	scanf("%d",&position);
	tete= supprimer_position(tete,position);
	printf("\n============affichage dans le bon ordre =====================\n");
	afficher(tete);
	
}


