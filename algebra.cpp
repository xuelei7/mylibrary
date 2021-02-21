// from
// aoj0004
pair<double,double> solveLinearEquation(double a, double b, double c, double d, double e, double f) {
    // solve this equation
    /****************
    |  ax + by = c  |
    |  dx + ey = f  |
    ****************/
    double x = (b * f - c * e) / (b * d - a * e);
    if (b * f - c * e == 0) x = 0;
    double y = (c * d - a * f) / (b * d - a * e);
    if (c * d - a * f == 0) y = 0;
    return {x,y};
}

// from
// aoj1327
typedef vector<int> vec;
typedef vector<vec> mat;
int mod = 1e9+7;
int MAXN = 55;
vec mul(mat m, vec v) {
    vec ret(MAXN);
    for (int i = 0; i < MAXN; i++) {
        for (int k = 0; k < MAXN; k++) {
            ret[i] += m[i][k] * v[k];
            ret[i] %= mod;
        }
    }
    return ret;
}
mat mul(mat a, mat b) {
    mat c(MAXN,vec(MAXN));
    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXN; j++) {
            for (int k = 0; k < MAXN; k++) {
                c[i][j] += a[i][k] * b[k][j];
                c[i][j] %= mod;
            }
        }
    }
    return c;
}
mat mul(mat m, int t) {
    if (t == 0) {
        mat ret(MAXN, vec(MAXN));
        for (int i = 0; i < MAXN; i++) ret[i][i] = 1;
        return ret;
    }
    mat ret = mul(m,t/2);
    ret = mul(ret,ret);
    if (t&1) ret = mul(ret,m);
    return ret;
}

// menu
// pair<double,double> solveLinearEquation(double a, double b, double c, double d, double e, double f)
// matrix multiply