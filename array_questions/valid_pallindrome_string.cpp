#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// for any given string (including spaces and # and more) we need to create a string containing only charectors that are
/*
A-Z
a-z
0-9
ABSOLUTELY NO SPECIAL CHARECTORS 
*/

// the intermediate value will contain (A-Z)(a-z)(0-9) then we need to check if this forms a pallindrome
// after removal we will convert all the strings to lowercase for comparrision 
// we store all those in a temp string 
// after that in temp string we run the pallindrome check if its pallindrome we return true; 
class solution{
    private:
        bool is_valid(char ch){
            if((ch>='A' && ch<='Z')||(ch>='a'&&ch<='z')||(ch>='0' && ch<='9')){
                return true;
            }
            else{return 0;}
        }


        bool check_pallindrome(string s){
            int start = 0;
            int end = s.length() - 1;
            while(start<end){
                if(s[start] != s[end]){
                    return false;
                }
                else{
                    start++;
                    end--;
                }
                
            }
            return true;
        }

    public:
        bool valid_pallindrome(string s){
            // remove unnecesary chars
            int indx = 0;
            string temp = "";


            for(int jindx = 0;jindx<s.length(); jindx++){
                if(is_valid(s[jindx])){
                    temp.push_back(s[jindx]);
                }

            for(int tindx = 0; tindx<temp.length();tindx++){
                temp[tindx] = tolower(temp[tindx]);

            }
            }

            return check_pallindrome(temp);
        }
        
    
    
};

int main(void){
    string test1 = "race a car";
    string test2 = "A man, a plan, a canal: Panama";
    string test3 = "raceecar";

    solution ans;
    cout << ans.valid_pallindrome(test1) << endl;
    cout << ans.valid_pallindrome(test2) << endl;
    cout << ans.valid_pallindrome(test3) << endl;

    return 0;


}


