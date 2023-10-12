lass Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int left = 0;
    int right = mountainArr.length() - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    int peak_index = left;

    left = 0;
    right = peak_index;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int mid_val = mountainArr.get(mid);
        if (mid_val == target) {
            return mid;
        } else if (mid_val < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    left = peak_index;
    right = mountainArr.length() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int mid_val = mountainArr.get(mid);
        if (mid_val == target) {
            return mid;
        } else if (mid_val < target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return -1;
    }
};
