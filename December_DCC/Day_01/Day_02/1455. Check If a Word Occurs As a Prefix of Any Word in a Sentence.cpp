// class Solution {
// public:
//     int isPrefixOfWord(string sentence, string searchWord) {
//         istringstream stream(sentence);  // Use string stream to split the sentence into words
//         string word;
//         int position = 1;  // To keep track of the word position

//         while (stream >> word) {  // Read each word from the sentence
//             if (word.find(searchWord) == 0) {  // Check if the word starts with searchWord
//                 return position;  // Return the word position (1-based index)
//             }
//             position++;  // Move to the next word
//         }

//         return -1;  // If no word starts with searchWord
//     }
// };


// TRIE Data Structure
class Solution {
    struct trienode{
        int idx;
        unordered_map<char,trienode*> child;
    };
    trienode *root = new trienode;

    void trieInsert(string& word,int index){
        trienode* curr = root;
        for(int i=0;word[i];++i){
            if(!curr->child.count(word[i])){
                curr->child[word[i]] = new trienode;
                curr->child[word[i]]->idx = index;
            }
            curr = curr->child[word[i]];
        }
    }
    int trieSearch(string& word){
        trienode* curr = root;
        for(int i=0;word[i];++i){
            if(!curr->child.count(word[i]))
                return -1;
            curr = curr->child[word[i]];
        }
        return curr->idx;
    }
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int n=sentence.size();
        int index=1;

        for(int i=0;i<n;++i){
            //Extract a word
            string word="";
            while(i<n and sentence[i]!=' '){
                word.push_back(sentence[i]);
                i++;
            }
            trieInsert(word,index);
            index++;
        }
        return trieSearch(searchWord);
    }
};
