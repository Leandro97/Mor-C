#include <stdio.h>
#include <string.h>
#include <stdlib.h>

FILE *fp;
int qnt = 0, check = 0;
char palavras[1000][20];
char pM[20];

void getPalavras() {
    
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