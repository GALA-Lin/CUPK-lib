#include <iostream>
#include <vector>
#include <algorithm> // 使用 std::swap
#include <fstream>   // 使用 ifstream 文件流

using namespace std;

void PrintArray(const vector<int> &arr)
{
    for (int value : arr)
        cout << value << " ";
    cout << endl;
}

void InsertionSort(vector<int> &arr)
{
    int n = arr.size();
    int i, j, key;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void BubbleSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// 分区函数：选择一个基准元素并重新排列数组
int Partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high];                // 选择最后一个元素作为基准
    int i = (low - 1);                    // i是小于基准的元素的最后一个索引
    for (int j = low; j <= high - 1; j++) // 遍历数组
    {
        if (arr[j] < pivot) // 如果当前元素小于基准
        {
            i++;                  // 增加小于基准元素的索引
            swap(arr[i], arr[j]); // 交换元素
        }
    }
    swap(arr[i + 1], arr[high]); // 将基准放到正确位置
    return (i + 1);              // 返回基准的索引
}

// 快速排序函数：递归地对数组进行排序
void QuickSort(vector<int> &arr, int low, int high)
{
    if (low < high) // 确保有两个以上元素
    {
        int pi = Partition(arr, low, high); // 找到分区索引
        QuickSort(arr, low, pi - 1);        // 递归排序基准左侧
        QuickSort(arr, pi + 1, high);       // 递归排序基准右侧
    }
}

int main()
{
    ifstream inputFile("D:\\C++work\\data.txt"); // 打开文件
    if(!inputFile.is_open())
    {
        cout << "打开文件失败" << endl;
        return -1;
    }
    vector<int> arr1;
    int number;

    // 读取文件中的整数到数组中
    while (inputFile >> number)
    {
        arr1.push_back(number);
    }
    inputFile.close(); // 关闭文件

    vector<int> arr2 = arr1; // 复制 arr1
    vector<int> arr3 = arr1; // 复制 arr1
    cout << "Array 1: ";
    PrintArray(arr1);
    cout << "Array 2: ";
    PrintArray(arr2);
    cout << "Array 3: ";
    PrintArray(arr3);
    InsertionSort(arr1);
    BubbleSort(arr2);
    QuickSort(arr3, 0, arr3.size() - 1);
    cout << "Insertionsort Array 1: ";
    PrintArray(arr1);
    cout << "Bubblesort Array 2: ";
    PrintArray(arr2);
    cout << "Quicksort Array 3: ";
    PrintArray(arr3);
    return 0;
}
