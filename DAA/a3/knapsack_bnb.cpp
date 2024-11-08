#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

class item{
    public:
    int weight;
    int value;
    double ratio;
};

class Node{
    public:
    int level;
    int profit;
    int weight;
    double bound;
    vector<int> includedItems;

};

bool Compare(item a,item b){
    return a.ratio > b.ratio;
}

double boundCal(Node u,int n,int W,vector<item>&items){
    if(u.weight >= W){
        return 0;
    }
    double profit_bound = u.profit;
    int j= u.level+1;
    int totalweight = u.weight;
    while((j<n) && (totalweight+items[j].weight <= W)){
        totalweight += items[j].weight;
        profit_bound += items[j].value;
        j++;
    }
    if (j<n){
        profit_bound = profit_bound + (W-totalweight)*items[j].ratio;
    }
    return profit_bound;
}

int knapsack(int W,vector<item>&items,vector<int>&selecteditems){
    int n = items.size();
    sort(items.begin(),items.end(),Compare);
    queue<Node>q;
    Node u,v;
    u = {-1,0,0,0};
    q.push(u);

    int max_profit = 0;

    while(!q.empty()){
        u = q.front();
        q.pop();

        if(u.level == -1){
            v.level = 0;
        }
        if(u.level == n-1){
            continue;
        }
        v.level = u.level+1;

        v.weight = u.weight + items[v.level].weight;
        v.profit = u.profit + items[v.level].value;
        v.includedItems = u.includedItems;
        v.includedItems.push_back(v.level);

        
        if(v.weight <= W && v.profit > max_profit){
            max_profit = v.profit;
            selecteditems = v.includedItems;
        }
        v.bound = boundCal(v,n,W,items);
        if(v.bound > max_profit){
            q.push(v);
        }

        v.weight = u.weight;
        v.profit = u.profit;
        v.includedItems = u.includedItems;
        v.bound = boundCal(v,n,W,items);

        if(v.bound > max_profit){
            q.push(v);
        }



    }
    return max_profit;
}

int main(){
    int W = 50;
    vector<item>items = {
        {10,60,6},{20,100,5},{30,120,4}
    };
    vector<int>selecteditems;
    int max_v = knapsack(W,items,selecteditems);
    for (int index : selecteditems) {
        cout << "Index: " << index 
             << ", Weight: " << items[index].weight 
             << ", Value: " << items[index].value << endl;
    }
    cout<<max_v;
    return 0;
}