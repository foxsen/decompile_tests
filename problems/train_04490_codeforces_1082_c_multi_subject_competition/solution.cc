#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > team_size;
vector<int> count_occur, score_sum;
vector<pair<int, int> > special_score, score_team;
int main() {
  int candidate, subject, specialization, score, ans = 0;
  scanf("%d %d", &candidate, &subject);
  count_occur = vector<int>(subject, 0);
  score_sum = vector<int>(subject, 0);
  for (int i = 0; i < candidate; i++) {
    scanf("%d %d", &specialization, &score);
    special_score.push_back({score, specialization - 1});
  }
  sort(special_score.rbegin(), special_score.rend());
  for (int i = 0; i < candidate; i++) {
    count_occur[special_score[i].second]++;
    score_sum[special_score[i].second] += special_score[i].first;
    int cur_team_size = count_occur[special_score[i].second];
    int cur_team_score = score_sum[special_score[i].second];
    score_team.push_back({cur_team_score, cur_team_size});
    ans = max(ans, cur_team_size);
  }
  team_size = vector<vector<int> >(ans, vector<int>());
  ans = 0;
  sort(score_team.rbegin(), score_team.rend());
  for (int i = 0; i < candidate; i++) {
    int cur_team_size = score_team[i].second;
    int cur_score = score_team[i].first;
    if (team_size[cur_team_size - 1].size() == 0)
      team_size[cur_team_size - 1].push_back(cur_score);
    else
      team_size[cur_team_size - 1].push_back(
          team_size[cur_team_size - 1].back() + cur_score);
    ans = max(ans, team_size[cur_team_size - 1].back());
  }
  printf("%d\n", ans);
  return 0;
}
