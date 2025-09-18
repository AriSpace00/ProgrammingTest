#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int solution(vector<vector<int>> maps)
{
    int col = maps.size();
    int row = maps[0].size();

    queue<tuple<int, int, int>> bfs;
    vector<vector<bool>> visited(col, vector<bool>(row, false));

    bfs.push({ 0, 0, 1 });
    visited[0][0] = true;

    vector<int> dirX = { 1, 0, -1, 0 };
    vector<int> dirY = { 0, 1, 0, -1 };

    while (!bfs.empty())
    {
        tuple<int, int, int> current = bfs.front();
        int currentX = get<0>(current);
        int currentY = get<1>(current);
        int currentDistance = get<2>(current);
        
        bfs.pop();

        if (currentX == (row - 1) && currentY == (col - 1))
            return currentDistance;

        for (int i = 0; i < dirX.size(); i++)
        {
            int nextX = currentX + dirX[i];
            int nextY = currentY + dirY[i];

            if (nextX < 0 || nextX >= row || nextY < 0 || nextY >= col)
                continue;

            if (maps[nextY][nextX] == 0 || visited[nextY][nextX])
                continue;

            visited[nextY][nextX] = true;
            bfs.push({ nextX, nextY, currentDistance + 1 });
        }
    }

    return -1;
}