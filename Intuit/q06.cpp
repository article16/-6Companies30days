class Solution {
public:
    int findInMountainArray(int tar, MountainArray &a) {
        int n = a.length(), amid, amid1, amid2, ind;
        int low = 1, high = n - 2, mid, f = 0;

        while (low <= high) {
            mid = (low + high) / 2;
            amid = a.get(mid); amid1 = a.get(mid - 1); amid2 = a.get(mid + 1);
            if (amid > amid2 && amid < amid1)high = mid - 1;
            else if (amid > amid1 && amid < amid2)low = mid + 1;
            else {ind = mid; break;}
        }

        low = 0; high = ind;
        while (low <= high) {
            mid = (low + high) / 2;
            amid = a.get(mid);
            if (amid < tar)low = mid + 1;
            else if (amid > tar)high = mid - 1;
            else {f = 1; break;}
        }

        if (f)return mid;

        low = ind; high = n - 1;
        while (low <= high) {
            mid = (low + high) / 2;
            amid = a.get(mid);
            if (amid > tar)low = mid + 1;
            else if (amid < tar)high = mid - 1;
            else {f = 1; break;}
        }

        if (f)return mid;
        else return -1;

    }
};