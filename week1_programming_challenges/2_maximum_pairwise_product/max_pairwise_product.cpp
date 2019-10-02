#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long MaxPairwiseProduct(vector<long long>& numbers) {

    // for (int first = 0; first < n; ++first) {
    //     for (int second = first + 1; second < n; ++second) {
    //         max_product = std::max(max_product,
    //             numbers[first] * numbers[second]);
    //     }
    // }

    sort(numbers.begin(), numbers.end(), greater<long long>());
    return numbers[0] * numbers[1];
}

int main() {
    long long n;
    cin >> n;
    vector<long long> numbers(n);
    for (long long i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}
