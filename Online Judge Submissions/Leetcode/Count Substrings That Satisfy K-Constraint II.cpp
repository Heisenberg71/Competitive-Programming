class Solution {
public:
    
    vector<long long> countKConstraintSubstrings(string s, int k, vector<vector<int>>& queries) 
    {
        int n = s.size();
        vector <long long> ans,pre(n),prev(n);
        int l = 0,zeros=0,ones=0;
        for(int r=0;r<n;r++)
        {
            if(s[r]=='1') ones++;
            else zeros++;
            while(zeros > k && ones > k)
            {
                if(s[l]=='1') ones--;
                else zeros--;
                l++;
            }
            prev[r] = l;
        }

        <!-- Calculating prefix sums -->
        pre[0]=1;
        for(int i=1;i<n;i++)
        {
            pre[i] = pre[i-1] + i-prev[i]+1;
        }
        for(auto &q : queries)
        {
            long long l = q[0];
            long long r = q[1];
            long long cur = 0;
            long long pos=r+1;
            <!-- Finding pos -->
            while(l<=r)
            {
                long long mid = (l+r)/2;
                if(prev[mid]>=q[0])
                {
                    pos=mid;
                    r=mid-1;
                } 
                else l=mid+1;
            }

            <!-- If there exists such index -->
            
            if(pos<=q[1])
            {
                cur+=pre[q[1]];
                if(pos>0)cur-=pre[pos-1];
            }
            cur+=(pos-q[0])*(pos-q[0]+1)/2;
            
            ans.push_back(cur);
        }
        return ans;
    }
};
