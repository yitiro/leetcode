/**
 * @brief https://leetcode.com/problems/valid-word-abbreviation/
 * @brief 408
 */

bool validWordAbbreviation(char * word, char * abbr){
    int num = 0;
    
    int word_idx = 0;
    int abbr_idx = 0;
    while (abbr_idx < 11){
        if (abbr[abbr_idx] >= 'a'){
            // English letter
            if (word[word_idx] != abbr[abbr_idx]) return false;
            abbr_idx ++;
            word_idx ++;
        }
        else if (abbr[abbr_idx] > '0') {
            num = atoi(abbr + abbr_idx);
            if (num < 9) abbr_idx ++;
            else abbr_idx += 2;
            
            while(num > 0 && word[word_idx] != '\0'){
                word_idx++;
                num --;
            }
            if (num > 0) return false;
        }
        else if (abbr[abbr_idx] == '\0'){
            return word[word_idx] == '\0';
        }
        else {
            return false;
            
        }
        
    }
    return false;
}