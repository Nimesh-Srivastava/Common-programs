#include<bits/stdc++.h>
using namespace std;

int nextSp(long long int q, long long int rem) {
    int qDig = 0;
    while(q){
        qDig++;
        q /= 10;
    }

    int rDig = 0;
    while(rem){
        rDig++;
        rem /= 10;
    }

    int ans = pow(10, (qDig - rDig));
    return ans / 10;
}

void disp(vector<int>& v) {
    int cnt = v.size();

    while(cnt--)
        cout << " ";
}

void cal(long long int n, vector<int>& v) {
    while(n > 0) {
        v.push_back(0);
        n /= 10;
    }
}

void printLine(int n) {
    while(n) {
        cout << "-";
        n /= 10;
    }
}

int factor(long long int& a, long long int& b) {
    
    long long int divisor = a > b ? b : a;
    long long int dividend = a > b ? a : b;

    long long int rem = dividend;
    long long int hcf = 0;

    vector<int> space;
    cal(divisor, space);

    while(rem) {
        hcf = divisor;
        int q = dividend / divisor;
        rem = dividend % divisor;

        cout << endl;
        disp(space);
        cout << divisor << " ) " << dividend << " ( " << q << endl;
        
        cal(divisor * 10, space);
        int nxt = nextSp(dividend, divisor * q);
        cal(nxt, space);
        disp(space);
        cout << "- " << divisor * q << endl;
        if(nxt != 0)
            space.pop_back();
        
        disp(space);
        cout << " ";
        printLine(dividend * 100);

        nxt = nextSp(dividend, rem);
        cal(10, space);
        cal(nxt, space);

        dividend = divisor;
        divisor = rem;
    }
    cout << endl;
    space.pop_back();
    disp(space);
    cout << "0";
    return hcf;
}

int main() {
    
    long long int n1, n2;
    
    cout << "\nFind HCF\n";
    cout << "Input number 1 : ";
    cin >> n1;

    cout << "Input number 2 : ";
    cin >> n2;

    cout << "\nLong division :-\n";
    long long int ans = factor(n1, n2);

    cout << "\n\nHCF of " << n1 << ", " << n2 << " : " << ans << endl;
    return 0;
}
