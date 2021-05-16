

int lengthOfLongestSubstring(char * s){
    int index[128] = {0};
    int start = 0;
    int max = -1;
    int count = 0;

    int i;
    for ( i = 0; s[i] != '\0'; ++i)
    {
        if ( index[s[i]] > start )
        {
            count = i - start;
            max = count > max ? count : max;
            start = index[s[i]];
        }

        index[s[i]] = i + 1;    //i+1表示下一个位置
    }

    count = i - start;
    return count > max ? count : max;
}