#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int linearsearh(int arr[], int n, int x){
    for(int i=0; i<n; i++){
        if(arr[i]==x){
            return i;
        }
    }
    return -1;
} 

int binarysearch(int arr[], int l, int r, int x){
    if(r>=l){
        int mid = l + (r-l)/2;
        if(arr[mid]==x){
            return mid;
        }
        if(arr[mid]>x){
            return binarysearch(arr, l, mid-1, x);
        }
        return binarysearch(arr, mid+1, r, x);
    }
    return -1;
}

// void heapsort(int arr[], int n){
//     for(int i=n/2-1; i>=0; i--){
//         heapify(arr, n, i);
//     }
//     for(int i=n-1; i>=0; i--){
//         swap(arr[0], arr[i]);
//         heapify(arr, i, 0);
//     }
// }
// void heapify(int arr[], int n, int i){
//     int largest = i;
//     int l = 2*i+1;
//     int r = 2*i+2;
//     if(l<n && arr[l]>arr[largest]){
//         largest = l;
//     }
//     if(r<n && arr[r]>arr[largest]){
//         largest = r;
//     }
//     if(largest!=i){
//         swap(arr[i], arr[largest]);
//         heapify(arr, n, largest);
//     }
// }
// int radixsort(int arr[], int n){
//     int m = getMax(arr, n);
//     for(int exp=1; m/exp>0; exp*=10){
//         countSort(arr, n, exp);
//     }
// }   

// int getMax(int arr[], int n){
//     int mx = arr[0];
//     for(int i=1; i<n; i++){
//         if(arr[i]>mx){
//             mx = arr[i];
//         }
//     }
//     return mx;
// }

// void countSort(int arr[], int n, int exp){
//     int output[n];
//     int i, count[10]={0};
//     for(i=0; i<n; i++){
//         count[(arr[i]/exp)%10]++;
//     }
//     for(i=1; i<10; i++){
//         count[i]+=count[i-1];
//     }
//     for(i=n-1; i>=0; i--){
//         output[count[(arr[i]/exp)%10]-1] = arr[i];
//         count[(arr[i]/exp)%10]--;
//     }
//     for(i=0; i<n; i++){
//         arr[i] = output[i];
//     }
// }   

// void mergesort(int arr[], int l, int r){
//     if(l<r){
//         int m = l+(r-l)/2;
//         mergesort(arr, l, m);
//         mergesort(arr, m+1, r);
//         merge(arr, l, m, r);
//     }
// }

// void merge(int arr[], int l, int m, int r){
//     int n1 = m-l+1;
//     int n2 = r-m;
//     int L[n1], R[n2];
//     for(int i=0; i<n1; i++){
//         L[i] = arr[l+i];
//     }
//     for(int j=0; j<n2; j++){
//         R[j] = arr[m+1+j];
//     }
//     int i=0, j=0, k=l;
//     while(i<n1 && j<n2){
//         if(L[i]<=R[j]){
//             arr[k] = L[i];
//             i++;
//         }
//         else{
//             arr[k]=R[j];
//             j++;
//         }
//         k++;
//     }
//     while(i<n1){
//         arr[k] = L[i];
//         i++;
//         k++;
//     }
//     while(j<n2){
//         arr[k] = R[j];
//         j++;
//         k++;
//     }
// }





int main (){    

    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x ;
    cin>>x;
    int result = linearsearh(arr, n, x);
    if(result == -1){
        cout<<"Element is not present in array"<<endl;
    }
    else{
        cout<<"Element is present at index "<<result<<endl;
    }

    int result2 = binarysearch(arr, 0, n-1, x);
    cout<<result2<<endl;

    return 0;
}