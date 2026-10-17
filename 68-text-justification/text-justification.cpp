class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int n = words.size();
        int i = 0;

        while (i < n) {
            int j = i;
            int letters = 0;

            // Step 1: Greedily pack as many words as possible
            while (j < n && letters + words[j].size() + (j - i) <= maxWidth){
                letters += words[j].size();
                j++;
            }

            int wordCount = j - i;
            int spaces = maxWidth - letters;
            string line = "";

            // Step 2: Last line OR only one word -> left-justified
            if (j == n || wordCount == 1){
                for (int k = i; k < j; k++){
                    line += words[k];

                    if (k < j - 1)
                        line += ' ';
                }

                line += string(maxWidth - line.size(), ' ');
            }
            else{
                // Fully justified line
                int gaps = wordCount - 1;
                int spacesPerGap = spaces / gaps;
                int extraSpaces = spaces % gaps;

                for (int k = i; k < j; k++){
                    line += words[k];

                    if (k < j - 1){
                        int count = spacesPerGap;

                        // Leftmost gaps get the extra spaces
                        if (k - i < extraSpaces)
                            count++;

                        line += string(count, ' ');
                    }
                }
            }

            ans.push_back(line);
            i = j;
        }

        return ans;
    }
};
