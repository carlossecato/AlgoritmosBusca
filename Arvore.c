#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <mem.h>
#include "Arvore.h"





//inicializa a �rvore, fazendo a raiz igual a NULL
void cria(Arvore *A) {
     A->raiz=NULL;
}

//verifica se a �rvore est� vazia
int IsEmpty(Arvore *A) {
    if (A->raiz==NULL)
       return 1;
    else return 0;
}

//busca x na �rvore, devendo iniciar com p=raiz ou outro ponto da �rvore
no* busca(no *p, elem *x) {
    no *aux;
    
    if (p==NULL)
       return(NULL);
    else if (p->info==*x)
         return(p);
    else {
         aux=busca(p->esq,x);
         if (aux==NULL)
            aux=busca(p->dir,x);
         return(aux);
    }    
}

//busca pai de x na �rvore, devendo iniciar com p=raiz ou outro ponto da �rvore
no* busca_pai(no *p, elem *x) {
    no *aux;
    
    if (p==NULL)
       return(NULL);
    else if ((p->esq!=NULL) && (p->esq->info==*x))
         return(p);
    else if ((p->dir!=NULL) && (p->dir->info==*x))
         return(p);
    else {
         aux=busca_pai(p->esq,x);
         if (aux==NULL)
            aux=busca_pai(p->dir,x);
         return(aux);
    }
}

//se poss�vel, insere x � esquerda de pai na �rvore
//se pai=-1, insere na raiz
void inserir_esq(Arvore *A, elem *x, elem *pai, int *erro) {
     no *aux, *p;
	if( *x != 32){
     if (*pai!=-1) {
        aux=busca(A->raiz,pai);
        if ((aux!=NULL) && (aux->esq==NULL)) {
           p=(no*) malloc(sizeof(no));
           if(*x != 32)
           p->info=*x;
           p->esq=NULL;
           p->dir=NULL;
           aux->esq=p;
           *erro=0;
        }
        else *erro=1;
     }
     else if (A->raiz==NULL) {
          p=(no*) malloc(sizeof(no));
          p->info=*x;
          p->esq=NULL;
          p->dir=NULL;
          A->raiz=p;
          *erro=0;
     }
 }    
     else *erro=1;
}

//se poss�vel, insere x � direita de pai na �rvore
//se pai=-1, insere na raiz
void inserir_dir(Arvore *A, elem *x, elem *pai, int *erro) {
     no *aux, *p;
    if( *x != 32){
     if (*pai!=-1) {
        aux=busca(A->raiz,pai);
        if ((aux!=NULL) && (aux->dir==NULL)) {
           p=(no*) malloc(sizeof(no));
           p->info=*x;
           p->esq=NULL;
           p->dir=NULL;
           aux->dir=p;
           *erro=0;
        }
        else *erro=1;
     }
     else if (A->raiz==NULL) {
          p=(no*) malloc(sizeof(no));
          p->info=*x;
          p->esq=NULL;
          p->dir=NULL;
          A->raiz=p;
          *erro=0;
     }
     else *erro=1;
}}

//imprime os elementos da �rvore
void imprimir(no *p) {
     if (p!=NULL) {
        printf("%c(",p->info);
        imprimir(p->esq);
        printf(",");
        imprimir(p->dir);
        printf(")");
     }
     else printf("null");
}

//fun��o para computar a altura de uma �rvore bin�ria; devo come�ar com p
//apontando para a raiz
int altura(no *p) {
    int alt_esq, alt_dir;

    if (p==NULL)
       return(0);
    else {
         alt_esq=1+altura(p->esq);
         alt_dir=1+altura(p->dir);
         if (alt_esq>alt_dir)
            return(alt_esq);
         else return(alt_dir);
    }
}

//libera toda a mem�ria usada na �rvore
void finaliza(no *p) {
     if (p!=NULL) {
        finaliza(p->esq);
        finaliza(p->dir);
        free(p);
     }
}

//fun��o que remove um elemento da �rvore, caso ele esteja nela
void remover(Arvore *A, elem *x, int *erro) {
     no *filho, *pai;
     int eh_filho_esq;
     
     //localizando o n� e o pai dele
     if ((A->raiz!=NULL) && (A->raiz->info==*x)) {
        pai=NULL;
        filho=A->raiz;
     }
     else {
          pai=busca_pai(A->raiz,x);
          if (pai!=NULL) {
             if ((pai->esq!=NULL) && (pai->esq->info==*x)) {
                filho=pai->esq;
                eh_filho_esq=1;
             }
             else {
                  filho=pai->dir;
                  eh_filho_esq=0;
             }
          }
          else filho=NULL;
     }
     
     if (filho==NULL)
        *erro=1;
     else {
          //primeiro caso: o n� n�o tem filhos
          if ((filho->esq==NULL) && (filho->dir==NULL)) {
             if (pai!=NULL) {
                if (eh_filho_esq)
                   pai->esq=NULL;
                else pai->dir=NULL;
             }
             else A->raiz=NULL;
             free(filho);
             *erro=0;
          }
          //segundo caso: o n� tem um ou dois filhos
          else {
               if (filho->esq!=NULL) {
                  filho->info=filho->esq->info;
                  filho->esq->info=*x;
               }
               else {
                    filho->info=filho->dir->info;
                    filho->dir->info=*x;
               }
               remover(A,x,erro);
          }
     }
}





//fun��o de percurso de pre-ordem na �rvore = busca em profundidade
void percurso_pre_ordem(no *p, char * c) {
    if (p != NULL){
        strcat(c, (const char *) &p->info);
        percurso_pre_ordem(p->esq, c);
        percurso_pre_ordem(p->dir, c);
    }
}

//fun��o para verificar se subarvore atende o requisito preordem
int is_percurso_pre_ordem(no *p){
    if (p!=NULL) {
        int i;
        char str[50]="";
        percurso_pre_ordem(p, str);
        printf("Percurso pre ordem -> %s\n", str);
        for (i = 1; i < strlen(str); ++i) {
            if (str[i] == 0){
                break;
            }
            if (str[i-1]>str[i]){
                return 0;
            }
        }
        return 1;
    }else{
        return 0;
    }
}

//fun��o de percurso de em-ordem na �rvore
void percurso_em_ordem(no *p, char * c) {
    if (p!=NULL) {
        percurso_em_ordem(p->esq, c);
        strcat(c, (const char *) &p->info);
        percurso_em_ordem(p->dir, c);
    }
}

//fun��o para verificar se subarvore atende o requisito em ordem
int is_percurso_em_ordem(no *p){
    if (p!=NULL) {
        int i;
        char str[50]="";
        percurso_em_ordem(p, str);
        printf("Percurso em ordem -> %s\n", str);
        for (i = 1; i < strlen(str); ++i) {
            if (str[i] == 0){
                break;
            }
            if (str[i-1]>str[i]){
                return 0;
            }
        }
        return 1;
    }else{
        return 0;
    }
}

//fun��o de percurso de pos-ordem na �rvore
void percurso_pos_ordem(no *p, char * c) {
    if (p!=NULL) {
        percurso_pos_ordem(p->esq, c);
        percurso_pos_ordem(p->dir, c);
        strcat(c, (const char *) &p->info);
    }
}

//fun��o para verificar se subarvore atende o requisito posordem
int is_percurso_pos_ordem(no *p){
    if (p!=NULL) {
        int i;
        char str[50]="";
        percurso_pos_ordem(p, str);
        printf("Percurso pos ordem -> %s\n", str);
        for (i = 1; i < strlen(str); ++i) {
            if (str[i] == 0){
                break;
            }
            if (str[i-1]>str[i]){
                return 0;
            }
        }
        return 1;
    }else{
        return 0;
    }
}



/*** fun��es necessarias para utilizar a estrutura de fila ***/

void CriaFila(Fila *F) {
     F->inicio=0;
     F->fim=0;
     F->total=0;
     return;
}

void EsvaziaFila(Fila *F) {
     F->inicio=0;
     F->fim=0;
     F->total=0;
     return;
}

int EstaVaziaFila(Fila *F) {
    if (F->total==0)
       return 1;
    else return 0;
}

int EstaCheiaFila(Fila *F) {
    if (F->total==TamFila)
       return 1;
    else return 0;
}

void EntraFila(Fila *F, no *X, int *erro) {
     if (!EstaCheiaFila(F)) {
          *erro=0;
          F->total++;
          F->itens[F->fim]=X;
          if (F->fim==TamFila-1) F->fim=0;
          else F->fim++;
     }
     else *erro=1;
     return;
}

void SaiFila(Fila *F, no **x, int *erro) {
     if (!EstaVaziaFila(F)) {
          *erro=0;
          F->total--;
          *x= (F->itens[F->inicio]);
          if (F->inicio==TamFila-1) F->inicio=0;
          else F->inicio++;
     }else {
    	 *erro=1;
     }
     return;
}



//FUN��O QUE VERIFICA SE A ARVORE ESTA CHEIA
int EstaArvoreCheia(no* p){
    if (p==NULL)
        return(0);
    else{
        Fila F;
        CriaFila(&F);
        int erro = 0;
        EntraFila(&F,p,&erro);
        no *n = NULL;
        while (F.total > 0) {
            SaiFila(&F,&n,&erro);
            if(n->esq != NULL ){
                EntraFila(&F,n->esq,&erro);
            }
            if(n->dir != NULL){
                EntraFila(&F,n->dir,&erro);
            }
            if ((n->esq == NULL && n->dir != NULL) ||
                    (n->esq != NULL && n->dir == NULL)){
                EsvaziaFila(&F);
                return 0;
            }
        }
        EsvaziaFila(&F);
        return 1;
    }
}

//fun��o para verificar se uma arvore � do tipo ABB
int IsABB(no* p){
    if (p==NULL)
        return(0);
    else{
        Fila F;
        CriaFila(&F);
        int erro = 0;
        EntraFila(&F,p,&erro);
        no *n = NULL;
        while (F.total > 0) {
            SaiFila(&F,&n,&erro);
            if(n->esq != NULL ){
                EntraFila(&F,n->esq,&erro);
                if(n->esq->info > n->info){
                    EsvaziaFila(&F);
                    return 0;
                }
            }
            if(n->dir != NULL){
                EntraFila(&F,n->dir,&erro);
                if(n->info > n->dir->info){
                    EsvaziaFila(&F);
                    return 0;
                }
            }
        }
        EsvaziaFila(&F);
        return 1;
    }
}

//fun��o responsavel por inserir uma string em camadas por uma arvore
void inserirLarguraRecursivo(no** n, int raiz, char * str){
    if (raiz >strlen(str)){ // igual a zero ou EOF ou int maior que comprimento da string
        return;
    }
    char c = str[raiz-1]; //convers�o de posicao n� para posi��o no array
    if (*n == NULL && c != 0 && c != 32){
        criarNo(&(*n));
        if (&(*n) == NULL){
            printf("erro criarNo");
        }
        (*n)->info=c;
        inserirLarguraRecursivo(&(*n)->esq, raiz*2, str);
        inserirLarguraRecursivo(&(*n)->dir, (raiz*2)+1, str);
    }else{
        (*n)=NULL;
    }
}





