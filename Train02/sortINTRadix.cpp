#include<iostream>
#include<algorithm>

using namespace std;

void countSort(int arr[], int n, int exp) { 
    int output[n]; // output array 
    int i, count[10] = {0}; 
  
    // Store count of occurrences in count[] 
    for (i = 0; i < n; i++) 
        count[ (arr[i]/exp)%10 ]++; 
  
    // Change count[i] so that count[i] now contains actual 
    //  position of this digit in output[] 
    for (i = 1; i < 10; i++) 
        count[i] += count[i - 1]; 
  
    // Build the output array 
    for (i = n - 1; i >= 0; i--) 
    { 
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i]; 
        count[ (arr[i]/exp)%10 ]--; 
    } 
  
    // Copy the output array to arr[], so that arr[] now 
    // contains sorted numbers according to current digit 
    for (i = 0; i < n; i++) 
        arr[i] = output[i]; 
} 
   
// Radix Sort 
void RadixSort(int arr[], int n) { 
    // tim so lon nhat de chay  
    int mx = arr[0]; 
    for (int i = 1; i < n; i++) 
        if (arr[i] > mx) 
            mx = arr[i]; 
    // sap xep toi  
    for (int exp = 1; mx/exp > 0; exp *= 10) 
        countSort(arr, n, exp); 
} 



int main(){
    //ios_base::sync_with_stdio(false);
    int n;
    cin >>n;
    int k[n];
    for(int i=0;i<n;i++){
        cin >>k[i];
    }
    RadixSort(k,n);
    

    for(int i=0;i<n;i++){
        cout <<k[i]<<" ";
    }

    
    // return 1;
    return 0;
}