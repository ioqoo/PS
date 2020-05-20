#include <bits/stdc++.h>

#define pii pair<int, int>

using namespace std;

int getrand(int mod){
    return rand()%mod;
}

int T;

int main() {

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    srand((unsigned int)time(0));
    cin >> T;
    string line;
    getline(cin, line);
    while(T--){
        string playtemp, artisttemp;
        getline(cin, playtemp);
        getline(cin, artisttemp);
        istringstream ist(playtemp);
        vector<string> playlist;
        vector<string> artist;
        string buff;
        while(getline(ist, buff, '\t')){
            playlist.push_back(buff);
        }
        istringstream ist2(artisttemp);
        while(getline(ist2, buff, '\t')){
            artist.push_back(buff);
        }
        // input

        
        int artistnum = 0;
        unordered_map<string, int> H; // H[artist] = artist id
        unordered_map<int, string> artistlist; // artistlist[i] = artist whose id is i
        for (auto a: artist){
            if (!H.count(a)) {
                H[a] = artistnum;
                artistlist[artistnum] = a;
                artistnum++;
            }
        }
        vector<string> song_per_artist[artistnum] = {vector<string> (),}; // song_per_artist[i][j] = jth song of artist 
        for (int i=0;i<playlist.size();i++){
            song_per_artist[H[artist[i]]].push_back(playlist[i]);
        }


        for (int i=0;i<artistnum;i++){ // shuffle the songs by the same artist among each other using Fisher?Yates shuffle
            for (int j=song_per_artist[i].size()-1;j>1;j--){
                int k = getrand(j+1);
                swap(song_per_artist[i][j], song_per_artist[i][k]); 
            }
        }
        vector<pair<int, string>> ret;
        vector<int> firstoffset(artistnum);

        for (int i=0;i<artistnum;i++){
            firstoffset[i] = getrand(10000);
        }

        for (int i=0;i<artistnum;i++){
            ret.push_back({firstoffset[i], song_per_artist[i][0]});
        }
        
        for (int i=0;i<artistnum;i++){
            int lastpos = firstoffset[i];
            int songcnt = song_per_artist[i].size();
            int jump = 2000000000 / songcnt;
            int nextpos = 0;
            for (int j=1;j<songcnt;j++){
                string currsong = song_per_artist[i][j];
                nextpos = lastpos + jump + (int)(songcnt*(getrand(100)-50)*0.001);
                ret.push_back({nextpos, currsong});
                lastpos = nextpos;
            }
        }
        sort(ret.begin(), ret.end());
        for (auto p: ret){
            cout << p.second << '\t';
        }
        cout << endl;
        
    }

    return 0;
}



