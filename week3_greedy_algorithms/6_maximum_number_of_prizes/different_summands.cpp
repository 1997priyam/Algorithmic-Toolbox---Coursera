#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  //write your code here
  if(n==0) return summands;
  int num = 1;
  while(n!=0){
    if(n-num<=num){
      summands.push_back(n);
      n = n - n;
    }
    else{
      summands.push_back(num);
      n = n - num;
    }
    num++;
  }
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
