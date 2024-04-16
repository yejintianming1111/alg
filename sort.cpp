/*
 * @Author: yelujian 1487407699@qq.com
 * @Date: 2024-04-16 16:42:54
 * @LastEditors: yelujian 1487407699@qq.com
 * @LastEditTime: 2024-04-17 00:25:20
 * @FilePath: /undefined/home/yelujian/Codes/alg/sort.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <stdio.h>

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
        swap(&a[i], &a[j]);
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

int main()
{
    int a[10] = {5, 4, 1, 10, 8, 6, 2, 7, 3, 9};
    // quickSort(a, 0, 9);
    selectSort(a, 10);
    for (int i = 0; i < 10; i++)
    {
        printf("index : %d --- value : %d \n", i + 1, a[i]);
    }
    
    return 0;
}