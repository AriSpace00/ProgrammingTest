#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> dice;

void dfs(int index, int sum, int size, vector<int>& sums, vector<int>& team)
{
    if(index == size)
    {
        sums.push_back(sum);
        return;
    }
    
    for(int face : dice[team[index]])
        dfs(index+1, sum+face, size, sums, team);
}

vector<int> getSums(vector<int>& team)
{
    vector<int> sums;
    dfs(0, 0, team.size(), sums, team);
    return sums;
}

vector<int> solution(vector<vector<int>> inDice) 
{
    dice = inDice;
    int diceCount = dice.size();
    
    long long bestWin = -1;
    vector<int> answer;
    
    vector<int> comb(diceCount, 0);
    fill(comb.begin(), comb.begin() + diceCount/2, 1);
    
    do
    {
        vector<int> teamA, teamB;
        for(int i=0; i<diceCount; i++)
        {
            if(comb[i] > 0)
                teamA.push_back(i);
            else
                teamB.push_back(i);
        }
        
        vector<int> sumsA = getSums(teamA);
        vector<int> sumsB = getSums(teamB);
        sort(sumsB.begin(), sumsB.end());
        
        long long winCount =0;
        for(int x : sumsA)
        {
            winCount += lower_bound(sumsB.begin(), sumsB.end(), x) - sumsB.begin();
        }
        
        if(winCount > bestWin)
        {
            bestWin = winCount;
            answer = teamA;
        }
        
    } while (prev_permutation(comb.begin(), comb.end()));
    
    for(int& i : answer)
        i++;
    
    return answer;
}