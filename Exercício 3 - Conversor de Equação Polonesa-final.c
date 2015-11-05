#include<stdio.h>
#include<stdlib.h>

struct simb //Aqui definimos como ser� cada s�mbolo matem�tico da espress�o polonesa         
	{
		char ch;             
		struct simb * prox;// � importante saber qual � o pr�ximo elemento da express�o  
	};

struct arvore //Definimos a �rvore                   
	{
		char ch;
		struct arvore * dir;
		struct arvore * esq;
	};

void emordem(struct arvore*no){ //Aqui temos o emordem do 1�exercicio
	if(no!=NULL){
		emordem(no->dir);       
		printf(" %c",no->ch); 
		emordem(no->esq);       
	}
}

void labelledbracketing(struct arvore*no){//Aqui temos um labelledbracketing parecido com o do 1� exercicio porem com algumas altera��es 
	                                
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
	                                
}

void addsimb(struct simb*inicial, char ch){ //Nessa fun��o adicionamos os s�mbolos matem�ticos   

	if(inicial->prox==NULL){                                
		struct simb*novo = (struct simb*)malloc(sizeof(struct simb));// Alocamos memoria para o novo s�mbolo, ent�o o criamos 
		novo->ch = ch; //Colocamos o s�mbolo                       
		novo->prox = NULL;//"Aterramos" o s�mbolo
		inicial->prox = novo;                               
	}

	else{
		addsimb(inicial->prox, ch);
	}

}

struct simb * novo_numero(struct simb*prox, char valor){    

	struct simb*novo = (struct simb*)malloc(sizeof(struct simb));//Alocamos memoria para o novo numero, ent�o o criamos.
	novo->ch = valor;//colocamos seu valor.
	novo->prox = prox;                    
	return(novo);

}

void criaarvore(struct arvore*raiz, struct simb*soma, struct simb*num){//Nessa fun��o criamos a arvore, sempre tendo a raiz, a opera��o(soma) e o numero.
                                            
	if(soma==NULL || num==NULL){     
		return;
	}
                                            
    struct arvore*esq = (struct arvore*)malloc(sizeof(struct arvore));//Alocamos memoria para a arvore.
	esq->ch = soma->ch;//inserimos o simbolo da opera��o, colocando-o no ch. 
	esq->dir = NULL;                   
	esq->esq = NULL;
	struct arvore*dir = (struct arvore*)malloc(sizeof(struct arvore));//Alocamos memoria para inserir o numero na arvore.
	dir->ch = num->ch;//idem para o numero
	dir->dir = NULL;                    
	dir->esq = NULL;

	raiz->esq = esq;//fazemos a liga��o da raiz com os "galhos" criados              
	raiz->dir = dir;

	criaarvore(dir, soma->prox, num->prox);     
}





void main () {

	printf("Digite a equacao polonesa:\n");//Pedimos para a pessoa digitar a equa��o

	char c;
	int i=0,j=1;

	scanf("%c",&c); 

	struct simb*first_simbol = (struct simb*)malloc(sizeof(struct simb)); //Alocamos memoria   
	first_simbol->ch = c;
	first_simbol->prox = NULL;

	while(i==0){//Coletamos o primeiro simbolo
		scanf("%c",&c); 
			if(c=='+'||c=='-'||c=='/'||c=='*'||c=='^'){
				addsimb(first_simbol,c);               
				j++;
			}else{
			i=1;
		}
}
	struct simb*first_number = (struct simb*)malloc(sizeof(struct simb)); //Alocamos memoria para o primeiro numero   
	first_number->ch = c;
	first_number->prox = NULL;
	for (i=0;i<j;i++){//Coletamos o primeiro numero
		scanf("%c",&c);     
		if(c!=' '){
            first_number = novo_numero(first_number,c); 
		}
		else {
            i--;
		}
	}

	struct arvore*raiz = (struct arvore*)malloc(sizeof(struct arvore));//Alocamos memoria para a raiz   
	raiz->ch = first_number->ch;                                        
	raiz->esq = NULL;
	raiz->dir = NULL;
	criaarvore(raiz,first_simbol,first_number->prox);//Criamos a �rvore                                  
    printf("\nRPN:\n");                                                         
    emordem(raiz);//Chamamos a fun��o emordem
    printf("\nInfixa:\n");
    labelledbracketing(raiz);//Chamamos a fun��o labbeled bracketing

}
