/**
@Author Leandro Martins de Freitas
**/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//vetor que armazena os caractéres alfabéticos
char alpha[36][1] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    
//vetor que armazena(como strings) os caractéres em Morse
char morse[36][6] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."};

int i, j, k, c, tam = 0, size = 5, cont = 0;
 
char* realoca(char str[], char *aux) {
    while(size <= strlen(aux)) {
        aux = realloc(aux, ((size * 2) + 1) * sizeof(char));
        printf("Size: %d\n", size);
        size *= 2;
    }
    
    return aux; 
}

void alphaToMorse(char str[], char *aux) {
    while(str[tam]) {
        tam++;
    }
    for(i = 0; i < tam; i++) {
        c = str[i];
        
        if(c == ' ') {
            strcat(aux, "x");
        }
        
        for(j = 0; j < 36; j++) {
            if(alpha[j][0] == toupper(c)) {
                strcat(aux, morse[j]);
                strcat(aux, " ");
                break;
            }
        }
    
        if(strlen(aux) > size) {  
            if(realoca(str, aux) == NULL) {
                printf("Memória insuficiente!");
                exit(1);
            }
        }
    }
    
    tam = 0;
}

void morseToAlpha(char str[], char *aux) {
    for(i = 0; i < strlen(str); i++) {
        if(str[i] != ' ') {
            aux[cont] = str[i];
            cont++;
        } 
        
        if(str[i] == ' ' || i == strlen(str) - 1){
            for(j = 0; j < 36; j++) {
                if(strcmp(morse[j], aux) == 0) {
                    printf("%c", alpha[j][0]);
                    memset(aux, '\0', size);
                    break;
                }
            }
            cont = 0;
        }
    }
    
    cont = 0;
}

int verifica(char str[]) {
    int res = 1;
    for(i = 0; i < strlen(str); i++) {
        if(str[i] != '.' && str[i] != '-' && str[i] != ' ') {
            res = 0;
        }
    }
    return res;
}

int main() {
    int opc;
    char str[100];
    char *aux = (char *) malloc(5 * sizeof(char));
    
//   scanf("%[^\n]s", str);
//  morseToAlpha(pStr);
    
    for(;;) {
        //header    
            printf("################################################################################\n");    
printf("#                                   Mor-C                                      #\n");       
printf("################################################################################\n");
        printf("Escolha sua opção: \n");
        printf("1 - Instruções e caractéres.\n");
        printf("2 - Tradução: Morse -> Alfabeto.\n");
        printf("3 - Tradução: Alfabeto -> Morse.\n");
        printf("4 - Test your might!\n");
        printf("5 - Sair.\n");
        
        scanf("%d", &opc);
        memset(str, '\n', 100);
        
        if(opc == 5) {
            system("clear");
            printf("Até mais! ;D\n");
            break;
        }
        system("clear");
        
        switch(opc) {
            //Instruções e caractéres
            case 1:
        
                while(strcasecmp(str, ";") != 0) {
                    printf("Em Morse usa-se os caractéres \"-\" e \".\" para escrever. Cada letra e número é um conjunto de \"-\"s e \".\"s.\n");
                    printf("Letras são separadas por espaços e palavras por quebras de linha.\nExemplo: ");
                    printf("\"Projeto de P1\"\n");
                    printf("\".--. .-. --- .--- . - ---\n-.. .\n.--. .---- \"\n");
                    printf("Alfabeto - Morse\n");
                    for(i = 0; i < 36; i++) {
                        printf("%c = %s  ||  %c = %s ||  %c = %s\n", alpha[i][0], morse[i], alpha[i + 1][0], morse[i + 1], alpha[i + 2][0], morse[i + 2]); 
                        i++;
                        i++;
                    }
                    printf("Aperte \";\" e enter para sair.\n");
                    scanf("%s", str);
                    system("clear");
                }
                system("clear");
                strcpy(str, " ");
                break;
            
        //Tradução: Morse -> Alfabeto
            case 2:
                printf("Digite as palavras em morse linha a linha. Aperte \";\" e enter para sair.\n");
            
                while(strcasecmp(str, ";") != 0) {
                    aux[0] = '\0';
                    str[0] = '\0';
                    scanf(" %[^\n]s", str);
                    
                    if(strcasecmp(str, ";") == 0) {
                        break;
                    }
                    
                    if(verifica(str)) {
                        morseToAlpha(str, aux);
                    }
                    printf("\n");   
                }
                system("clear");
                strcpy(str, " ");
                memset(aux, '\0', size);
                break;
            
        //Tradução: Alfabeto -> Morse
            case 3:
            printf("Digite a palavra a ser traduzida ou aperte \";\" e enter para sair.\n");
                while(strcasecmp(str, ";") != 0) {
                    
                    aux[0] = '\0';
                    str[0] = '\0';
                    scanf("%s", str);
                    
                    if(strcasecmp(str, ";") == 0) {
                        break;
                    }
                    
                    alphaToMorse(str, aux);
                    
                    for(i = 0; i < strlen(aux); i++) { 
                        if(aux[i] == 'x') {
                            printf("\n");
                        } else {
                            printf("%c", aux[i]);
                        }
                    }
                    
                    
                    memset(aux, '\0', size);
                    size = 5;
                    printf("\n");
                }
                system("clear");
    
                break;  
            
        //Test your might(jogo)
            case 4:
                while(strcasecmp(str, ";") != 0) {
                    printf("Aperte \";\" e enter para sair.\n");
                    scanf("%s", str);
                    system("clear");
                }
                system("clear");
                strcpy(str, "");
                break;  
            default:
            break;
        }  
    }
    
    free(aux);
    return 0;
}