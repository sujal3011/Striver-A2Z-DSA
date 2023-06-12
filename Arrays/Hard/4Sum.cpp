#include<bits/stdc++.h>
using namespace std;

//Brute approach
//Four pointers
 vector<vector<int>> fourSum(vector<int>& arr, int target) {
        int n=arr.size();
        set<vector<int>>st;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    for(int l=k+1;l<n;l++){
                        long long x=arr[i],y=arr[j],z=arr[k],w=arr[l];
                        long long sum=(x+y+z+w);
                        if(sum==target){
                            vector<int>res={arr[i],arr[j],arr[k],arr[l]};
                            sort(res.begin(),res.end());
                            st.insert(res);
                        }
                    }
                }
            }
        }
        vector<vector<int>>ans(st.begin(),st.end());
        return ans;

}

//Hashing
//Better
vector<vector<int>> fourSum(vector<int>& arr, int target) {
        int n=arr.size();
        set<vector<int>>st;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                set<int>hashset;
                for(int k=j+1;k<n;k++){
                   long long sum=arr[i]+arr[j];
                   sum+=arr[k];
                   long long fourth=target-sum;
                    auto it=hashset.find(fourth);
                    if(it!=hashset.end()){
                        vector<int>res={arr[i],arr[j],arr[k],*it};
                        sort(res.begin(),res.end());
                        st.insert(res);
                    }
                    hashset.insert(arr[k]);
                }
            }
        }
        vector<vector<int>>ans(st.begin(),st.end());
        return ans;

}


//Three pointer approach
//Optimal appraoch
vector<vector<int>> fourSum(vector<int>& arr, int target) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            if(i>0 && arr[i]==arr[i-1]) continue;
            for(int j=i+1;j<n;j++){
                if(j!=(i+1) && arr[j]==arr[j-1]) continue;
                int k=j+1,l=n-1;
                while(l>k){
                    long long sum=arr[i]+arr[j];
                    sum+=arr[k]+arr[l];

                    if(sum==target){
                        vector<int>temp={arr[i],arr[j],arr[k],arr[l]};
                        ans.push_back(temp);
                        k++;
                        l--;

                        while(k<l && arr[k]==arr[k-1]) k++;
                        while(k<l && arr[l]==arr[l+1]) l--; 
                    }
                    else if(sum>target) l--;
                    else k++;
                }

            }
        }


        return ans;

}