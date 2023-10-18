#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    set<int> pokemon;
    
    for(auto num:nums)
    {
        pokemon.insert(num);
    }
    
    if(pokemon.size() < nums.size() / 2)
    {
        return pokemon.size();
    }
    else
    {
        return nums.size() / 2;
    }
}