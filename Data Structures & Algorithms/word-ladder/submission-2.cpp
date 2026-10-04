class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(),wordList.end());
        if(!wordSet.count(endWord)) return 0;
        unordered_map<string, vector<string>> patternMap;
        wordList.push_back(beginWord);

        for(const auto& word: wordList){
            for(int i=0; i<word.length(); i++){
                string pattern = word.substr(0,i) + '*' + word.substr(i+1);
                patternMap[pattern].push_back(word);
            }
        }

        // bfs
        queue<string> q;
        q.push(beginWord);
        unordered_set<string> visited;
        visited.insert(beginWord);
        int steps = 1;

        while(!q.empty()){
            int n = q.size();
            for(int i=0; i<n ; i++){
                string word = q.front();
                q.pop();
                if(word == endWord) return steps;
                for(int j=0; j<word.length() ; j++){
                    string pattern = word.substr(0,j) +'*'+ word.substr(j+1);
                    for(const string& neigh: patternMap[pattern] ){
                        if(!visited.count(neigh)){
                            q.push(neigh);
                            visited.insert(neigh);
                        }
                    }
                    patternMap[pattern].clear();
                }
            }
            steps++;
        }
        return 0;
    }
};
