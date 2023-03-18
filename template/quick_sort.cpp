void sort(vector<int>& nums, int low, int high) {
	int l = low, r = high;
	int mid = nums[(l + r) >> 1];
	while(l <= r) {
		while(nums[l] < mid)
			l++;
		while(nums[r] > mid)
			r--;
		if(l <= r) {
			swap(nums[l], nums[r]);
			l++;
			r--;
		}
	}
	if(low < r)
		sort(nums, low, r);
	if(l < high)
		sort(nums, l, high);
}