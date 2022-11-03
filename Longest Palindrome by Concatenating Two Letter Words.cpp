You are given an array of strings words. Each element of words consists of two lowercase English letters.

Create the longest possible palindrome by selecting some elements from words and concatenating them in any order. Each element can be selected at most once.

Return the length of the longest palindrome that you can create. If it is impossible to create any palindrome, return 0.

A palindrome is a string that reads the same forward and backward.

 

Example 1:

Input: words = ["lc","cl","gg"]
Output: 6
Explanation: One longest palindrome is "lc" + "gg" + "cl" = "lcggcl", of length 6.
Note that "clgglc" is another longest palindrome that can be created.
Example 2:

Input: words = ["ab","ty","yt","lc","cl","ab"]
Output: 8
Explanation: One longest palindrome is "ty" + "lc" + "cl" + "yt" = "tylcclyt", of length 8.
Note that "lcyttycl" is another longest palindrome that can be created.
Example 3:

Input: words = ["cc","ll","xx"]
Output: 2
Explanation: One longest palindrome is "cc", of length 2.
Note that "ll" is another longest palindrome that can be created, and so is "xx".
  
  
  
  
  
  Sol:

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int>mp;
        int n=words.size();
        for(auto it : words)
        {
            mp[it]++;
        }
        int cnt=0;
        bool flag=false;
       for(int i=0;i<n;i++)
       {
           string t=words[i];
           reverse(t.begin(),t.end());
            if(words[i]==t && mp[t]%2==0)
            {
                cnt+=mp[t]*2;
                mp[t]=0;
            }
           if(words[i]==t && mp[t]%2!=0)
            {
                cnt+=(mp[t]-1)*2;
               flag=true;
               mp[t]=0;
               
            }
             
               if(mp.find(t)!=mp.end())
           {
               int m=min(mp[t],mp[words[i]]);
                 cnt+=m*4;
                   mp[words[i]]=0;
                   mp[t]=0;
               
           }
               
               
           
       }
        if(flag)cnt+=2;
        return cnt;
    }
};
