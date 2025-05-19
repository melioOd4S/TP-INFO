#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Noeud {
	int valeur;
	struct Noeud *suivant;
	struct Noeud *precedent;
}Noeud;
typedef Noeud* liste;
liste creer(int valeur)
{
	liste new_element=(liste )malloc(sizeof(Noeud));
	if(new_element==NULL)
	{
		printf("allocation dynamique échouer");
		exit(01);
	}
	new_element->valeur=valeur;
	new_element->suivant=NULL;
	new_element->precedent=NULL;
	return new_element;
}
void affiche(liste debut)
{
	liste temp = debut;
	while(temp!=NULL)
	{
		printf("%d->",temp->valeur);
		temp=temp->suivant;
	}
	printf("NULL");
}
void afficheInverse(Noeud *debut)
{
	liste temp=debut;
	while(temp->suivant!=NULL)
	{
		temp=temp->suivant;
	}
	while(temp!=NULL)
	{
		printf("%d->",temp->valeur);
		temp=temp->precedent;
	}
	printf("NULL");
}
liste ajouterD(Noeud *debut,int _valeur)
{
	liste new_element=creer(_valeur);
	if(debut==NULL)
	{
		debut=new_element;
	}
	else {
		  new_element->suivant=debut;
		  debut->precedent=new_element;
		  debut=new_element;
	}
	return debut;
}
liste ajouterF(liste debut ,int _valeur)
{
		liste new_element=creer(_valeur);
	if(debut==NULL)
	{
		debut=new_element;
	}
	else {
		liste temp=debut;
		while(temp->suivant!=NULL)
		{
			temp=temp->suivant;
		}
		temp->suivant=new_element;
		new_element->precedent=temp;
	}
	return debut;
}
int taille(liste debut )
{
   int compteur=0;
   liste temp=debut;
   while(temp!=NULL)
   {
   	   compteur++;
   	   temp=temp->suivant;
   }
   return compteur;
}
liste insertion(liste debut ,int pos ,int _valeur)
{
	liste new_element=creer(_valeur);
	int compteur=1;
	if(pos>taille(debut)+1||pos<1)
   {
	printf("Position entrer invalide");
     }
    else if(pos==1)
    {
    	debut=ajouterD(debut,_valeur);
	}
	else {
		  liste temp=debut;
		  while(temp->suivant!=NULL  && compteur!=pos)
		  {
		  	  compteur++;
		  	  temp=temp->suivant;
		  }
		  temp->precedent->suivant=new_element;
		  new_element->suivant=temp;
		  new_element->precedent=temp->precedent;
		  temp->precedent=new_element;
	}
	return debut;
	
}
liste rechercher(liste debut,int _valeur)
{
	liste temp=debut;
	while(temp!=NULL)
	{
		if(temp->valeur ==_valeur)
		{
			break;
		}
		temp=temp->suivant;
	}
	return temp;
}
liste SuppressionD(liste debut)
{
	if(debut!=NULL)
	{
		if(debut->suivant==NULL)
		{
			free(debut);
			debut=NULL;
		}
		else {
			liste temp=debut;
			debut=debut->suivant;
			debut->precedent=NULL;
			free(temp);
		}
	}
	return debut;
}
liste SuppressionF(liste debut)
{
		if(debut!=NULL)
	{
		if(debut->suivant==NULL)
		{
			free(debut);
		}
		else{
			liste temp=debut;
			while(temp->suivant!=NULL)
			{
				temp=temp->suivant;
			}
			temp->precedent->suivant=NULL;
			free(temp);
		}
		return debut;
}
}
liste SuppressionP(liste debut,int pos)
{
	
	if(pos>taille(debut)+1 || pos<1)
	{
		printf("position invalide\n");
	}
	else {
		  if(pos==1)
		  {
		  	debut=SuppressionD(debut);
		  }
		 else {
		  liste temp=debut;
		  int compteur=1;
		  while(temp !=NULL && compteur!=pos)//toujours temp!=NULL sinon il ne modifiera ou du moins la boucle sera infini
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
		  	temp->precedent->suivant=temp->suivant;
		  	temp->suivant->precedent=temp->precedent;
		  	free(temp);
		  }
		}
		
	}
	return debut;
}
liste ModifierD(liste debut ,int _valeur)
{
	if(debut==NULL)
	{
		printf("erreur modification \n");
	}
	else {
		   debut->valeur=_valeur;
	}
	return debut;
}
liste ModifierF(liste debut ,int _valeur)
{
		if(debut==NULL)
	{
		printf("erreur modification \n");
	}
	else {
		   liste temp=debut;
		   while(temp->suivant!=NULL)
		   {
		   	temp=temp->suivant;
		   }
		   temp->valeur=_valeur;
	}
	return debut;
}
liste modifierP(liste debut,int pos,int _valeur)
{
	if(debut==NULL || pos >taille(debut)+1 || pos<1)
	{
		printf("\n Position non existante \n");
	}
	else {
		if (pos==1)
		{
			debut=ModifierD(debut,_valeur);
		}
		else {
			 liste temp=debut;
			 int compteur=1;
			 while(temp->suivant!=NULL && compteur!=pos)
			 {
			 	compteur++;
			 	temp=temp->suivant;
			 }
			 temp->valeur=_valeur;
		}
	}
	return debut;
}
liste tri(liste debut)
{
	if(debut ==NULL)
	{
		printf("liste vide \n");
	}
	else {
		liste temp=debut;
		liste temp2=temp->suivant;
		int valeur;
		while(temp!=NULL)
		{
	     	temp2=temp->suivant;
			while(temp2!=NULL)
			{
				if(temp2->valeur<temp->valeur)
				{
					valeur=temp2->valeur;
					temp2->valeur=temp->valeur;
					temp->valeur=valeur;
				}
				temp2=temp2->suivant;
			}
			temp=temp->suivant;
		}
	}
	return debut;
}
void main()
{
  liste debut=NULL,ptr;
  int valeur,compteur=0,pos;
  for(compteur=0;compteur<3;compteur++)
  {
  	 printf("entrer la valeur %d de la liste : \n",compteur+1);
  	 scanf("%d",&valeur);
  	 debut=ajouterD(debut,valeur);
  }
  printf("\n========affichage de la liste chaine==========\n");
  affiche(debut);
  printf("\n=========INVERSE DE LA LISTE CHAINEE=========\n");
  afficheInverse(debut);
  printf("\n============SAISIE D 'UNE VALEUR A INSERER A LA FIN===========\n");
  for(compteur=0;compteur<3;compteur++)
  {
  	 printf("entrer la valeur %d de la liste : \n",compteur+1);
  	 scanf("%d",&valeur);
  	 debut=ajouterF(debut,valeur);
  }
  affiche(debut);
  printf("\n=========INVERSE DE LA LISTE CHAINEE=========\n");
  afficheInverse(debut);
  printf("\n la taille de votre liste est :%d\n",taille(debut));
  printf("==========Insertion a une position donnée===========\n");
  do {
  	  printf("entrer une position : \n");
  	scanf("%d",&pos);
  	if(pos<0)
  	{
  		printf("erreur potentiel de la position \n");
	  }
  }while(pos<0);
  printf("entrer la nouvelle valeur a insérer a la position %d : \n",pos);
  scanf("%d",&valeur);
  debut=insertion(debut,pos,valeur);
  affiche(debut);
  printf("================RECHERCHE AU SEIN DE LA LISTE DOUBLEMENT CHAINEEE======================\n");
  printf("entrer la valeur a rechercher au sein de votre liste chainee : \n");
  scanf("%d",&valeur);
  ptr=rechercher(debut,valeur);
  printf("==========affichage valeur au sein de la liste ================\n");
  printf("la valeur au sein de la liste est : %d\n",ptr->valeur);
  printf("\n===============SUPPRESSION AU DEBUT DE LA LISTE=======================================\n");
  debut=SuppressionD(debut);
  affiche(debut);
  printf("===============SUPPRESSION A LA FIN DE LA LISTE=======================================\n");
  debut=SuppressionF(debut);
  affiche(debut);
  printf("===============SUPPRESSION A UNE POSITION DONNEE DE LA LISTE=======================================\n");
  do {
  	  printf("entrer une position : \n");
  	scanf("%d",&pos);
  	if(pos<0)
  	{
  		printf("erreur potentiel de la position \n");
	  }
  }while(pos<0);
  debut=SuppressionP(debut ,pos);
  affiche(debut);
  printf("\n =======modifier valeur Debut========\n");
  printf("\n new value: \n");
  scanf("%d",&valeur);
  debut=ModifierD(debut,valeur);
  affiche(debut);
  printf("\n=======modifier valeur Fin========\n");
  printf("\n new value: \n");
  scanf("%d",&valeur);
  debut=ModifierF(debut,valeur);
  affiche(debut);
  printf("\n=======modifier valeur Position donnée========\n");
  printf("\n new value: \n");
  scanf("%d",&valeur);
  printf("\n new position : \n");
  scanf("%d",&pos);
  debut=modifierP(debut ,pos,valeur);
  affiche(debut);
  printf("\n");
  printf("\n=======Liste trie ordre croissant========\n");
  debut=tri(debut);
  affiche(debut);
  
  
  
}
