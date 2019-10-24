#include <iostream>
#include <string>
#include <vector>
#include <pair>
using namespace std;

vector<pair<size_t, size_t> > findPatternInText(string& text, string& pattern){
    int *lps = lpsArray(pattern);
    int i = 1, j = 0;
    vector<pair<size_t, size_t> > positions;
    while (i<text.size()){
        if (text[i] == pattern[j]){
            i++;
            j++;
        }
        if (j == pattern.size()){
            positions.push_pack(make_pair(i-j, i-1));
            j = lps[j-1];
        }
        if (i < text.size() && text[i] != pattern[j]){
            if (j!=0)
                j=lps[j-1];
            else
                i++;                
        }
    }
    delete []lps;
    return positions;
}

int* lpsArray(string& pattern){
    int* lps = new int[pattern.size()];
    int i = 1, j = 0;
    lps[0] = 0;
    while (i<pattern.size()){
        if (pattern[i] == pattern[j]){
            j++;
            lps[i] = j;
            i++;
            continue;
        }
        if (j==0){
            lps[i] = 0;
            i++;
        else
            j = lps[j-1];
    }
    return lps;
}  

int main() {
	string pattern("abcaby");
	string text("abxabcabcaby");
    vector<pair<size_t, size_t> > positions = findPatternInText(text, pattern);
    for(auto it:positions)
        cout<<"("<<it.first<<", "<<it.second<<")"<<endl;	
	return 0;
}