#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//deadline
//
struct ToDo{
    int id;
    char titre[50];
    char description[1000];
    char statut[20];

};
 typedef struct ToDo todo;

   int total_taches=0;



   //******************************************************************************************************************
   // les fonctions :


void ajouter_tache(todo *todos,int choix ){
    int ntache=1,i;
    //selon le choix de l'utilisateur il boucle pour afficher l'ajout du tache
    if(choix==2){
        printf("Combient de tache voullez-vous ajouter ? :\n");
        scanf("%d",&ntache);
    }
    //pour total_taches + ntache c'est pour que le debut soit les taches deja saisit plus le nbr des taches à entrer
        for(i=total_taches;i<total_taches + ntache;i++){
            //stockage de l'ID automatiquement a l'aide de i
            todos[i].id=i+1;
            printf("entrez le titre de la tache a realiser :");
            scanf("%s",todos[i].titre);
            printf("entrez la description :");
            scanf(" %99[^\n]",todos[i].description);
            strcpy(todos[i].statut,"TO_DO");
            printf("\nAjoute avec succes ! \n");
            printf("\n**************\n");
        }

        total_taches = total_taches + ntache;
}

                                            //affichage par tri

void affichage_par_tri(todo *todos){
    int i,tri,j;
    todo tri_alph;
    if(total_taches>0){
    for(i=0;i<total_taches;i++){
        printf("l'id de la tache : %d\n", todos[i].id);
        printf("le titre de la tache a realiser : %s\n", todos[i].titre);
        printf("la description : %s\n", todos[i].description);
        printf("le statut : %s\n", todos[i].statut);
        printf("**************\n");
    }}else printf("\nAucune tache a afficher !\n");
    printf("\n1 tri par ordre alphabetique.\n");
    printf("\n2 tri par deadline.\n");
    printf("\n0 Retour au menu principal.\n");
    scanf("%d",&tri);

        for(i=0;i<total_taches-1;i++){
            for(j=i+1;j<total_taches;j++){
                if(strcmp(todos[i].titre,todos[j].titre)==1){
                    tri_alph=todos[i];
                    todos[i]=todos[j];
                    todos[j]=tri_alph;
                }
            }
        }
        switch(tri){
        case 1:
            if(total_taches>0){
                for(i=0;i<total_taches;i++){
                    printf("l'id de la tache : %d\n", todos[i].id);
                    printf("le titre de la tache a realiser : %s\n", todos[i].titre);
                    printf("la description : %s\n", todos[i].description);
                    printf("le statut : %s\n", todos[i].statut);
                    printf("**************\n");
                }
            }else printf("Vous n'avez entrer encors aucune tache ! \n");
            break;
        case 0:
            break;
        }

                            //tri par deadline :

}


void modifier_desc(todo *todos){
    int id_,i;
    int modifie=0;
    char descrip[200];
    printf("\nEntrez l'id du tache : ");
    scanf("%d",&id_);
    for(i=0;i<total_taches;i++){
        if(todos[i].id==id_){
            printf("\nentrez la description : ");
            scanf(" %[^\n]",descrip);
            strcpy(todos[i].description, descrip);
            printf("\n Modifie avec succes !\n");
            modifie=1;
            break;
        }
    }
    if(modifie==0){
        printf("\nCe id n'existe pas !");
    }
}

void modifier_statut(todo *todos){
    int id_,i,modifie;
    char stu[200];
    printf("\nEntrez l'id du tache : ");
    scanf("%d",&id_);
    for(i=0;i<total_taches;i++){
        if(todos[i].id==id_){
            printf("\nentrez le statut : ");
            scanf("%s",stu);
            strcpy(todos[i].statut, stu);
            printf("\n Modifie avec succes !\n");
            modifie=1;
            break;
        }
    }
    if(modifie==0){
        printf("\nCe id n'existe pas !");
    }
}

void Modification(todo *todos){
    int choix;
        printf("1 : Modifier la description d'une tache\n");
        printf("2 : Modifier le statut d'une tache\n");
        printf("3 : Modifier le deadline d'une tache\n");
        printf("0 : quitter\n");
        scanf("%d",&choix);
        printf("\n***********************************************\n\n");
        switch(choix){
            case 1:
            modifier_desc(todos);
            break;
            case 2:
            modifier_statut(todos);
            break;
//            case 3:
//            affichage_par_tri(todos);
            case 0:
            break;
        }
}

void Suppression(todo *todos){
    int id_,trouve,i,j;
    printf("\nEntrez l'id du tache a supprimer : ");
    scanf("%d",&id_);
    for(i=1;i<total_taches;i++){
        if(todos[i].id==id_){
            for(j=i;j<total_taches;j++)
                todos[j+1]=todos[j+2];
            printf("\nSupprime avec succes !\n");
            trouve=1;
            break;
        }
    }
    total_taches--;
    if(trouve==0)
        printf("\nl'id que vous avez entre n'existe pas !\n");
}


void Recherche_id(todo *todos){
    int id_,trouve=0,i;
    printf("\nEntrez l'id du tache a rechercher : ");
    scanf("%d",&id_);
    for(i=1;i<total_taches;i++){
        if(todos[i].id==id_){
                printf("\nLes infos sur la tache : id = %d ,Titre : %s , Description : %s , Statut : %s \n\n\n",todos[i].id,todos[i].titre,todos[i].description,todos[i].statut);
            trouve=1;
            break;
        }
    }
    if(trouve==0)
        printf("\nla tache n'existe pas !\n");
}


void Recherche_titre(todo *todos){
    int trouve=0,i;
    char titre[20];
    printf("\nEntrez le titre du tache a rechercher : ");
    scanf("%s",titre);
    for(i=1;i<total_taches;i++){
        if(strcmp(todos[i].titre,titre)==0){
            printf("\nLes infos sur la tache : id = %d ,Titre : %s , Description : %s , Statut : %s \n\n\n",todos[i].id,todos[i].titre,todos[i].description,todos[i].statut);
            trouve=1;
            break;
        }
    }
    if(trouve==0)
        printf("\nla tache n'existe pas !\n");
}

void Recherche(todo *todos){
    int choix;
        printf("1 : recherche par id\n");
        printf("2 : recherche par titre\n");
        printf("0 : quitter\n");
        scanf("%d",&choix);
        printf("\n***********************************************\n\n");
        switch(choix){
            case 1:
            Recherche_id(todos);
            break;
            case 2:
            Recherche_titre(todos);
            break;
            case 0:
            system("pause");
        }

}
// fonction main ********************************************************************************************************************

int main()
{
    int choix;

    todo todos[100];

    printf("Bienvenu dans votre application pour gerer vos To Do listes : \n");
    printf("total des taches : %d",total_taches);
    printf("\n*************************************************************************\n\n");
    do{
        printf("1 : ajouter une tache\n");
        printf("2 : ajouter plusieurs tache\n");
        printf("3 : affichage\n");
        printf("4 : Modification\n");
        printf("5 : Suppression\n");
        printf("6 : Recherche\n");
        printf("0 : quitter\n");
        scanf("%d",&choix);
        printf("\n***********************************************\n\n");
        switch(choix){
            case 1:
            ajouter_tache(todos,choix);
            break;
            case 2:
            ajouter_tache(todos,choix);
            break;
            case 3:
            affichage_par_tri(todos);
            break;
            case 4:
            Modification(todos);
            break;
            case 5:
            Suppression(todos);
            break;
            case 6:
            Recherche(todos);
            break;
            case 0:
            printf("Merci !");
            system("pause");
        }
    }while(choix!=0);

    return 0;
}
