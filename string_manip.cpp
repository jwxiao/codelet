#include "common.h"

using namespace std;

struct hist_elm {
    int last_idx;

    hist_elm(): last_idx(-1) {}
};

vector<int> partition_labels(string &s)
{
    struct hist_elm hist_tbl[26];
    vector < int > result;

    for (int i = 0; i < s.size(); i++) {
        int hi = s.at(i) - 'a';

        if (i > hist_tbl[hi].last_idx) {
            hist_tbl[hi].last_idx = i;
        }
    }

    for (int i = 0; i < s.size(); ) {
        int cnt = 0;
        int range = hist_tbl[s.at(i) - 'a'].last_idx;

        while (i <= range) {
            int ofst = s.at(i) - 'a';

            if (hist_tbl[ofst].last_idx > range) {
                range = hist_tbl[ofst].last_idx;
            }
            i++;
            cnt++;
        }
        result.push_back(cnt);
    }

    return result;
}

void main_partition_labels(void)
{
    string str("ababc");

    partition_labels(str);
}