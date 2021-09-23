#include<bits/stdc++.h>
using namespace std;

void insert(vector<int>&v1,int tmp)
{
        if(v1.size()==0 || v1[v1.size()-1]<=tmp)
        {
                v1.push_back(tmp);
                return;
        }
        int tmp1=v1[v1.size()-1];
        v1.pop_back();
        insert(v1,tmp);
        v1.push_back(tmp1);
}
void sort(vector<int>&v1)
{
        if(v1.size()==1)
        {
                return;     
        }
        int tmp=v1[v1.size()-1];
        v1.pop_back();
        sort(v1);
        insert(v1,tmp);
        
}
int main()
{
        vector<int>v1={3,1,4,0,111,2};
        sort(v1);
        for(int i=0;i<v1.size();i++)
                cout << v1[i] << " ";
}