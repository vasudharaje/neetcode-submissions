class Solution {

private:
    unordered_map<char, unordered_set<char>> adj;
    unordered_map<char, int> visit;
    string result;

    bool dfs(char c){
        if(visit[c] == 1) return true;
        if(visit[c] == 2) return false;
        visit[c] = 1;
        for(char neighbour: adj[c]){
            if(dfs(neighbour)){
                return true;
            }
        }

        visit[c] = 2;
        result.push_back(c);
        return false;
    }
    

public:
    string foreignDictionary(vector<string>& words) {

        for(const string& word: words){
            for(char c: word){
                adj[c] = {};
            }
        }

        for(int i=0; i<words.size()-1 ; i++){
            string w1 = words[i];
            string w2 = words[i+1];
            int minlen = min(w1.length(), w2.length());

            if(w1.length() > w2.length() && w2 == w1.substr(0, minlen)){
                return "";
            }
            int j=0;
            while(j < minlen && w1[j] == w2[j]){
                j++;
            }
            if (j < minlen) {
                adj[w1[j]].insert(w2[j]);
            }
        }

        for(const auto& [ch,_] : adj){
            if(visit[ch] == 0){
                if(dfs(ch)){
                    return "";
                }
            }
        }

        reverse(result.begin(),result.end());
        return result;
    }
};
