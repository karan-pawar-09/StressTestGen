/*
author:Karan
created:23.08.2021 22:20:42
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'


//------------------------------------------------------------------------------------------------------------//
struct testcase{
    int n;
    vector<vector<int>> arr;
};

int randomNumber(int a,int b){    
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

vector<vector<int>> randomMatrix(const int n) {
    srand( time(0));
    vector<vector<int>> ans(n);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            int p=randomNumber(1,10);
            ans[i].push_back(p);           
        }       
    }

    return ans;
}
vector<int> randomArray(const int n) {
    srand(time(0));
    vector<int> ans(n);
    for(int i=0;i<n;i++) {
        int p=randomNumber(1,10);
        ans[i]=p;
    }
    return ans;
}
testcase generateTestCase(){
    srand( time(0));
    testcase randomTest;
    randomTest.n = randomNumber(2,2);
    randomTest.arr= randomMatrix(randomTest.n);
    return randomTest;
}


int bruteForce(testcase T){
    return 1;
}

int optimizedSolution(testcase T){
    return 1;
}

bool debugger(int &t){
    testcase random = generateTestCase();
    int ans1 = bruteForce(random);
    int ans2 = optimizedSolution(random);
    if(ans1 != ans2) {
        cout<<"WA on testcase "<<t<<endl;
        for(int i=0;i<random.arr.size();i++) {
            for(int j=0;j<random.arr.size();j++) {
                cout<<random.arr[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
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
