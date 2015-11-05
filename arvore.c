#include <stdio.h>
#include <stdlib.h>
#include <string.h>

    struct No
{
    char Id[30];
    struct No *Esquerda;
    struct No *Direita;
};


struct No* AdicionarNo(struct No *Raiz, char Id[30])
{

    if (Raiz == (struct No*) NULL)
    {
        Raiz = (struct No*) malloc(sizeof(struct No));
        Raiz-> Id[30] = Id[30];
        Raiz-> Esquerda = (struct No*) NULL;
        Raiz-> Direita = (struct No*) NULL;
        return Raiz;
    }

    if (Id < Raiz-> Id)
        Raiz-> Esquerda = AdicionarNo(Raiz-> Esquerda, Id);
    else if (Id > Raiz-> Id)
        Raiz-> Direita = AdicionarNo(Raiz-> Direita, Id);    

    return Raiz;
}

void PreOrdem(struct No *NoAtual)
{
    if (NoAtual == (struct No*) NULL)
        return;

    printf("%s ", NoAtual->Id ); 
    PreOrdem(NoAtual-> Esquerda);
    PreOrdem(NoAtual-> Direita);
}

int main(){

struct No *Raiz = (struct No*) NULL;

    int opcao;
    while(1){

printf("Digite Uma Opção!\n");
printf("1- Construir Arvore Genealogica\n");
printf("2- Salvar\n");
printf("3- Abrir\n");
printf("4- Mostrar\n");
printf("5- Pesquisar\n");   

scanf("%i", &opcao);

switch(opcao){
    case 1:
        system("cls");
        char Id[30];
            printf("Digite um nome ");
            scanf("%s", &Id);

            Raiz = AdicionarNo(Raiz, Id);           
            system("cls");
        break;

            case 2:
                system("cls");
        printf("Salvar\n");
        break;

                    case 3:
                        system("cls");
        printf("Abrir\n");
        break;

                            case 4:
                                system("cls");
        printf("Mostrar\n");
         PreOrdem(Raiz);
            printf("\n");
            system("pause");
system("cls");
        break;

                                    case 5:
                                        system("cls");
        printf("Pesquisar\n");
        break;


     default:
        system("cls");
        printf("Digite uma opção valida\n");
        break;
}
}

}
