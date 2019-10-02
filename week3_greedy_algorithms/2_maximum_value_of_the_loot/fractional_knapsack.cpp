#include <iostream>
#include <vector>
#include <unordered_map>
#include <bits/stdc++.h> 
using namespace std;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;

  // write your code here
  // vector<double> valperwt;
  map <double, int, greater<double>> valperwt;
  for(int i=0; i<weights.size(); i++){
    double temp = (double)values[i]/(double)weights[i];
    valperwt[temp] = i;
  }

  for(auto i=valperwt.begin(); i!=valperwt.end(); i++){
    int index = i->second;
    if(capacity>=weights[index]){
        capacity = capacity - weights[index];
        value = value + (double)values[index];
      }
      else{
        value = value + ((double)capacity*(i->first));
        break;
      }
  }
  value = round( value * 1000.0 ) / 1000.0;
  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
