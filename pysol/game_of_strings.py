def compute_lps(s, k):
    j = 0
    n = len(s)
    lps = [0] * n
    mxp = 0
    for i in xrange(1, n):
        while j and s[j] != s[i]:
            j = lps[j-1]
        if s[j] == s[i]:
            j += 1
        lps[i] = j
        if i < k:
            mxp = max(mxp, lps[i])
    return lps, mxp


def find_lps(s, k):
    lps, mxp = compute_lps(s, k)
    i = lps[len(s) - 1]
    while i and i > mxp:
        i = lps[i-1]
    if i:
        print s[:i]
    else:
        print "Puchi is a cheat!"


for _ in xrange(int(raw_input())):
    s, k = raw_input().split()
    k = int(k)
    find_lps(s, k)
