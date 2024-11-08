#include<iostream>
using namespace std;


int partition(vector<vector<int>>&arr , int l , int h )
{
int pivot = arr[l];
while (true)
{
    while (arr[i]<=pivot && i<high)i++;
    while(arr[j]>=pivot && j>low)j--;
    if(i<j)swap(arr[i] , arr[j]);
    else break;
}
swap(arr[l] , arr[j]);
return j;
}
void quickSortDeterminitic(int low , int high , vector<vector<int>>&arr)
{
    int p = 0;
    while(low<high)
    {
        p = partition(arr , low , high);
        quickSortDeterminitic(low , p-1 , arr);
        quickSortDeterminitic(p+1 , high , arr);
    }
}

void display(vector<int> &arr){for(auto i  :arr)cout<<i<<" ";
cout<<endl;}
int main()
{
    vector<int>arr = {5,12,3,7,1,9,2};
    display(arr);
    quickSortDeterminitic(0 , arr.size() - 1 , arr);
    display(arr);
}