class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x){
        if(x==parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    void Union(int x,int y){
        int x__par = find(x);
        int y__par = find(y);

        if(x__par == y__par){
            return;
        }

        if(rank[x__par]>rank[y__par]){
            parent[y__par] = x__par;
        }
        else if(rank[x__par]<rank[y__par]){
            parent[x__par] = y__par;
        }
        else{
            parent[x__par] = y__par;
            rank[y__par]++;
        }
    }



    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(25,0);

        for(int i=0;i<26;i++){
            parent[i]=i;
        }

        for(string &s : equations){
            if(s[1]=='='){
                Union(s[0]-'a',s[3]-'a');
            }
        }

        for(string &s : equations){
            if(s[1]=='!'){
                int parfirst = find(s[0]-'a');
                int parsec = find(s[3]-'a');

                if(parfirst==parsec) return false;
            }
        }

        return true;





        
    }
};