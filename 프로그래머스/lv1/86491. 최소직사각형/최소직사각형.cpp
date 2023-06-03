#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int max_width = 0;
    int max_height = 0;
    
    for(auto& size : sizes)
    {
        sort(size.begin(), size.end());
        max_width = max(max_width, size[0]);
        max_height = max(max_height, size[1]);
    }
    
    return max_width * max_height;
}