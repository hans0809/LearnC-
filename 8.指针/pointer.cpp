#include <iostream>
using namespace std;

//冒泡排序，参数1：数组首地址，参数2：数组长度
void bubbleSort(int *arr,int len)
{
    for (int i=0;i<len-1;i++)
    {
        for (int j=0;j<len-i-1;j++)
        {
            if (arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

void printArr(int *arr,int len)
{
    for(int i=0;i<len;i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int arr[10]={1,2,5,3,9,8,7,10,11,6};
    int len=sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr,len);
    printArr(arr,len);//1 2 3 5 6 7 8 9 10 11
}