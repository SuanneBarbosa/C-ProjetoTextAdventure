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
LEVEL currentLevel ; // nível atual
LEVEL nextLevel ; // proximo nivel

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

int main () // dentro da main so manipula os dados
{
// int teste = test();
// printf("%d", teste);

char userAnswer[49];

levelList[0].id = 0;
strcpy(levelList[0].type, "normal");
strcpy(levelList[0].text, "** Voce esta na sala **\nPara onde vc vai seguir?");
levelList[0].answerList[0].path = 1;
levelList[0].answerList[1].path = 2;
levelList[0].answerList[2].path = 3;
strcpy(levelList[0].answerList[0].text, "Cozinha");
strcpy(levelList[0].answerList[1].text, "Escada");
strcpy(levelList[0].answerList[2].text, "Banheiro");
levelList[0].answerQuantity = 3;

levelList[1].id = 1;
strcpy(levelList[1].type, "normal");
strcpy(levelList[1].text, "** Voce esta na cozinha. **\nPara onde vc vai seguir?");
levelList[1].answerList[0].path = 0;
strcpy(levelList[1].answerList[0].text, "sala");
levelList[1].answerQuantity = 1;

levelList[2].id = 2;
strcpy(levelList[2].type, "normal");
strcpy(levelList[2].text, "** Você esta no corredor no segundo andar. **\nPara onde vc vai seguir?");
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
strcpy(levelList[3].text, "** Voce entrou no banheiro. **\nPara onde vc vai seguir?");
levelList[3].answerList[0].path = 0;
strcpy(levelList[3].answerList[0].text, "sala");
levelList[3].answerQuantity = 1;

levelList[4].id = 4;
strcpy(levelList[4].type, "normal");
strcpy(levelList[4].text, "** Voce entrou no quarto 1. **\nPara onde vc vai seguir?");
levelList[4].answerList[0].path = 2;
strcpy(levelList[4].answerList[0].text, "corredor");
levelList[4].answerQuantity = 1;

levelList[5].id = 5;
strcpy(levelList[5].type, "normal");
strcpy(levelList[5].text, "** Voce entrou no quarto 2. **\nPara onde vc vai seguir?");
levelList[5].answerList[0].path = 2;
strcpy(levelList[5].answerList[0].text, "corredor");
levelList[5].answerQuantity = 1;

levelList[6].id = 6;
strcpy(levelList[6].type, "normal");
strcpy(levelList[6].text, "** Voce entrou no quarto 3 e percebeu que existe um quadro na parede. **\nPara onde vc vai seguir?");
levelList[6].answerList[0].path = 2;
levelList[6].answerList[1].path = 7;
strcpy(levelList[6].answerList[0].text, "corredor");
strcpy(levelList[6].answerList[1].text, "investigar");
levelList[6].answerQuantity = 2;

levelList[7].id = 7;
strcpy(levelList[7].type, "normal");
strcpy(levelList[7].text, "** Voce retirou o quadro e acho um cofre! Acerte a combinação para achar o tesouro. **\n");
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
printf("---------------------------------------------------------------------------------------\n\n");
printf("   Voce entra numa casa abandonada na espera de encontrar algum tesouro antigo (ou pelo menos algo que possa vender por um preco razoavel).\n\n   Voce lembra do rosto do velho enquanto era levado pelas ambulacias: tao sem vida quanto a casa que ele morou nos ultimos 2 meses. \n   Ele havia se mudado pra vizinhanca apos ter sua casa no centro da cidade tomada por dividas, entao voce nao espera encontrar muita coisa dele, mas a casa esteve de pe por muitos anos antes e a familia Skalo que sempre a habitou nao parecia ser tao 'pe-rapada' quanto o velho senhor que provavelmente a conseguiu por uma pechincha. \n\n   O motivo pela mudanca de senhorio, ainda que peculiar, foi o que te trouxe aqui neste momento. \n   No ultimo ano, cada um dos 6 membros da familia Skalo faleceu de formas estranhas (para nao dizer suspeitas). A forma subita que as mortes se sucederam te fizeram imaginar que seus bens permaneceram na casa, ja que eram os ultimos integrantes da familia antiga, e roubar uma casa abandonada sem ninguem pra dar falta e muito melhor que invadir as residencias dos rostos conhecidos na regiao, sempre com o risco de ser pego ou reconhecido. \n\n   Hoje, ao ver as ambulancias saindo, voce decidiu tentar a sorte.\n\n\n   Agora, voce tem as seguintes opcoes:\n\n");


currentLevel = levelList[0]; // passo inicial - Level que o personagem está

// fazer while chamar a função makequestion

  while (currentLevel.type != "endgame") // enquanto não for fim de jogo
  {
  	
    for (int i = 0; i < currentLevel.answerQuantity; i++){ // fazer as perguntas para mudar de nível
        
    printf(currentLevel.answerList[i].text); // lista de respostas possíveis
    printf("\n");
   }   
    scanf("%s", &userAnswer);
    
    printf("\n\n Agora voce esta no/na %s. E tem as seguintes opcoes: \n\n", userAnswer);
  
  
}

// int suanne = sizeof(levelList[8].answerList)/sizeof(levelList[8].answerList[0]);
// printf("%d",suanne);
 
 printf("ESTOU SAINDO");


return 0;
}

