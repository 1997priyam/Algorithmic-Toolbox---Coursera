#include <iostream>

int get_change(int m) {
  //write your code here
  int n = 0;
  if(m>=10){
    int temp = m/10;
    m = m%10;
    n = n + temp;
  }
  if(m>=5){
    int temp = m/5;
    m = m%5;
    n = n + temp;
  }
  n = n+m;
  return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
