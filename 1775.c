/**
 * @brief https://leetcode.com/problems/equal-sum-arrays-with-minimum-number-of-operations/
 * @brief 1775
 */

int minOperations(int* nums1, int nums1Size, int* nums2, int nums2Size){
    if (6 * nums1Size < nums2Size) return -1;
    if (6 * nums2Size < nums1Size) return -1;

    int cnt1[6], cnt2[6], cnt[6], sum1 = 0, sum2 = 0;
    memset(cnt1, 0, 6 * sizeof(int));
    memset(cnt2, 0, 6 * sizeof(int));
    memset(cnt, 0, 6 * sizeof(int));

    for (int i = 0; i < nums1Size; i++){
        cnt1[nums1[i] - 1]++;
        sum1 += nums1[i];
    }

    for (int i = 0; i < nums2Size; i++){
        cnt2[nums2[i] - 1]++;
        sum2 += nums2[i];
    }

    int diff = 0;
    if (sum1 > sum2) {
        diff = sum1 - sum2;
        cnt[5] = cnt1[5] + cnt2[0];
        cnt[4] = cnt1[4] + cnt2[1];
        cnt[3] = cnt1[3] + cnt2[2];
        cnt[2] = cnt1[2] + cnt2[3];
        cnt[1] = cnt1[1] + cnt2[4];
    }
    else if (sum2 > sum1){
        diff = sum2 - sum1;
        cnt[5] = cnt2[5] + cnt1[0];
        cnt[4] = cnt2[4] + cnt1[1];
        cnt[3] = cnt2[3] + cnt1[2];
        cnt[2] = cnt2[2] + cnt1[3];
        cnt[1] = cnt2[1] + cnt1[4];
    }
    else {
        return 0;
    }

    int res = 0;
    for (int target = 5; target > 0; target --){
        int num_use = diff / target;
        if (num_use > cnt[target]) num_use = cnt[target];
        res += num_use;
        diff -= num_use * target;
        cnt[target] -= num_use;
        cnt[target-1] += cnt[target];
    }
    return res;

}