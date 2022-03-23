#include<bits/stdc++.h>
using namespace std;

int main(){

 vector<int> arr = {1,3,-1,-3,5,3,6,7};
 vector<int> ans;
 int i=0, j = 0;
 int mx = INT_MIN;
 int k = 3;
 while(j < arr.size()){
 
  if(arr[j] > mx){
      mx = arr[j];
  }

  if(j-i+1 < k){
      j++;
  }else if(j-i+1 == k){
      ans.push_back(mx);
      i++;
      j++;
  }


 }

  for(auto i:ans){
      cout << i <<" ";
  }

}