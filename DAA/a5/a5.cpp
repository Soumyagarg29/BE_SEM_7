#include<iostream>
#include<vector>
using namespace std;


int partition(vector<int>&arr , int low , int high)
{
int pivot = arr[high];
int i = low -1;
for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
     swap(arr[i + 1], arr[high]);  
    return i + 1;

}


void QuickSortR(vector<int> & arr , int low , int high)
{
    if(low < high)
    {
        int random = rand() % (high - low) + low;
        swap(arr[random] , arr[low]);
        int p = partition(arr , low , high);
        QuickSortR(arr , low , p);
        QuickSortR(arr , p+1 , high);
    }
}


int main()
{
vector<int>arr = {1,4,2,5,3,6};
int high = arr.size();
int low = 0;
int random = rand() % (high - low + 1) + low;
QuickSortR(arr , low, high);
for(auto i : arr)cout<<i<<" ";
cout<<endl;
return 0;
}