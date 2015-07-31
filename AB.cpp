#include <iostream>
using namespace std;

class AB{
    public:
    	string createString(int, int);
};

string AB::createString(int N, int K){
    string ans = "";
    int ind_curr_a, ind_last_a;
    
    if(N % 2 == 1){
        if(K > (N/2)*((N/2)+1))
            return ans;
    }else{
        if(K > (N/2)*(N/2))
            return ans;
    }
    
    for(int i = 0; i < N - 1; i++){
        ans += 'B';
    }
    if(N <= 2){
        ans += 'A';
        ind_curr_a = N - 1;

        while(checkMatches(ans) != K)
    }else{
        ans += 'B';
    }
}

int checkMatches(string s){
    int indexA = 0, indexB = 0;
    int matches = 0;
    while(index < s.length()){
        while(s[i] != 'A' && s[i] != '\0')
            index++;
        if(index < s.length()){
            indexB = indexA + 1;
            while(s[indexB] != '\0')
                if(s[indexB++] == 'B')
                	matches++;
        }
    }
    return matches;
}
