/**
@Author Leandro Martins de Freitas
**/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Traducao.c"
#include "Jogo.c"

//char* realoca(char str[], char *aux) {
//    while(size <= strlen(aux)) {
//        aux = realloc(aux, ((size * 2) + 1) * sizeof(char));
//        printf("Size: %d\n", size);
//        size *= 2;
//    }
//    
//    return aux; 
//}

int main() {
    int opc, pid, teste, tempo = 8;
    char str[100];
    char kill[15];
    
    getPalavras();
    for(;;) {
        //header    
            printf("################################################################################\n");    
printf("#                                   Mor-C                                      #\n");       
printf("################################################################################\n");
        printf("Escolha sua opção: \n");
        printf("1 - Instruções e caractéres.\n");
        printf("2 - Tradução: Morse -> Alfabeto.\n");
        printf("3 - Tradução: Alfabeto -> Morse.\n");
        printf("4 - Cadastar palavras.\n");
        printf("5 - Test your might!\n");
        printf("6 - Sair.\n");
        
        scanf("%d", &opc);
        memset(str, '\n', 100);
        
        if(opc == 6) {
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
                    scanf(" %[^\n]s", str);
                    
                    if(strcasecmp(str, ";") == 0) {
                        break;
                    }
                    
                    if(verificaM(str)) {
                        morseToAlpha(str, aux);
                    }
                    printf("\n");   
                }
                system("clear");
                strcpy(str, " ");
                memset(aux, '\0', 1000);
                break;
            
            //Tradução: Alfabeto -> Morse
            case 3:
                printf("Digite a palavra (ou frase) a ser traduzida ou aperte \";\" e enter para sair.\n");
                while(strcasecmp(str, ";") != 0) {
                    scanf("%s", str);
                    
                    if(strcasecmp(str, ";") == 0) {
                        break;
                    }
                    
                    if(verificaA(str)) {
                        alphaToMorse(str, aux);
                    }
                    
                    for(i = 0; i < strlen(aux); i++) { 
                        if(aux[i] == 'x') {
                            printf("\n");
                        } else {
                            printf("%c", aux[i]);
                        }
                    }
                    
                    
                    memset(aux, '\0', 1000);
                    printf("\n");
                }
                system("clear");
                break;  
            
            //Cadastrar palavras para o jogo 
            case 4:
                printf("Digite a palavra a ser cadastrada ou \";\" e enter para sair.\n");
                while(strcasecmp(str, ";") != 0) {
                    scanf("%s", str);
                    
                    if(strcasecmp(str, ";") == 0) {
                        break;
                    }
                    
                    cadastra(str);

                }
                system("clear");
                break;    
            
            //Test your might(jogo)
            case 5:
//                pid = fork();
//                sprintf(kill, "%s%d", "kill -9 ", pid);
//                    
//                if(pid > 0) {
//                    for(i = tempo; i >= 0; i--) {
//                        printf("Tempo restante: %d segundos\n", i);
//                        printf("P\n");
//                        sleep(1);
//                        system("clear");
//                    }    
//                    system(kill);
//                }
//                    
//                if(pid == 0) {
//                    for(i = tempo; i >= 0 ; i--) {
//                        scanf("%d", &teste);
//                        printf("%d\n", teste);
//                       }
//                }
                
            default:
                break;
        }  
    }
    
    return 0;
}
