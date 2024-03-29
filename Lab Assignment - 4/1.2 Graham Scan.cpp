// TC: O(n log(n))
// SC: O(n)
// Mahesh Reddy B N

#include<bits/stdc++.h>
using namespace std;

class Point    {
public:
    int x, y;
    bool operator < (Point b) {
        if (y != b.y)
            return y < b.y;
        return x < b.x;
    }
};

Point pivot;
int ccw(Point a, Point b, Point c) {
    int area = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    if (area > 0)
        return -1;
    else if (area < 0)
        return 1;
    return 0;
}
int sqrDist(Point a, Point b)  {
    int dx = a.x - b.x, dy = a.y - b.y;
    return dx * dx + dy * dy;
}
bool POLAR_ORDER(Point a, Point b)  {
    int order = ccw(pivot, a, b);
    if (order == 0)
        return sqrDist(pivot, a) < sqrDist(pivot, b);
    return (order == -1);
}
stack<Point> grahamScan(Point *points, int N)    {
    stack<Point> hull;
    if (N < 3)
        return hull;
    int leastY = 0;
    for (int i = 1; i < N; i++)
        if (points[i] < points[leastY])
            leastY = i;
    Point temp = points[0];
    points[0] = points[leastY];
    points[leastY] = temp;
    pivot = points[0];
    sort(points + 1, points + N, POLAR_ORDER);
    hull.push(points[0]);
    hull.push(points[1]);
    hull.push(points[2]);
    for (int i = 3; i < N; i++) {
        Point top = hull.top();
        hull.pop();
        while (ccw(hull.top(), top, points[i]) != -1)   {
            top = hull.top();
            hull.pop();
        }
        hull.push(top);
        hull.push(points[i]);
    }
    return hull;
}
int main()  {
    Point points[] = {{0, 0}, {1, 1}, {2, 2}, {3, -1}};
    int N = sizeof(points)/sizeof(points[0]);
    stack<Point> hull = grahamScan(points, N);
    while (!hull.empty())   {
        Point p = hull.top();
        hull.pop();
        cout<< p.x<<" "<<p.y<<endl;
    }
    return 0;
}