#include<stdlib.h>
#include<stdio.h>

struct simb                      
	{
		char ch;             
		struct simb * prox;      
	};

struct arvore                       
	{
		char ch;
		struct arvore * dir;
		struct arvore * esq;
	};
void criaarvore(struct arvore*raiz, struct simb*operador, struct simb*numero){
                                            
	if(operador==NULL || numero==NULL){     
		return;
	}
                                            
    struct arvore*esquerda = (struct arvore*)malloc(sizeof(struct arvore));
	esquerda->ch = operador->ch;
	esquerda->dir = NULL;                   
	esquerda->esq = NULL;
	struct arvore*direita = (struct arvore*)malloc(sizeof(struct arvore));
	direita->ch = numero->ch;
	direita->dir = NULL;                    
	direita->esq = NULL;
	//?
}

void insercao(struct arvore* no, char key){
    struct arvore *p = no;
    
    struct arvore *pai = NULL;
     
    while(p != NULL) {
        pai = p;
        if (p->chave >= key) {
            p = p->esq;
        } else {
            p= p->dir;
        }
    }
 
	struct arvore *novo = (struct arvore*)malloc(sizeof(struct arvore));     
	novo->chave = key;
	novo->dir = NULL;
	novo->esq = NULL;
     
    if(pai->chave >= novo->chave){
        pai->esq=novo;
    }   
    else{
        pai->dir=novo;
        }
} 
emordem(struct arvore*no) //vai passar por todas as chaves, em ordem crescente.
{
	if(no!=NULL)
	{
		emordem(no->esq); //se aqui fosse dir, e embaixo esq, iria imprimir em ordem decrescente
		printf(" %c",no->chave);
		emordem(no->dir);
	}
}


void labelledbracketing(struct arvore*no){	    
	                                
	 if(no->dir==NULL &&no->esq==NULL){
        printf(" %c",no->ch);               
    }
	if(no->dir!=NULL){              
		printf(" (");               
		labelledbracketing(no->dir);        
		printf(" %c",no->esq->ch);           
		printf(" %c",no->ch);               
		printf(" )");               
	}
	                                //fecha o no
}

void main(){
	int n;
	printf("Quantos numeros serao colocados no programa?");
	scanf("%i", &n);
	char ch[100];
	struct arvore * raiz = (struct arvore*) malloc(sizeof(struct arvore));	
	int i=0;
	printf("Coloque sua formula em notacao polonesa\n");
	scanf("%s", ch);
	printf("Notacao polonesa: %s", ch);
	raiz->chave=ch[0];
	while(ch[i] != 0){
		printf("%c", ch[i]);
		i++;
	}
}
