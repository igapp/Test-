#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* right;
    struct node* left;
} node;

void input(int, node*);
void view(node*);
int pause();
void clear();

node* root = NULL;

void main() {
    int pil, n, lanjut = 1;

    do {
        clear();
        printf("Program Binary Tree\n");
        printf("Menu : \n");
        printf(" 1. Input Data\n");
        printf(" 2. View Data\n");
        printf(" 3. Keluar\n");
        printf("Masukan Pilihan : ");
        scanf("%d", &pil);

        switch (pil) {
        case 1:
            printf("\nMasukan Data : ");
            scanf("%d", &n);
            input(n, root);
            break;
        case 2:
            printf("\nData : ");
            view(root);
            lanjut = pause();
            break;
        case 3:
            break;
        default:
            break;
        }
    } while (pil != 3 && lanjut == 1);
}

void input(int i, node* parent) {
    node* now = NULL;
    node* new = (node*)malloc(sizeof(node));
    new->data = i;
    new->left = new->right = NULL;

    if (root == NULL) {
        root = new;
        return;
    }

    while (1)
        if (i < parent->data) {
            if (parent->left == NULL) {
                parent->left = new;
                return;
            }
            parent = parent->left;
        } else {
            if (parent->right == NULL) {
                parent->right = new;
                return;
            }
            parent = parent->right;
        }
}

void view(node* now) {
    if (now != NULL) {
        printf("%d ", now->data);
        view(now->left);
        view(now->right);
    }
}

void clear() {
#ifdef _WIN32
    std : system("cls");
#else
std: system("clear");
#endif
}

int pause() {
    char pil;
    printf("\nLanjutkan? (y/t) : ");
    fflush(stdin);
    scanf("%c", &pil);

    if (pil == 'y') return 1;
    else return 0;
}
