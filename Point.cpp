#include<iostream>
#include<cmath>
using namespace std;


#define eps (1e-10)
#define equals(a, b) (fabs((a)-(b)) < eps)
//差の絶対値の誤差がeps以下だったら等しいとする

struct Point{
    double x,y;

    Point(double x = 0,double y = 0): x(x), y(y) {}
    //コンストラクタ::x,yの初期化

    Point operator + (Point p) { return Point(x+p.x,y+p.y); }
    Point operator - (Point p) { return Point(x-p.x,y-p.y); }
    Point operator * (double a) { return Point(a*x, a*y); }
    Point operator / (double a) { return Point(x/a,y/a); }
    //演算子オーバーロード

    double abs() { return sqrt(norm()); }
    double norm() { return x*x + y*y; }
    //ベクトルの大きさ/ノルム計算

    bool operator < (const Point &p) const {
        return x != p.x ? x<p.x : y<p.y;
    }
    //何の大きさを比べているのか謎

    bool operator == (const Point &p) const {
        return fabs(x-p.x) < eps && fabs(y-p.y) < eps;
    }
    //ベクトルが同じかどうか
};

int main(){
    double a,b;
    cin >> a >> b;
    Point p(a,b);
    cout << p.x << " " << p.y << endl;
}