#include <stdio.h>
#include <string.h>

typedef struct
{
    int path;
    char text[49];
} ANSWER;

ANSWER answerList[20];

typedef struct
{
    int id;
    ANSWER answerList[20];
    char type[49];
    char text[49];
    int answerQuantity;
} LEVEL;

LEVEL levelList[49];
LEVEL currentLevel; // nível atual
LEVEL nextLevel;    // proximo nivel

int currentPuzzleRandomNumber;
char currentPuzzleResponse[49];

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
    strcpy(levelList[0].answerList[0].text, "Cozinha");
    strcpy(levelList[0].answerList[1].text, "Escada");
    strcpy(levelList[0].answerList[2].text, "Banheiro");
    levelList[0].answerQuantity = 3;

    levelList[1].id = 1;
    strcpy(levelList[1].type, "normal");
    strcpy(levelList[1].text, "** Você está na cozinha. **\nPara onde vc vai seguir?");
    levelList[1].answerList[0].path = 0;
    strcpy(levelList[1].answerList[0].text, "sala");
    levelList[1].answerQuantity = 1;

    levelList[2].id = 2;
    strcpy(levelList[2].type, "normal");
    strcpy(levelList[2].text, "** Você está no corredor no segundo andar. **\nPara onde vc vai seguir?");
    levelList[2].answerList[0].path = 0;
    levelList[2].answerList[1].path = 5;
    levelList[2].answerList[2].path = 6;
    levelList[2].answerList[3].path = 7;
    strcpy(levelList[2].answerList[1].text, "quarto 1");
    strcpy(levelList[2].answerList[2].text, "quarto 2");
    strcpy(levelList[2].answerList[3].text, "quarto 3");
    strcpy(levelList[2].answerList[0].text, "descer escada");
    levelList[2].answerQuantity = 4;

    levelList[3].id = 3;
    strcpy(levelList[3].type, "normal");
    strcpy(levelList[3].text, "** Você entrou no banheiro. **\nPara onde vc vai seguir?");
    levelList[3].answerList[0].path = 0;
    strcpy(levelList[3].answerList[0].text, "sala");
    levelList[3].answerQuantity = 1;

    levelList[4].id = 4;
    strcpy(levelList[4].type, "normal");
    strcpy(levelList[4].text, "** Você entrou no quarto 1. **\nPara onde vc vai seguir?");
    levelList[4].answerList[0].path = 2;
    strcpy(levelList[4].answerList[0].text, "corredor");
    levelList[4].answerQuantity = 1;

    levelList[5].id = 5;
    strcpy(levelList[5].type, "normal");
    strcpy(levelList[5].text, "** Você entrou no quarto 2. **\nPara onde vc vai seguir?");
    levelList[5].answerList[0].path = 2;
    strcpy(levelList[5].answerList[0].text, "corredor");
    levelList[5].answerQuantity = 1;

    levelList[6].id = 6;
    strcpy(levelList[6].type, "normal");
    strcpy(levelList[6].text, "** Você entrou no quarto 3 e percebeu que existe um quadro na parede. **\nPara onde vc vai seguir?");
    levelList[6].answerList[0].path = 2;
    levelList[6].answerList[1].path = 7;
    strcpy(levelList[6].answerList[0].text, "corredor");
    strcpy(levelList[6].answerList[1].text, "investigar");
    levelList[6].answerQuantity = 2;

    levelList[7].id = 7;
    strcpy(levelList[7].type, "normal");
    strcpy(levelList[7].text, "** Você retirou o quadro e acho um cofre! Acerte a combinação para achar o tesouro. **\n");
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
    

    printf("Você entra numa casa abandonada na espera de encontrar algum tesouro antigo (ou pelo menos algo que possa vender por um preço razoável). Você lembra do rosto do velho enquanto era levado pelas ambulâncias: tão sem vida quanto a casa que ele morou nos últimos 2 meses. Ele havia se mudado pra vizinhança após ter sua casa no centro da cidade tomada por dívidas, então você não espera encontrar muita coisa dele, mas a casa esteve de pé por muitos anos antes e a família Skalo que sempre a habitou não parecia ser tão 'pé-rapada' quanto o velho senhor que provavelmente a conseguiu por uma pechincha. O motivo pela mudança de senhorio, ainda que peculiar, foi o que te trouxe aqui neste momento. No último ano, cada um dos 6 membros da família Skalo faleceu de formas estranhas (para não dizer suspeitas). A forma súbita que as mortes se sucederam te fizeram imaginar que seus bens permaneceram na casa, já que eram os últimos integrantes da família antiga, e roubar uma casa abandonada sem ninguém pra dar falta é muito melhor que invadir as residências dos rostos conhecidos na região, sempre com o risco de ser pego ou reconhecido. Hoje, ao ver as ambulâncias saindo, você decidiu tentar a sorte.\n Agora, você tem as seguintes opções:\n");

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
            // puzzle
         }
         
        
        
    }

    // int suanne = sizeof(levelList[8].answerList)/sizeof(levelList[8].answerList[0]);
    // printf("%d",suanne);

    printf("ESTOU SAINDO");

    return 0;
}

