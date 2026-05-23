#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;

int sum=0;

vector<int> solve(bitset<13>&used, vector<int>&nums) {
	if (used.count() == 13) {
		return vector<int>{-1};
	}
	else {
		for (int i = 0; i < 13; ++i) {
			if (!used[i]) {
				if (sum % (i + 1)==0) {
					sum+=(i+1)*nums[i];
					used[i] = true;
					auto v(solve(used, nums));
					if (!v.empty()) {
						if (v == vector<int>{-1}) {
							v.clear();
						}
						for (int j = 0; j < nums[i];++j) {

							v.push_back(i);
						}
						return v;
					}
					used[i]=false;
					sum-=(i+1)*nums[i];
				}
			}
		}
		return vector<int>();
	}

}

int main() {
	
	while (true) {
		sum=0;
		int N;cin>>N;
		if(!N)break;
		if (N % 2) {
			long long int dp[100][2][2][9];
			for (int i = 0; i < 100; ++i) {
				for (int j = 0; j < 2; ++j) {
					for (int k = 0; k < 2; ++k) {
						for (int n = 0; n < 9; ++n) {
							dp[i][j][k][n] = 0;
						}
							
					}
				}
			}
			for (int luse = 0; luse < 2; ++luse) {
					dp[0][luse][luse][luse] = 1;
			}
			for (int h = 0; h < N  - 1; ++h) {
				for (int fst_luse = 0; fst_luse < 2; ++fst_luse) {
					for (int pre_luse = 0; pre_luse < 2; ++pre_luse) {
						for (int cnt = 0; cnt <= 8; ++cnt) {
							const long long int num = dp[h][fst_luse][pre_luse][cnt];

							for (int next_luse = 0; next_luse < 2; ++next_luse) {
								const int next_cnt = cnt + next_luse;
								if (next_cnt>8)continue;
								const int next_h = h + 1;
								if (pre_luse&&next_luse)continue;
								if (next_h == N - 1) {
									if (fst_luse&&next_luse)continue;
								}
								dp[next_h][fst_luse][next_luse][next_cnt] += num;
								
							}
						}
					}
				}
			}
			long long int ans = 0;
			{
				int h = N - 1;
				for (int fst_luse = 0; fst_luse < 2; ++fst_luse) {
					for (int pre_luse = 0; pre_luse < 2; ++pre_luse) {
						{
							int cnt = 8;
							const long long int num = dp[h][fst_luse][pre_luse][cnt];
							ans += num;
						}
					}
						
				}
				
			}
			ans *= 40320;
			cout << ans << endl;
		}
		else {
			long long int dp[100][2][2][2][2][9];
			for (int i = 0; i < 100; ++i) {
				for (int j = 0; j < 2; ++j) {
					for (int k = 0; k < 2; ++k) {
						for (int l = 0; l < 2; ++l) {
							for (int m = 0; m < 2; ++m) {
								for (int n = 0; n < 9; ++n) {
									dp[i][j][k][l][m][n]=0;
								}
							}
						}
					}
				}
			}
			for (int luse = 0; luse < 2; ++luse) {
				for (int ruse = 0; ruse < 2; ++ruse) {
					if(luse&&ruse)continue;
					dp[0][luse][ruse][luse][ruse][luse+ruse]=1;
				}
			}
			for (int h = 0; h < N / 2-1; ++h) {
				for (int fst_luse = 0; fst_luse < 2; ++fst_luse) {
					for (int fst_ruse = 0; fst_ruse < 2; ++fst_ruse) {
						for (int pre_luse = 0; pre_luse < 2; ++pre_luse) {
							for (int pre_ruse = 0; pre_ruse < 2; ++pre_ruse) {
								for (int cnt = 0; cnt <= 8; ++cnt) {
									const long long int num = dp[h][fst_luse][fst_ruse][pre_luse][pre_ruse][cnt];

									for (int next_luse = 0; next_luse < 2; ++next_luse) {
										for (int next_ruse=0; next_ruse < 2; ++next_ruse) {
											const int next_cnt=cnt+next_luse+next_ruse;
											if(next_cnt>8)continue;
											const int next_h=h+1;
											if(pre_luse&&next_ruse)continue;
											if(pre_ruse&&next_luse)continue;
											if(next_luse&&next_ruse)continue;
											if (next_h == N / 2-1) {
												if(fst_luse&&next_luse)continue;
												if(fst_ruse&&next_ruse)continue;
											}
											dp[next_h][fst_luse][fst_ruse][next_luse][next_ruse][next_cnt]+=num;
										}
									}
								}
							}
						}
					}
				}
			}
			long long int ans=0;
			{
				int h=N/2-1;
				for (int fst_luse = 0; fst_luse < 2; ++fst_luse) {
					for (int fst_ruse = 0; fst_ruse < 2; ++fst_ruse) {
						for (int pre_luse = 0; pre_luse < 2; ++pre_luse) {
							for (int pre_ruse = 0; pre_ruse < 2; ++pre_ruse) {
								 {
									int cnt=8;
									const long long int num = dp[h][fst_luse][fst_ruse][pre_luse][pre_ruse][cnt];
									ans+=num;
								}
							}
						}
					}
				}
			}
			ans*=40320;
			cout<<ans<<endl;
		}
	}
	return 0;
}