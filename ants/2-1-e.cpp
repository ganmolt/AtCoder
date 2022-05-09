#include<iostream>
#include<queue>

using namespace std;

int main(){
    queue<int> que;
    que.push(1);
    que.push(2);
    que.push(3);
    cout<<que.front()<<"\n";
    que.pop();
    cout<<que.front()<<"\n";
    que.pop();
    cout<<que.front()<<"\n";
    que.pop();
}