#3. Longest Substring Without Repeating Characters
C version:
######Sliding window algorithm  
Using hashing, each char has its own space, as it shown in ``` previdx[128] ``` <br> Set two counter i and j, let the string always legal in range $[i,j]$.

```c
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
int lengthOfLongestSubstring(char *s) {
    int previdx[128];
    memset(previdx, -1, sizeof(previdx)); 
    int res = 0;
    const int n = strlen(s);
    for(int i = 0, j = 0; j < n; j++){
        i = MAX(i, previdx[s[j]] + 1);
        res = MAX(res, j - i + 1);
        previdx[s[j]] = j;
    }
    return res;
}

```