#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义学生结构体
typedef struct Student {
    char name[50];
    int height;
    int weight;
    struct Student *next;
} Student;

// 插入学生信息到链表尾部
void Insert(Student **head, char name[], int height, int weight) {
    Student *new_student = (Student *)malloc(sizeof(Student));
    strcpy(new_student->name, name);
    new_student->height = height;
    new_student->weight = weight;
    new_student->next = NULL;

    if (*head == NULL) {
        *head = new_student;
    } else {
        Student *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_student;
    }
}

// 返回第i个学生记录
Student* Locate(Student *head, int index) {
    Student *current = head;
    int i = 1; // 下标从1开始
    while (current != NULL && i < index) {
        current = current->next;
        i++;
    }
    return current;
}

// 删除第i个学生记录
void Delete(Student **head, int index) {
    if (*head == NULL) return;

    Student *temp = *head;

    if (index == 1) { // 下标从1开始
        *head = temp->next;
        free(temp);
        return;
    }

    for (int i = 1; temp != NULL && i < index - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) return;

    Student *next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

// 打印学生信息
void Display(Student *head) {
    Student *current = head;
    while (current != NULL) {
        printf("%s %d %d\n", current->name, current->height, current->weight);
        current = current->next;
    }
}

// 释放链表内存
void FreeList(Student *head) {
    Student *current = head;
    Student *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    Student *student_list = NULL;

    for (int i = 0; i < n; i++) {
        char name[50];
        int height, weight;
        scanf("%s %d %d", name, &height, &weight);
        Insert(&student_list, name, height, weight);
    }

    int delete_index;
    scanf("%d", &delete_index);

    if (delete_index >= 1 && delete_index <= n) { // 下标从1开始
        Delete(&student_list, delete_index);
    }

    Display(student_list);

    // 释放链表内存
    FreeList(student_list);

    return 0;
}
