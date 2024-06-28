#include <iostream>
#include <algorithm>
using namespace std;

typedef struct
{
    int data[100];
    int size;
} Sqlist;

void create(Sqlist &s);  // 创建顺序表
void display(Sqlist s);  // 显示顺序表
void insert(Sqlist &s, int pos, int val);  // 在指定位置插入元素
void delete_element1(Sqlist &s, int pos);  // 删除指定位置的元素
void delete_element2(Sqlist &s, int target);  // 删除指定值的元素
int search(Sqlist s, int val);  // 查找元素
int get_elment(Sqlist s, int pos);  // 获取指定位置的元素
bool is_empty(Sqlist s);  // 判断顺序表是否为空
void reverse(Sqlist &s);  // 反转顺序表
bool merge(Sqlist &s1, Sqlist &s2, Sqlist &s3);  // 合并两个顺序表
void Destroy(Sqlist &s);  // 销毁顺序表
void Bubble_sort(Sqlist &s);  // 冒泡排序
void selection_sort(Sqlist &s);  // 选择排序
void quick_sort(Sqlist &s, int low, int high);  // 快速排序

void create(Sqlist &s)
{
    cout << "Enter size of the list: ";
    cin >> s.size;
    cout << "Enter elements of the list: ";
    for (int i = 0; i < s.size; i++)
    {
        cin >> s.data[i];
    }
}

void display(Sqlist s)
{
    for (int i = 0; i < s.size; i++)
    {
        cout << s.data[i] << " ";
    }
    cout << endl;
}

void insert(Sqlist &s, int pos, int val)
{
    if (pos < 0 || pos > s.size)
    {
        cout << "Invalid position" << endl;
        return;
    }
    for (int i = s.size - 1; i >= pos; i--)
    {
        s.data[i + 1] = s.data[i];
    }
    s.data[pos] = val;
    s.size++;
    return;
}

void delete_element1(Sqlist &s, int pos)
{
    if (pos < 0 || pos >= s.size)
    {
        cout << "Invalid position" << endl;
        return;
    }
    for (int i = pos; i < s.size - 1; i++)
    {
        s.data[i] = s.data[i + 1];
    }
    s.size--;
    return;
}
void delete_element2(Sqlist &s, int target)
{
    int i = 0;
    int j = 0;
    while (i < s.size)
    {
        if (s.data[i] == target)
        {
            i++;
        }
        else
        {
            s.data[j] = s.data[i];
            i++;
            j++;
        }
    }
    s.size = j;
}


int search(Sqlist s, int val)
{
    for (int i = 0; i < s.size; i++)
    {
        if (s.data[i] == val)
        {
            return i;
        }
    }
    return -1;
}

int get_elment(Sqlist s, int pos)
{
    if (pos < 0 || pos >= s.size)
    {
        cout << "Invalid position" << endl;
        return -1;
    }
    return s.data[pos];
}

bool is_empty(Sqlist s)
{
    return s.size == 0;
}

void reverse(Sqlist &s)
{
    int temp;
    for (int i = 0; i < s.size / 2; i++)
    {
        temp = s.data[i];
        s.data[i] = s.data[s.size - i - 1];
        s.data[s.size - i - 1] = temp;
    }
}

bool merge(Sqlist &s1, Sqlist &s2,Sqlist &s3)
{
    if (s1.size + s2.size > 100)
    {
        cout << "The merged list is too large" << endl;
        return false;
    }
    s3.size = s1.size + s2.size;
    for (int i = 0; i < s1.size; i++)
    {
        s3.data[i] = s1.data[i];
    }
    for (int i = 0; i < s2.size; i++)
    {
        s3.data[i + s1.size] = s2.data[i];
    }
    return true;
}

void Destroy(Sqlist &s)
{
    s.size = 0;
}

void Bubble_sort(Sqlist &s)
{
    for (int i = 0; i < s.size - 1; i++)
    {
        for (int j = i + 1; j < s.size; j++)
        {
            if (s.data[i] > s.data[j])
            {
                int temp = s.data[i];
                s.data[i] = s.data[j];
                s.data[j] = temp;
            }
        }
    }
}

void selection_sort(Sqlist &s)
{
    int i, j, k, temp;
    for (i = 0; i < s.size; i++){
        k = i;
        for (j = i + 1; j < s.size; j++){
            if (s.data[j] < s.data[k]){
                k = j;
            }
        }
        if (k != i){
            // 添加边界检查
            if (i < s.size && k < s.size) {
                // 将 temp 声明为与数组元素类型一致的变量
                int temp = s.data[i];
                s.data[i] = s.data[k];
                s.data[k] = temp;
            }
        }
    }
}



void quick_sort(Sqlist &s, int low, int high)
{
    if (low < high)
    {
        int pivot = s.data[high];
        int i = low - 1;
        for (int j = low; j < high; j++)
        {
            if (s.data[j] < pivot)
            {
                i++;
                int temp = s.data[i];
                s.data[i] = s.data[j];
                s.data[j] = temp;
            }
        }
        swap(s.data[i + 1], s.data[high]);
        quick_sort(s, low, i);
        quick_sort(s, i + 2, high);
    }
}


int main()
{
    Sqlist s1, s2,s3;
    create(s1);
    create(s2);
    display(s1);
    display(s2);
    merge(s1, s2, s3);
    display(s3);
    Bubble_sort(s1);
    display(s1);
    selection_sort(s2);
    display(s2);
    quick_sort(s3, 0, s3.size - 1);
    display(s3);
    Destroy(s1);
    Destroy(s2);
    Destroy(s3);
    return 0;
}