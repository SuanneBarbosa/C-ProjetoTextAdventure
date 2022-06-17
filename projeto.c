#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

typedef struct{
    int path; // caminho
    char text[900];
} ANSWER;

ANSWER answerList[900]; // objeto de respostas

typedef struct{
    int id;
    ANSWER answerList[900];
    char type[900];
    char text[900];
    int answerQuantity;
} LEVEL;

LEVEL levelList[900]; // lista de todos os níveis
LEVEL currentLevel;   // nível atual

int errorCount = 0; // contador de erros do puzzle
char puzzleAnswer[100];// respostas dos enigmas
char textFromFile[5000]; // variavel que recebe os textos dos arquivos
char userAnswer[49];     // resposta do usuário

void printPuzzle(char *question, char *answerquestion){ // função das perguntas do puzzle
    printf(question);
    strcpy(puzzleAnswer, answerquestion);
}

void getTextFromFile(char *filename){ // função dos arquivos em txt
    bzero(textFromFile, 5000);       // limpa a variavel textfromfile
    FILE *fp = fopen(filename, "r"); // abre conexão com o arquivo
    if (fp == NULL){
        printf("Error: could not open file %s", filename);
    }
    char ch; // percorre todo o arquivo carctere por caractere
    int i = 0;
    while ((ch = fgetc(fp)) != EOF){
        textFromFile[i] = ch;
        i++;
    }
    fclose(fp);
}

void initLevels(){// Tipos de níveis e caminhos percorridos por array
    levelList[0].id = 0;
    strcpy(levelList[0].type, "normal");
    getTextFromFile("./textos/frasesnivel0.txt");
    strcpy(levelList[0].text, textFromFile);
    levelList[0].answerList[0].path = 1;
    levelList[0].answerList[1].path = 2;
    levelList[0].answerList[2].path = 3;
    strcpy(levelList[0].answerList[0].text, "cozinha");
    strcpy(levelList[0].answerList[1].text, "escada");
    strcpy(levelList[0].answerList[2].text, "banheiro");
    levelList[0].answerQuantity = 3;

    levelList[1].id = 1;
    strcpy(levelList[1].type, "endgame");
    getTextFromFile("./textos/frasesnivel1.txt");
    strcpy(levelList[1].text, textFromFile);

    levelList[2].id = 2;
    strcpy(levelList[2].type, "normal");
    getTextFromFile("./textos/frasesnivel2.txt");
    strcpy(levelList[2].text, textFromFile);
    levelList[2].answerList[0].path = 0;
    levelList[2].answerList[1].path = 4;
    levelList[2].answerList[2].path = 5;
    levelList[2].answerList[3].path = 6;
    levelList[2].answerList[4].path = 10;
    strcpy(levelList[2].answerList[1].text, "quarto1");
    strcpy(levelList[2].answerList[2].text, "quarto2");
    strcpy(levelList[2].answerList[3].text, "quarto3");
    strcpy(levelList[2].answerList[4].text, "janela");
    strcpy(levelList[2].answerList[0].text, "voltar");
    levelList[2].answerQuantity = 5;

    levelList[3].id = 3;
    strcpy(levelList[3].type, "normal");
    getTextFromFile("./textos/frasesnivel3.txt");
    strcpy(levelList[3].text, textFromFile);
    levelList[3].answerList[0].path = 0;
    strcpy(levelList[3].answerList[0].text, "voltar");
    levelList[3].answerQuantity = 1;

    levelList[4].id = 4;
    strcpy(levelList[4].type, "normal");
    getTextFromFile("./textos/frasesnivel4.txt");
    strcpy(levelList[4].text, textFromFile);
    levelList[4].answerList[0].path = 2;
    strcpy(levelList[4].answerList[0].text, "voltar");
    levelList[4].answerQuantity = 1;

    levelList[5].id = 5;
    strcpy(levelList[5].type, "normal");
    getTextFromFile("./textos/frasesnivel5.txt");
    strcpy(levelList[5].text, textFromFile);
    levelList[5].answerList[0].path = 2;
    strcpy(levelList[5].answerList[0].text, "voltar");
    levelList[5].answerQuantity = 1;

    levelList[6].id = 6;
    strcpy(levelList[6].type, "normal");
    getTextFromFile("./textos/frasesnivel6.txt");
    strcpy(levelList[6].text, textFromFile);
    levelList[6].answerList[1].path = 2;
    levelList[6].answerList[0].path = 7;
    strcpy(levelList[6].answerList[0].text, "pressionar");
    strcpy(levelList[6].answerList[1].text, "voltar");
    levelList[6].answerQuantity = 2;

    levelList[7].id = 7;
    strcpy(levelList[7].type, "normal");
    getTextFromFile("./textos/frasesnivel7.txt");
    strcpy(levelList[7].text, textFromFile);
    levelList[7].answerList[0].path = 8;
    levelList[7].answerList[1].path = 2;
    strcpy(levelList[7].answerList[0].text, "iniciar");
    strcpy(levelList[7].answerList[1].text, "voltar");
    levelList[7].answerQuantity = 2;

    levelList[8].id = 8;
    strcpy(levelList[8].type, "puzzle");
    getTextFromFile("./textos/frasesnivel8.txt");
    strcpy(levelList[8].text, textFromFile);
    levelList[8].answerList[0].path = 9;
    levelList[8].answerList[1].path = 2;
    strcpy(levelList[8].answerList[0].text, "correct");
    strcpy(levelList[8].answerList[1].text, "voltar");
    levelList[8].answerQuantity = 2;

    levelList[9].id = 9;
    strcpy(levelList[9].type, "endgame");
    getTextFromFile("./textos/frasesnivel9.txt");
    strcpy(levelList[9].text, textFromFile);

    levelList[10].id = 10;
    strcpy(levelList[10].type, "endgame");
    getTextFromFile("./textos/frasesnivel10.txt");
    strcpy(levelList[10].text, textFromFile);
}

void loadNormalLevel(){
    for (int i = 0; i < currentLevel.answerQuantity; i++){ // fazer as perguntas
        printf(currentLevel.answerList[i].text);
        printf("\n");
    }
    printf("ajuda\n");
    printf("sair\n");
    scanf("%s", &userAnswer);
    printf("Sua resposta foi %s!\n", userAnswer);
    if (strcmp(userAnswer, "ajuda") == 0){
        getTextFromFile("./textos/ajuda.txt");
        printf(textFromFile);
    }
    else if (strcmp(userAnswer, "sair") == 0){
        getTextFromFile("./textos/sair.txt");
        printf(textFromFile);
        exit(0);
    }
    else{ // comparar as respostas e níveis
        for (int i = 0; i < currentLevel.answerQuantity; i++){
            if (strcmp(currentLevel.answerList[i].text, userAnswer) == 0){
                currentLevel = levelList[currentLevel.answerList[i].path];
                break;
            }
        }
    }
}

void loadPuzzle(){
    printf("Desvende o enigma ou escolha uma das seguintes opções:\najuda\nvoltar\nsair\n");
    // case aleatório
    srand(time(NULL));
    int puzzle = rand() % 7;
    switch (puzzle){
    case 0:
        getTextFromFile("./textos/puzzle0.txt");
        printPuzzle(textFromFile, "moeda");
        break;
    case 1:
        getTextFromFile("./textos/puzzle1.txt");
        printPuzzle(textFromFile, "nuvem");
        break;
    case 2:
        getTextFromFile("./textos/puzzle2.txt");
        printPuzzle(textFromFile, "cebola");
        break;
    case 3:
        getTextFromFile("./textos/puzzle3.txt");
        printPuzzle(textFromFile, "pipi");
        break;
    case 4:
        getTextFromFile("./textos/puzzle4.txt");
        printPuzzle(textFromFile, "tempo");
        break;
    case 5:
        getTextFromFile("./textos/puzzle5.txt");
        printPuzzle(textFromFile, "cadeado");
        break;
    case 6:
        getTextFromFile("./textos/puzzle6.txt");
        printPuzzle(textFromFile, "espelho");
        break;
    }
    scanf("%s", &userAnswer);
    printf("Sua resposta foi %s!\n", userAnswer);
    if (strcmp(userAnswer, "ajuda") == 0){
        getTextFromFile("./textos/ajuda.txt");
        printf(textFromFile);
    }
    else if (strcmp(userAnswer, "sair") == 0){
        getTextFromFile("./textos/sair.txt");
        printf(textFromFile);
        exit(0);
    }
    else if (strcmp(userAnswer, "voltar") == 0){
        currentLevel = levelList[currentLevel.answerList[1].path];
    }
    else if (strcmp(userAnswer, puzzleAnswer) == 0){
        currentLevel = levelList[currentLevel.answerList[0].path];
    }
    else{ // comparar as respostas e níveis
        errorCount++;
        if (errorCount == 3){
            getTextFromFile("./textos/respostaIncorreta.txt");
            printf(textFromFile);
            exit(0);
        }
        else{
            printf("\n***VOCÊ ERROU E TEM MAIS %d TENTATIVAS***\n", 3 - errorCount);
        }
    }
}

int main(){  
    initLevels();
    getTextFromFile("./textos/historiaskalo.txt"); // primeira tela historia inicial
    printf(textFromFile); //puxa o texto
    getchar(); // para ate precionar o enter para entrar nas opções
    currentLevel = levelList[0]; // o nível atual inicia no nivel 0 - passo inicial
    while (strcmp(currentLevel.type, "endgame") != 0){
        printf("%s\n", currentLevel.text); // verificar o tipo de nível
        if (strcmp(currentLevel.type, "normal") == 0){
            loadNormalLevel();
        }
        else{
            loadPuzzle();
        }
    }
    printf("%s \n", currentLevel.text);
    return 0;
}
