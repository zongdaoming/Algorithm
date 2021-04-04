#include <bits/stdc++.h>
#include<iostream>
using namespace std;

struct Point
{
    int x,y;
};

int main()
{
    int n;
    cin>>n;
    vector<Point> points(n);
    for(size_t i=0; i<n; i++)
    {
        cin>>points[i].x>>points[i].y;
    }
    // 按照y升序（从小到大）  x降序排列（从大刀到小）
    sort(points.begin(),points.end(),[](Point &p1, Point &p2)
    {
        return p1.y==p2.y?p1.x>p1.x:p1.y<p2.y;
    });
    cout<<points[n-1].x<<' '<<points[n-1].y<<endl;
    int maxx = points[n-1].x;
    // 逆序输出
    for(int i = n-2; i>=0; i--)
    {
        if(points[i].x>maxx)
        {
            cout<<points[i].x<<' '<<points[i].y<<endl;
            maxx = points[i].x;
        }
    }
    // for(int i = 0; i<points.size(); i++)
    // {
    //     cout<<points[i].x<<points[i].y<<endl;
    // }


    system("pause");

    return 0;

}



