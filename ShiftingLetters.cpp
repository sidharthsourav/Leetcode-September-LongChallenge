/*

Problem statement.

You are given a string s of lowercase English letters and an integer array shifts of the same length.

Call the shift() of a letter, the next letter in the alphabet, (wrapping around so that 'z' becomes 'a').

For example, shift('a') = 'b', shift('t') = 'u', and shift('z') = 'a'.
Now for each shifts[i] = x, we want to shift the first i + 1 letters of s, x times.

Return the final string after all such shifts to s are applied.

 

Example 1:

Input: s = "abc", shifts = [3,5,9]
Output: "rpl"
Explanation: We start with "abc".
After shifting the first 1 letters of s by 3, we have "dbc".
After shifting the first 2 letters of s by 5, we have "igc".
After shifting the first 3 letters of s by 9, we have "rpl", the answer.
Example 2:

Input: s = "aaa", shifts = [1,2,3]
Output: "gfd"
 

Constraints:

1 <= s.length <= 105
s consists of lowercase English letters.
shifts.length == s.length
0 <= shifts[i] <= 109

*/


#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int final_char_excedes(ll x)
{
    x=x-122;
    x=x%26;
   // cout<<"final char function returning: "<<x+97<<endl;
    return x+96;
}
string shiftingLetters(string s, vector<int>& shifts) 
{
        
        ll total_shifts=0, dec_shift=0;;
        for(int i=0;i<shifts.size();i++) total_shifts+=shifts[i];
        for(int i=0;i<shifts.size();i++)
        {
            char x=s[i];
            ll final_char=x+total_shifts;
            if(i==0)
            { 
                if(final_char>122) final_char=final_char_excedes(final_char);
                s[i]=final_char;
            }
            else
            {
                dec_shift=dec_shift+shifts[i-1];
                final_char=x+total_shifts-dec_shift;
                if(final_char>122) final_char=final_char_excedes(final_char);
                s[i]=final_char;
            }

        }
        return s;
}

int main()
{
    string s="mkgfzkkuxownxvfvxasy";
    vector <int> shifts={505870226,437526072,266740649,224336793,532917782,311122363,567754492,595798950,81520022,684110326,137742843,275267355,856903962,148291585,919054234,467541837,622939912,116899933,983296461,536563513};
    cout<<shiftingLetters(s,shifts);
    
}