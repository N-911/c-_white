int Factorial(int f) {
    int res = 1;

    if (f == 0)
        return 1;
    else if (f < 0)
        return 1;
    else {
        while (f > 1) {
            res *= f;
            f--;
        }
        return res;
    }
}
