class LogSystem {
private:
    map<string, vector<int>> timestampIdsMap;
    vector<string> timestampList;

    void setMinuteGranularity(string& timestamp, char ch) {
        timestamp[17] = ch, timestamp[18] = ch;
    }
    void setHourGranularity(string& timestamp, char ch) {
        timestamp[14] = ch, timestamp[15] = ch;
        setMinuteGranularity(timestamp, ch);
    }
    void setDayGranularity(string& timestamp, char ch) {
        timestamp[11] = ch, timestamp[12] = ch;
        setHourGranularity(timestamp, ch);
    }
    void setMonthGranularity(string& timestamp, char ch) {
        timestamp[8] = ch, timestamp[9] = ch;
        setDayGranularity(timestamp, ch);
    }
    void setYearGranularity(string& timestamp, char ch) {
        timestamp[5] = ch, timestamp[6] = ch;
        setMonthGranularity(timestamp, ch);

    }

    vector<string>::iterator findLogFromTheBeginingTo(string& timestamp, string& granularity, char ch) {
        
        if(granularity == "Minute") {
            setMinuteGranularity(timestamp, ch);
        }
        if(granularity == "Hour") {
            setHourGranularity(timestamp, ch);
        }
        if(granularity == "Day") {
            setDayGranularity(timestamp, ch);
        }
        if(granularity == "Month") {
            setMonthGranularity(timestamp, ch);
        }
        if(granularity == "Year") {
            setYearGranularity(timestamp, ch);
        }

        if(ch == '0') return lower_bound(timestampList.begin(), timestampList.end(), timestamp);
        return upper_bound(timestampList.begin(), timestampList.end(), timestamp);
    }
public:
    LogSystem() {
        timestampIdsMap.clear();
        timestampList.clear();
    }
    
    void put(int id, string timestamp) {
        if(!timestampIdsMap.count(timestamp)) timestampList.push_back(timestamp);
        timestampIdsMap[timestamp].push_back(id);
    }
    
    vector<int> retrieve(string start, string end, string granularity) {
        sort(timestampList.begin(), timestampList.end());
        auto endId = findLogFromTheBeginingTo(end, granularity, '9');
        auto beginId = findLogFromTheBeginingTo(start, granularity, '0');

        vector<int> idList;
        while(beginId != endId) {
            for(int i = 0; i < timestampIdsMap[*beginId].size(); i++) {
                idList.push_back(timestampIdsMap[*beginId][i]);
            }
            beginId++;
        }

        return idList;
    }
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem* obj = new LogSystem();
 * obj->put(id,timestamp);
 * vector<int> param_2 = obj->retrieve(start,end,granularity);
 */
