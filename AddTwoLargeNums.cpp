#include<bits/stdc++.h>
using namespace std;

void getInput(string& s, int val) {
    cout << "Enter number " << val << " : ";
    cin >> s;
}

void clean(vector<int>& v) {
    int siz = v.size() - 1;

    while(v[siz] == 0) {
        v.pop_back();
        siz--;
    }

    reverse(v.begin(), v.end());
}

vector<int> convert(string& s) {
    int len = s.size();

    vector<int> v;

    for(int i = 0; i < len; i++)
        v.push_back(s[i] - '0');

    reverse(v.begin(), v.end());

    return v;
}

void mod(vector<int>& v, int len) {
    int diff = len - v.size();

    if(v.size() < len) {
        for(int i = 0; i < diff; i++)
            v.push_back(0);
    }
}

void add(string& s1, string& s2, vector<int>& v3) {

    vector<int> v1 = convert(s1);
    vector<int> v2 = convert(s2);

    int len = max(v1.size(), v2.size());
    mod(v1, len);
    mod(v2, len);

    int c = 0;

    for(int i = 0; i < len; i++) {
        int temp = v1[i] + v2[i] + c;
        c = temp / 10;
        v3.push_back(temp % 10);
    }

    v3.push_back(c);

    clean(v3);
}

void display(vector<int>& v, string& s1, string& s2) {
    if(s2.size() > s1.size())
        swap(s1, s2);

    int diff = v.size() - s1.size() + 3;

    for(int i = 0; i < diff; i++)
        cout << " ";
    cout << s1 << endl;

    cout << " + ";
    diff = v.size() - s2.size();
    for(int i = 0; i < diff; i++)
        cout << " ";
    cout << s2 << endl;

    for(int i = 0; i < v.size() + 3; i++)
        cout << "-";
    cout << endl;

    cout << "   ";
    for(int i = 0; i < v.size(); i++)
        cout << v[i];
}

int main() {
    
    string s1, s2;

    getInput(s1, 1);
    getInput(s2, 2);

    vector<int> ans;

    add(s1, s2, ans);
    
    display(ans, s1, s2);
    
    return 0;
}
