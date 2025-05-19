#include<stdio.h>
#include<stdlib.h>
typedef struct Noeud {
    int valeur ;
    struct Noeud *suivant;
}Noeud ;
Noeud *creer(int valeur)
{
    Noeud *nv=(Noeud *)malloc(sizeof(Noeud ));
    if(nv==NULL)
    {
        printf("erreur d'allocation dynamique \n");
        return NULL;
    }
    nv->valeur =valeur ;
    nv->suivant=NULL;
    return nv;
}
Noeud *ajouterD(Noeud *debut,int valeur )
{

    Noeud *nv=creer(valeur);
    if(nv!=NULL)
    {
        if(debut==NULL)
        {
            debut=nv;
        }
        else {
            nv->suivant=debut;
            debut=nv;
        }
    }
    return debut;
}
int taille(Noeud *debut)
{
    Noeud *temp=debut;
    int compteur=0;
    while(temp!=NULL)
    {
        compteur ++;
        temp=temp->suivant;

    }
    return compteur ;

}
Noeud *insertposition(Noeud *debut,int pos,int valeur)
{
    Noeud *nv=creer(valeur);
    Noeud *courant=debut;;
    if(nv!=NULL)
    {
        if(debut==NULL)
        {
            printf("la liste est vide \n");
        }
        else if(pos<1 || pos>taille(debut))
        {
            printf("Position invalide\n");
        }
        else if(pos==1)
        {
                   debut=ajouterD(debut,valeur);
                   return debut;
        }
        else{
              for(int i=1;i<=pos-1;i++)
              {
                   if(i==pos-1)
                   {
                       break;
                   }
                  courant =courant->suivant;
              }
              nv->suivant=courant->suivant;
             courant->suivant =nv;
        }
    }
    return debut;
}
Noeud *ajouterF(Noeud *debut,int valeur )
{
    Noeud *nv=creer(valeur);
    if(nv!=NULL)
    {
        if(debut==NULL)
        {
            debut=nv;
        }
        else {
                Noeud *temp=debut;
            while(temp->suivant!=NULL)
            {
                temp=temp->suivant;
            }
            temp->suivant=nv;
        }
    }
    return debut;
}
void rechercher(Noeud *debut,int _valeur)
{

    Noeud *courant=debut;
    int pos=0;
    while(courant!=NULL)
    {
        if(courant->valeur ==_valeur)
        {
            printf("la valeur %d est presente dans la liste a la position %d\n",_valeur,pos+1);
            break;
        }
        pos++;
        courant=courant->suivant;
    }
}
Noeud *supprimerD(Noeud *debut)
{
    if(debut==NULL)
    {
        printf("la liste est vide \n");
    }
    else {
          Noeud *temp=debut;
          debut=debut->suivant;
          free(temp);
    }
    return debut;
}
Noeud *supprimerF(Noeud *debut)
{
    if(debut==NULL)
    {
        printf("la liste est vide \n");
    }
    else {
         Noeud *temp=debut,*precedent=debut;
         while(temp->suivant!=NULL)
         {
             precedent=temp;
             temp=temp->suivant;
         }
         precedent->suivant=temp->suivant;
         free(temp);
    }
    return debut;
}
Noeud *suppressionP(Noeud *debut ,int pos )
{
    if(debut==NULL)
    {
        printf("la liste est vide \n");
        return NULL;
    }
    else if(pos<1 || pos>taille(debut))
    {
        printf("position non valide \n");
    }
    else {
           if(pos==1)
           {
               debut=supprimerD(debut);
           }
           else {
                Noeud *courant=debut,*precedent=debut;
               for (int i=1;i<pos;i++)
               {
                    precedent=courant;
                   courant=courant->suivant;
               }
               precedent->suivant=courant->suivant;
               if(courant->suivant==NULL)
               {
                   precedent->suivant=NULL;
               }
               free(courant);

           }
    }
    return debut;
}
Noeud *modifierD(Noeud *debut ,int valeur )
{
    if(debut==NULL)
    {
        printf("la liste est vide \n");
        return NULL;
    }
    debut->valeur=valeur;
    return debut ;
}
Noeud *modifierF(Noeud *debut,int valeur )
{
      if(debut ==NULL)
      {
            printf("la liste est vide \n");
            return NULL;
      }
      Noeud *temp=debut;
      while(temp->suivant!=NULL)
      {
          temp=temp->suivant;
      }
      temp->valeur=valeur;
     return debut;
}
Noeud *modifierP(Noeud *debut,int pos,int valeur)
{
    if(debut ==NULL)
    {
        printf("la liste est vide\n");
    }
    else if (pos<1 || pos>taille(debut))
    {
        printf("position invalide");
    }
    else {
            Noeud *temp=debut;
          for(int i=1;i<pos;i++)
          {
              temp=temp->suivant;
          }
           temp->valeur=valeur;
    }
    return debut;
}
void afficher(Noeud *debut)
{
    Noeud *temp=debut;
    while(temp!=NULL)
    {
        printf("%d->",temp->valeur);
        temp=temp->suivant;
    }
    printf("NULL\n");
}
void main()
{
    Noeud *debut=NULL;
    int pos;
    int valeur;
    printf("entrer un certains de nombre de valeur au d�but liste jusqu'a z�ro :\n");
    do {
            scanf("%d",&valeur);
         if(valeur !=0)
         {
            debut=ajouterD(debut,valeur);
         }
    }while(valeur!=0);
    afficher(debut);
    printf("entrer un certains de nombre de valeur a la fin de la liste  jusqu'a z�ro :\n");
    do {
            scanf("%d",&valeur);
         if(valeur !=0)
         {
            debut=ajouterF(debut,valeur);
         }
    }while(valeur!=0);
    afficher(debut);
    printf("==================AJOUT A UNE POSITION DE LA LISTE==================\n");
    printf("entrer la position a laquelle vous souhaitez inserer : \n");
    scanf("%d",&pos);
    printf("entrer une valeur :\n");
    scanf("%d",&valeur);
    debut=insertposition(debut,pos,valeur);
    afficher(debut);
    printf("=====================LA TAILLE DE VOTRE LISTE =======================\n");
    printf("la taille de votre liste est : %d\n",taille(debut));
    printf("=====================RECHERCHE D UNE VALEUR==========================\n");
    printf("entrer une valeur a rechercher au sein de la liste :\n");
    scanf("%d",&valeur);
    rechercher(debut,valeur);
    printf("==================SUPPRESSION DEBUT DE LA LISTE==================\n");
    debut=supprimerD(debut);
    afficher(debut);
    printf("==================SUPPRESSION FIN DE LA LISTE==================\n");
    debut=supprimerF(debut);
    afficher(debut);
    printf("==================SUPPRESSION A UNE POSITION  DE LA LISTE==================\n");
    printf("entrer la position a laquelle vous souhaitez supprimer : \n");
    scanf("%d",&pos);
    debut=suppressionP(debut,pos);
    afficher(debut);
    printf("===================MODIFIER VALEUR DEBUT LISTE=====================\n");
    printf("entrer la nouvelle valeur : \n");
    scanf("%d",&valeur);
    debut=modifierD(debut,valeur);
    afficher(debut);
    printf("===================MODIFIER VALEUR FIN LISTE=====================\n");
    printf("entrer la nouvelle valeur : \n");
    scanf("%d",&valeur);
    debut=modifierF(debut,valeur);
    afficher(debut);
     printf("===================MODIFIER VALEUR POSITION DE LA LISTE=====================\n");
    printf("entrer la nouvelle valeur : \n");
    scanf("%d",&valeur);
    printf("entrer la position a laquelle le changement doit se faire : \n");
    scanf("%d",&pos);
    debut=modifierP(debut,pos,valeur);
    afficher(debut);


}