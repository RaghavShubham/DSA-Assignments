#include<bits/stdc++.h>
using namespace std;

void swap(float* a, float* b)  
{  
    float t = *a;  
    *a = *b;  
    *b = t;  
}  
int partition (float arr[], int low, int high)  
{  
    float pivot = arr[high];
    int i = (low - 1);
  
    for (int j = low; j <= high - 1; j++)   if (arr[j] < pivot)      
        i++,    swap(&arr[i], &arr[j]);
    swap(&arr[i + 1], &arr[high]);  
    return (i + 1);  
}  
void quick_sort(float arr[], int low, int high)  
{  
    if (low < high)  
    {  
        int pi = partition(arr, low, high);  
        quick_sort(arr, low, pi - 1);  
        quick_sort(arr, pi + 1, high);  
    }  
}

void bubble_sort(float arr[],int n){
    int i, j;  
    for (i = 0; i < n-1; i++)   for (j = 0; j < n-i-1; j++)  
        if (arr[j] > arr[j+1])  
            swap(&arr[j], &arr[j+1]);  
}

void shell_sort(float arr[],int n){
    for (int gap = n/2; gap > 0; gap /= 2) 
    { 
        for (int i = gap; i < n; i += 1) 
        { 
            float temp = arr[i]; 
            int j;             
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) 
                arr[j] = arr[j - gap]; 
            arr[j] = temp; 
        } 
    } 
}

void insertion_sort(float arr[],int n){
    float key;
    for (int j,i = 1; i < n; i++) 
    {  
        key = arr[i];  
        j = i - 1;  
        while (j >= 0 && arr[j] > key) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = key;  
    }  
}
struct bucket 
{
    int count;
    float* value;
};
 
int compareIntegers(const void* first, const void* second)
{
    float x = *((float*)first), y =  *((float*)second);
    if (x == y)
    {
        return 0;
    }
    else if (x < y)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}
 
void bucket_sort(float array[],int n)
{
    struct bucket buckets[3];
    int i, j, k;
    for (i = 0; i < 3; i++)
    {
        buckets[i].count = 0;
        buckets[i].value = (float*)malloc(sizeof(float) * n);
    }
    
    for (i = 0; i < n; i++)
    {
        if (array[i] < 0)	 buckets[0].value[buckets[0].count++] = array[i];
        else if (array[i] > 10)    buckets[2].value[buckets[2].count++] = array[i];
        else    buckets[1].value[buckets[1].count++] = array[i];
    }
    for (k = 0, i = 0; i < 3; i++)
    {
        qsort(buckets[i].value, buckets[i].count, sizeof(float), &compareIntegers);
        for (j = 0; j < buckets[i].count; j++)
        {
            array[k + j] = buckets[i].value[j];
        }
        k += buckets[i].count;
        free(buckets[i].value);
    }
}
float getMax(float arr[], int n) 
{ 
    float mx = arr[0]; 
    for (int i = 1; i < n; i++)    max(mx,arr[i]);
    return mx; 
} 
void countSort(float arr[], int n, int exp) 
{ 
    float output[n];
    int i, count[10] = {0}; 

    for (i = 0; i < n; i++) 
        count[ ((int)arr[i]/exp)%10 ]++; 

    for (i = 1; i < 10; i++) 
        count[i] += count[i - 1]; 
  
    for (i = n - 1; i >= 0; i--) 
    { 
        output[count[ ((int)arr[i]/exp)%10 ] - 1] = arr[i]; 
        count[ ((int)arr[i]/exp)%10 ]--; 
    } 
  
    for (i = 0; i < n; i++) 
        arr[i] = output[i]; 
} 
void radix_sort(float arr[],int n){
    float m = getMax(arr, n); 
    for (int exp = 1; m/exp > 0; exp *= 10) 
        countSort(arr, n, exp); 
}

void print(float a[],int n){
    cout<<"\n\n  The Sorted Array - ";
    for(int i=0;i<n;i++)    cout<<a[i]<<' ';
}

int main(){
    string s="",x;
    int ch=1,n;
    cout<<"\n\n  Enter the total number of Students - ";    cin>>n;
        float a[n]={};
        cout<<"\n  Enter the First Year Percentages of Students - \n";
        for(int i=0;i<n;i++)    cin>>a[i];
        
    while(ch){
        cout<<"\n\n\t\t   Sorting Algorithms\n\t\t=======================";
        cout<<"\n  Choose type of Operation - \n  1. Quick Sort\n  2. Bubble Sort\n  3. Shell Sort\n  4. Insertion Sort\n  5. Bucket Sort\n  6. Radix Sort\n  0. Exit\n\n Enter choice (0-6) - ";
        cin>>ch;
        switch(ch){
            case 1: quick_sort(a,0,n-1);print(a,n);break;
            case 2: bubble_sort(a,n);print(a,n);break;
            case 3: shell_sort(a,n);print(a,n);break;
            case 4: insertion_sort(a,n);print(a,n);break;
            case 5: bucket_sort(a,n);print(a,n);break;
            case 6: radix_sort(a,n);print(a,n);break;
            case 0: cout<<"\n\n\t !! Closing Program !!\n\n\n\n";break;
            default: cout<<"\n\n\t!! Enter a Valid Choice !!";
        }
    }
    return 0;
}
