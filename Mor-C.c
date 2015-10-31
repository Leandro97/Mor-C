/**
@Author Leandro Martins de Freitas
**/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
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
    int opc, pid, nivel, p, j;
    char str[1000], word[1000];
    char kill[15];
    
    srand(time(NULL));
    getArq();
    getJogadores();
    
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
        printf("5 - Teste seus conhecimentos.\n");
        printf("6 - Ranking.\n");
        printf("7 - Sair.\n");
        
        scanf("%d", &opc);
        memset(str, '\n', 100);
        
        if(opc == 7) {
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
            
            //Jogo
            case 5:
                printf("O objetivo deste jogo é treinar o reconhecimento de Morse através da audição.\nSerão apresentadaos sons de palavras aleatórias e sua missão é informar que\npalavra(em alfabeto) é essa. Você possui 3 vidas, ao errar perde uma.\nAo acertar, uma nova palavra é gerada e voce ganha 10 pontos. As palavras são\napresentadas a cada 3 segundos.\n");
                do {
                    printf("Escolha o nível. Easy(1), Normal(2), Hard(3)\n");
                    scanf("%d", &nivel);
                } while(nivel != 1 && nivel != 2 && nivel != 3);
                
            
                system("clear");
                init();
                memset(aux, '\0', 1000);
                strcpy(word, getPalavra());
                alphaToMorse(word, aux);
            
                pid = fork();
                sprintf(kill, "%s%d", "kill -9 ", pid);
            
                for(;;){
                    if(pid > 0) {
                        for(;;) {
                            printf("Vidas: %d.      Pontuação: %d\n", vidas, pontos);
                            //to mostrando a palavra só pra testar, na versão final vou tirar
                            //printf("Palavra: %s\n", word);
                            scanf(" %[^\n]s", str);

                            if(strcasecmp(str, word) == 0) {
                                pontos += 10;
                                
                                memset(aux, '\0', 1000);
                                strcpy(word, getPalavra());
                                alphaToMorse(word, aux);
                                
                                system(kill);
                                
                                pid = fork();
                                sprintf(kill, "%s%d", "kill -9 ", pid);
                                
                                sleep(1,5);
                                system("clear");
                                break;
                            } else {
                                system("clear");
                                vidas--;
                            }

                            if(strcmp(str, ";") == 0 || vidas == 0) { 
                                system("clear");
                                system(kill);
                                break;
                            }
                        }
                        if(strcmp(str, ";") == 0 || vidas == 0) { 
                                system("clear");
                                system(kill);
                                break;
                        }
                    }
                    
                    if(pid == 0) {
                        toca(aux, nivel);
                        sleep(3);
                    }   
                }
                
                do {
                    memset(str, '\0', 1000);
                    printf("Nome do jogador(até 15 letras sem espaços): ");
                    scanf(" %[^\n]s", str);
                } while(strlen(str) > 15 || verificaE(str));
            
                cadastraJogador(str, pontos);
                sleep(2);
                system("clear");
                
                opc = 6;    
            
            case 6:
                ordena();
            
                for(i = 0; i < pl; i++) {
                    for(j = 0; j < 16; j++) {
                        if(!isalpha(jogadores[i].nome[j]) && !isdigit(jogadores[i].nome[j])) {
                            jogadores[i].nome[j] = ' ';
                        }
                    }
                }
            
                printf("Nome                   Pontos\n");
            
                for(i = 0; i < pl; i++) {
                    printf("%s          %d\n", jogadores[i].nome, jogadores[i].pts);
                }
                
                printf("Digite algo para sair\n");
                scanf("%s", str);
                system("clear");
                break;
            default:
                break;
        }  
    }
    
    return 0;
}

