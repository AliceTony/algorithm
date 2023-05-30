class Solution {
private:
    const int DX[9]{ -1 , 0 , 1 , -1 , 1 , -1 , 0 , 1 }, DY[9]{ 1 , 1 , 1 , 0 , 0 , -1 , -1 , -1 };
    int fx = 0, fy = 0;
    struct Point {
        int x;
        int y;
        double f;               //f = g + h
        int g;                  //�Ѿ��߹��Ĳ���
        double h;               //�����յ��Ԥ������
        Point(int x, int y, int g, double h) : x(x), y(y), f(g + h), g(g), h(h) {}
        Point() : x(0), y(0), f(0), g(0), h(0) {}
        bool operator < (const Point& b) const {
            return g < b.g;
        }
        bool operator > (const Point& b) const {
            return g > b.g;
        }
    };
    //�������յ��ֱ�߾���
    double getH(int x, int y) {
        return sqrt((x - fx) * (x - fx) + (y - fy) * (y - fy));
    }
    //����λ�Ƿ�Ϸ�
    bool check_Point(int x, int y) {
        if (x >= 0 && y >= 0 && x <= fx && y <= fy) return 1;
        else return 0;
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 1) return -1;
        fx = grid.size() - 1, fy = grid.size() - 1;
        priority_queue<Point, vector <Point>, greater<Point>> pq;     //Ӧ��������Щ�����յ����
        vector<vector <int>> vis(fx + 1, vector <int>(fx + 1, 0));     //��ǵ�ǰ��λ�Ƿ��߹�
        pq.push({ 0 , 0 , 1 , getH(0 , 0) });
        vis[0][0] = 1;
        while (!pq.empty()) {
            Point p = pq.top();
            pq.pop();
            if (p.x == fx && p.y == fy) return p.g;                      //��ǰ�ڵ�Ϊ�յ�
            for (int i = 0; i < 8; i++) {
                int nx = p.x + DX[i];
                int ny = p.y + DY[i];
                if (check_Point(nx, ny) && !vis[nx][ny] && !grid[nx][ny]) {
                    pq.push({ nx ,ny , p.g + 1 , getH(nx , ny) });
                    vis[nx][ny] = 1;
                }
            }
        }
        return -1;
    }
};