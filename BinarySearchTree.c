
#include <stdio.h>
#include <stdlib.h>

struct bstNode
{
    struct bstNode *lChild;
    int data;
    struct bstNode *rChild;
} *root = NULL;

void Preorder(struct bstNode *p)
{
    if (p)
    {
        printf("%d -> ", p->data);
        Preorder(p->lChild);
        Preorder(p->rChild);
    }
}

void Inorder(struct bstNode *p)
{
    if (p)
    {
        Inorder(p->lChild);
        printf("%d -> ", p->data);
        Inorder(p->rChild);
    }
}

void Postorder(struct bstNode *p)
{
    if (p)
    {
        Postorder(p->lChild);
        Postorder(p->rChild);
        printf("%d -> ", p->data);
    }
}

void Search(int key)
{
    struct bstNode *t = root;

    while (t != NULL)
    {
        if (key == t->data)
        {
            printf("\nKey %d is found!", key);
            return;
        }
        else if (key < t->data)
            t = t->lChild;
        else
            t = t->rChild;
    }
    printf("\nEntered key %d is NOT found!", key);
}

struct bstNode *RInsert(struct bstNode *p, int key)
{
    struct bstNode *t = NULL;

    if (p == NULL)
    {
        t = (struct bstNode *)malloc(sizeof(struct bstNode));
        t->data = key;
        t->lChild = t->rChild = NULL;
        return t;
    }
    if (key < p->data)
        p->lChild = RInsert(p->lChild, key);
    else if (key > p->data)
        p->rChild = RInsert(p->rChild, key);

    return p;
}

int Height(struct bstNode *p)
{
    int x, y;
    if (p == NULL)
        return 0;
    x = Height(p->lChild);
    y = Height(p->rChild);
    return x > y ? x + 1 : y + 1;
}

struct bstNode *InPre(struct bstNode *p)
{
    while (p && p->rChild != NULL)
        p = p->rChild;

    return p;
}

struct bstNode *InSucc(struct bstNode *p)
{
    while (p && p->lChild != NULL)
        p = p->lChild;

    return p;
}

struct bstNode *Delete(struct bstNode *p, int key)
{
    struct bstNode *q;

    if (p == NULL)
        return NULL;
    if (p->lChild == NULL && p->rChild == NULL)
    {
        if (p == root)
            root = NULL;
        free(p);
        return NULL;
    }

    if (key < p->data)
        p->lChild = Delete(p->lChild, key);
    else if (key > p->data)
        p->rChild = Delete(p->rChild, key);
    else
    {
        if (Height(p->lChild) > Height(p->rChild))
        {
            q = InPre(p->lChild);
            p->data = q->data;
            p->lChild = Delete(p->lChild, q->data);
        }
        else
        {
            q = InSucc(p->rChild);
            p->data = q->data;
            p->rChild = Delete(p->rChild, q->data);
        }
    }
    return p;
}

void main()
{
    struct bstNode *temp;
    int ch, n;

    printf("\nOPERATIONS ~");
    printf("1 - To Insert an element into tree\n");
    printf("2 - To Delete an element from the tree\n");
    printf("3 - To Search an element\n");
    printf("4 - Inorder Traversal\n");
    printf("5 - Preorder Traversal\n");
    printf("6 - Postorder Traversal\n");
    printf("0 - To Exit!\n");

    do
    {
        printf("\n\nEnter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter data to insert: ");
            scanf("%d", &n);
            if (root == NULL)
                root = RInsert(root, n);
            else
                RInsert(root, n);
            break;
        case 2:
            printf("Enter the data to be deleted: ");
            scanf("%d", &n);
            Delete(root, n);
            break;
        case 3:
            printf("Enter data to be searched: ");
            scanf("%d", &n);
            Search(n);
            break;
        case 4:
            Inorder(root);
            break;
        case 5:
            Preorder(root);
            break;
        case 6:
            Postorder(root);
            break;
        case 0:
            exit(0);
        default:
            printf("Invalid Choice!\n");
        }
    } while (ch != 0);
}