#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct jogador {
    char nome[16];
    int pts;
};

FILE *fp;
int qnt = 0, pl = 0, check = 0, indice, vidas, pontos;
char palavras[1000][20];
struct jogador jogadores[100];
char pM[20];


void init() {
    vidas = 3;
    pontos = 0;
}

void getArq() {
    
    fp = fopen("palavras", "a+");
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

void getJogadores() {
    fp = fopen("jogadores", "a+");
    
    while(fscanf(fp, "%s %d", jogadores[pl].nome, &jogadores[pl].pts) != EOF) {
        pl++;
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
        sprintf(cmP, "%s%.1f%s", "play -n -q synth ", 0.3/nivel, " sine 750 vol 0.1");
        sprintf(cmE, "%s%.1f%s", "play -n -q synth ", 0.3/nivel, " sine 750 vol 0");
        
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
    
    sleep(3);
    
}

int verificaE(char str[]) {
    int i, res = 0;
    for(i = 0; i < strlen(str); i++) {
        if(str[i] == ' ') {
            res++;
            break;
        }
    }
    
    return res;
}

void cadastraJogador(char nome[], int pont) {
    int ck = 0;
    
    for(i = 0; i < pl; i++) {
        if(strcasecmp(jogadores[i].nome,nome) == 0) {
            ck++;
            
            if(jogadores[i].pts < pont) {
                jogadores[i].pts = pont;
                
                fp = fopen("jogadores", "w");
                
                for(j = 0; j < pl; j++) {
                    fprintf(fp, "%s %d\n", jogadores[j].nome, jogadores[j].pts);
                }
                
                fclose(fp);
                printf("Pontuação alterada\n");
            }
            
            break;
        }
    }
    
    if(ck == 0) {
        
        fp = fopen("jogadores", "a");
    
        fprintf(fp, "%s %d\n", nome, pont);
        printf("Jogador cadastrado com sucesso!\n");

        strcpy(jogadores[pl].nome, nome);
        jogadores[pl].pts = pont;

        pl++;
        fclose(fp);
        sleep(1);
    }
}

void formata(char nome[], int pontos) {
    printf("%s", nome);
    for(j = 0; j < 20; j++) {
        if(!isalpha(nome[j]) && !isdigit(nome[j])) {
            printf(" ");
        }
    }

    printf(" %d\n", pontos);
}


void ordena() {
    int i, j, aux;
    char nomeA[15];
    
    for(i = 0; i < pl; i++) {
        for(j = i + 1; j < pl; j++) {
            if(jogadores[j].pts > jogadores[i].pts) {
                aux = jogadores[i].pts;
                jogadores[i].pts = jogadores[j].pts;
                jogadores[j].pts = aux;
                
                strcpy(nomeA, jogadores[i].nome);
                strcpy(jogadores[i].nome, jogadores[j].nome);
                strcpy(jogadores[j].nome, nomeA);
            }
        }
    }
    
}
