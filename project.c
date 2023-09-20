#include <stdio.h>
#include <string.h>

int tachcount = 0; //kay7seb lina les tach li tzado

typedef struct
{
    int id;
    char Titre[33];
    char Description[33];
    char Deadline[11];
    char Statut[33];
} tach;

tach list[100]; //hna fin ghan7et dok les tach li kaytzado

void affi()
{
          for (int i = 0; i < tachcount; i++)
            {
                for(int j = 0; j <tachcount ;j++)
                {
                    if(strcmp(list[i].Titre, list[j].Titre)>0)
                    {
                        tach swap = list[i] ;
                        list[i] = list[j];
                        list[j] = swap;
                    }
                }
                //printf("%d\t%s\t%s\t%s\t%s\n", list[i].id, list[i].Titre, list[i].Description, list[i].Deadline, list[i].Statut);
            }
}


int main()
{
    int n;

    while (1)
    {
        printf("1. Ajouter une tâche\n");
        printf("2. Afficher toutes les tâches\n");
        printf("3. Quitter\n");
        printf("Choisissez une option : ");
        scanf("%d", &n);

        switch (n)
        {
        case 1:
OB        {
OB            if (tachcount < 100)
            {
OB                printf("Titre : ");
                scanf("%s", list[tachcount].Titre);
OB
OB                printf("Description : ");
                scanf("%s", list[tachcount].Description);
OB
OB                printf("Deadline : ");                scanf("%s", list[tachcount].Deadline);
                printf("votre Statut est : (réaliser) ou (en cours de réalisation) ou bien (finalisée)   ");
scanf("%s", list[tachcount].Statut);
                list[tachcount].id = tachcount + 1;
                tachcount++;
                printf("Tâche bien ajoutée.\n");
	    }
            else
            {
                printf("La liste des tâches est pleine.\n");
            }
            break;        }

        case 2:
        {
            printf("\n Toutes les tâches ---\n");
            affi();
      
            break;
        }

        case 3:
            printf("Merci.\n");
            return 0;

        default:
            printf("Choix invalide. Veuillez réessayer.\n");
            break;
        }
    }

    return 0;
}

