/* Algorithm Steps
1. Start at the beginning of the array
2. compare each pair of adjacent element and swap them if they are in the worng order
3. 
*/
#include <iostream>
using namespace std;
void bubbleSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;i++)
        {
            if(arr[j]>arr[j+1]);{
                int temp=arr[j];
                arr[j]=arr[j=1];
                arr[j+1]=temp;
            }
        }
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
    bubbleSort(arr,n);
    cout<<"Sorted Array "<<endl;
    printArray(arr,n);
    return 0;

}