#include <stdio.h>
#include <string.h>
#include <stdlib.h>

FILE *fp;
int qnt = 0, check = 0, indice, vidas, pontos;
char palavras[1000][20];
char pM[20];

void getArq() {
    
    fp = fopen("palavras", "r");
    while(fscanf(fp, "%s", palavras[qnt]) != EOF) {
        qnt++;
    }
    fclose(fp);
}

void cadastra(char str[]) {
    fp = fopen("palavras", "a");
    memset(pM, '\0', 20);
    
    for(i = 0; i < strlen(str); i++) {
        pM[i] = toupper(str[i]);
    }
    
    if(verificaA(pM)) {    
        for(i = 0; i < qnt; i++)  {
            if(strcmp(pM,palavras[i]) == 0) {
                printf("Palavra já cadastrada.\n");
                check++;
                break;
            } 
        }
        
        if(check == 0) {
            fprintf(fp, "%s\n", pM);
            printf("Palavra cadastrada com sucesso!\n");
            strcpy(palavras[qnt],pM);
            qnt++;
        }
        
        check = 0;
    } else {
        printf("Caractére não suportado! Cadastro falhou.\n");
    }
    fclose(fp);
}

char* getPalavra() {
    return palavras[rand() % (qnt - 1)];
}

void toca(char str[], int nivel) {
    for(i = 0; i < strlen(str); i++) {
        char cmT[40], cmP[40], cmE[40];
        
        sprintf(cmT, "%s%.1f%s", "play -n -q synth ", 0.8/nivel, " sine 750 vol 0.1");
        sprintf(cmP, "%s%.1f%s", "play -n -q synth ", 0.4/nivel, " sine 750 vol 0.1");
        sprintf(cmE, "%s%.1f%s", "play -n -q synth ", 0.4/nivel, " sine 750 vol 0");
        
        if(str[i] == '-') {
            system(cmT);
        }
                   
        if(str[i] == '.') {
            system(cmP);
        }
                   
        if(str[i] == ' ') {
            system(cmE);
        }
    }
    
}

void init() {
    vidas = 3;
    pontos = 0;
}