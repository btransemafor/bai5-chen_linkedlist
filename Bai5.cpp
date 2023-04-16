#include <iostream>
using namespace std;

struct Node
{
    int info;
    Node* pNext;
};

struct LIST
{
    Node* pHead;
    Node* ptail;
};

void CreateEmptyList(LIST& l)
{
    l.pHead = NULL;
    l.ptail = NULL;
}
void Init(LIST& L)
{
    L.pHead = L.ptail = NULL;
}

void pushTail(LIST& l, Node* p)
{
    if (l.pHead == NULL)
    {
        l.pHead = p;
        l.ptail = l.pHead;
    }
    else {
        l.ptail->pNext = p;
        l.ptail = p;
    }
}
Node* createNode(int x)
{
    Node* newNode = new Node;
    if (newNode == NULL) exit(1);
    newNode->info = x;
    newNode->pNext = NULL;
    return newNode;
}
void insertAfter(Node* node, int& Y)
{
    Node* newNode = new Node;
    newNode->info = Y;
    newNode->pNext = node->pNext;
    node->pNext = newNode;
}

void add_afterX_1(LIST& L, int  Y, int  X)
{
    for (Node* i = L.pHead; i != NULL; i = i->pNext)
        if (i->info == X)
        {
            insertAfter(i, Y);
            break;
        }
}

void PrintList(Node* p)
{
    if (p == NULL)
    {
        cout << "Empty List." << endl;
        return;
    }
    for (Node* i = p; i != NULL; i = i->pNext)
    {
        cout << i->info << " ";
    }
    cout << endl;
}
void CreateList(LIST& l)
{
    int n;
    cin >> n;
    while (n != -1)
    {
        Node* p = createNode(n);
        pushTail(l, p);
        cin >> n;
    }
}


int main() {
    LIST L;
    int X, Y;

    CreateEmptyList(L);

    CreateList(L);

    std::cin >> X >> Y;
    add_afterX_1(L, Y, X);

    PrintList(L.pHead);

    return 0;
}

