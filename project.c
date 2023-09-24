i#include <stdio.h>
#include <string.h>
#include <time.h>

int tachcount = 0; // kay7seb lina les tach li tzado
int i, j;
    time_t current_time;
    struct tm *time_info;
    char time_string[100];

typedef struct
{
    int jj;
    int mm;
    int aa;
    
} date;

typedef struct
{
    date df;
    int id;
    char Titre[33];
    char Description[33];
    char Statut[33];
    char creationTime[MAX_TIME_STRING];
} tach;

tach list[100]; // tableaux de taches

void ajou() // fonction pour ajouter une tach
{
    if (tachcount < 100)
    {
        printf("Titre : ");
        fscanf(stdin, " ");

        gets(list[tachcount].Titre);

        printf("Description : ");

        gets(list[tachcount].Description);

        printf("%s", "Deadline doit etre DD/MM/YYYY : ");
        scanf("%d/%d/%d", &list[tachcount].df.jj, &list[tachcount].df.mm, &list[tachcount].df.aa);
	    
	    while (1) {
        printf("votre Statut est : (a realiser) ou (en cours de realisation) ou bien (finalisee) ? ");
        scanf("%d", 0);
        scanf("%[^\n]", &list[tachcount].Statut);

        // Check if statut valide 
        if (strcmp(&list[tachcount].Statut, "a realiser") == 0 ||
            strcmp(&list[tachcount].Statut, "en cours de realisation") == 0 ||
            strcmp(&list[tachcount].Statut, "finalisee") == 0) {
            scanf("%[^\n]", &list[tachcount].Statut);
            break; // statut valide, exit the loop
        } else {
            printf("\nStatut n'est pas valide. svp entrez 'a realiser', 'en cours de realisation', ou 'finalisee'.\n");
        }
    }


        list[tachcount].id = tachcount + 1;
        tachcount++;
        printf("Tache bien ajoutee.\n");
    }
    else
    {
        printf("La liste des taches est pleine.\n");
    }
}

void ajouplus() // fonction pour ajouter plusieur tach
{
    int c;
    printf("Combien Tach tu veu ajouter ? :  ");
    scanf("%d", &c);
    for (i = 1; i <= c; i++)
    {
        ajou();
    }
}

void tptitre() // trie par titre
{
    for (i = 0; i < tachcount; i++)
    {
        for (j = i + 1; j < tachcount; j++)
        {
            if (strcmp(list[i].Titre, list[j].Titre) > 0)
            {
                tach swap = list[i];
                list[i] = list[j];
                list[j] = swap;
            }
        }
			printf("Tache id : %d \t|\t Titre : %s \t|\t Description : %s \t|\t Deadline  %d/%d/%d \t|\t  Statut : %s\n",
            list[i].id, list[i].Titre, list[i].Description, list[i].df.jj, list[i].df.mm, list[i].df.aa, list[i].Statut); 
    }
}
void tp3jour()
{
    time(&current_time);
    time_info = localtime(&current_time);
    int currentDay = time_info->tm_mday;
    int currentMonth = time_info->tm_mon + 1;
    int currentYear = time_info->tm_year + 1900;
    for (i = 0; i < tachcount; i++)
    {
        int taskDays = list[i].df.aa * 365 + list[i].df.mm * 30 + list[i].df.jj;
        int currentDays = currentYear * 365 + currentMonth * 30 + currentDay;

        if ((taskDays - currentDays) <= 3 && (taskDays - currentDays) > 0)
        {
            printf("%d \t %s \t %s \t %d-%d-%d \t %s \t \n", list[i].id, list[i].Titre, list[i].Description, list[i].df.jj, list[i].df.mm, list[i].df.aa, list[i].Statut);
        }
    }
}
void nombre_de_jours_restants() //Afficher le nombre de jours restants jusqu'au délai de chaque tâche.
{
	time(&current_time);
	time_info = localtime(&current_time);
	int currentDay = time_info->tm_mday;
	int currentMonth = time_info->tm_mon + 1;
	int currentYear = time_info->tm_year + 1900;
	for(i = 0; i < tachcount; i++)
	{
		int taskdate = list[i].df.aa * 365 + list[i].df.mm * 30 + list[i].df.jj;
		int currentdate = currentYear * 365 + currentMonth * 30 + currentDay;
		if(taskdate - currentdate > 0)
		{
            int jeurs_reste = taskdate - currentdate;
            printf("Tache id %d - Titre : %s - Description : %s -Deadline  %d/%d/%d - Statut : %s - Jours restants jusqu'au delai : %d jours\n",
            list[i].id, list[i].Titre, list[i].Description, list[i].df.jj, list[i].df.mm, list[i].df.aa, list[i].Statut ,jeurs_reste);
    	}
    }
}

void tpdate() // trie par date
{
    for (i = 0; i < tachcount; i++)
    {
        for (j = i + 1; j < tachcount; j++)
        {
            if (list[i].df.aa > list[j].df.aa || list[i].df.aa == list[j].df.aa && list[i].df.mm > list[j].df.mm || list[i].df.aa == list[j].df.aa && list[i].df.mm == list[j].df.mm && list[i].df.jj > list[j].df.jj)
            {
                tach sw = list[i];
                list[i] = list[j];
                list[j] = sw;
            }
        }
        printf("%d \t %s \t %s \t %d-%d-%d \t %s \t \n", list[i].id, list[i].Titre, list[i].Description, list[i].df.jj, list[i].df.mm, list[i].df.aa, list[i].Statut);
    }
}

void modifierdescription() // modifier le desciption
{
    int id;
    printf("Donner l'id de la tâche que vous voulez modifier : ");
    scanf("%d", &id);

    if (id <= tachcount)
    {
        printf("Nouvelle description pour la tâche %d : ", id);
        scanf("%s", list[id - 1].Description);
        printf("Description modifiée avec succès pour la tâche %d.\n", id);
    }
    else
    {
        printf("Identifiant de tâche invalide.\n");
    }
}
void modifierStatu() // modifier statu
{
    int id;
    printf("Donner l'id de la tâche que vous voulez modifier : ");
    scanf("%d", &id);

    if (id <= tachcount)
    {
        printf("Nouvelle Statu pour la tâche %d : ", id);
        scanf("%s", list[id - 1].Statut);
        printf("statu modifiée avec succès pour la tâche %d.\n", id);
    }
    else
    {
        printf("Identifiant de tâche invalide.\n");
    }
}

void modifierdeadline() // modifier le date
{
    int id;
    printf("Donner l'id de la tâche que vous voulez modifier : ");
    scanf("%d", &id);

    if (id <= tachcount)
    {
        printf("Nouvelle deadline pour la tâche %d : ", id);
        scanf("%d/%d/%d", &list[id - 1].df.jj, &list[id - 1].df.mm, &list[id - 1].df.aa);
        printf("deadline modifiée avec succès pour la tâche %d.\n", id);
    }
    else
    {
        printf("Identifiant de tâche invalide.\n");
    }
}

// Fonction pour supprimer une tâche par identifiant
void supprimertache()
{
    int id;
    printf("Donner l'id de la tâche que vous voulez Suppremer : ");
    scanf("%d", &id);
    // Vérifier que l'identifiant est valide
    if (id > tachcount)
    {
        printf("L'identifiant %d n'existe pas.\n", id);
        return;
    }

    // Déplacer les tâches suivantes vers l'avant
    for (i = id; i < tachcount - 1; i++)
    {
        list[i] = list[i + 1];
    }

    // Décrémenter le nombre de tâches
    tachcount--;

    printf("\n\nTâche supprimée avec succès.\n");
}

void rechercherPid() // recherch par ide
{
    int id;
    printf("Entrez l'ID de la tâche à rechercher : ");
    scanf("%d", &id);

    for (i = 0; i < tachcount; i++)
    {
        if (list[i].id == id)
        {
            printf("Tache trouvae :\n");

            printf("%d \t %s \t %s \t %d-%d-%d \t %s \t \n", list[i].id, list[i].Titre, list[i].Description, list[i].df.jj, list[i].df.mm, list[i].df.aa, list[i].Statut);
            return;
        }
    }
    printf("\n\nAucune tache trouve avec l'ID %d.\n", id);
}
void rechercherPtitre()
{
    char titre[33];
    printf("Entrez le tetre de la tache a rechercher : ");
    scanf("%s", &titre);
    for (i = 0; i < tachcount; i++)
    {
        if (strcmp(list[i].Titre, titre) == 0)
        {
            printf("Tache trouvae :\n");
            printf("%d \t %s \t %s \t %d-%d-%d \t %s \t \n", list[i].id, list[i].Titre, list[i].Description, list[i].df.jj, list[i].df.mm, list[i].df.aa, list[i].Statut);
        }
    }
    printf("\n\nAucune tache trouve avec ce Titre %s\n", titre);
}

void affiche() // fonction afficherz
{
    for (i = 0; i < tachcount; i++)
    {
    	
        	printf("Tache id : %d \t|\t Titre : %s \t|\t Description : %s \t|\t Deadline  %d/%d/%d \t|\t  Statut : %s\n",
            list[i].id, list[i].Titre, list[i].Description, list[i].df.jj, list[i].df.mm, list[i].df.aa, list[i].Statut);
    }
}

void nbrtach() // count nomber des taches
{
    for (i = 0; i <= tachcount; i++)
    {
        printf("Nomber Total des Tach est %d\n", tachcount);
        return;
    }
}

void taches_completes_incompletes()
{
    int incp = 0, comp = 0;
    for (i = 0; i <= tachcount; i++)
    {

        if (strcmp(list[i].Statut, "finalisee") == 0)
        {
            comp++;
        }
        else if(strcmp(list[i].Statut, "a realiser" ) == 0 || strcmp(list[i].Statut, "en cours de realisation") == 0)
        {
            incp++;
        }
        
    }
       printf("Nomber Total des Tach finalise %d\n", comp);
        printf("Nomber Total des Tach non complite est %d\n", incp);
        
}

int main()
{
    int n;
    
    while (1)
    {
    	printf("\n\n\n\t\t\t\t===Bienvenue dans l'application de gestion de taches!===\n\n\n");
        printf("1. Ajouter une tache\n");
        printf("2. Ajouter Plusieurs tache\n");
        printf("3. Afficher toutes les taches\n");
        printf("4. Modifier\n");
        printf("5. Supprimer une Tache \n");
        printf("6. rechercher une Tache Par ID \n");
        printf("7. rechercher une Tache Par Titre \n");
        printf("8. Afficher les statistiques \n");
        printf("9. Quitter  \n");
         //printf("10. Affichier \n");
        printf("\n Choisissez une option : ");
        scanf("%d", &n);

        switch (n)
        {
        case 1:
            ajou();

            break;

        case 2:
            ajouplus();
            break;
        case 3:
        {
            int a;
            printf("si vous voulez Trier les taches par ordre alphabetique Tape 1: \n ");
            printf("si vous voulez Trier les taches par deadline Tape 2: \n");
            printf(" si vous voulez Afficher les taches dont le deadline est dans 3 jours ou moins Tape 3: \n ");
            printf("\n\n\n**Choisissez une option pour la affichiage : ** ");
            printf(" \n\n\n ");
            scanf("%d", &a);
            switch (a)
            {
            case 1:
                printf("\n Toutes les tâches ---\n");
                tptitre();
                break;
            case 2:
                printf("\n Toutes les tâches ---\n");
                tpdate();
                break;
            case 3:tp3jour();
            break;
            }
            break;
        }

        case 4:
        {
            int m;
            printf("si vous voulez modifier la description tapy 1: \n ");
            printf("si vous voulez modifier la Statue tapy 2: \n ");
            printf("si vous voulez modifier la deadline tapy 3: \n ");
            printf(" \n\n\n**Choisissez une option pour la modification : **  ");
            printf(" \n\n\n  ");
            scanf("%d", &m);
            switch (m)
            {
            case 1:
                modifierdescription();
                break;
            case 2:
                modifierStatu();
                break;
            case 3:
                modifierdeadline();
                break;
            }
            break;
        }
         case 10:
            affiche();
            break;
        case 5:
            supprimertache();
            break;
        case 6:
            rechercherPid();
            break;
        case 7:
            rechercherPtitre();
            break;
        case 8:
        	{
	        	int n;
	            printf("si vous voulez le nombre total des tâches 1: \n ");
	            printf("si vous voulezle nombre de taches completes et incomplètes 2: \n ");
	            printf("si vous voulez le nombre de jours restants jusqu'au delai de chaque tache 3: \n ");
	            printf(" \n\n\n**Choisissez une option pour la modification : ** ");
	            printf(" \n\n\n ");
	            scanf("%d", &n);
	            switch (n)
	            {
	            case 1:
	                nbrtach();
	                break;
	            case 2:
	                taches_completes_incompletes();
	                break;
	            case 3:nombre_de_jours_restants();
	            	break;
	            }
	            break;
	        }
        case 9:
            printf("1. Au revoir !!\n");
             exit(0);
        default:
            printf("Choix invalide. Veuillez réessayer.\n");
            break;
        }
    }

    return 0;
}

