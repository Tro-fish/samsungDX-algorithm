#include <iostream>
using namespace std;
#define MAX_NODE 10000

struct Node
{
    int data;
    Node *prev;
    Node *next;
};

Node node[MAX_NODE];
int nodeCnt;
Node *head;

Node *getNode(int data)
{
    node[nodeCnt].data = data;
    node[nodeCnt].prev = nullptr;
    node[nodeCnt].next = nullptr;
    return &node[nodeCnt++];
}

void init()
{
    head = new Node;
    head->next = nullptr;
    head->prev = nullptr;
}

void addNode2Head(int data)
{
    Node *newNode = getNode(data);
    if (head->next == nullptr)
    {
        head->next = newNode;
        newNode->prev = head;
    }
    else
    {
        head->next->prev = newNode;
        newNode->next = head->next;
        head->next = newNode;
        newNode->prev = head;
    }
}

void addNode2Tail(int data)
{
    Node *lastNode = head;
    if (lastNode->next == nullptr) // head가 null일 때
    {
        addNode2Head(data);
    }
    else
    {
        while (lastNode->next != nullptr)
        {
            lastNode = lastNode->next;
        }
        Node *newNode = getNode(data);
        lastNode->next = newNode;
        newNode->prev = lastNode;
    }
}

void addNode2Num(int data, int num)
{
    if (num == 1)
    {
        addNode2Head(data);
    }
    else
    {
        Node *insertPos = head;
        for (int i = 1; i < num; i++)
        {
            insertPos = insertPos->next;
        }
        Node *newNode = getNode(data);
        insertPos->next->prev = newNode;
        newNode->next = insertPos->next;
        insertPos->next = newNode;
        newNode->prev = insertPos;
    }
}

int findNode(int data)
{
    Node *IndexNode = head;
    int count = 1;
    while (IndexNode->next != nullptr)
    {
        if (IndexNode->next->data == data)
        {
            break;
        }
        IndexNode = IndexNode->next;
        count++;
    }
    return count;
}

void removeNode(int data)
{
    Node *IndexNode = head;
    while (IndexNode->next != nullptr)
    {
        if (IndexNode->next->data == data)
        {
            if (IndexNode->next->next != nullptr)
            {
                IndexNode->next = IndexNode->next->next;
                IndexNode->next->prev = IndexNode;
                break;
            }
            else // 마지막 노드일 때
            {
                IndexNode->next = nullptr;
                break;
            }
        }
        IndexNode = IndexNode->next;
    }
}

int getList(int output[MAX_NODE])
{
    Node *IndexNode = head;
    int count = 0;
    while (IndexNode->next != nullptr)
    {
        output[count] = IndexNode->next->data;
        IndexNode = IndexNode->next;
        count += 1;
    }
    return count;
}

int getReversedList(int output[MAX_NODE])
{
    Node *TailNode = head;
    int count = 0;
    while (TailNode->next != nullptr)
    {
        TailNode = TailNode->next;
    }
    while (TailNode->prev != nullptr)
    {
        output[count] = TailNode->data;
        TailNode = TailNode->prev;
        count += 1;
    }
    return count;
}

int main(void)
{
    init();
    
    addNode2Head(10);
     removeNode(10);
    addNode2Tail(11);
     removeNode(11);

    addNode2Tail(2);
    addNode2Tail(3);
    addNode2Tail(4);
    addNode2Tail(5);
    addNode2Tail(6);
    

    // removeNode(1);
    // cout << "findNode : " << findNode(4) << endl;
    int output[MAX_NODE];
    int node_length = getReversedList(output);
    for (int i = 0; i < node_length; i++)
    {
        cout << output[i] << endl;
    }
    cout<<endl<<endl;
    node_length = getList(output);
    for (int i = 0; i < node_length; i++)
    {
        cout << output[i] << endl;
    }
}