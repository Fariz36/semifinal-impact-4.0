#include <bits/stdc++.h>
#include <tcframe/spec.hpp>
using namespace std;
using namespace tcframe;
const int MAXN = 200000;

class ProblemSpec : public BaseProblemSpec {
protected:
    int N;
    vector<int> U, V;
    long long answer;

    void InputFormat() {
        LINE(N);
        LINES(U, V) % SIZE(N - 1);
    }

    void OutputFormat() {
        LINE(answer);
    }

    void GradingConfig() {
        TimeLimit(2);
        MemoryLimit(256);
    }

    void StyleConfig() {
        CustomScorer();
    }

    void Constraints() {
        CONS(2 <= N && N <= MAXN);
        CONS(eachElementBetween(U, 1, N));
        CONS(eachElementBetween(V, 1, N));
        CONS(isTree(U, V));
    }

    void Subtask1() {
        Points(17);

        CONS(1 <= N && N <= 40);
    }

    void Subtask2() {
        Points(6);

        CONS(isLine(U, V));
    }

    void Subtask3() {
        Points(16);

        CONS(isStar(U, V));
    }


    void Subtask4() {
        Points(26);

        CONS(1 <= N && N <= 1000);
    }

    void Subtask5() {
        Points(35);
    }

private:
    bool eachElementBetween(const vector<int> &v, int lo, int hi) {
        for (int i : v) {
            if (i < lo || i > hi) {
                return false;
            }
        }
        return true;
    }

    bool isTree(const vector<int> &u, const vector<int> &v) {
        vector<vector<int>> adj(N + 1);

        for (int i = 0; i < N - 1; i++) {
            adj[u[i]].push_back(v[i]);
            adj[v[i]].push_back(u[i]);
        }

        vector<bool> visited(N + 1);
        stack<pair<int, int> > st;
        st.emplace(1, 1);
        while (!st.empty()) {
            auto[idx, par] = st.top();
            st.pop();
            visited[idx] = true;
            for (int nxt : adj[idx]) {
                if (nxt != par) {
                    if (visited[nxt]) {
                        return false;
                    }
                    st.emplace(nxt, idx);
                }
            }
        }

        for (int i = 1; i <= N; i++) {
            if (!visited[i]) {
                return false;
            }
        }
        return true;
    }

    bool isStar(const vector<int> &u, const vector<int> &v) {
        for(int i = 0; i < N - 1; ++i){
            if(U[i] != 1 && V[i] != 1){
                return 0;
            }
        }
        return 1;
    }

    bool isLine(const vector<int>& u, const vector<int> &v) {
        vector<vector<int> > adj(N + 1);
        for (int i = 0; i < N - 1; i++) {
            adj[u[i]].push_back(v[i]);
            adj[v[i]].push_back(u[i]);
        }

        for (int i = 1; i <= N; i++) {
            if (adj[i].size() > 2) {
                return false;
            }
        }
        return true;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:

    void SampleTestCase1() {

        Subtasks({ 1, 3, 4, 5 });
        Input({
            "5",
            "1 2",
            "1 3",
            "1 4",
            "1 5"
        });
        Output({
            "24"
        });
    }

    void BeforeTestCase() {
        U.clear();
        V.clear();
    }

    void TestGroup1() {

        Subtasks({ 1, 2, 4, 5 });

        CASE(N = 4, randomLine());
        CASE(N = 20, randomLine());
        CASE(N = 40, randomLine());
    }

    void TestGroup2() {

        Subtasks({ 1, 3, 4, 5 });

        CASE(N = 4, randomTrueStar());
        CASE(N = 20, randomTrueStar());
        CASE(N = 40, randomTrueStar());
    }

    void TestGroup3() {

        Subtasks({ 1, 4, 5 });

        CASE(N = 10, randomTree());
        CASE(N = 40, randomTree());
        CASE(N = 20, randomCaterpillarTree(8));
        CASE(N = 40, randomCaterpillarTree(10));
        CASE(N = 40, randomCaterpillarTree(18));
        CASE(N = 40, randomStarTree(8, 3));
        CASE(N = 40, randomStarTree(10, 4));
        CASE(N = 40, randomStarTree(12, 3));
    }

    void TestGroup4() {

        Subtasks({ 2, 4, 5 });

        CASE(N = 500, randomLine());
        CASE(N = 1000, randomLine());
    }

    void TestGroup5() {

        Subtasks({ 2, 5 });

        CASE(N = 100000, randomLine());
        CASE(N = 200000, randomLine());
    }

    void TestGroup6() {

        Subtasks({ 3, 4, 5 });

        CASE(N = 500, randomTrueStar());
        CASE(N = 600, randomTrueStar());
        CASE(N = 800, randomTrueStar());
        CASE(N = 969, randomTrueStar());
        CASE(N = 1000, randomTrueStar());
    }

    void TestGroup7() {
        Subtasks({ 3, 5 });

        CASE(N = 100000, randomTrueStar());
        CASE(N = 150000, randomTrueStar());
        CASE(N = 200000, randomTrueStar());
    }

    void TestGroup8() {

        Subtasks({ 4, 5 });

        CASE(N = 100, randomTree());
        CASE(N = 500, randomTree());
        CASE(N = 1000, randomTree());
        CASE(N = 400, randomCaterpillarTree(100));
        CASE(N = 400, randomCaterpillarTree(200));
        CASE(N = 500, randomCaterpillarTree(300));
        CASE(N = 1000, randomCaterpillarTree(350));
        CASE(N = 1000, randomCaterpillarTree(500));
        CASE(N = 400, randomStarTree(20, 10));
        CASE(N = 700, randomStarTree(30, 15));
        CASE(N = 800, randomStarTree(100, 10));
        CASE(N = 1000, randomStarTree(50, 17));
        CASE(N = 1000, randomStarTree(40, 12));
        CASE(N = 1000, randomStarTree(100, 6));
    }

    void TestGroup9() {

        Subtasks({ 5 });

        CASE(N = 100000, randomTree());
        CASE(N = 150000, randomTree());
        CASE(N = 200000, randomTree());
        CASE(N = 200000, randomTree());

        CASE(N = 100000, randomCaterpillarTree(3000));
        CASE(N = 100000, randomCaterpillarTree(30000));
        CASE(N = 100000, randomCaterpillarTree(50000));
        CASE(N = 100000, randomCaterpillarTree(80000));
        CASE(N = 100000, randomCaterpillarTree(90000));
        CASE(N = 200000, randomCaterpillarTree(1000));
        CASE(N = 200000, randomCaterpillarTree(10000));
        CASE(N = 200000, randomCaterpillarTree(40000));
        CASE(N = 200000, randomCaterpillarTree(70000));
        CASE(N = 200000, randomCaterpillarTree(100000));
        CASE(N = 200000, randomCaterpillarTree(120000));

        CASE(N = 100000, randomStarTree(50000, 20));
        CASE(N = 100000, randomStarTree(3000, 100));
        CASE(N = 100000, randomStarTree(2000, 30));
        CASE(N = 150000, randomStarTree(100000, 60));
        CASE(N = 160000, randomStarTree(80000, 10));
        CASE(N = 180000, randomStarTree(40000, 50));
        CASE(N = 180000, randomStarTree(4000, 55));
        CASE(N = 200000, randomStarTree(40, 100));
        CASE(N = 200000, randomStarTree(40, 50));
        CASE(N = 200000, randomStarTree(1000, 80));
        CASE(N = 200000, randomStarTree(4000, 40));
        CASE(N = 200000, randomStarTree(100000, 70));
        CASE(N = 200000, randomStarTree(100000, 10));
        CASE(N = 200000, randomStarTree(10000, 20));
        CASE(N = 200000, randomStarTree(6000, 15));
        CASE(N = 200000, randomStarTree(50000, 8));
        CASE(N = 200000, randomStarTree(100, 100));
    }

private:
    void randomLine() {
        vector<int> perm(N);
        iota(perm.begin(), perm.end(), 1);

        rnd.shuffle(perm.begin(), perm.end());
        vector<pair<int, int> > edges;
        for (int i = 0; i < N - 1; i++) {
            edges.emplace_back(perm[i], perm[i + 1]);
        }

        rnd.shuffle(edges.begin(), edges.end());
        for (int i = 0; i < N - 1; i++) {
            if (rnd.nextInt(0, 1) == 1) {
                swap(edges[i].first, edges[i].second);
            }
            U.push_back(edges[i].first);
            V.push_back(edges[i].second);
        }
    }

    void randomTree() {
        vector<pair<int, int> > edges;
        for (int i = 2; i <= N; i++) {
            edges.emplace_back(i, rnd.nextInt(1, i - 1));
        }
        rnd.shuffle(edges.begin(), edges.end());

        for (int i = 0; i < N - 1; i++) {
            if (rnd.nextInt(0, 1) == 1) {
                swap(edges[i].first, edges[i].second);
            }
            U.push_back(edges[i].first);
            V.push_back(edges[i].second);
        }
    }

    void randomCaterpillarTree(const int d) {
        vector<int> perm(d);
        iota(perm.begin(), perm.end(), 1);
        rnd.shuffle(perm.begin(), perm.end());
        vector<pair<int, int> > edges;
        for (int i = 0; i < d - 1; i++) {
            edges.emplace_back(perm[i], perm[i + 1]);
        }
        for (int i = d + 1; i <= N; i++) {
            edges.emplace_back(rnd.nextInt(1, d), i);
        }

        vector<int> shf(N);
        iota(shf.begin(), shf.end(), 0);
        rnd.shuffle(shf.begin(), shf.end());
        for (auto &[x, y] : edges) {
            x = shf[x - 1] + 1;
            y = shf[y - 1] + 1;
        }
        rnd.shuffle(edges.begin(), edges.end());
        for (int i = 0; i < N - 1; i++) {
            if (rnd.nextInt(0, 1) == 1) {
                swap(edges[i].first, edges[i].second);
            }
            U.push_back(edges[i].first);
            V.push_back(edges[i].second);
        }
    }

    void randomStarTree(const int f, const int k){
        vector<int> perm(N);
        iota(perm.begin(), perm.end(), 1);
        rnd.shuffle(perm.begin(), perm.end());

        vector<int> prev_layer;
        prev_layer.push_back(perm[0]);

        bool first = 1;
        int index = 0, cur = N - 1;
        vector<pair<int, int>> edges;
        while(cur > 0){
            vector<int> cur_layer;
            int sz = (int)prev_layer.size();

            if(first){
                first = 0;
                int par = prev_layer.back();
                for(int i = 1; i <= f; ++i){
                    int now = perm[++index];

                    cur_layer.push_back(now);
                    edges.push_back({par, now});
                }
                cur -= f;
            }
            else{
                for(int par : prev_layer){
                    int children = rnd.nextInt(max(0, min(cur, k - 2)), min(cur, k + 2));
                    for(int i = 1; i <= min(cur, children); ++i){
                        int now = perm[++index];

                        cur_layer.push_back(now);
                        edges.push_back({par, now});
                    }
                    cur -= min(cur, children);
                }
            }
            prev_layer = cur_layer;
        }

        for (int i = 0; i < N - 1; i++) {
            if (rnd.nextInt(0, 1) == 1) {
                swap(edges[i].first, edges[i].second);
            }
            U.push_back(edges[i].first);
            V.push_back(edges[i].second);
        }
    }

    void randomTrueStar() {
        vector<int> perm(N);
        iota(perm.begin(), perm.end(), 1);
        rnd.shuffle(perm.begin(), perm.end());

        vector<pair<int, int>> edges;
        for(int i = 0; i < N; ++i){
            if(perm[i] != 1){
                edges.push_back({1, perm[i]});
            }
        }

        for (int i = 0; i < N - 1; i++) {
            if (rnd.nextInt(0, 1) == 1) {
                swap(edges[i].first, edges[i].second);
            }
            U.push_back(edges[i].first);
            V.push_back(edges[i].second);
        }
    }
};
