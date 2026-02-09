
    void reverseString(char* s, int sSize) {
    int i = 0;
    int j = sSize - 1;
    char c;
    while(i < j){
        c = s[i];
        s[i] = s[j];
        s[j] = c;
        i++;
        j--;
    }
}
