#include <stdio.h>
#include <ctype.h>	// bibliotheque pour les fonctions isalpha, isdigit, etc..
#include <string.h>
#include <stdlib.h>

int scan() {
   int nombre;
   while(scanf("%d", &nombre) != 1) {
   		printf("\033[38;2;255;40;0m");
    	printf("Erreur : veuillez entrer un nombre entier valide.\n");
    	while(getchar() != '\n'); 
    	printf("Entrez un nombre entier : ");
   }
   return (nombre);
}

//*************************Procedure pour calculer le nombre total de lettres, caracteres speciaux et nombres dans une chaine de caracteres****************************

void compter_caracteres_chaine(char chaine[], int *lettres, int *caracteres_speciaux, int *nombres) {
    int i;
    *lettres = 0;
    *caracteres_speciaux = 0;
    *nombres = 0;
    
        //Parcours la chaine de caracteres pour compter les lettres, caracteres speciaux et nombres
    for (i = 0; chaine[i] != '\0'; i++) {
        if (isalpha(chaine[i])) {
            (*lettres)++;
        } else if (isdigit(chaine[i])) {
            (*nombres)++;
        } else {
            (*caracteres_speciaux)++; 
        }
    }
}


//*******************************Procedure pour compter le nombre de mots dans la phrase***********************************************************************************

void compter_mots(char chaine[], int *mots) {
    int i;
    *mots = 0;

    // Parcours la chaine de caracteres pour compter les mots
    for (i = 0; chaine[i] != '\0'; i++) {
        if (chaine[i] == ' ') {
            (*mots)++;
        }
    }
 
    // Compte le dernier mot s'il n'y a pas d'espace apres
    if (i > 0 && chaine[i-1] != ' ') {
        (*mots)++;
    }
}
 
void compter_voyelles_consonnes(char chaine[], int *voyelles, int *consonnes) {
    int i;
    *voyelles = 0;
    *consonnes = 0;

    // Parcours la chaine de caracteres pour compter les voyelles et les consonnes
    for (i = 0; chaine[i] != '\0'; i++) {
        if (isalpha(chaine[i])) {
            if (chaine[i] == 'a' || chaine[i] == 'e' || chaine[i] == 'i' || chaine[i] == 'o' || chaine[i] == 'u' || chaine[i] == 'y' ||
                chaine[i] == 'A' || chaine[i] == 'E' || chaine[i] == 'I' || chaine[i] == 'O' || chaine[i] == 'U' || chaine[i] == 'Y') {
                (*voyelles)++;
            }
            else {
                (*consonnes)++;
            }
        }
    }
}

//************************************Procedure pour compter le nombre d'occurrences d'une lettre entree par l'utilisateur***********************************************

void compter_occurrence_lettre(char chaine[], char lettre, int *occurrences) {
    int i;
    *occurrences = 0;
    
        // Parcours la chaine de caracteres pour compter les occurrences de la lettre
    for (i = 0; chaine[i] != '\0'; i++) {
        if (tolower(chaine[i]) == tolower(lettre)) {
            (*occurrences)++;
        }
    }
}


//***************************************Procedure pour compter le nombre d'occurrences de chaque lettre dans la phrase************************************************
void compter_occurrence_lettres(char chaine[], int *occurrences) {
    int i;
    for (i = 0; i < 26; i++) {
        occurrences[i] = 0;
    }
    for (i = 0; chaine[i] != '\0'; i++) {
        if (isalpha(chaine[i])) {
            occurrences[tolower(chaine[i]) - 'a']++;  //tolower(chaine[i]) - 'a': This subtracts the ASCII value of the character 'a' from the ASCII value of the lowercase character, to get an integer between 0 and 25 that represents the index of the occurrences array that corresponds to the given character.
        }
    }
}
void entrerPhrase(char chaine[]) {  //procedure pour entrer la phrase. (Frensh version) 
    int choix;
    do {
        printf("Entrez une phrase : ");
        fgets(chaine, 100, stdin);
        chaine[strlen(chaine)-1] = '\0';  //Since the newline character is usually added by the user pressing the Enter key, this line of code removes it from the string so that it is not counted as part of the user's input.

        printf("La phrase que vous avez entre est : %s\n", chaine);

        do {
            printf("Voulez-vous changer la phrase ? (0 pour oui, 1 pour non) : ");
            scanf("%d", &choix);
            fflush(stdin);
        } while (choix != 0 && choix != 1);

        while (choix == 0) {
            printf("Entrez une nouvelle phrase : ");
            fgets(chaine, 100, stdin);
            chaine[strlen(chaine)-1] = '\0';
            printf("La nouvelle phrase est : %s\n", chaine);

            do {
                printf("Voulez-vous garder cette phrase ? (0 pour non, 1 pour oui) : ");
                scanf("%d", &choix);
                fflush(stdin);
            } while (choix != 0 && choix != 1);
        }

    } while (choix != 1);
	system("cls");
    
}
void enterPhrase(char chaine[]) {  //procedure pour entrer la phrase. (English version) 
    int choix;
    do {
        printf("Enter a sentence: ");
    	fgets(chaine, 100, stdin);
    	chaine[strlen(chaine)-1] = '\0';

    printf("The sentence you entered is: %s\n", chaine);

    do {
        printf("Do you want to change the sentence? (0 for yes, 1 for no): ");
        scanf("%d", &choix);
        fflush(stdin);
    } while (choix != 0 && choix != 1);

    while (choix == 0) {
        printf("Enter a new sentence: ");
        fgets(chaine, 100, stdin);
        chaine[strlen(chaine)-1] = '\0';
        printf("The new sentence is: %s\n", chaine);

        do {
            printf("Do you want to keep this sentence? (0 for no, 1 for yes): ");
            scanf("%d", &choix);
            fflush(stdin);
        } while (choix != 0 && choix != 1);
    }

} while (choix != 1);
	system("cls");
	
}
void Fprint_menu(char chaine[]) {  //this procedure prints the Frensh version of the Menu.
	    printf("\033[38;2;90;200;150m");
		printf("La phrase finale est : %s\n\n", chaine);
		printf("\033[0;33m");
	    printf("                                                                                                   +----------------------------+\n");
	    printf("                                                                                                   |            MENU            | \n");
	    printf("                                                                                                   +----------------------------+\n\n");
	    printf("\033[0m");
	    printf("\033[1;33m"); //sets the text color to yellow and makes it bold.
	    printf("---> 1. Calculer le nombre total de lettres, caracteres speciaux et nombres dans la phrase.\n");
	    printf("---> 2. Calculer le nombre de mots dans la phrase.\n");
	    printf("---> 3. calculer le nombre de voyelles et de consonnes dans la phrase.\n");
	    printf("---> 4. Compter le nombre d'occurrences d'une lettre entree par l'utilisateur.\n");
	    printf("---> 5. Compter le nombre d'occurrences de chaque lettre dans la phrase.\n");
	    printf("---> 6. Pour quitter\n");
}
void Eprint_menu(char chaine[]) {  //this procedure prints the English version of the Menu.
		printf("\033[38;2;90;200;150m");
		printf("The final sentence is : %s\n\n", chaine);
		printf("\033[0;33m");
    	printf("                                                                                                   +----------------------------+\n");
	    printf("                                                                                                   |            MENU            | \n");
	    printf("                                                                                                   +----------------------------+\n\n");
	    printf("\033[0m");
	    printf("\033[1;33m");         // sets the text color to yellow and makes it bold.
	    printf("---> 1. Calculate the total number of letters, special characters, and numbers in the sentence.\n");
	    printf("---> 2. Calculate the number of words in the sentence.\n");
	    printf("---> 3. Calculate the number of vowels and consonants in the sentence.\n");
	    printf("---> 4. Count the number of occurrences of a letter entered by the user.\n");
	    printf("---> 5. Count the number of occurrences of each letter in the sentence.\n");
	    printf("---> 6. To quit\n");
}
void Welcom()
{
	printf("                                                                               ##      ## ######## ##        ######   #######  ##     ## ######## \n");
    printf("                                                                               ##  ##  ## ##       ##       ##    ## ##     ## ###   ### ##       \n");
    printf("                                                                               ##  ##  ## ##       ##       ##       ##     ## #### #### ##       \n");
    printf("                                                                               ##  ##  ## ######   ##       ##       ##     ## ## ### ## ######   \n");
    printf("                                                                               ##  ##  ## ##       ##       ##       ##     ## ##     ## ##       \n");
    printf("                                                                               ##  ##  ## ##       ##       ##    ## ##     ## ##     ## ##       \n");
    printf("                                                                                ###  ###  ######## ########  ######   #######  ##     ## ######## \n");
    printf("\n\n");
}

void Prog_term(){
	printf("                               ########  ########   #######   ######   ########     ###    ##     ## ##     ## ########    ######## ######## ########  ##     ## #### ##    ## ########     \n");
	printf("                               ##     ## ##     ## ##     ## ##    ##  ##     ##   ## ##   ###   ### ###   ### ##             ##    ##       ##     ## ###   ###  ##  ###   ## ##           \n");
	printf("                               ##     ## ##     ## ##     ## ##        ##     ##  ##   ##  #### #### #### #### ##             ##    ##       ##     ## #### ####  ##  ####  ## ##           \n");
	printf("                               ########  ########  ##     ## ##   #### ########  ##     ## ## ### ## ## ### ## ######         ##    ######   ########  ## ### ##  ##  ## ## ## ######       \n");
	printf("                               ##        ##   ##   ##     ## ##    ##  ##   ##   ######### ##     ## ##     ## ##             ##    ##       ##   ##   ##     ##  ##  ##  #### ##           \n");
	printf("                               ##        ##    ##  ##     ## ##    ##  ##    ##  ##     ## ##     ## ##     ## ##             ##    ##       ##    ##  ##     ##  ##  ##   ### ##           \n");
	printf("                               ##        ##     ##  #######   ######   ##     ## ##     ## ##     ## ##     ## ########       ##    ######## ##     ## ##     ## #### ##    ## ########     \n");
	printf("\n\n");	
}
void End_prog(){
	printf("                                                ######## ##    ## ########      #######  ########    ########  ########   #######   ######   ########     ###    ##     ## \n");
	printf("                                                ##       ###   ## ##     ##    ##     ## ##          ##     ## ##     ## ##     ## ##    ##  ##     ##   ## ##   ###   ### \n");
	printf("                                                ##       ####  ## ##     ##    ##     ## ##          ##     ## ##     ## ##     ## ##        ##     ##  ##   ##  #### #### \n");
	printf("                                                ######   ## ## ## ##     ##    ##     ## ######      ########  ########  ##     ## ##   #### ########  ##     ## ## ### ## \n");
	printf("                                                ##       ##  #### ##     ##    ##     ## ##          ##        ##   ##   ##     ## ##    ##  ##   ##   ######### ##     ## \n");
	printf("                                                ##       ##   ### ##     ##    ##     ## ##          ##        ##    ##  ##     ## ##    ##  ##    ##  ##     ## ##     ## \n");
	printf("                                                ######## ##    ## ########      #######  ##          ##        ##     ##  #######   ######   ##     ## ##     ## ##     ## \n");
	printf("\n\n");	
}

void main() {
    char chaine[100];
    int option = 0;
    int i, choix, lettres, caracteres_speciaux, nombres, mots, voyelles, consonnes, occurrences;
    int occurrences_lettres[26];
    char lang_choice;
    int valid_choice = 0;
    system("color 0C");
    
    printf("\033[38;2;0;255;150m");
    Welcom();
    printf("\033[1;34m");

    while (!valid_choice) //while (!valid_choice) means "while the variable valid_choice is false" (valid_choice == 0) 
	{
    	
    printf("Choose a language (F for French OR E for English) :\n");
    printf("\n-->");
	scanf(" %c", &lang_choice);
	fflush(stdin);
	system("cls");
	
if (toupper(lang_choice) == 'F') {	
	
    entrerPhrase(chaine);
	
    while (option != 6) {
    	
    	printf("\033[38;2;255;165;0m");  
    	
        Fprint_menu(chaine);
        
        printf("Entrez le numero de l'option choisie : ");
        option=scan();
        printf("\n");
        switch (option) {
            case 1:
            	printf("\033[1;33m");
                compter_caracteres_chaine(chaine, &lettres, &caracteres_speciaux, &nombres);
                printf("Nombre total de lettres : %d\n", lettres);
                printf("Nombre de caracteres speciaux : %d\n", caracteres_speciaux);
                printf("Nombre de nombres : %d\n", nombres);
                printf("\n");
                break;

            case 2:
            	printf("\033[1;33m");
                compter_mots(chaine, &mots);
                printf("Nombre de mots : %d\n", mots);
                printf("\n");
                break;

            case 3:
            	printf("\033[1;33m");
                compter_voyelles_consonnes(chaine, &voyelles, &consonnes);
                printf("Nombre de voyelles : %d\n", voyelles);
                printf("Nombre de consonnes : %d\n", consonnes);
                printf("\n");
                break;

            case 4:
            	printf("\033[1;33m");
                printf("Entrez une lettre : ");
                char lettre;
                scanf(" %c", &lettre);
                compter_occurrence_lettre(chaine, lettre, &occurrences);
                printf("Nombre d'occurrences de la lettre %c : %d\n", lettre, occurrences);
                printf("\n");
                break;

            case 5:
            	printf("\033[1;33m");
                compter_occurrence_lettres(chaine, occurrences_lettres);
                printf("Occurrences de chaque lettre :\n");
                for (i = 0; i < 26; i++) {
                    printf("%c : %d\n", 'a' + i, occurrences_lettres[i]);
                }
                break;

            case 6:
            	system("cls");
            	printf("\033[38;2;0;255;150m");
                Prog_term();
                valid_choice = 1;  //Si la valeur de la variable valid_choice = 1, alors la condition (!valid_choice) sera fausse, alors le programme sortira de la boucle.
                break;

            default:
            	printf("\033[38;2;255;40;0m");
                printf("Option invalide. Veuillez entrer un numero entre 1 et 6.\n");
                printf("\n");
        }
    } }
    
    else if (toupper(lang_choice) == 'E') {
    	enterPhrase(chaine);
	
	while (option != 6) {
	    printf("\033[38;2;255;165;0m");  
	    
	    Eprint_menu(chaine);
	    
	    option=scan();
	    printf("\n");
	
	    switch (option) {
	        case 1:
	        	printf("\033[1;33m");
	            compter_caracteres_chaine(chaine, &lettres, &caracteres_speciaux, &nombres);
	            printf("Total number of letters: %d\n", lettres);
	            printf("Number of special characters: %d\n", caracteres_speciaux);
	            printf("Number of numbers: %d\n", nombres);
	            printf("\n");
	            break;
	
	        case 2:
	        	printf("\033[1;33m");
	            compter_mots(chaine, &mots);	
	            printf("Number of words: %d\n", mots);
	            printf("\n");
	            break;
	
	        case 3:
	        	printf("\033[1;33m");
	            compter_voyelles_consonnes(chaine, &voyelles, &consonnes);
	            printf("Number of vowels: %d\n", voyelles);
	            printf("Number of consonants: %d\n", consonnes);
	            printf("\n");
	            break;
	
	        case 4:
	        	printf("\033[1;33m");
	            printf("Enter a letter: ");
	            char lettre;
	            scanf(" %c", &lettre);
	            compter_occurrence_lettre(chaine, lettre, &occurrences);
	            printf("Number of occurrences of the letter %c: %d\n", lettre, occurrences);
	            printf("\n");
	            break;
	
	        case 5:
	        	printf("\033[1;33m");
	    		compter_occurrence_lettres(chaine, occurrences_lettres);
	   			printf("Occurrences of each letter:\n");
	    		for (i = 0; i < 26; i++) {
	        		printf("%c : %d\n", 'a' + i, occurrences_lettres[i]);
	    		}
	    		printf("\n");
	    		break;
	
				case 6:
				system("cls");
				printf("\033[38;2;0;255;150m");
	    		End_prog();
	    		valid_choice = 1;  //Si la valeur de la variable valid_choice = 1, alors la condition (!valid_choice) sera fausse, alors le programme sortira de la boucle.
	    		break;
	
				default:
				printf("\033[38;2;255;40;0m");
	    		printf("Invalid option. Please enter a number between 1 and 6.\n");
	    		printf("\n");
	    		break;
	}
	
	} while (option != 6); }
			else {
				printf("\033[38;2;255;40;0m");
	    		printf("Invalid choice. Please choose between F and E.\n");
	} }
		
	
	}

    



