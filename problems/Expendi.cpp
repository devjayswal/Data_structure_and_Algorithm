/* a group of cows grabbed a truck and ventrured on an expedition deep
into the jungle. being rather poor drivers the cows unfortunatelu to run over a rock and puncture the truck fuel tank. 
the truck now leaks one unit of fuel every unit of distance it travels 

to repair the truck , the cows need to drive to the nearest town  down a long einding roas ont this 
road on this roas  between the town and the current locationn of the truck. there are N  fuel stops where the cows can stop to acquire  additional fuel .
the truck currently n units away from the town and has p unit of fuel 
determine  the niminum number of stopss needed  to reach the town, or it the cows annot reach the town at all
 */

#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<pair<int,int> > a(n);

        for(int i=0; i<n; i++){
            cin>>a[i].first>>a[i].second;

        }

        int l,p;
        cin>>l>>p;

        for(int i=0;i<n; i++){
            a[i].first = l -a[i].first;
        }

        sort(a.begin(),a.end());


        int ans=0;
        int curr = p;

        priority_queue <int ,vector<int>> pq;

        bool flag=0;

        for (int i=0;i<n;i++){
            if (curr>=l)
                break;

            while(curr<a[i].first){

               if (pq.empty()){

                flag = 1;
                break;
               }
               ans++;
               curr +=pq.top();
               pq.pop();

            }
            if(flag)
                break;
            pq.push(a[i].second);

        }

        if(flag){
            cout<<" -1"<<endl;
        }

        while(!pq.empty() && curr<1){
            curr+=pq.top();
            pq.pop();
            ans++;
        }

        if(curr<1){
            cout<<"-1"<<endl;
            continue;
        }
        cout<<ans<<endl;


    }


    return 0;
}