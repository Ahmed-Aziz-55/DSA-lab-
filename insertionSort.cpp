/*
Algorithm Steps
start from the second element(index 1) and assume the first element is already sorted.
2 compare the current element with the previous elements.
3. shift all the elements greater than the current element one position ahead.
4. Insert the current element at its current  position in the sorted part of the aaray.
5. Repeat the process for all element
*/
#include <iostream>
using namespace std;
void insertionSort(int arr[],int n)
{
    for(int i=1;i<n;i++)
    {
    int key=arr[i];
    int j=i-1;

    while(j>=0 && arr[j] > key){
        arr[j+1]=arr[j];
        j=j-1;
    }
    arr[j+1]=key;
}
}
void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[]={12,11,13,5,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"Origional Array "<<endl;
    printArray(arr,n);
    insertionSort(arr,n);
    cout<<"Sorted Array "<<endl;
    printArray(arr,n);
    return 0;
}
