//vetor que armazena os caractéres alfabéticos
char alpha[36][1] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    
//vetor que armazena(como strings) os caractéres em Morse
char morse[36][6] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."};

int i, j, k, c, tam = 0, cont = 0;
char aux[1000];
 

void alphaToMorse(char str[], char aux[]) {
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
    }
    
    tam = 0;
}

void morseToAlpha(char str[], char aux[]) {
    for(i = 0; i < strlen(str); i++) {
        if(str[i] != ' ') {
            aux[cont] = str[i];
            cont++;
        } 
        
        if(str[i] == ' ' || i == strlen(str) - 1){
            for(j = 0; j < 36; j++) {
                if(strcmp(morse[j], aux) == 0) {
                    printf("%c", alpha[j][0]);
                    memset(aux, '\0', 1000);
                    break;
                }
            }
            cont = 0;
        }
    }
    
    cont = 0;
}

//se a string em for composta apenas por "."s, "-"s ou " "s, a tradução pode continuar 
int verificaM(char str[]) {
    int res = 1;
    for(i = 0; i < strlen(str); i++) {
        if(str[i] != '.' && str[i] != '-' && str[i] != ' ') {
            res = 0;
            break;
        }
    }
    return res;
}

//se a string for composta apenas por letras sem acentos ou por números, a tradução pode continuar
int verificaA(char str[]) {
    int res = 1;
    for(i = 0; i < strlen(str); i++) {
        if((toupper(str[i]) > 90 || toupper(str[i]) < 65) && (str[i] > 57 || str[i] < 48)) {
            res = 0;
            break;
        }
    }
    return res;
}