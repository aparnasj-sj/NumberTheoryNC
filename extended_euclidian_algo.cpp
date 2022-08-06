int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
/*
In main we can call  gcd fun 
if gcd==1 
only them a has a modular mul inv wrt b 
else no inv wrt b
note: x and u are pass by reference here 
*/
