#include <iostream>
#include <stdio.h>
using namespace std;

#define MAX_NODE 10000

struct Node
{
    int data;
    Node *next;
};

Node node[MAX_NODE];
int nodeCnt;
Node *head;

Node *getNode(int data)
{
    node[nodeCnt].data = data;
    node[nodeCnt].next = nullptr;
    return &node[nodeCnt++];
}

void init()
{
    head = new Node;
    head->next = nullptr;
}

void addNode2Head(int data)
{
    if (head->next == nullptr)
    {
        head->next = getNode(data);
    }
    else
    {
        Node *newNode = getNode(data);
        newNode->next = head->next;
        head->next = newNode;
    }
}

void addNode2Tail(int data)
{
    Node *prev_last = head;
    while (prev_last->next != nullptr)
    {
        prev_last = prev_last->next;
    }
    Node *new_last = getNode(data);
    prev_last->next = new_last;
}

void addNode2Num(int data, int num)
{
    Node *pos = head;
    for (int i = 1; i < num; i++)
    {
        pos = pos->next;
    }
    Node *new_node = getNode(data);
    new_node->next = pos->next;
    pos->next = new_node;
}

void removeNode(int data)
{
    Node *pos = head;
    while (pos->next != nullptr)
    {
        if (pos->next->data == data)
        {
            pos->next = pos->next->next;
            break;
        }
        pos = pos->next;
    }
}

int getList(int output[MAX_NODE])
{
    Node *pos = head;
    int count = 0;
    while (pos->next != nullptr)
    {
        output[count] = pos->next->data;
        pos = pos->next;
        count += 1;
    }
    return count;
}

int main(void)
{
    init();
    addNode2Head(2);
    addNode2Tail(1);
    addNode2Head(4);
    addNode2Head(5);
    addNode2Head(6);
    removeNode(2);
    addNode2Head(7);
    addNode2Tail(8);
    addNode2Num(10,2);
    int output[MAX_NODE];
    int node_length = getList(output);
    for (int i = 0; i < node_length; i++)
    {
        cout << output[i] << endl;
    }
    
}