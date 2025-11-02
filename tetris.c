#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define sizeList 5
// Estrutura da peça
typedef struct {
    char type; 
    int id;   
} Piece;
//vetor sobre a lista de peca
typedef struct {
    Piece list[sizeList];
    int start;
    int end;
    int quantity;
} ListOfPieces;

ListOfPieces listofpeaces ;
int OptionSelected;

int idGenerator() ;
void startListOfPieces(ListOfPieces *listofpeaces) ;
void  showListOfPieces(ListOfPieces *listofpeaces);
void Options(int option);
void showMenu();
void playPeace(ListOfPieces *listofpeaces);
void insertPeace(ListOfPieces *listofpeaces) ;
Piece pieceGenerator();
//gerador de id
int idGenerator() {
    int id = 00001 + rand() % 90000;
    return id;
}
//exibe menu de opcoes
void showMenu()
{
    printf("\n1 - Jogar uma peca \n");
    printf("2 - Inserir uma nova peca \n");
    printf("3 - Visualizar a Fila de pecas\n");
    printf("0 - Sair \n");
    printf("\nDigite o Numero da opcao desejada e aperte ENTER : ");
    do
    {
        scanf("%d", &OptionSelected);
        getchar();
        if (OptionSelected < 0 || OptionSelected > 3)
        {
            printf("opcao incorreta! \n");
            printf("Digite novamente: ");
        }
    } while (OptionSelected < 0 || OptionSelected > 3);
    Options(OptionSelected);
}
//executa a opcao selecionada
void Options(int option)
{
    switch (option)
    {
    case 1:
    playPeace(&listofpeaces) ;
        break;
    case 2:
    insertPeace(&listofpeaces);
        break;
    case 3:
    showListOfPieces(&listofpeaces);
        break;
    case 0:
    printf("Saindo .. \n");
        exit(0);
        break;
    default:
        printf("Opcao invalida !\n");
        break;
    }
}
//gerador de peca
Piece pieceGenerator() {
    char typesOfPieces[] = {'I', 'O', 'T', 'L'};
    Piece newPiece;
    newPiece.type = typesOfPieces[rand() % 4];
    newPiece.id = idGenerator();
    return newPiece;
}
//inicia a lista de peças
void startListOfPieces(ListOfPieces *fp) {
    fp->start = 0;
    fp->end = 0;
    fp->quantity = 0;
    for (int i = 0; i < sizeList; i++) {
        fp->list[fp->end] = pieceGenerator();
        fp->end = (fp->end + 1) % sizeList;
        fp->quantity++;
    }
}
//exibe a lista de peças
void showListOfPieces(ListOfPieces *listofpeaces) {
    printf("= = = = = = = = = Fila de Pecas = = = = = = = = =\n");
    int i = listofpeaces->start;
if (listofpeaces->quantity == 0) 
{
   printf("Fila vazia no momento"); 
}
else{
    for (int count = 0; count < listofpeaces->quantity; count++) {
     printf("[ %c %d ] ", listofpeaces->list[i].type, listofpeaces->list[i].id);
        i = (i + 1) % sizeList;
    }
    }
printf("\n");
    showMenu();
}

//jogar uma peça(remove a peça da frente)
void playPeace(ListOfPieces *listofpeaces) {
    if (listofpeaces->quantity == 0) {
        printf("Fila vazia. Nenhuma peca para jogar.\n");
        return;
    }
    printf("Peca jogada : [ %c %d ]\n\n", listofpeaces->list[listofpeaces->start].type, listofpeaces->list[listofpeaces->start].id);
    listofpeaces->start = (listofpeaces->start + 1) % sizeList;
    listofpeaces->quantity -- ;
        showListOfPieces(listofpeaces);
}
//insere uma nova peça
void insertPeace(ListOfPieces *listofpeaces) {
    if (listofpeaces->quantity == sizeList) {
        printf("Fila cheia. Nao e possivel inserir nova peca.\n");
    }
    else
    {
    listofpeaces->list[listofpeaces->end] = pieceGenerator();
        printf("Peca inserida : [ %c %d ]\n\n",listofpeaces->list[listofpeaces->end].type,listofpeaces->list[listofpeaces->end].id); 
    listofpeaces->end = (listofpeaces->end + 1) % sizeList;
    listofpeaces->quantity++ ;
}
        showListOfPieces(listofpeaces);
        showMenu();
}

int main(){
// Inicializa o gerador de números aleatórios p/ fazer id
srand(time(NULL));
startListOfPieces(&listofpeaces);
    printf("= = = = = = = = = = = = = = = = = = = = == = = =\n");
    printf("                      Tetris                    \n");
    printf("= = = = = = = = = = = = = = = = = = = = == = = =\n");
showMenu();
return 0;
}
