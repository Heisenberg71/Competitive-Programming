class SummaryRanges {
private:
    unordered_map<int, bool> isExist;
    unordered_map<int, int> start_finish, finish_start;
    set<vector<int>> ranges;
public:
    SummaryRanges() {
        isExist.clear();
        start_finish.clear();
        finish_start.clear();
        ranges.clear();
    }

    void addNum(int value) {
        if (isExist.count(value))
            return;

        isExist[value] = true;
        if (start_finish.count(value + 1) && finish_start.count(value - 1)) {
            ranges.erase(ranges.find({value + 1, start_finish[value + 1]}));
            ranges.erase(ranges.find({finish_start[value - 1], value - 1}));
            ranges.insert({finish_start[value - 1], start_finish[value + 1]});

            int L = finish_start[value - 1], R = start_finish[value + 1];

            start_finish.erase(start_finish.find(value + 1));
            finish_start.erase(finish_start.find(value - 1));

            start_finish[L] = R;
            finish_start[R] = L;

            return;
        }
        if (start_finish.count(value + 1)) {
            int finish = start_finish[value + 1];
            ranges.erase(ranges.find({value + 1, finish}));
            ranges.insert({value, finish});
            start_finish[value] = finish;
            finish_start[finish] = value;
            start_finish.erase(start_finish.find(value + 1));

            return;
        }
        if (finish_start.count(value - 1)) {
            int start = finish_start[value - 1];
            ranges.erase(ranges.find({start, value - 1}));
            ranges.insert({start, value});
            start_finish[start] = value;
            finish_start[value] = start;
            finish_start.erase(finish_start.find(value - 1));

            return;
        }

        ranges.insert({value, value});
        start_finish[value] = value;
        finish_start[value] = value;
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> result;
        for (auto& range : ranges) {
            result.push_back(range);
        }
        return result;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
