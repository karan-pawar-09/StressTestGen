/*
author:Karan
created:23.08.2021 22:20:42
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

struct testcase{
    int n;
    string s;
};

int randomNumber(int a,int b){    
    srand(time(0));
    return a + (rand() % b);
}

string randomString(const int len) {    
    string tmp_s;
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    
    srand( (unsigned) time(NULL) * getpid());
    tmp_s.reserve(len);
    for (int i = 0; i < len; ++i) 
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];    
    
    return tmp_s;    
}

testcase generateTestCase(){
    testcase randomTest;
    randomTest.n = randomNumber(1,10);
    randomTest.s = randomString(randomTest.n);
    return randomTest;
}
string bruteForce(testcase T){
    reverse(all(T.s));
    return T.s;
}
string optimizedSolution(testcase T){
    string ans;
    for(int i=T.s.size()-1;i>=0;i--) {
        ans.push_back(T.s[i]);
    }
    return ans;
}

bool debugger(int &t){
    testcase random = generateTestCase();
    string  ans1 = bruteForce(random);
    string ans2 = optimizedSolution(random);
    if(ans1 != ans2) {
        cout<<"WA on testcase "<<t<<endl;
        cout<<ans1<<" "<<ans2<<endl;
        return false;
    }
    else {
        cout<<"AC on testcase "<<t<<endl;
        return true;
    }
}


bool solve(int &t){
    if(!debugger(t)) {
        return false;
    }
    else {
        return true;
    }
}

int32_t main(){
    int t;
    cin>>t;
    for(int i=1;i<=t;i++) {
        if(!solve(i)) break;
    }
    return 0;
}
