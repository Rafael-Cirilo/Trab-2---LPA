	#include<stdio.h>
	#include<stdlib.h>
	//Diferentemente do que foi pedido, opteinpor utilizar uma forma mais organizada de se colocar pessoas na árvore
		struct pessoa{//Definimos uma pessoa
			char *nome;
			int geracao;
			struct pessoa *esq;
			struct pessoa *dir;
		};
		struct ponteiro{//Criamos um "ponteiro"
			struct pessoa *ponteiro;
		};
	
	
		void notemordem(struct pessoa *no, struct ponteiro p, char  *chave) //Uma variação do emordem que permite localizar o lugar onde está a pessoa
		{
			if(no!=NULL)
			{
				notemordem(no->esq, p, chave); 
				if(no->nome=chave){
					p.ponteiro=no;
				}
				notemordem(no->dir, p , chave);
			}
		}
		
	void insira(struct pessoa *no){//Aqui inserimos o pai e a mae de cada pessoa
		
		char*pai;
		char*mae;
		struct pessoa *novo = (struct pessoa*)malloc(sizeof(struct pessoa));//Alocamos memória
		printf("\nInsira sua mae:\n");	
		gets(mae);
		novo->nome = mae;
		novo->geracao = no->geracao +1	 ; //A geração dos pais sempre será 1 a mais do que a dos filhos   
		novo->dir = NULL;
		novo->esq = NULL;
		no->esq = novo;
		printf("%s",no->esq->nome);
		    
	    struct pessoa *noov = (struct pessoa*)malloc(sizeof(struct pessoa));//Alocamos memoria para o pai tambem
	    printf("\nInsira seu pai:\n");	
		gets(pai);
		noov->nome = pai;	 
		noov->dir = NULL;
		noov->esq = NULL;
		no->dir = noov;
		printf("%s", no->dir->nome);
	    
	} 
		void adiciona(struct pessoa *raiz){//Aqui temos apenas como localizar a pessoa cujos pais serão adicionados
			char *nome;
			struct ponteiro k;
			printf("Adicionar os pais de quem?");
			gets(nome);
			notemordem(raiz, k , nome);
			k.ponteiro->nome=nome;
			insira(k.ponteiro);//Aqui mandamos o filho para a inserção dos pais
			
		}
	void emordem(struct pessoa*no) //Imprimimos os antepassados de uma pessoa. Uma vez que não é possível voltar no emordem, basta fazer com que a raiz seja a pessoa cujos antepassados desejamos saber
{
	if(no!=NULL)
	{
		emordem(no->esq); 
		printf("%s", no->nome);
		emordem(no->dir);
	}
}
 	void print_gen(struct pessoa*no, int geracao){//Aqui descobrimos as pessoas de uma geração específica
 		if(no!=NULL || no->geracao <= geracao){
 			print_gen(no->esq, geracao);
 			if(no->geracao==geracao){
 				printf("%s", no->nome);
			 }
			 print_gen(no->dir, geracao);
		 }
 		
	 }
	void imprimir_lb(struct pessoa* no){//Aqui temos o labbelbracketing
	printf("[");
	if(no != NULL){
		printf("%s", no->nome);
		if(no->esq != NULL){
			imprimir_lb(no->esq);
			printf(" ");
		}
		if(no->dir != NULL){
			imprimir_lb(no->dir);
		}
	}
	printf("]");
	}
	
	void grau(struct pessoa* p1, struct pessoa* p2, int i){//Aqui descobrimos o grau de parentesco de duas pessoas
			if(p1!=NULL)
	{
		if(p1=p2){
			printf("O grau de parentesco eh %d", p2->geracao-i);
		}
		grau(p1->esq, p2, i); 
		
		grau(p1->dir, p2, i);
	}
		
	}
	void main(){
		char nome[10];
		char nome1[10];
		char nome2[10];
		int d;
		char i,h;
		struct ponteiro p;
		struct ponteiro q;
		struct pessoa *raiz=(struct pessoa *)malloc(sizeof(struct pessoa));//Alocamos memoria para a raiz da arvore
		printf("Qual a primeira pessoa da arvore genealógica?\n");
		gets(nome);
		raiz->nome=nome;
		raiz->geracao = 0;
		printf("%s\n", raiz->nome);	
		insira(raiz);//Começamos a raiz propriamente aqui
		
		printf("Adicionar mais alguem? <S/N>");
		scanf("%c", &h);
		if(h=='S' || h=='s'){
			adiciona(raiz);
		}
		
		printf("Deseja fazer mais alguma coisa? \n1-)imprimir os membros por geracao \n2-)imprimir os antepassados de alguem \n ");
		printf("3-) imprimir labelled bracketing \n4-) calcular grau de parentesco \n5-) encerrar programa\n");//Aqui temos o menu
		scanf("%c",&i);
		
		if(i='1'){
		
				printf("Qual geracao?");
				scanf("%i", &d);
				print_gen(raiz,d);
		}
		else if(i='2'){
		
			
				printf("De quem?");
				gets(nome);
				emordem(raiz);
		}
		
			else if(i='3'){
			
				imprimir_lb(raiz);
			}
		
			else if(i='4'){
			
				printf("Pessoa 1:");
				gets(nome1);
				printf("Pessoa 2");
				gets(nome2);
				
				
				
				if(p.ponteiro->geracao > q.ponteiro->geracao){
					grau(q.ponteiro, p.ponteiro, q.ponteiro->geracao);
				}else{
					grau(p.ponteiro,q.ponteiro, p.ponteiro->geracao);
				}
			}
			else{
				printf("Bye Bye");
			}
		}
		
