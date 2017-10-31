//Trabalho 1 - Disciplina: Algoritmos e Estrutura de Dados
//Data: 15/10/2017
//Alberice Lucas de Araújo nUSP 7986563
//Carlos Henrique de Carvalho Secato nUSP 9292890

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "lista.h"

//cria lista de alunos L
void cria_lista(Lista *L){
	L->qtd = 0;
}

//cria lista de livros LL
void cria_livros(ListaLivros *LL){
	LL->qtd = 0;
}

//esvazia lista de alunos L
void libera_lista(Lista* L){
	L->qtd = 0;
}

//esvazia lista de livros LL
void liberaLivros(ListaLivros *LL){
	LL->qtd = 0;
}

//consulda a posicao na lista L
int consulta_lista_pos(Lista* L, int pos, eleml *X){
	if(L == NULL || pos <= 0 ||  pos > L->qtd)
		return 0;
	*X = L->dados[pos-1];
	return 1;

}

//insere o elemento aluno na lista L. Returna 0 se erro, 1 se insercao correta
int insere_lista(Lista* L, eleml *X){

	if(L == NULL)
		return 0;
	if(L->qtd == TamLista)//lista cheia
		return 0;
	L->dados[L->qtd] = *X;
	L->qtd++;
	return 1;
}
//insere o elemento livro na lista LL. Retorna 0 se erro, 1 se insercao correta
int insereListaLivros(ListaLivros *LL, elemLivro *X){
	if(LL == NULL)
		return 0;
	if(LL->qtd == TamListaLivro)//lista cheia
		return 0;

	LL->dados[LL->qtd] = *X;
	LL->qtd++;
	return 1;


}

//remove o elemento aluno buscado pelo nome, e sobreescreve a posicao dele alterando todas as posicoes do vetor a partir do buscado
int remove_lista(Lista* L, char *nome){
	if(L == NULL)
		return 0;
	if(L->qtd == 0)
		return 0;

	int k,i = 0;
	while(i<L->qtd && strcmp(L->dados[i].nome, nome)!=0)
		i++;
	if(i == L->qtd)//elemento nao encontrado
		return 0;
	for(k=i; k< L->qtd-1; k++)
		L->dados[k] = L->dados[k+1];
	L->qtd--;
	return 1;
}

//remove o elemento livro buscado pelo titulo e exemplar, e sobreescreve a posicao dele alterando todas as posicoes do vetor a apartir do buscado
int removeListaLivro(ListaLivros *LL, char *titulo, int *exemplar){
	if(LL == NULL)
		return 0;
	if(LL->qtd == 0)
		return 0;

	int k,i = 0;
	while(i<LL->qtd && strcmp(LL->dados[i].titulo, titulo)!=0)// && LL->dados[i].exemplar != *exemplar)
		i++;
	if(i == LL->qtd)//elemento nao encontrado
		return 0;

	for(k=i; k< LL->qtd-1; k++)
		LL->dados[k] = LL->dados[k+1];
	LL->qtd--;
	return 1;

}

//retorna o tamanho da lista de alunos
int tamanho_lista(Lista* L){
	if(L == NULL)
		return -1;
	else
		return L->qtd;
}

//retorna se a lista de alunos esta cheia ou nao
int lista_cheia(Lista* L){
	if(L == NULL)
		return -1;
	return (L->qtd == TamLista);
}

//retorna se a lista de livros esta cheia ou nao
int listaLivro_cheia(ListaLivros *LL){
	if(LL == NULL)
		return -1;
	return(LL->qtd == TamListaLivro);
}

//retorna se a lista de alunos esta vazia
int lista_vazia(Lista* L){
	if(L == NULL)
		return -1;
	return (L->qtd == 0);
}

