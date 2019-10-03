#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    // write your code here
    stops.push_back(dist);
    int num_stations = stops.size();
    int min_refill = 0;
    int prev_value = 0;
    int prev_index = -1;
    int current_index = 0;
    while(current_index!=num_stations){
        if(stops[current_index]-prev_value > tank && prev_index == (current_index - 1)){
            return -1;
        }
        else if(stops[current_index]-prev_value > tank){
            min_refill++;
            prev_index = current_index-1;
            prev_value = stops[prev_index];
        }
        else{
            current_index++;
        }
    }

    return min_refill;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
