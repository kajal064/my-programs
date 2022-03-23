#include<bits/stdc++.h>
using namespace std;


int search(string pat, string txt) {
  unordered_map <char, int> m;
  for(auto i: pat)
  m[i]++;

  int k = pat.size();
  int count = m.size();
  int ans = 0;
  int i = 0, j = 0;

  while(j < txt.size()) {

  if(m.find(txt[j]) != m.end()) {
  m[txt[j]]--;
  }
  
  if(m[txt[j]] == 0){
  count--;
  }

  if(j - i + 1 < k) j++;

  else if(j - i + 1 == k) {
  if(count == 0)
  ans++;

  if(m.find(txt[i]) != m.end()) {
  m[txt[i]]++;
  }
  if(m[txt[i]] == 1){
  count++;
  }

  i++; j++;
  }
}

  return ans;
  }




int main(){

    string ptr = "aaba";
    string str = "aabaabaa";

    cout<<search(ptr, str);

    // map<char, int> m;
    // int k = str.length();
    // for(int i=0;i<4;i++){
    //     m[ptr[i]]++;
    // }

    // int i = 0;
    // int j = 0;
    // int ans = 0,count = m.size();
    // cout<<m['a'];
    // cout<<m['b'];
//  while(j < str.length()){

//    if(m.find(str[j]) != m.end()) {
//   m[str[j]]--;
//    }
//     if(m[str[j]]==0){
//         count--;
//     }

//     if(j-i+1 < k){
//         j++;
//     }else if(j-i+1 == k){
//         if(count == 0){
//             ans++;
//         }

//        if(m.find(str[i]) != m.end()) {
//   m[str[i]]--;
//        }
//         if(m[str[i]] == 0 ){
//         count++;
//     }

//         i++;
//         j++;
//     }

//  }

// cout<<ans<<endl;


    // cout<<ptr[0];



}