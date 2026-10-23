#include <iostream>

int sign(char* s) {
    if (s[0] == '-')
        return -1;
    return 1;
}
int start(char* s) {
    if (s[0] == '+' or s[0] == '-')
        return 1;
    return 0;
}
int len(char* s) {
    int i = 0;
    while (s[i] != '\0')
        i++;
    return i;
}
int comp(char* a, char* b) {
    int ia = start(a);
    int ib = start(b);
    int pa = ia;
    int pb = ib;
    int da = -1, db = -1;
    while (a[pa] != '\0') {
        if (a[pa] == '.')
            da = pa;
        pa++;
    }
    while (b[pb] != '\0') {
        if (b[pb] == '.')
            db = pb;
        pb++;
    }
    if (da == -1)
        da = len(a);
    if (db == -1)
        db = len(b);
    int lena = da - ia;
    int lenb = db - ib;
    if (lena > lenb)
        return 1;
    if (lena < lenb)
        return -1;
    for (int i = 0; i < lena; i++) {
        if (a[ia+i] > b[ib+i])
            return 1;
        if (a[ia+i] < b[ib+i])
            return -1;
    }
    int fa = (da == len(a)) ? da : da + 1;
    int fb = (db == len(b)) ? db : db + 1;
    while (fa < len(a) || fb < len(b)) {
        char ca = (fa < len(a)) ? a[fa] : '0';
        char cb = (fb < len(b)) ? b[fb] : '0';
        if (ca > cb)
            return 1;
        if (ca < cb)
            return -1;
        fa++;
        fb++;
    }
    return 0;
}

int main(int argc, char* argv[]) {
    if(argc != 3)
        return 1;
    char* a = argv[1];
    char* b = argv[2];
    int sa = sign(a);
    int sb = sign(b);
    int result;
    if (sa != sb) {
        result = (sa > sb) ? 1 : -1;
    }
    else {
        result = comp(a, b);
        if (sa == -1)
            result = -result;
    }
    if (result < 0)
        std::cout << "less" << "\n";
    else if (result == 0)
        std::cout << "equal" << "\n";
    else
        std::cout << "greater" << "\n";
    return 0;
}
