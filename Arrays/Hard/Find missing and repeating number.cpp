 #include<bits/stdc++.h>
using namespace std;
 
 //Using hashing
 vector<int> findTwoElement(vector<int> arr, int n) {
       vector<int>freq_arr(n+1);
       for(int i=0;i<arr.size();i++){
           freq_arr[arr[i]]++;
       }
       int repeating=-1,missing=-1;
       for(int i=1;i<n+1;i++){
           if(freq_arr[i]==0) missing=i;
           else if(freq_arr[i]==2) repeating=i;
           if(missing!=-1 && repeating!=-1) break;
           
       }
       vector<int>ans={repeating,missing};
       return ans;     
}


//Optimal approach 1
//Arithmetic approach
vector<int> findTwoElement(vector<int> arr, int n) {
        long long total_sum=n*(n+1)/2;
        long long total_square_sum=(n*(n+1)*(2*n+1))/6;
        long long sum=0,square_sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            square_sum+=((long long)arr[i]*(long long)arr[i]);
        }
        long long diff=sum-total_sum;
        long long square_diff=square_sum-total_square_sum;
        long long sum2=square_diff/diff;
        long long repeating=(sum2+diff)/2;
        long long missing=(sum2-diff)/2;
        vector<int>ans={(int)repeating,(int)missing};
        return ans;
}


//Optimal approach 2
//XOR approach
 vector<int> findTwoElement(vector<int> arr, int n) {
        int xr=0;
        for(int i=0;i<arr.size();i++) xr^=arr[i];
        for(int i=1;i<=n;i++) xr^=i;
        //xr = x^y
        //cout<<xr<<endl;
        //int setbit=0;
        // while(1){
        //     if((xr & (1<<setbit))!=0) break;
        //     else setbit++;
        // }
        int num= xr & ~(xr-1);    //num is equivalent to (1<<setbit)
        //cout<<setbit<<endl;
        
        int one=0,zero=0;
        for(int i=0;i<arr.size();i++){
            if((arr[i] & num)==0){
                zero^=arr[i];
            }
            else one^=arr[i];
        }
        
        for(int i=1;i<=n;i++){
            if((i & num)==0){
                zero^=i;
            }
            else one^=i;
        }
        
        int cnt=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==zero) cnt++;
        }
        //cout<<zero<<" "<<one<<endl;
        int repeating=-1,missing=-1;
        if(cnt==0){
            missing=zero;
            repeating=one;
        }
        else{
            missing=one;
            repeating=zero;
        }
        vector<int>ans={repeating,missing};
        return ans;
        
    }