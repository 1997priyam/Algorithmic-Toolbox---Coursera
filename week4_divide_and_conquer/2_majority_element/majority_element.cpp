#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <bits/stdc++.h> 
using namespace std;

int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  //write your code here
  std::unordered_map<int, int> lookup;
  for(int i=0; i<a.size(); i++){
    if ( lookup.find(a[i]) == lookup.end() ) {
      lookup[a[i]] = 1;
    } else {
      lookup[a[i]] += 1; 
    }
  }
  int threshold = a.size()/2;
  for(int i=0; i<a.size(); i++){
    if(lookup[a[i]] > threshold) return 1;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
