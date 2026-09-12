class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st;

        for(auto word: wordList)
            st.insert(word);

        if(st.find(endWord)== st.end())
            return 0;

        queue<pair<string, int>> q;
        st.erase(beginWord);
        q.push({beginWord, 1});

        while(!q.empty()){
            string word= q.front().first;
            int steps= q.front().second;

            q.pop();

            if(word== endWord)
                return steps;

            for(int i=0; i<word.size(); i++){
                string temp= word;
                
                for(char ch= 'a'; ch<= 'z'; ch++){
                    temp[i]= ch;

                    if(st.find(temp)!= st.end()){
                        st.erase(temp);
                        q.push({temp, steps+1});
                    }

                }
            }
        }
        return 0;
    }
};