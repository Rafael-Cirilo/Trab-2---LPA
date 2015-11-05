#include<stdio.h>
#include<stdlib.h>

struct simb //Aqui definimos como será cada símbolo matemático da espressão polonesa         
	{
		char ch;             
		struct simb * prox;// É importante saber qual é o próximo elemento da expressão  
	};

struct arvore //Definimos a árvore                   
	{
		char ch;
		struct arvore * dir;
		struct arvore * esq;
	};

void emordem(struct arvore*no){ //Aqui temos o emordem do 1ºexercicio
	if(no!=NULL){
		emordem(no->dir);       
		printf(" %c",no->ch); 
		emordem(no->esq);       
	}
}

void labelledbracketing(struct arvore*no){//Aqui temos um labelledbracketing parecido com o do 1º exercicio porem com algumas alterações 
	                                
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

void addsimb(struct simb*inicial, char ch){ //Nessa função adicionamos os símbolos matemáticos   

	if(inicial->prox==NULL){                                
		struct simb*novo = (struct simb*)malloc(sizeof(struct simb));// Alocamos memoria para o novo símbolo, então o criamos 
		novo->ch = ch; //Colocamos o símbolo                       
		novo->prox = NULL;//"Aterramos" o símbolo
		inicial->prox = novo;                               
	}

	else{
		addsimb(inicial->prox, ch);
	}

}

struct simb * novo_numero(struct simb*prox, char valor){    

	struct simb*novo = (struct simb*)malloc(sizeof(struct simb));//Alocamos memoria para o novo numero, então o criamos.
	novo->ch = valor;//colocamos seu valor.
	novo->prox = prox;                    
	return(novo);

}

void criaarvore(struct arvore*raiz, struct simb*soma, struct simb*num){//Nessa função criamos a arvore, sempre tendo a raiz, a operação(soma) e o numero.
                                            
	if(soma==NULL || num==NULL){     
		return;
	}
                                            
    struct arvore*esq = (struct arvore*)malloc(sizeof(struct arvore));//Alocamos memoria para a arvore.
	esq->ch = soma->ch;//inserimos o simbolo da operação, colocando-o no ch. 
	esq->dir = NULL;                   
	esq->esq = NULL;
	struct arvore*dir = (struct arvore*)malloc(sizeof(struct arvore));//Alocamos memoria para inserir o numero na arvore.
	dir->ch = num->ch;//idem para o numero
	dir->dir = NULL;                    
	dir->esq = NULL;

	raiz->esq = esq;//fazemos a ligação da raiz com os "galhos" criados              
	raiz->dir = dir;

	criaarvore(dir, soma->prox, num->prox);     
}





void main () {

	printf("Digite a equacao polonesa:\n");//Pedimos para a pessoa digitar a equação

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
	criaarvore(raiz,first_simbol,first_number->prox);//Criamos a árvore                                  
    printf("\nRPN:\n");                                                         
    emordem(raiz);//Chamamos a função emordem
    printf("\nInfixa:\n");
    labelledbracketing(raiz);//Chamamos a função labbeled bracketing

}
