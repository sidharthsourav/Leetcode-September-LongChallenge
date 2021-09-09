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