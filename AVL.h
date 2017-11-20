//declaração do nó da árvore
typedef int elem;

typedef struct bloco_avl {
        elem info;
        int fb;
        struct bloco_avl *esq, *dir;
} no_avl;

typedef struct {
        no_avl *raiz_avl;
} AVL;


//protótipos das funções
void criar(AVL*);
//void finalizarAVL(no_avl**);
void imprimirAVL(no_avl**);
int inserir_avl(no_avl**,int*);
int buscar(no_avl**,int*);
