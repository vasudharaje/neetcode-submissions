class Solution {

private: 
    vector<vector<int>> memo;
    int dfs(string& s, string& t, int i, int j){
        if(j==t.size()) return 1;
        if(i==s.size() && j!= t.size()) return 0;
        if(memo[i][j]!= -1) return memo[i][j];
        int count=0;
        int include = 0;
        int skip = 0;
        if( i<s.size() && s[i] == t[j]){
            include = dfs(s,t, i+1, j+1);
            skip = dfs(s,t,i+1,j);
            count = include + skip;
        }
        if( i<s.size() && s[i] != t[j]){
            count = dfs(s,t,i+1, j);
        }
        return memo[i][j] = count;;

    }

public:
    int numDistinct(string s, string t) {
        //state variable = i,j
        // decision to make = to include this i or no, can only include if s[i] == t[j]
        // recurrance relation is dfs(i,j) = dfs(i is included) + dfs(i is not included)
        //dfs(i is included) -> new state = s(i+1,j+1)
        //dfs(i is not included) -> new state = s(i+1, j)
        //base state -> if(i = s.size() , j!= t.size()) return 0 if(i = s.size(), j = t.size()) return 1;
        // store memo[i][j] where it stores ways past i, j 
        memo.assign(s.size()+1, vector<int>(t.size()+1,-1));
        return dfs(s,t,0,0);
    }
};
