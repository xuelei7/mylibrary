// from
// aoj0004
pair<double,double> solveLinearEquation(double a, double b, double c, double d, double e, double f) {
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