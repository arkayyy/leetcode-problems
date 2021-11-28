class Solution
{
public:
    struct elem
    {
        int x;
        int y;
        int k;
        int dist;

        elem(int _x, int _y, int _k, int _dist)
        {
            x = _x;
            y = _y;
            k = _k;
            dist = _dist;
        }
    };
    int shortestPath(vector<vector<int>> &grid, int k)
    {
        queue<elem *> q;

        q.push(new elem(0, 0, k, 0));

        int r = grid.size(), c = grid[0].size();

        int mini = INT_MAX;

        //here we are taking a different kind of 3-D visited array.
        //The first two coordinates are obvio the coordinates of row and column in the grid, but the third coordinate is the no. of obstacle eliminations (k) still left.
        //We are doing this in order to get the most optimal/minimum number of steps.
        //So for multiple values of k left, the same coordinate in the grid can be visited, so that at last we get the minimum number of steps after eliminating obstacles accross any path possible

        //NOTE: If we use a normal 2D array, we can visit every coordinate in the grid only once.
        //But what if once the coordinate is visited without any obstacle removed before, it will be marked visited permanently, and in the future if any such shorter path is possible by removing any obstacle,
        //...this coordinate would not be included in that path,since it is already marked visited.

        vector<vector<vector<bool>>> v(r, vector<vector<bool>>(c, vector<bool>(k + 1, false)));

        v[0][0][k] = true;

        while (!q.empty())
        {
            int x = q.front()->x;
            int y = q.front()->y;
            int kleft = q.front()->k;
            int dist = q.front()->dist;

            q.pop();

            if (x == r - 1 && y == c - 1)
                return dist;

            //checking in all 4 directions
            if (x + 1 < r && !v[x + 1][y][kleft])
            {
                if (grid[x + 1][y] == 1)
                {
                    if (kleft > 0)
                        q.push(new elem(x + 1, y, kleft - 1, dist + 1));
                }
                else
                {
                    q.push(new elem(x + 1, y, kleft, dist + 1));
                }
                v[x + 1][y][kleft] = true;
            }

            if (x - 1 >= 0 && !v[x - 1][y][kleft])
            {
                if (grid[x - 1][y] == 1)
                {
                    if (kleft > 0)
                        q.push(new elem(x - 1, y, kleft - 1, dist + 1));
                }
                else
                {
                    q.push(new elem(x - 1, y, kleft, dist + 1));
                }
                v[x - 1][y][kleft] = true;
            }

            if (y + 1 < c && !v[x][y + 1][kleft])
            {
                if (grid[x][y + 1] == 1)
                {
                    if (kleft > 0)
                        q.push(new elem(x, y + 1, kleft - 1, dist + 1));
                }
                else
                {
                    q.push(new elem(x, y + 1, kleft, dist + 1));
                }
                v[x][y + 1][kleft] = true;
            }

            if (y - 1 >= 0 && !v[x][y - 1][kleft])
            {
                if (grid[x][y - 1] == 1)
                {
                    if (kleft > 0)
                        q.push(new elem(x, y - 1, kleft - 1, dist + 1));
                }
                else
                {
                    q.push(new elem(x, y - 1, kleft, dist + 1));
                }
                v[x][y - 1][kleft] = true;
            }
        }

        return -1;
    }
};