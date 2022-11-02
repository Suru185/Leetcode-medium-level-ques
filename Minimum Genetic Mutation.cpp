A gene string can be represented by an 8-character long string, with choices from 'A', 'C', 'G', and 'T'.
Suppose we need to investigate a mutation from a gene string start to a gene string end where one mutation is defined as one single character changed in the gene string.

For example, "AACCGGTT" --> "AACCGGTA" is one mutation.
There is also a gene bank bank that records all the valid gene mutations. A gene must be in bank to make it a valid gene string.

Given the two gene strings start and end and the gene bank bank, return the minimum number of mutations needed to mutate from start to end. If there is no such a mutation, return -1.
Note that the starting point is assumed to be valid, so it might not be included in the bank.

 

Example 1:
Input: start = "AACCGGTT", end = "AACCGGTA", bank = ["AACCGGTA"]
Output: 1
  
Example 2:
Input: start = "AACCGGTT", end = "AAACGGTA", bank = ["AACCGGTA","AACCGCTA","AAACGGTA"]
Output: 2
  
  
Solution:

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
       unordered_set<string>st(bank.begin(),bank.end());
        queue<string>q;
        q.push(start);
        int count=0,n;
        string curr,t;
        while(!q.empty())
        {
            n=q.size();
            while(n--)
            {
                curr=q.front();
                q.pop();
                st.erase(curr);
                if(curr==end)return count;
                for(int i=0;i<8;i++)
                {
                    t=curr;
                    t[i]='A';
                    if(st.count(t))
                        q.push(t);
                     t[i]='C';
                    if(st.count(t))
                        q.push(t);
                     t[i]='G';
                    if(st.count(t))
                        q.push(t);
                     t[i]='T';
                    if(st.count(t))
                        q.push(t);
                }
                
            }
            count++;
        }
        return -1;
    }
};
