#include <iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
} Node, *link;

void create(link &head); // 创建一个新的链表
void insert(link &head, int data, int pos); // 在链表的指定位置插入一个新节点
void delete_head(link &head); // 删除链表的第一个节点
void delete_node(link &head, int data); // 删除链表中指定数据的节点
void delete_pos(link &head, int pos); // 删除链表中指定位置的节点
Node *listsort(link head); // 对链表进行排序
Node* freeList(link head); // 释放链表所占用的内存空间
void reverse(link &head); // 反转链表
void display(link head); // 显示链表中的所有节点数据
int get_length(link head); // 获取链表的长度
void merge(link &head1, link &head2); // 合并两个链表
int serach_pos(link head, int data); // 在链表中查找指定数据的位置

void create(link &head)
{
    int n, i;
    cout << "Enter the number of nodes: ";
    cin >> n;
    head = NULL;
    for (i = 0; i < n; i++)
    {
        link new_node = new Node;
        cout << "Enter data for node " << i + 1 << ": ";
        cin >> new_node->data;
        new_node->next = head;
        head = new_node;
    }
}
void createAtTail(link &head)
{
    int n, i;
    cout << "Enter the number of nodes: ";
    cin >> n;
    head = NULL;
    link tail = NULL;  // 添加尾指针
    for (i = 0; i < n; i++)
    {
        link new_node = new Node;
        cout << "Enter data for node " << i + 1 << ": ";
        cin >> new_node->data;
        new_node->next = NULL;  // 新节点的next指针指向NULL
        if (head == NULL) {
            head = new_node;
            tail = new_node;  // 如果是第一个节点，同时将尾指针指向此节点
        }
        else {
            tail->next = new_node;  // 尾节点的next指向新节点
            tail = new_node;  // 更新尾指针
        }
    }
}


void insert(link &head, int data, int pos)
{
    if (pos < 1)
    {
        cout << "Invalid position." << endl;
        return;
    }

    link new_node = new Node;
    new_node->data = data;

    if (pos == 1)
    {
        new_node->next = head;
        head = new_node;
    }
    else
    {
        link current = head;
        int i = 1;
        while (current != NULL && i < pos - 1)
        {
            current = current->next;
            i++;
        }
        if (current == NULL)
        {
            cout << "Position is out of range." << endl;
        }
        else
        {
            new_node->next = current->next;
            current->next = new_node;
        }
    }
}



void delete_head(link &head)
{
    if (head == NULL)
    {
        cout << "List is empty." << endl;
    }
    else
    {
        link temp = head;
        head = head->next;
        delete temp;
    }
}

void delete_node(link &head, int data)
{
    Node *current = head, *prev = NULL;
    while (current != NULL && current->data != data)
    {
        prev = current;
        current = current->next;
    }
    if (current == NULL)
    {
        cout << "Node with data " << data << " not found." << endl;
    }
    else
    {
        if (prev == NULL)
        {
            head = current->next;
        }
        else
        {
            prev->next = current->next;
        }
        delete current;
    }
}

void delete_pos(link &head, int pos)
{
    if (pos == 1)
    {
        delete_head(head);
    }
    else
    {
        link current = head;
        int i = 1;
        while (current != NULL && i < pos - 1)
        {
            current = current->next;
            i++;
        }
        if (current == NULL)
        {
            cout << "Position is out of range." << endl;
        }
        else
        {
            link temp = current->next;
            current->next = temp->next;
            delete temp;
        }
    }
}

Node *listsort(link head)
{
    Node *current = head;
    Node *temp = NULL;
    Node *sorted = NULL;
    while (current != NULL)
    {
        temp = current->next;
        current->next = NULL;
        if (sorted == NULL || current->data <= sorted->data)
        {
            current->next = sorted;
            sorted = current;
        }
        else
        {
            Node *prev = sorted;
            while (prev->next != NULL && prev->next->data < current->data)
            {
                prev = prev->next;
            }
            current->next = prev->next;
            prev->next = current;
        }
        current = temp;
    }
    return sorted;
}


Node* freeList(Node* head)
{
    Node *current = head;
    Node *next;
    while (current != NULL)
    {
        next = current->next;
        delete current;
        current = next;
    }
    cout << "List freed." << endl;
    return NULL; // 返回释放后的 head 指针
}


void merge(link &head1, link &head2)
{
    if (head2 == NULL) // 添加对head2为空的判断
    {
        return; 
    }
    if (head1 == NULL)
    {
        head1 = head2;
    }
    else
    {
        link current1 = head1;
        while (current1->next != NULL)
        {
            current1 = current1->next;
        }
        current1->next = head2;
    }
}


int serach_pos(link head, int data)
{
    int pos = 0;
    Node *current = head;
    while (current != NULL && current->data != data)
    {
        pos++;
        current = current->next;
    }
    if (current == NULL)
    {
        return -1;
    }
    else
    {
        return pos;
    }
}

void reverse(link &head)
{
    link prev = NULL, current = head, next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

void display(link head)
{
    link current = head;
    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int get_length(link head)
{
    int length = 0;
    link current = head;
    while (current != NULL)
    {
        length++;
        current = current->next;
    }
    return length;
}

int main()
{
    link head = NULL;
    create(head);
    cout << "Original list: ";
    display(head);
    delete_node(head, 2);
    cout << "List after deleting node with data 2: ";
    display(head);
    reverse(head);
    cout << "List after reversing: ";
    display(head);
    freeList(head);
    return 0;
}