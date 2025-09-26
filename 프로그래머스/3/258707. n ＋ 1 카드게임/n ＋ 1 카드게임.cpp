#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int coin, vector<int> cards)
{
    vector<bool> hand(1000, false);
    vector<bool> reserve(1000, false);
    
    int cardCount = cards.size();
    int zeroCoinPairs = 0, oneCoinPairs =0, twoCoinPairs =0;
    
    for(int i=0; i<cards.size() / 3; i++)
    {
        hand[cards[i]] = true;
        if(hand[cards[i]] && hand[cardCount + 1 - cards[i]])
        {
            zeroCoinPairs++;
            hand[cardCount + 1 - cards[i]] = false;
        }
    }
    
    int round = 1;
    for(int i=cards.size() / 3; i<cardCount; i+=2)
    {
        int draw1 = cards[i];
        int draw2 = cards[i+1];
        
        reserve[draw1] = true;
        reserve[draw2] = true;
        
        if(reserve[draw1] && hand[cardCount + 1 - draw1])
        {
            oneCoinPairs++;
            reserve[draw1] = false;
            hand[cardCount + 1 - draw1] = false;
        }
        if(reserve[draw2] && hand[cardCount + 1 - draw2])
        {
            oneCoinPairs++;
            reserve[draw2] = false;
            hand[cardCount + 1 - draw2] = false;
        }
        if(reserve[draw1] && reserve[cardCount + 1 - draw1])
        {
            twoCoinPairs++;
            reserve[draw1] = false;
            reserve[cardCount + 1 - draw1] = false;
        }
        if(reserve[draw2] && reserve[cardCount + 1 - draw2])
        {
            twoCoinPairs++;
            reserve[draw2] = false;
            reserve[cardCount + 1 - draw2] = false;
        }
        
        if(zeroCoinPairs > 0)
        {
            zeroCoinPairs--;
            round++;
        }
        else if(oneCoinPairs > 0 && coin >= 1)
        {
            oneCoinPairs--;
            coin--;
            round++;
        }
        else if(twoCoinPairs > 0 && coin >= 2)
        {
            twoCoinPairs--;
            coin -= 2;
            round++;
        }
        else
            break;
    }
    
    return round;
}
