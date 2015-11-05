#include<stdlib.h>
#include<stdio.h>
 
struct arvore{//Definimos uma árvore que nem mostrado em aula
int chave;
struct arvore *esq;
struct arvore *dir;
};
 
 
struct arvore*busca(struct arvore*raiz, int chave){//Aqui temos a busca de um determinado numero da arvore
    if(raiz==NULL){return NULL;}
    if(raiz->chave==chave){
        return raiz;
    }
    if(chave>=raiz->chave){
        return busca(raiz->dir, chave);}
    if(chave < raiz->chave){
        return busca(raiz->esq, chave);
    }
}
 
void insercao(struct arvore* no, int key){//Aqui inserimos um determinado valor na árvore, assim como explicado em aula
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
		emordem(no->esq); 
		printf(" %d",no->chave);
		emordem(no->dir);
	}
}
preordem(struct arvore*no)//Aqui temos o preordem
{
	if(no!=NULL)
	{
		printf(" %d",no->chave); 
		preordem(no->esq);
		preordem(no->dir);
	}
}
posordem(struct arvore*no)//Aqui temos o posordem
{
	if(no!=NULL)
	{
		posordem(no->esq);
		posordem(no->dir);
		printf(" %d",no->chave);
	}
}
void remocao(struct arvore *no, int chave){//Nesse temos a remoção
    struct arvore *p = no;
    struct arvore *pai = NULL;
     
    while(p != NULL && p->chave != chave) {
        pai = p;
        if (p->chave >= chave) {
            p = p->esq;
        } else {
            p = p->dir;
        }
    }
        if(p == NULL){
        		 printf("O valor não esta na arvore");
                 return;
    }
    struct arvore *m = p->dir;
    while(m != NULL && m->esq != NULL){
            m = m->esq;
    }
    struct arvore *n;
        if(m != NULL){
        m -> esq = p -> esq;
        n = p->dir;
    } else {
        n = p->esq;
    }
        if(pai->chave < chave) {
        pai->dir = n;
    } else {
        pai->esq = n;
    }
    free(p);
}
void menu(struct arvore *raiz){ //O menu a fim de saber se haverá remoção de alguem
 	char c;
	int k;
	while(c!='s' && c!='S' && c!= 'N' && c!='n'){
	
	printf("Deseja remover algum valor?<S/N>");
	
	scanf("%c", &c);
	if(c == 's' || c == 'S'){
		printf("Qual valor?");
		scanf("%d", &k);
		remocao(raiz , k);
		menu(raiz);
	}else if(c=='n' || c=='N'){
		break;
	}
	}
 }
void labelledbracketing(struct arvore*no){	    //função que imprime a arvore em labelled bracketing
	printf("[");                                
	if(no!=NULL){                               
		printf("%d",no->chave);                   
		labelledbracketing(no->esq);            
		labelledbracketing(no->dir);		    
	}
	printf("]");                                
}
 
void main(){
	struct arvore * raiz = (struct arvore*) malloc(sizeof(struct arvore));//Alocamos memoria para a arvore
	raiz->esq = NULL;
	raiz->dir = NULL;
	printf("Quantos valores haverá?");//descobrimos o numero de valores que serao colocados
	int i;
	scanf("%d",&i);
	printf("\nO valor 1 eh:");
	scanf("%d", &raiz->chave);
   	int n, valor;
	for(n = 2 ; n <= i ; n++){
		printf("\nO valor %d eh:",n);
		scanf("%d",&valor);
		insercao(raiz , valor);
	}
	menu(raiz);
	
	
	
	emordem(raiz);//Chamamos as funções que nós criamos
	printf("\n");
	preordem(raiz);
	printf("\n");
	posordem(raiz);
	printf("\n");
	labelledbracketing(raiz);

}
