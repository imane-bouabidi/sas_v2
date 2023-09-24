#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct deadline{
    int jour,mois,annee;
}deadline;
struct ToDo{
    int id;
    char titre[50];
    char description[1000];
    char statut[20];
    deadline dead;

};
typedef struct ToDo todo;

int total_taches=0,taches_non_complets=0,taches_complets=0;
int day,month,year,t = 0;
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
            todos[i].id=i+1 + t;
            printf("entrez le titre de la tache a realiser :");
            scanf("%s",todos[i].titre);
            printf("entrez la description :");
            scanf(" %99[^\n]",todos[i].description);
            strcpy(todos[i].statut,"TO_DO");
            taches_non_complets++;
            //on a ajoute / car l'utilisateur va tapper /
            printf("\nDonnez la date sous forme jj/mm/aaaa : ");
            scanf("%d/%d/%d",&todos[i].dead.jour,&todos[i].dead.mois,&todos[i].dead.annee);
            printf("\nAjoute avec succes ! \n");
            printf("\n**************\n");
        }
        total_taches = total_taches + ntache;
}

                                            //affichage par tri

void affichage_par_tri(todo *todos){
    int i,tri,j;
    todo tri_alph;
    int tache_3jours=0;
    printf("\n1 tri par ordre alphabetique.\n");
    printf("\n2 tri par deadline.\n");
    printf("\n3 afficher les taches dont le deadline est dans 3 jours .\n");
    printf("\n0 Retour au menu principal.\n");
    scanf("%d",&tri);

        switch(tri){
        case 1:
            if(total_taches>0){
                for(i=0;i<total_taches-1;i++){
                    for(j=i+1;j<total_taches;j++){
                        if(strcmp(todos[i].titre,todos[j].titre)==1){
                            tri_alph=todos[i];
                            todos[i]=todos[j];
                            todos[j]=tri_alph;
                        }
                    }
                }
                for(i=0;i<total_taches;i++){
                    printf("l'id de la tache : %d\n", todos[i].id);
                    printf("le titre de la tache a realiser : %s\n", todos[i].titre);
                    printf("la description : %s\n", todos[i].description);
                    printf("le statut : %s\n", todos[i].statut);
                    printf("le deadline est : %d/%d/%d\n",todos[i].dead.jour,todos[i].dead.mois,todos[i].dead.annee);
                    printf("**************\n");
                }
            }else printf("Vous n'avez entrer encors aucune tache ! \n");
            break;

                                        //tri par deadline :


        case 2:
            if(total_taches>0){
                for(i=0;i<total_taches-1;i++){
                    for(j=i+1;j<total_taches;j++){
                        if((todos[i].dead.annee > todos[j].dead.annee) || (todos[i].dead.annee==todos[j].dead.annee && (todos[i].dead.mois>todos[j].dead.mois)) || (todos[i].dead.annee==todos[j].dead.annee && todos[i].dead.mois==todos[j].dead.mois && todos[i].dead.jour>todos[j].dead.jour)){
                            tri_alph=todos[i];
                            todos[i]=todos[j];
                            todos[j]=tri_alph;
                        }
                    }
                }
                for(i=0;i<total_taches;i++){
                    printf("l'id de la tache : %d\n", todos[i].id);
                    printf("le titre de la tache a realiser : %s\n", todos[i].titre);
                    printf("la description : %s\n", todos[i].description);
                    printf("le statut : %s\n", todos[i].statut);
                    printf("le deadline est : %d/%d/%d\n",todos[i].dead.jour,todos[i].dead.mois,todos[i].dead.annee);
                    printf("**************\n");
                }
            }else printf("Vous n'avez entrer encors aucune tache ! \n");
            break;
        case 3:
            if(total_taches>0){
                for(i=0;i<total_taches;i++){
                    if((todos[i].dead.annee - year)==0 && (todos[i].dead.mois - month)==0 && (todos[i].dead.jour - day)<4){
                        printf("\nid = %d ,Titre : %s , Description : %s , Statut : %s , deadline : %d/%d/%d\n\n\n",todos[i].id,todos[i].titre,todos[i].description,todos[i].statut,todos[i].dead.jour,todos[i].dead.mois,todos[i].dead.annee);
                        tache_3jours=1;
                    }
                }
                if(tache_3jours==0) printf("\ntoutes les taches ont deadline > 3 jours \n");
            }else printf("\nVous n'avez entrer encors aucune tache ! \n");
            break;
        case 0:
            break;
        }

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
            strcpy(todos[i].description,descrip);
            printf("\n Modifie avec succes !\n");
            modifie=1;
            break;
        }
    }
    if(modifie==0){
        printf("\nCe id n'existe pas !");
    }
}
// la fonction modifier_statut apres la saisi d'id il verifie si l'id existe sinon il affiche n'existe pas, apres le choix du statut (1,2 ou 3) sinon user doit saisir again
void modifier_statut(todo *todos){
    int id_,i,modifie,stu;
    printf("\nEntrez l'id du tache : ");
    scanf("%d",&id_);
    for(i=0;i<total_taches;i++){
        if(todos[i].id==id_){
            here:
            printf("\neChoisissez : 1- TO_DO, 2-  DOING, 3- DONE \n");
            scanf("%d",&stu);
            if(stu==1 || stu==2 || stu ==3){
            switch(stu){
            case 1:
                if(strcmp(todos[i].statut,"DONE")==0){
                    taches_complets-=1;
                    taches_non_complets+=1;
                }
                strcpy(todos[i].statut,"TO_DO");
                break;
            case 2:
                if(strcmp(todos[i].statut,"DONE")==0){
                    taches_complets-=1;
                    taches_non_complets+=1;
                }
                strcpy(todos[i].statut,"DOING");
                break;
            case 3:
                if(strcmp(todos[i].statut,"DOING")==0 || strcmp(todos[i].statut,"TO_DO")==0){
                    taches_complets+=1;
                    taches_non_complets-=1;
                }
                strcpy(todos[i].statut,"DONE");
                break;
            }
            printf("\n Modifie avec succes !\n");
            modifie=1;
            break;
            }else {
                printf("Saisissez 1 ou 2 ou 3 ");
                goto here;
                }
        }
    }
    if(modifie==0){
        printf("\nCe id n'existe pas !");
    }
}

void modifier_deadline(todo *todos){
    int id_,i;
    int modifie=0;
    deadline new_deadline;
    printf("\nEntrez l'id du tache : ");
    scanf("%d",&id_);
    for(i=0;i<total_taches;i++){
        if(todos[i].id==id_){
            printf("\nEntrez le nouveau deadline sous la forme jj/mm/aaaa : ");
            scanf("%d/%d/%d",&new_deadline.jour,&new_deadline.mois,&new_deadline.annee);
            todos[i].dead.jour=new_deadline.jour;
            todos[i].dead.mois=new_deadline.mois;
            todos[i].dead.annee=new_deadline.annee;
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
            case 3:
            modifier_deadline(todos);
            case 0:
            break;
        }
}

                                                        //Suppression :
void Suppression(todo *todos){
    int id_,trouve,i,j;
    printf("\nEntrez l'id du tache a supprimer : ");
    scanf("%d",&id_);
    for(i=0;i<total_taches;i++){
        if(todos[i].id==id_){
            for(j=i;j<total_taches;j++)
            {
                todos[j]=todos[j+1];

            }
            t++;
            printf("\nSupprime avec succes !\n");
            trouve=1;
            break;
        }
    }
    total_taches--;
    if(trouve==0)
        printf("\nl'id que vous avez entre n'existe pas !\n");
}

                                                        //recherche par titre:
void Recherche_id(todo *todos){
    int id_,trouve=0,i;
    printf("\nEntrez l'id du tache a rechercher : ");
    scanf("%d",&id_);
    for(i=0;i<total_taches;i++){
        if(todos[i].id==id_){
                printf("\nLes infos sur la tache : id = %d ,Titre : %s , Description : %s , Statut : %s \n\n\n",todos[i].id,todos[i].titre,todos[i].description,todos[i].statut);
            trouve=1;
            break;
        }
    }
    if(trouve==0)
        printf("\nla tache n'existe pas !\n");
}

                                                        //recherche par titre:

void Recherche_titre(todo *todos){
    int trouve=0,i;
    char titre[20];
    printf("\nEntrez le titre du tache a rechercher : ");
    scanf("%s",titre);
    for(i=0;i<total_taches;i++){
        if(strcmp(todos[i].titre,titre)==0){
            printf("\nLes infos sur la tache : id = %d ,Titre : %s , Description : %s , Statut : %s \n\n\n",todos[i].id,todos[i].titre,todos[i].description,todos[i].statut);
            trouve=1;
            break;
        }
    }
    if(trouve==0)
        printf("\nla tache n'existe pas !\n");
}

                                                        //recherche :

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

                                                            //statistiques :

void Statistiques(todo *todos){
        int choix;
        printf("1 : Afficher le nombre total des taches\n");
        printf("2 : Afficher le nombre de taches completes et incompletes\n");
        printf("3 : Afficher le nombre de jours restants jusqu'au delai de chaque tache\n");
        printf("0 : quitter\n");
        scanf("%d",&choix);
        printf("\n***********************************************\n\n");
        switch(choix){
            case 1:
            printf("\nle nombre total des taches est : %d\n",total_taches);
            break;
            case 2:
            printf("\nle nombre des taches non complets est : %d\n",taches_non_complets);
            printf("\nle nombre des taches complets est : %d\n",taches_complets);
            break;
            case 3:
                nbr_jours_restant(todos);
            break;
            case 0:
            system("pause");
        }
}

void nbr_jours_restant(todo *todos){
    int nbr_jrs_mois[]={0,31,28,31,30,31,30,31,30,31,30,31,30},nbr_jours;
    for(int i=0;i<total_taches;i++){
        int mois_=todos[i].dead.mois;
        int jours_=todos[i].dead.jour;
        int nbr_annees=todos[i].dead.annee-year;
        nbr_jours = 0;
        //si l'annee entree est superieure ou egale a cette annee :
        if(nbr_annees>0){
                //nbr du jours jusqu'a fin de ce mois
                nbr_jours +=nbr_jrs_mois[month]-day;
                //nbr du jours + jours jusqu'a fin de cette annee
                for(int j=month+1;j<=12;j++){
                    nbr_jours+=nbr_jrs_mois[j];
                }
                //nbr du jours + jours des annee plus
                nbr_jours+=365*(nbr_annees-1);
                //nbr du jours + jours jusqu'a mois avans mois entré
                for(int k=0;k<mois_;k++){
                    nbr_jours+=nbr_jrs_mois[k];
                }
                //nbr du jours + nbr du jours entrés
                nbr_jours+=jours_;
        }else if(nbr_annees==0 && month<mois_){
            //nbr du jours jusqu'a fin de ce mois
                nbr_jours +=nbr_jrs_mois[month]-day;
            //nbr du jours + jours jusqu'a mois avans mois entré
                for(int k=month+1;k<mois_;k++){
                    nbr_jours+=nbr_jrs_mois[k];
                }
            //nbr du jours + nbr du jours entrés
            nbr_jours+=jours_;
        }else if(nbr_annees==0 && month==mois_){
            nbr_jours+=jours_-day;
        }

        printf("\nid : %d \ntitre : %s \ndescription : %s \nnombre de jours restants jusqu'au delai : %d\n",todos[i].id,todos[i].titre,todos[i].description,nbr_jours);

    }
}

// fonction main ********************************************************************************************************************

int main()
{
    int choix;

    todo todos[100];
           //stocker la date actuelle :
    time_t now;
    time(&now);
    struct tm *local = localtime(&now);
    day = local->tm_mday;            // récupère le jour du mois (1 à 31)
    month = local->tm_mon + 1;      // obtient le mois de l'année (0 à 11)
    year = local->tm_year + 1900;
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
        printf("7 : Statistiques\n");
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
            case 7:
            Statistiques(todos);
            break;
            case 0:
            printf("Merci !");
            system("pause");
        }
    }while(choix!=0);

    return 0;
}
