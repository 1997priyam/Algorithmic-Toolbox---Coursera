#include <iostream>
#include <vector>
#include<bits/stdc++.h> 
using namespace std;

int get_change(int m) {
  //write your code here
  vector<int> M(m+1);
  M[0] = 0;
  for(int i=1; i<=m; i++){
    int minimum = INT_MAX;
    if(i>=1) minimum = min(minimum, 1+M[i-1]);
    if(i>=3) minimum = min(minimum, 1+M[i-3]);
    if(i>=4) minimum = min(minimum, 1+M[i-4]);
    M[i] = minimum;
  }
  return M[m];;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
