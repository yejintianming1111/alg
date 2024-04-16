/*
 * @Author: yelujian 1487407699@qq.com
 * @Date: 2024-04-16 14:27:47
 * @LastEditors: yelujian 1487407699@qq.com
 * @LastEditTime: 2024-04-16 14:47:02
 * @FilePath: /undefined/home/yelujian/Codes/alg/leetcode_69.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <stdio.h>
int mySqrt(int x) 
{
    if (x == 1)
    {
        return 1;
    }
    int begin = 1;
    int end = x / 2;
    int mid = 0;
    while(begin <= end)
    {
        mid = (begin + end) / 2;
        long long result = (long long)mid * mid;
        if (result < x)
        {
            begin = mid + 1;
        }
        else if (result > x)
        {
            end = mid - 1;
        }
        else
        {
            return mid;
        }
    }
    return begin - 1;
}
int main()
{
    //for (int i = 0; i <= 100; i++)
    {
        printf("i : %d --- sqrt : %d \n", 2147395599, mySqrt(2147395599));
    }
    return 0;
}