class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string res =""; //contain resultent string
        priority_queue<pair<int,char>>maxheap;  //to strore max freq on top of queue
        for(auto [cnt,ch] : {make_pair(a,'a'),make_pair(b,'b'),make_pair(c,'c')})  //stores as {count,char} = frequency of three char 
          if(cnt>0)maxheap.push({cnt,ch});  //eleminate those who have 0 freq

         while(!maxheap.empty()){   //travese till maxheap has char left inside
            auto [cnt_curr,ch_curr] = maxheap.top(); //stors currcount and currchar with max freq
            maxheap.pop();  // Remove it from the queue
    
            // If appending this character doesn't violate the rule of having > 2 consecutive characters
            if (res.size() < 2 || res.back() != ch_curr || res[res.size() - 2] != ch_curr) {
                res += ch_curr; // Append the character to the result
                cnt_curr--;     // Decrease its frequency
                if (cnt_curr > 0) {
                    maxheap.push({cnt_curr, ch_curr}); // Reinsert the character with updated frequency
                }
            } else {
                // If we can't append this character, we need to check the next most frequent character
                if (maxheap.empty()) break;  // No other characters available, we cannot proceed
                
                auto [cnt_next, ch_next] = maxheap.top();  // Get the next most frequent character
                maxheap.pop();  // Remove it from the queue
                
                res += ch_next; // Append this second character
                // Decrease its frequency
                if (--cnt_next > 0) {
                    maxheap.push({cnt_next, ch_next}); // Reinsert the second character with updated frequency
                }
                maxheap.push({cnt_curr, ch_curr});  // Reinsert the original character
            }
        }
        return res;
    }
};      