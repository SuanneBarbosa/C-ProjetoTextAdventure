#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    int path;
    char text[200];
} ANSWER;

ANSWER answerList[200];

typedef struct
{
    int id;
    ANSWER answerList[200];
    char type[200];
    char text[200];
    int answerQuantity;
} LEVEL;

LEVEL levelList[200];
LEVEL currentLevel; // nível atual
LEVEL nextLevel;    // proximo nivel

int currentPuzzleRandomNumber;
char currentPuzzleResponse[200];
 int errorCount = 0;

// função de carregar o nível

// int loadingLevel () {
//     printf (currentLevel.text);
//     printf ((currentLevel.type == "normal") ? currentPuzzleRandomNumber () : currentPuzzleResponse ());
//     (ANSWER) >= {
//         printf();
//     }

// }

int main() // dentro da main so manipula os dados
{
    // int teste = test();
    // printf("%d", teste);

    char userAnswer[49];

    levelList[0].id = 0;
    strcpy(levelList[0].type, "normal");
    strcpy(levelList[0].text, "** Você está na sala **\nPara onde vc vai seguir?");
    levelList[0].answerList[0].path = 1;
    levelList[0].answerList[1].path = 2;
    levelList[0].answerList[2].path = 3;
    strcpy(levelList[0].answerList[0].text, "cozinha");
    strcpy(levelList[0].answerList[1].text, "escada");
    strcpy(levelList[0].answerList[2].text, "banheiro");
    levelList[0].answerQuantity = 3;

    levelList[1].id = 1;
    strcpy(levelList[1].type, "normal");
    strcpy(levelList[1].text, "** Você está na cozinha. **\nPara onde você vai seguir?");
    levelList[1].answerList[0].path = 0;
    strcpy(levelList[1].answerList[0].text, "voltar");
    levelList[1].answerQuantity = 1;

    levelList[2].id = 2;
    strcpy(levelList[2].type, "normal");
    strcpy(levelList[2].text, "** Você está no corredor no segundo andar. **\nPara onde vc vai seguir?");
    levelList[2].answerList[0].path = 0;
    levelList[2].answerList[1].path = 4;
    levelList[2].answerList[2].path = 5;
    levelList[2].answerList[3].path = 6;
    strcpy(levelList[2].answerList[1].text, "quarto1");
    strcpy(levelList[2].answerList[2].text, "quarto2");
    strcpy(levelList[2].answerList[3].text, "quarto3");
    strcpy(levelList[2].answerList[0].text, "voltar");
    levelList[2].answerQuantity = 4;

    levelList[3].id = 3;
    strcpy(levelList[3].type, "normal");
    strcpy(levelList[3].text, "** Você entrou no banheiro. **\nPara onde vc vai seguir?");
    levelList[3].answerList[0].path = 0;
    strcpy(levelList[3].answerList[0].text, "voltar");
    levelList[3].answerQuantity = 1;

    levelList[4].id = 4;
    strcpy(levelList[4].type, "normal");
    strcpy(levelList[4].text, "** Você entrou no quarto 1. **\nPara onde vc vai seguir?");
    levelList[4].answerList[0].path = 2;
    strcpy(levelList[4].answerList[0].text, "voltar");
    levelList[4].answerQuantity = 1;

    levelList[5].id = 5;
    strcpy(levelList[5].type, "normal");
    strcpy(levelList[5].text, "** Você entrou no quarto 2. **\nPara onde vc vai seguir?");
    levelList[5].answerList[0].path = 2;
    strcpy(levelList[5].answerList[0].text, "voltar");
    levelList[5].answerQuantity = 1;

    levelList[6].id = 6;
    strcpy(levelList[6].type, "normal");
    strcpy(levelList[6].text, "** Você entrou no quarto 3 e percebeu que existe um quadro na parede. **\nPara onde vc vai seguir?");
    levelList[6].answerList[0].path = 2;
    levelList[6].answerList[1].path = 7;
    strcpy(levelList[6].answerList[0].text, "voltar");
    strcpy(levelList[6].answerList[1].text, "investigar");
    levelList[6].answerQuantity = 2;

    levelList[7].id = 7;
    strcpy(levelList[7].type, "normal");
    strcpy(levelList[7].text, "** Você retirou o quadro e achou um cofre! Acerte a combinação para achar o tesouro. **\n");
    levelList[7].answerList[0].path = 8;
    levelList[7].answerList[1].path = 2;
    strcpy(levelList[7].answerList[0].text, "tentar");
    strcpy(levelList[7].answerList[1].text, "voltar");
    levelList[7].answerQuantity = 2;

    levelList[8].id = 8;
    strcpy(levelList[8].type, "puzzle");
    strcpy(levelList[8].text, "** Resolva o problema para achar a combinação. **\n");
    levelList[8].answerList[0].path = 9;
    levelList[8].answerList[1].path = 2;
    strcpy(levelList[8].answerList[0].text, "correct");
    strcpy(levelList[8].answerList[1].text, "voltar");
    levelList[8].answerQuantity = 2;

    levelList[9].id = 9;
    strcpy(levelList[9].type, "endgame");
    strcpy(levelList[9].text, "** Você achou o tesouro, parabéns!. **\n");

    // Configurações iniciais
    

    printf("Você entra numa casa abandonada na espera de encontrar algum tesouro antigo (ou pelo menos algo que possa vender por um preço razoável). Você lembra do rosto do velho enquanto era levado pelas ambulâncias: tão sem vida quanto a casa que ele morou nos últimos 2 meses.\nEle havia se mudado pra vizinhança após ter sua casa no centro da cidade tomada por dívidas, então você não espera encontrar muita coisa dele, mas a casa esteve de pé por muitos anos antes e a família Skalo que sempre a habitou não parecia ser tão 'pé-rapada' quanto o velho senhor que provavelmente a conseguiu por uma pechincha.\nO motivo pela mudança de senhorio, ainda que peculiar, foi o que te trouxe aqui neste momento. No último ano, cada um dos 6 membros da família Skalo faleceu de formas estranhas (para não dizer suspeitas).\nA forma súbita que as mortes se sucederam te fizeram imaginar que seus bens permaneceram na casa, já que eram os últimos integrantes da família antiga, e roubar uma casa abandonada sem ninguém pra dar falta é muito melhor que invadir as residências dos rostos conhecidos na região, sempre com o risco de ser pego ou reconhecido. Hoje, ao ver as ambulâncias saindo, você decidiu tentar a sorte.\n");

    // printf("Digite qualquer tecla para continuar");
    // scanf("%s", &userAnswer);
    // fflush (stdin);

    currentLevel = levelList[0]; // passo inicial

    // fazer while chamar a função makequestion

   
    while  (strcmp(currentLevel.type, "endgame") != 0)
    {
         // verificar o tipo de nível
       
         if  (strcmp(currentLevel.type , "normal") == 0){
             
            for (int i = 0; i < currentLevel.answerQuantity; i++){ // fazer as perguntas
                printf(currentLevel.answerList[i].text);
                printf("\n");
            }
               
            printf("ajuda\n");
            printf("sair\n");

                
            scanf("%s", &userAnswer);
            printf("Sua resposta foi %s!\n", userAnswer);
                
                // opções extras, ajuda e sair 
        
            if (strcmp(userAnswer , "ajuda") == 0)
            {
                printf("Vou te ajudar!\n");
            }
            else if (strcmp(userAnswer , "sair") == 0)
            {
                printf("Bye Bye!\n");
                return 0;
            }
            else
            { // comparar as respostas e níveis
                for (int i = 0; i < currentLevel.answerQuantity; i++){
                    if (strcmp(currentLevel.answerList[i].text, userAnswer) == 0){
                        currentLevel = levelList[currentLevel.answerList[i].path];
                        break; 
                    }
                }
                
                printf("%s\n", currentLevel.text);
            }           
         }
         else {
            printf("Desvende o enigma ou escolha uma das seguintes opções:\najuda\nvoltar\nsair\n");
            
            //criar o swith case
            //gerar um numero aleatorio de 0 a quatidade de enigmas possiveis
            // gerar uma pergunta e uma resposta dependendo do caso
            //para mesma logica a resposta gerada fica no lugar do correct do nivel do puzzle e depois percorrer as respostas ou so salva em uma variavel e compara
            // depois fazer o mesmo if else do tipo normal e da pra fazer em uma função copia do ajuda e do sair e voltar 
            int puzzle = rand() % 3;
            char puzzleAnswer[200];
           

            switch (puzzle)
            {
            case 0 : 
                printf("enigma 0\n");
                strcpy(puzzleAnswer, "resposta0");
                break;
            case 1 : 
                printf("enigma 1\n");
                strcpy(puzzleAnswer, "resposta1");
                break;
            case 2 : 
                printf("enigma 2\n");
                strcpy(puzzleAnswer, "resposta2");
                break;    
            default:
                printf("enigma 3\n");
                strcpy(puzzleAnswer, "resposta3");
                break;
            }
            scanf("%s", &userAnswer);
            printf("Sua resposta foi %s!\n", userAnswer);
                
                // opções extras, ajuda e sair 
        
            if (strcmp(userAnswer , "ajuda") == 0)
            {
                printf("Vou te ajudar!\n");
            }
            else if (strcmp(userAnswer , "sair") == 0)
            {
                printf("Bye Bye!\n");
                return 0;
            }
            else if (strcmp(userAnswer , "voltar") == 0)
            {
                currentLevel = levelList[currentLevel.answerList[1].path];
            }
            else if (strcmp(userAnswer , puzzleAnswer) == 0)
            {
                currentLevel = levelList[currentLevel.answerList[0].path];
            }
            
            else { // comparar as respostas e níveis
                errorCount++;
                if (errorCount == 3)
                {
                   printf("Você perdeu o jogo!");
                   return 0;
                }
                else {
                    printf("Você errou e tem mais %d tentativas\n", 3 - errorCount);
                }
                
            }           
         }
         
        
        
    }

    printf("Parabéns você ganhou o jogo!");

    return 0;
}

