#include<bits/stdc++.h>

using namespace std;

struct elm {
    int w;
    int p;

    elm(int _w, int _p) {
        w = _w;
        p = _p;
    }
};

bool cmp(elm a, elm b) {
    return (a.p / (float)a.w) > (b.p / (float)b.w);
}

int main() {
    int N, W;

    cin >> N >> W;

    vector<elm> v;

    for(int i = 0; i < N; ++i) {
        int n, w;
        cin >> n >> w;
        v.push_back(elm(n, w));
    }

    sort(v.begin(), v.end(), cmp);

    for(int i = 0; i < N; ++i) {
        cout << v[i].w << " " << v[i].p << endl;
    }

    int tot = 0;
    float ans = 0.0;

    for(int i = 0; i < N; ++i) {
        if(v[i].w + tot <= W) {
            tot += v[i].w;
            ans += v[i].p;
        }
        else {
            float d = W - tot;

            float f = (d / v[i].w);

            ans += (f * v[i].p);
            break;
        }
    }

    cout << ans << endl;
}

/*
3 10
6 4
5 5
3 4

3 10
7 3
14 6
5 4

3 10
5 3
6 6
10 7
*/








