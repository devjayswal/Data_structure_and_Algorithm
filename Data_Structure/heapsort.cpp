#include<bits/stdc++.h>

using namespace std;



#include<bits/stdc++.h>

using namespace std;

void heapsort(int arr[], int n){

    priority_queue<int,vector<int>,greater<int>> minh;

    for (int i = 0; i < n; i++)
    {
        minh.push(arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        arr[i]=minh.top();
        minh.pop();
    }
    for(int i=0; i<n;i++)
        {cout<<arr[i]<<" ";}
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){

        cin>>arr[i];
    }

    clock_t start,end;
        
        start=clock();
        cout<<"Before sorting"<<endl;
        cout<<start<<endl;
        heapsort(arr,n);
        end=clock();
        cout<<"\nAfter sorting"<<endl;
        cout<<end<<endl;
        double time_taken=double(end-start)/double(CLOCKS_PER_SEC);
        cout<<"\nTime taken by program is : "<<fixed<<time_taken<<setprecision(5);
        cout<<" sec "<<endl;

}


//time complexity of this algorithm is O(nlogn) and space complexity is O(n)
