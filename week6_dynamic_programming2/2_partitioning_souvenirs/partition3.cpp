#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int partition3(vector<int> &A) {
  //write your code here
  return 0;
}

bool canPartition(vector<int>& nums, int k) 
{
    int sum0=accumulate(nums.begin(),nums.end(),0);
    if(sum0%k) return 0;
    //discrete knapsack without repeti 
    int n=nums.size();
    vector<vector<int> > value(sum0/k+1,vector<int>(n+1));
    for(int i=1;i<=n;i++)
    {
        int wi=nums[i-1];
        //cout<<wi<<endl;
        for(int w=1;w<=sum0/k;w++) //all smaller problems
        {
            value[w][i]=value[w][i-1];//if w>wi then it use previous value
            if(w>=wi)
            {
                value[w][i]=max(value[w-wi][i-1]+wi,value[w][i-1]);                    
            }
        }
     }
    return value[sum0/k][n]==sum0/k; 
	}

int main() {
  int n, k=3;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
  }
  std::cout << canPartition(A, k) << '\n';
}
