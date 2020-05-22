#include<iostream>
#include<algorithm>

using namespace std;
// A utility function to swap two elements  
void swap(int* a, int* b)  
{  
    int t = *a;  
    *a = *b;  
    *b = t;  
}  
  
/* This function takes last element as pivot, places  
the pivot element at its correct position in sorted  
array, and places all smaller (smaller than pivot)  
to left of pivot and all greater elements to right  
of pivot */
int partition (int arr[], int low, int high)  
{  
    int pivot = arr[high]; // pivot  
    int i = (low - 1); // Index of smaller element  
  
    for (int j = low; j <= high - 1; j++)  
    {  
        // If current element is smaller than the pivot  
        if (arr[j] < pivot)  
        {  
            i++; // increment index of smaller element  
            swap(&arr[i], &arr[j]);  
        }  
    }  
    swap(&arr[i + 1], &arr[high]);  
    return (i + 1);  
}  
  
/* The main function that implements QuickSort  
arr[] --> Array to be sorted,  
low --> Starting index,  
high --> Ending index */
void quickSort(int arr[], int low, int high)  
{  
    if (low < high)  
    {  
        /* pi is partitioning index, arr[p] is now  
        at right place */
        int pi = partition(arr, low, high);  
  
        // Separately sort elements before  
        // partition and after partition  
        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high);  
    }  
}  

int T, n;
int x[1000]={0};
int y[1000]={0};

int fopt=INT32_MAX;
int fcur=0;
 
int main(){
    cin>> T;
    for(int i=1;i<=T;i++){
        //fopt=INT32_MAX;
        cin >> n;

        
        for(int j=0;j<n;j++){
            cin>>x[j];
            
        }
        for(int j=0;j<n;j++){
            cin>>y[j];
        }

        sort(x,x+n);
        sort(y,y+n);
          

         /* quickSort(x,0,n-1);
         quickSort(y,0,n-1); */
         fcur=0;
         long long fcur2=0;
         //if(    (x[0]>0&&y[0]>0   )||(  x[n-1]<0&&y[n-1]<0  )){
               /*  for(int j=0;j<n;j++){
                    fcur+=x[j]*y[j];
                } */
        // }else
        for(int j=0;j<n;j++){
            fcur2+=x[j]*y[n-j-1];
        }

        //fcur =min(fcur,fcur2);

        
        

        cout<< "Case #"<<i<<": " <<fcur2<<endl;


    }
    return 0;
}