class Leaderboard 
{
public:
    unordered_map<int, int> id_score;
    multiset<int> m;

    Leaderboard() 
    {
    }
    
    void addScore(int playerId, int score) 
    {
        if (id_score.find(playerId) == id_score.end())
        {
            id_score[playerId] = score;
            m.insert(score);
        }
        else
        {
            int old_score = id_score[playerId];
            id_score[playerId] += score;
            m.erase(m.find(old_score));
            m.insert(id_score[playerId]);
        }
    }
    
    int top(int K) 
    {
        int res = 0;
        int cnt = 0;
        for (auto it = m.rbegin(); it != m.rend(); it ++)
        {
            if (cnt == K)
                break;
            res += (*it);
            cnt ++;
        }
        return res;
    }
    
    void reset(int playerId) 
    {
        int old_score = id_score[playerId];
        id_score.erase(playerId);
        m.erase(m.find(old_score));
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */
