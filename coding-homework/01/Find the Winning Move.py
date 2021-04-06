PLAYER_UNKNOWN = 0
PLAYER_X = 1
PLAYER_O = -1

ansx = 0
ansy = 0

def judge(s:str):
    for i in range(4):
        if s[i*4] != '.' and s[i*4] == s[i*4+1] and s[i*4+1] == s[i*4+2] and s[i*4+2] == s[i*4+3]:
            return PLAYER_O if s[i*4] == 'o' else PLAYER_X
        if s[i] != '.' and s[i] == s[i+4] == s[i+8] == s[i+12]:
            return PLAYER_O if s[i] == 'o' else PLAYER_X
    if s[0] != '.' and s[0] == s[5] and s[5] == s[10] and s[10] == s[15]:
        return PLAYER_O if s[0] == 'o' else PLAYER_X
    if s[3] != '.' and s[3] == s[6] and s[6] == s[9] and s[9] == s[12]:
        return PLAYER_O if s[3] == 'o' else PLAYER_X
    return PLAYER_UNKNOWN

def dfs(s:str, now:int, alpha, beta):
    global ansx,ansy

    flag = judge(s)
    if flag != PLAYER_UNKNOWN:
        return flag
    
    #print("now:",s)
    
    if now == PLAYER_X:
        for i in range(4):
            for j in range(4):
                idx = i*4 + j
                if s[idx] != '.':
                    continue
                ns = s[:idx] + "x" + s[idx+1:]
                val = dfs(ns, PLAYER_O, alpha, beta)
                if val > alpha:
                    alpha = val
                    ansx = i
                    ansy = j
                if alpha >= beta:
                    return alpha
        return alpha
    else:
        for i in range(4):
            for j in range(4):
                idx = i*4 + j
                if s[idx] != '.':
                    continue
                ns = s[:idx] + "o" + s[idx+1:]
                val = dfs(ns, PLAYER_X, alpha, beta)
                if val < beta:
                    beta = val
                if alpha >= beta:
                    return beta
        return beta
            


def main():
    while True:
        s = input()
        if s == "$":
            break
        s = [input() for i in range(4)]
        s = ''.join(s)
        if s.count('.') >= 12:
            print("#####")
            continue
        ans = dfs(s, PLAYER_X, -1, 1)
        if ans > 0:
            print("({},{})".format(ansx,ansy))
        else:
            print("#####")


if __name__ == "__main__":
    main()