//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
       long long merge(long long arr[], long long temp[], long long left, long long mid, long long right) {
        long long i, j, k;
        long long inv_count = 0;

        i = left; // Initial index of the first subarray
        j = mid; // Initial index of the second subarray
        k = left; // Initial index of the merged subarray

        while (i <= mid - 1 && j <= right) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
                inv_count += (mid - i);
            }
        }

        // Copy the remaining elements of the first subarray, if any
        while (i <= mid - 1) {
            temp[k++] = arr[i++];
        }

        // Copy the remaining elements of the second subarray, if any
        while (j <= right) {
            temp[k++] = arr[j++];
        }

        // Copy the merged elements back to the original array
        for (i = left; i <= right; i++) {
            arr[i] = temp[i];
        }

        return inv_count;
    }

    long long mergeSort(long long arr[], long long temp[], long long left, long long right) {
        long long inv_count = 0;

        if (left < right) {
            long long mid = (left + right) / 2;

            // Total inversion count = inversion count in left subarray +
            //                         inversion count in right subarray +
            //                         inversion count while merging

            inv_count += mergeSort(arr, temp, left, mid);
            inv_count += mergeSort(arr, temp, mid + 1, right);
            inv_count += merge(arr, temp, left, mid + 1, right);
        }

        return inv_count;
    }

    long long inversionCount(long long arr[], long long N) {
        long long temp[N]; // Auxiliary array to store temporary merge results
        return mergeSort(arr, temp, 0, N - 1);
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends
