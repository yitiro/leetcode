// 215. Kth Largest Element in an Array
// https://leetcode.com/problems/kth-largest-element-in-an-array/
void swap(int* nums, int i, int j);
int findKthSmallest(int* nums, int lo, int hi, int k);
int setMedianOf3(int* nums, int lo, int hi);
void shuffle(int* nums, int numSize);
void insertionSort(int* nums, int lo, int hi);


// 1 <= k <= numSize <= 10^4
int findKthLargest(int* nums, int numsSize, int k){
    shuffle(nums, numsSize);
    return findKthSmallest(nums, 0, numsSize-1, numsSize - k);
}

int findKthSmallest(int* nums, int lo, int hi, int k) {
    if (lo >= hi) {
        return nums[lo];
    }
    if (hi - lo < 10) {
        insertionSort(nums, lo, hi);
        return nums[k];
    }
    
    int lt = lo, gt = hi;
    int pivot = setMedianOf3(nums, lo, hi);

    int i = lt;
    while (i <= gt) {
        int cmp = nums[i] - pivot;
        if (cmp < 0) {
            swap(nums, lt++, i++);
        }
        else if (cmp > 0) {
            swap(nums, i, gt--);
        }
        else {
            i++;
        }
    }
    
    
    if (k < lt) {
        return findKthSmallest(nums, lo, lt-1, k);
    }
    else if (k > gt){
        return findKthSmallest(nums, gt+1, hi, k);
    }
    return pivot;
    
    
}

int setMedianOf3(int* nums, int lo, int hi) {
    int mid = lo + (hi - lo) / 2;
    // printf("find mediem of %d, %d, %d\n", nums[lo], nums[mid], nums[hi]);
    if (nums[lo] > nums[mid]) {
        swap(nums, lo, mid);
    }
    
    if (nums[hi] <= nums[lo]) {
        return nums[lo];
    }
    else if (nums[hi] <= nums[mid]) {
        swap(nums, lo, hi);
        return nums[lo];
    }
    else {
        swap(nums, lo, mid);
        return nums[lo];
    }
    return nums[lo];      
}

// 1 <= numSize <= 10^4
void shuffle(int* nums, int numSize) {
    for (int i = 0; i < numSize - 1; i++) {
        int j = i + (rand() % (numSize - 1 - i)) + 1;
        swap(nums, i, j);
    }
}

void insertionSort(int* nums, int lo, int hi) {
    for (int i = lo + 1; i <= hi; i ++){
        int key = nums[i];
        int j = i - 1;
        while (j >= lo && nums[j] > key) {
            nums[j+1] = nums[j];
            j--;
        }
        nums[j+1] = key;
    }
}

void swap(int* nums, int i, int j){
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}