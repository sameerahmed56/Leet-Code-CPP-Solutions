// { Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


 // } Driver Code Ends
class Solution
{
    public:
    void outPlaceMerge(int nums[], int low, int mid, int high) {
	if (low >= high) return;
	int l = low, r = mid + 1, k = 0, size = high - low + 1;
	vector<int> sorted(size, 0);
	while (l <= mid and r <= high)
		sorted[k++] = nums[l] < nums[r] ? nums[l++] : nums[r++];
	while (l <= mid) 
		sorted[k++] = nums[l++];
	while (r <= high) 
		sorted[k++] = nums[r++];
	for (k = 0; k < size; k++)
		nums[k + low] = sorted[k];
}
    public:
    void mergeSort(int nums[], int low, int high)
    {
        if (low >= high) return;
	int mid = (high - low) / 2 + low;
	mergeSort(nums, low, mid);
	mergeSort(nums, mid + 1, high);
	outPlaceMerge(nums, low, mid, high);
    }
};

// { Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}  // } Driver Code Ends