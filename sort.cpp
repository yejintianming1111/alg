/*
 * @Author: yelujian 1487407699@qq.com
 * @Date: 2024-04-16 16:42:54
 * @LastEditors: yelujian 1487407699@qq.com
 * @LastEditTime: 2024-04-17 17:26:40
 * @FilePath: /undefined/home/yelujian/Codes/alg/sort.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <stdio.h>
#include <stdlib.h>

/// @brief 交换两个数
/// @param a 交换的数
/// @param b 交换的数
void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/// @brief 冒泡排序
/// @param a 输入数组
/// @param size 数组大小
/// @return 0
int bubbleSort(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (a[j] > a[j+1])
            {
                swap(&a[j], &a[j+1]);
            }
        }
    }
    
    return 0;
}

/// @brief 直接插入排序
/// @param a 数组
/// @param size 数组大小
/// @return 0
int insertSort(int a[], int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        int end = i;
        int tmp = a[end + 1];
        while(end >= 0)
        {
            if (a[end] > tmp)
            {
                a[end + 1] = a[end];
                end--;
            }
            else
            {
                break;
            }
        }
        a[end + 1] = tmp;
    }
    return 0;
}

/// @brief 
/// @param a 数组
/// @param begin 起始位置
/// @param end 终止位置
/// @return 返回基准元素
int part(int* a, int begin, int end)
{
    int key = begin;
    int i = begin;  
    int j = end;  
    while (i < j) 
    {  
        while (i < j && a[j] >= a[key]) 
        {  
            j--;  
        }
        while (i < j && a[i] <= a[key]) 
        {  
            i++;  
        }
        if (i < j)
        {
            swap(&a[i], &a[j]);
        }
    }  
    // 将基准值交换到正确的位置  
    swap(&a[key], &a[i]);
    return i;  
}

/// @brief 快速排序
/// @param a 数组
/// @param begin 起始位置
/// @param end 终止位置
void quickSort(int* a, int begin, int end) 
{  
    if (begin >= end) 
    {  
        return;
    }  
    int pivotIndex = part(a, begin, end);  
    quickSort(a, begin, pivotIndex - 1);  
    quickSort(a, pivotIndex + 1, end);  
} 

/// @brief 直接选择排序
/// @param a 数组
/// @param size 数组大小
/// @return 0
int selectSort(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int min = i;
        for (int j = i; j < size; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        swap(&a[i], &a[min]);
    }
    return 0;
}

/// @brief 将区间内的元素归并
/// @param a 数组
/// @param left 区间左端点
/// @param right 区间右端点
/// @param mid 区间的中间元素
void merge(int a[], int left, int right, int mid)
{
    int tmp[right - left + 1];
    int start = 0;
    int i = left;
    int j = mid + 1;
    while(i <= mid && j <= right)
    {
        tmp[start++] = a[i] > a[j] ? a[j++] : a[i++];
    }
    while(i <= mid)
    {
        tmp[start++] = a[i++];
    }
    while(j <= right)
    {
        tmp[start++] = a[j++];
    }
    for (start = 0; start < right -left + 1; start++)
    {
        a[left + start] = tmp[start];
    }
}

/// @brief 归并排序
/// @param a 数组
/// @param left 左区间端点
/// @param right 右区间端点
void mergeSort(int a[], int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int mid = left + (right - left) / 2;
    mergeSort(a, left, mid);
    mergeSort(a, mid + 1, right);
    merge(a, left, right, mid);
}

/// @brief 希尔排序
/// @param a 数组
/// @param size 数组大小
/// @return 0
int shellSort(int a[], int size)
{
    for (int step = (size - 1) / 2; step >= 1; step /=2)
    {
        // 这里实际上是一次插入排序, 把a[i]插入到对应位置
        for(int i = step; i < size; i++)
        {
            if (a[i - step] > a[i])
            {
                int tmp = a[i];
                int j = 0;
                // 重点取等号
                for (j = i; (j - step) >= 0 && a[j - step] > tmp; j -= step)
                {
                    a[j] = a[j - step];
                }
                a[j] = tmp;
            }
        }
    }
    return 0;
}

// 调整root之下的树
void adjust(int a[], int root, int n)
{
    int parent = root;
    int child = 2 * root + 1;
    while(child < n)
    {
        if (child + 1 < n && a[child] < a[child + 1])
        {
            child = child + 1;
        }
        if (a[parent] > a[child])
        {
            return;
        }
        else
        {
            swap(&a[parent], &a[child]);
            parent = child;
            child = child * 2 + 1;
        }
    }
}

/// @brief 堆排序
/// @param a 数组
/// @param size 数组大小
/// @return 
int heapSort(int a[], int size)
{
    // 建堆, -1 是因为数组下标 从 0 - n
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        adjust(a, i, size);
    }
    int end = size - 1;
    while(end)
    {
        adjust(a, 0, end);
        // 先取出最大的放在end
        swap(&a[0], &a[end]);
        // 区间缩小
        end--;
    }

    return 0;
}

/// @brief 基数排序/桶排序
/// @param a 数组
/// @param size 数组大小
/// @return 0
int bucketSort(int a[], int size)
{
    int* buf = new int[size];
    int max = a[0];
    for (int  i = 1; i < size; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }

    // 默认一位
    int count = 1;
    while(max > 9)
    {
        count++;
        max /= 10;
    }

    int base = 1;
    int bucket[10];
    
    for (int i = 0; i < count; i++)
    {
        // 统计每个分段的个数
        for(int j = 0; j < size; j++)
        {
            int number  = (a[i] / base ) % 10;
            bucket[number]++;
        }
        // 每个分段都有对应的区间
        for (int j = 1; j < 10; j++)
        {
            bucket[j] += bucket[j - 1];
        }
        // 对应分段填数字
        for (int j = 0; j < size; j++)
        {
            buf[bucket[(a[i] / base ) % 10] - 1];
            bucket[(a[i] / base ) % 10]--;
        }
        // 清空桶
        for (int j = 0; j < 10; j++)
        {
            bucket[j] = 0;
        }
        // 元素赋值给a[]
        for (int j = 0; j < size; j++)
        {
            a[j] = buf[j];
        }
    }
    
    delete [] buf;
    return 0;
}

int main()
{
    int a[10] = {5, 4, 1, 10, 8, 6, 2, 7, 3, 9};
    // quickSort(a, 0, 9);
    // selectSort(a, 10);
    // mergeSort(a, 0, 9);
    // shellSort(a, 10);
    // heapSort(a, 10);
    bubbleSort(a, 10);
    for (int i = 0; i < 10; i++)
    {
        printf("index : %d --- value : %d \n", i + 1, a[i]);
    }
    
    return 0;
}