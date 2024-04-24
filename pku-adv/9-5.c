#include <iostream>
#include <queue>

#define maxlen 105
using namespace std;

typedef struct POINT {
    int x;
    int y;
} point;

char maps[maxlen][maxlen];
//维护ans[i][j]到起点的最短距离(即dist(x))
int ans[maxlen][maxlen];
int dirx[]={-1,1,0,0};
int diry[]={0,0,-1,1};

int sx,sy,fx,fy;
int n,m;

queue<point> q;

//广搜维护最短路径
void bfs(int cx,int cy){
    point p;
    //转换为树的层序遍历
    while(!q.empty()){
        p = q.front();
        q.pop();
        //四个方向(找相邻结点)
        for(int i = 0 ;i<4 ;i++){
            point t;
            t.x = p.x+dirx[i];
            t.y = p.y+diry[i];
            if(t.x>0&&t.x<=n&&t.y>0&&t.y<=m&&maps[t.x][t.y]!='#'){
                //标记为访问过
                maps[t.x][t.y] = '#';
                q.push(t);
                //维护每个结点的最短路径
                ans[t.x][t.y] = ans[p.x][p.y]+1;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 1; i<=n ;i++){
        for(int j = 1 ;j<=m ;j++){
            cin>>maps[i][j];
            if (maps[i][j]=='S') {
                sx = i;
                sy = j;
            } else if(maps[i][j]=='T'){
                fx = i;
                fy = j;
            }
        }
    }
    point s;
    s.x = sx;
    s.y = sy;
    ans[s.x][s.y] = 0;
    q.push(s);
    bfs(sx,sy);
    cout << ans[fx][fy] << endl;
    return 0;
}
/********************************************/

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>


char s[100][100] = {0};
int minStep = INT_MAX;

void findExit(int i, int j, int step) {
    if (i < 0 || i >= m || j < 0 || j >= n) {
        return;
    }

    if (s[i][j] == '#' || s[i][j] == 'S') {
        return;
    }

    if (s[i][j] == 'T') {
        if (step < minStep) {
            minStep = step;
        }
        return;
    }

    s[i][j] = '#';

    findExit(i, j - 1, step + 1);
    findExit(i, j + 1, step + 1);
    findExit(i - 1, j, step + 1);
    findExit(i + 1, j, step + 1);

    s[i][j] = '.';
}

void solution_2(void) {
    int si, sj;
    scanf("%d %d", &m, &n);

    getchar();

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            char chr;
            scanf("%c", &chr);
            s[i][j] =chr;
            if (s[i][j] == 'S') {
                si = i;
                sj = j;
            }
            char c = getchar();
        }
    }

    findExit(si + 1, sj, 1);
    findExit(si - 1, sj, 1);
    findExit(si, sj + 1, 1);
    findExit(si, sj - 1, 1);

    printf("%d\n", minStep);
}

/*
findExit(1, 0 ,1) {
    findExit(1, -1, 2) {
        if (j < 0) {
            return;
        }
    }
    findExit(1, 1, 2) {
        if ('#') {
            return;
        }
    }
    findExit(0, 0, 2) {
        if ('S') {
            return;
        }
    }
    findExit(2, 0, 2) {
        findExit(2, -1, 3) {
            if (j < 0) {
                return;
            }
        }
        findExit(2, 1, 3) {
            findExit(2, 0, 4) {
                if ('#') {
                    return;
                }
            }
            findExit(2, 2, 4) {
                findExit(2, 1, 5) {
                    if ('#') {
                        return;
                    }
                }
                findExit(2, 3, 5) {
                    if (j >= n) {
                        return;
                    }
                }
                findExit(1, 2, 5) {
                    findExit(1, 1, 6) {
                        if ('#') {
                            return;
                        }
                    }
                    findExit(1, 3, 6) {
                        if (j >= n) {
                            return;
                        }
                    }
                    findExit(0, 2, 6) {
                        if ('T') {
                            minStep = 6;
                            return;
                        }
                    }
                }
            }
            findExit(1, 1, 4) {
                if ('#') {
                    return;
                }
            }
            findExit(3, 1, 4) {
                if (i >= m) {
                    return;
                }
            }
        }
        findExit(1, 0, 3) {
            if ('#') {
                return;
            }
        }
        findExit(3, 0, 3) {
            if (i >= m) {
                return;
            }
        }
    }
}
findExit(-1 , 0, 1) {
    if (i < 0) {
        return;
    }
    findExit(-1, -1, 2) {
        if ( i < 0 || j < 0) {
            return;
        }
    }
    findExit(-1, 1, 2) {
        if (i < 0) {
            return;
        }
    }
    findExit(-2, 0, 2) {
        if (i < 0) {
            return;
        }
    }
    findExit(1, 0, 2) {
        findExit(1, -1, 3) {
            if (j < 0) {
                return;
            }
        }
        findExit(1, 1, 2) {
            if ('#') {
                return;
            }
        }
        findExit(0, 0, 2) {
            if ('S') {
                return;
            }
        }
        findExit(2, 0, 2) {
            findExit(2, -1, 3) {
                if (j < 0) {
                    return;
                }
            }
            findExit(2, 1, 3) {
                findExit(2, 0, 4) {
                    if ('#') {
                        return;
                    }
                }
                findExit(2, 2, 3) {
                    findExit(2, 1, 4) {
                        if ('#') {
                            return;
                        }
                    }
                    findExit(2, 3, 4) {
                        if (j >= n) {
                            return;
                        }
                    }
                    findExit(1, 2, 4) {
                        findExit(1, 1, 5) {
                            if ('#') {
                                return;
                            }
                        }
                        findExit(1, 3, 5) {
                            if (j >= n) {
                                return;
                            }
                        }
                        findExit(0, 2, 5) {
                            if ('T') {
                                minStep = 5;
                            }
                        }
                    }
                    findExit(3, 2, 4) {
                        if (i >= m) {
                            return;
                        }
                    }
                }
                findExit(1, 1, 3) {
                    if ('#') {
                        return;
                    }
                }
                findExit(3, 1, 3) {
                    if (i >= m) {
                        return;
                    }
                }
            }
            findExit(1, 0, 2) {
                if ('#') {
                    return;
                }
            }
            findExit(3, 0, 2) {
                if (i >= m) {
                    return;
                }
            }
        }
    }
}
findExit() */