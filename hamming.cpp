#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main() {
    string inp,intermidiate;
    int m,r=0;
    cout<<"Enter the message bits : ";
    cin>>inp;
    intermidiate = inp;
    reverse(inp.begin(),inp.end());
    cout<<endl<<inp<<endl;
    m = inp.length();
    cout<<"\nm = "<<m<<endl;;
    //2^r >= m+r+1
    while(pow(2,r) < m+r+1) {
        inp.insert(pow(2,r)-1,"x");
        r++;
    };
    cout<<endl<<r;
    cout<<endl<<inp<<endl;
    for(int i = 0; i < r; i++) {
        int rb = 0;
        int par = pow(2,i);
        for(int j = par+1;j<=inp.length();j++) {
            cout<<"length : "<<inp.length()<<endl;
            cout<<"j : "<<j;
            cout<<(j&par)<<" ";
            if(((j&par) == par) && inp[j-1] == '1') {
                cout<<"pos : "<<inp[j-1];
                rb++;
            }
        }
        cout<<endl;
        if(rb%2 == 0) {
            inp.replace(pow(2,i)-1,1,"0");
        }
        else {
            inp.replace(pow(2,i)-1,1,"1");
        }
        cout<<inp<<endl;
    }
    cout<<"String : "<<inp<<endl;
    reverse(inp.begin(),inp.end());
    cout<<endl<<inp<<endl;

    cout<<"-------------------------------------------------------------Reciever Side\n";
    string out;
    //introduce error
    srand(time(0));
    int pos = rand()%(inp.length());
    inp.replace(pos,1,to_string(rand()%2));
    reverse(inp.begin(),inp.end());
    cout<<inp<<endl;
    for(int i = 0; i < r; i++) {
        int rb = 0;
        int par = pow(2,i);
        for(int j = par;j<=inp.length();j++) {
            cout<<"length : "<<inp.length()<<endl;
            cout<<"j : "<<j;
            cout<<(j&par)<<" ";
            if(((j&par) == par) && inp[j-1] == '1') {
                cout<<"pos : "<<inp[j-1];
                rb++;
            }
        }
        cout<<endl;
        if(rb%2 == 0){
            cout<<" i : "<<i<<" insert 0\n";
            out.insert(0,"0");
        }
        else {
            cout<<" i : "<<i<<" insert 1\n";
            out.insert(0,"1");
        }
    }
    int res = stoi(out,0,2);
    cout<<res<<endl;
    int i;
    for(i=0;i<r;i++) {
        int x = pow(2,i);
        if(res%x == 0) {
            cout<<"No Error\n";
            break;
        }
    }
    if(i == r)
    cout<<"Error at position: "<<stoi(out,0,2)<<endl;
}