#include <bits/stdc++.h>
using namespace std;

int nums[1000];
int query[25];

int main()
{
    int n, x, m;
    int q;
    int ss;
    int case_number = 0;
    while (scanf("%d", &n), n) {
        memset(nums, 0, sizeof nums);
        memset(query, 0, sizeof query);
        for (int i=0; i<n; i++) {
            scanf("%d", &x);
            nums[i] = x;
        }
        scanf("%d", &m);
        for (int i=0; i<m; i++) {
            scanf("%d", &x);
            query[i] = x;
        }
        sort(nums, nums+n);
        printf("Case %d:\n", ++case_number);
        for (int i=0; i<m; i++) {
            q = query[i];
            int closest = nums[0]+nums[1];
            int closest_diff = abs(closest - q);
            for (int j=0; j<n-1; j++) {
                for (int k=j+1; k<n; k++) {
                    ss = nums[j]+nums[k];
                    if (abs(q-ss) < closest_diff) {
                        closest = ss;
                        closest_diff = abs(closest - q);
                    }
                    if (nums[j]>q && nums[k]>q) {
                        goto done;
                    }
                }
            }
done:
            ;
            printf("Closest sum to %d is %d.\n", q, closest);
        }


    }
    return 0;
}

