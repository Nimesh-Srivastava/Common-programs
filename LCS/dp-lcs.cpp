# include <bits/stdc++.h>
using namespace std;

// finding lcs
int lcs(string& s1, string& s2, int l1, int l2){
    
    if(l1 == 0 || l2 == 0)
        return 0;

    if(s1[l1- 1] == s2[l2 - 1])
        return 1 + lcs(s1, s2, l1 - 1, l2 - 1);

    else
        return max(lcs(s1, s2, l1 - 1, l2), lcs(s1, s2, l1, l2 - 1));

}

int main(void){
    string s1;
    string s2;

    cout << "Input string 1 : ";
    cin >> s1;

    cout << "Input string 2 : ";
    cin >> s2;

    cout << "\nLength of LCS is : " << lcs(s1, s2, s1.length(), s2.length());

    return 0;
}
