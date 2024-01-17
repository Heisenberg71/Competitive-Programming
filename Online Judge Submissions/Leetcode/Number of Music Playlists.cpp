class Solution {
private:
    int INVALID = -1;
    int N, Goal, K;
    int MOD = 1000000007;
    vector<vector<int>> ways;
    
    int findNumberOfMusicPlaylists(int songListened, int unique){
        if(songListened == Goal && unique == N) return 1;
        if(songListened == Goal) return 0;
        int& ret = ways[songListened][unique];
        if(ret != INVALID) return ret;
        
        ret = 0;
        if(unique < N) ret = (1LL*(N - unique)*findNumberOfMusicPlaylists(songListened + 1, unique + 1))% MOD;
        if(unique > K) ret = (ret + (1LL*(unique - K)*findNumberOfMusicPlaylists(songListened + 1, unique)))% MOD;
        return ret;
    }
public:
    int numMusicPlaylists(int n, int goal, int k) {
        ways.assign(goal, vector<int>(n + 1, INVALID));
        N = n, Goal = goal, K = k;
        int numberOfMusicPlaylists = findNumberOfMusicPlaylists(0, 0);
        return numberOfMusicPlaylists;
    }
};
