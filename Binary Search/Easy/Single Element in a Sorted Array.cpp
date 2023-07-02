#include<bits/stdc++.h>
using namespace std;


//Brute force approach
//Xor all the numbers in the array and the number left is the final answer
//Time complexity--->O(n)
//Space complexity--->O(1)


//Optimized approach(Binary Search)
//Time complexity--->O(logn)
//Space complexity--->O(1)

//Explanation:
//Ideally, every even index should contain the first occurrence of the element and odd index should contain the second occurrence of the previous identical element. If there is an element in the array(with no duplicate) that means there will be distortion in this behavior in some part of the array. The distortion will start from the index where the single element element occurs. Use Binary search to check if the middle element follows the ideal behavior. If yes then the single element occurs to the right of the middle element. If not, it means that the single element lies to the left of the middle index. That’s how we reduce the search space.

//IMPORTANT TRICK--->Doing xor of an even number with 1 gives the odd number after it and doing xor of an odd number with 1 gives the previous even number

int singleNonDuplicate(vector<int>& arr) {
        int n=arr.size();
        int low=0,high=n-2;
        while(low<=high){
            int mid=low+((high-low)>>1);

            //Checking if mid is in the left half or not
            // Ist instance--->even index
            // 2nd instance--->odd index

            if(arr[mid]==arr[mid^1]){ //IMPORTANT (TRICK)
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }

        //After coming out of the while loop, low is standing immediately after the left half and high is standing immediately before the right half.

        return arr[low];

}

//Optimized approach(Binary Search)
//Time complexity--->O(logn)
//Space complexity--->O(1)
int singleNonDuplicate(vector<int>& nums) {

        int n = nums.size(),ans;
        int low=0,high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if((mid-1)>=0 && nums[mid]==nums[mid-1]){
                if(mid%2==0) high=mid-1;
                else low=mid+1;
            }

            else if((mid+1)<n && nums[mid]==nums[mid+1]){
               if(mid%2!=0) high=mid-1;
                else low=mid+1;
            }
            else{
                ans=nums[mid];
                break;
            }
            
        }
        return ans;
        
    }


int main(){



    return 0;
}

