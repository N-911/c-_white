int Factorial(int f) {
    int res = 1;

    if (f < 2)
        return res;
    else {
        return f * Factorial(f -1);
    }
}
