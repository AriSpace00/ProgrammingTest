#include <string>
#include <vector> 
#include <map> 
#include <sstream>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) 
{
    map<string, int> stringToIndex;
    for(int i=0; i<friends.size(); i++)
    {
        stringToIndex.insert({friends[i], i});
    }
    
    vector<vector<int>> giftCount(friends.size(), vector<int>(friends.size(), 0)); 
    for (string s : gifts)
    {
        stringstream ss(s);
        string word;
        vector<string> tokens;
        while(ss >> word)
        {
            tokens.push_back(word);
        }
        
        string giver = tokens[0];
        string receiver = tokens[1];
        giftCount[stringToIndex[giver]][stringToIndex[receiver]]++;
    }
    
    vector<int> giftDiff(friends.size(), 0);
    for (int i=0; i<giftCount.size(); i++)
    {
        int giveCount =0;
        for(int j=0; j<giftCount[0].size(); j++)
        {
            giveCount += giftCount[i][j];
        }
        
        int receiveCount =0;
        for(int j=0; j<giftCount.size(); j++)
        {
            if(i == j)
                continue;
            
            receiveCount += giftCount[j][i];
        }
        
        giftDiff[i] = giveCount - receiveCount;
    }

    vector<int> nextMonth(friends.size(), 0);
    for (int i=0; i<giftCount.size() - 1; i++)
    {
        for(int j=i+1; j<giftCount[0].size(); j++)
        {
            if (giftCount[i][j] > giftCount[j][i])
            {
                nextMonth[i]++;
            }
            else if(giftCount[i][j] < giftCount[j][i])
            {
                nextMonth[j]++;
            }
            else
            {
                if(giftDiff[i] > giftDiff[j])
                    nextMonth[i]++;
                else if(giftDiff[i] < giftDiff[j])
                    nextMonth[j]++;
            }
        }
    }
    
    int result =0;
    for(int i : nextMonth)
    {
        if(result < i)
        {
            result = i;
        }
    }
    
    return result;
}