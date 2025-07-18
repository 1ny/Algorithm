#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int max_width, max_height;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    for(int i=0; i<sizes.size(); i++) {
        if(sizes[i][0] > sizes[i][1]) {
            max_width = max(max_width, sizes[i][0]);
            max_height = max(max_height, sizes[i][1]);
        }
        else
        {
            max_width = max(max_width, sizes[i][1]);
            max_height = max(max_height, sizes[i][0]);
        }
    }
    
    answer = max_width * max_height;
    
    return answer;
}