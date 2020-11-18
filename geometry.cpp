// from
// aoj0003
// given 3 length of edges, judge whether these edges forms a RIGHT triangle
bool isRightTriangle(int a, int b, int c) {
    if (b > a) {
        int k = b;
        b = a;
        a = k;
    }
    if (c > a) {
        int k = c;
        c = a;
        a = k;
    }
    return a * a == b * b + c * c;
}

// from
// aoj0010
// 三角形の頂点座標から外接円の円心座標と半径を求める
pair<pair<double,double>, double> CircumscribedCircleOfATriangle(double x1, double y1, double x2, double y2, double x3, double y3) {
    double px,py,r;
    py = ((x1-x3) * (x1*x1 - x2*x2 + y1*y1 - y2*y2) - (x1-x2) * (x1*x1 - x3*x3 + y1*y1 - y3*y3)) / (2 * ((y1-y2)*(x1-x3) - (y1-y3)*(x1-x2)));
    if (x1 != x2) px = (x1*x1 - x2*x2 + y1*y1 - y2*y2) / (2 * (x1-x2)) - py * (y1-y2) / (x1-x2);
    else px = (x1*x1 - x3*x3 + y1*y1 - y3*y3) / (2 * (x1-x3)) - py * (y1-y3) / (x1-x3);
    r = sqrt((x1 - px) * (x1 - px) + (y1 - py) * (y1 - py));
    return {{px,py},r};
}