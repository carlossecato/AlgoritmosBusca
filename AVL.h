//declara��o do n� da �rvore
typedef int elem;

typedef struct bloco_avl {
        elem info;
        int fb;
        struct bloco_avl *esq, *dir;
} no_avl;

typedef struct {
        no_avl *raiz_avl;
} AVL;


//prot�tipos das fun��es
void criar(AVL*);
//void finalizarAVL(no_avl**);
void imprimirAVL(no_avl**);
int inserir_avl(no_avl**,int*);
int buscar(no_avl**,int*);
