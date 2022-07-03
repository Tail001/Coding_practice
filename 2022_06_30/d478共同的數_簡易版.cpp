//0.3s, 372KB
// too slow~~
#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int target){
    int left = 0, right = size - 1, mid;
    while(left <= right){
        mid = (left + right) / 2;
        if(arr[mid] == target)
            return mid;
        else if(arr[mid] > target)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}
int main() {
    ios::sync_with_stdio(0);
    int n, m;
    int a[10000];
    cin >> n >> m;
    while(n--){
        int ans = 0;
        for(int i = 0;i < m; i++){
            cin >> a[i];
        }
        cout << endl;
        for(int i = 0;i < m; i++){
            int temp;
            cin >> temp;
            if(binarySearch(a, m, temp) != -1){
                ans++;
            }
        }
        cout << ans << endl;        
    }
}

