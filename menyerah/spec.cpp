#include <tcframe/spec.hpp>
using namespace tcframe;

class ProblemSpec : public BaseProblemSpec {
protected:
    int N;
    vector<int> L, R;
    string answer;

    void InputFormat() {
        LINE(N);
        LINES(L, R) % SIZE(N);
    }

    void OutputFormat() {
        LINE(answer);
    }

    void StyleConfig() {
        CustomScorer();
    }

    void GradingConfig() {
        TimeLimit(2);
        MemoryLimit(256);
    }

    void Constraints() {
        CONS(1 <= N && N <= 200000);
        CONS(checkInterval(L, R, 1, 1000000000));
    }

    void Subtask1() {
		Points(7);

		CONS(N == 1);
		CONS(checkSame(L, R));
	}

	void Subtask2() {
		Points(8);

		CONS(N == 1);
	}

	void Subtask3() {
		Points(4);

		CONS(findOne(L));
	}

	void Subtask4() {
		Points(23);

		CONS(checkSame(L, R));
	}

	void Subtask5() {
		Points(19);

		CONS(checkInterval(L, R, 1, 1000000));
	}

	void Subtask6() {
		Points(39);
	}

private:
    bool checkSame(vector<int> &L, vector<int> &R){
        for(int i = 0; i < N; ++i){
            if(L[i] != R[i]){
                return 0;
            }
        }
        return 1;
    }

    bool checkInterval(vector<int> &L, vector<int> &R, int left, int right){
        bool check = 1;
        for(int i = 0; i < N; ++i){
            check &= (left <= L[i] && L[i] <= R[i] && R[i] <= right);
        }
        return check;
    }

    bool findOne(vector<int> &L){
        for(int i = 0; i < N; ++i){
            if(L[i] == 1){
                return 1;
            }
        }
        return 0;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:

    void BeforeTestCase() {
        L.clear();
        R.clear();
    }

    void SampleTestCase1() {

        Subtasks({ 4, 5, 6 });
        Input({
            "2",
            "2 2",
            "4 4"
        });
        Output({
            "YA"
        });
    }

    void TestGroup1() {

        Subtasks({ 1, 2, 3, 4, 5, 6 });

        CASE(N = 1, L = {1}, R = {1});
    }

    void TestGroup2() {

        Subtasks({ 1, 2, 4, 5, 6 });

        CASE(N = 1, L = {17}, R = {17});
        CASE(N = 1, L = {1000000}, R = {1000000});
    }

    void TestGroup3() {

        Subtasks({ 1, 2, 4, 6 });

        CASE(N = 1, L = {1000000000}, R = {1000000000});
    }

    void TestGroup4() {

        Subtasks({ 2, 6 });

        CASE(N = 1, L = {2}, R = {1000000000});
        CASE(N = 1, L = {457841}, R = {390538485});
    }

    void TestGroup5() {
        Subtasks({ 3, 5, 6 });

        CASE(N = 10, randomIntervalWithOne(1000000));
        CASE(N = 1000, randomIntervalWithOne(1000000));
        CASE(N = 100000, randomIntervalWithOne(1000000));
        CASE(N = 200000, randomIntervalWithOne(1000000));
        CASE(N = 200000 - rnd.nextInt(1, 10000), randomIntervalWithOne(1000000));
        CASE(N = 200000 - rnd.nextInt(1, 10000), randomIntervalWithOne(1000000));
        CASE(N = 200000 - rnd.nextInt(1, 50000), randomIntervalWithOne(1000000));
        CASE(N = 200000 - rnd.nextInt(1, 100000), randomIntervalWithOne(1000000));
    }

    void TestGroup6() {
        Subtasks({ 3, 6 });

        CASE(N = 5000, randomIntervalWithOne(1000000000));
        CASE(N = 10000, randomIntervalWithOne(1000000000));
        CASE(N = 100000, randomIntervalWithOne(1000000000));
        CASE(N = 200000, randomIntervalWithOne(1000000000));
        CASE(N = 200000 - rnd.nextInt(1, 10000), randomIntervalWithOne(1000000000));
        CASE(N = 200000 - rnd.nextInt(1, 10000), randomIntervalWithOne(1000000000));
        CASE(N = 200000 - rnd.nextInt(1, 50000), randomIntervalWithOne(1000000000));
        CASE(N = 200000 - rnd.nextInt(1, 100000), randomIntervalWithOne(1000000000));
    }

    void TestGroup7() {

        Subtasks({ 4, 5, 6 });

        CASE(N = 1000, leftEqualsRight(2, 1000000));
        CASE(N = 1000, leftEqualsRight(500000, 1000000));
        CASE(N = 10000, leftEqualsRight(500000, 1000000));
        CASE(N = 50000, leftEqualsRight(2, 1000000));
        CASE(N = 100000, leftEqualsRight(2, 1000000));
        CASE(N = 200000, leftEqualsRight(2, 1000000));
        CASE(N = 200000, leftEqualsRight(500000, 1000000));
        CASE(N = 200000 - rnd.nextInt(1, 1000), leftEqualsRight(2, 1000000));
        CASE(N = 200000 - rnd.nextInt(1, 10000), leftEqualsRight(rnd.nextInt(2, 500), 1000000));
        CASE(N = 200000 - rnd.nextInt(1, 100000), leftEqualsRight(rnd.nextInt(2, 500000), 1000000));

    }

    void TestGroup8() {

        Subtasks({ 4, 6 });

        CASE(N = 50000, leftEqualsRight(2, 1000000000));
        CASE(N = 100000, leftEqualsRight(500000000, 1000000000));
        CASE(N = 200000, leftEqualsRight(2, 1000000000));
        CASE(N = 200000, leftEqualsRight(500000, 1000000000));
        CASE(N = 200000 - rnd.nextInt(1, 1000), leftEqualsRight(2, 1000000000));
        CASE(N = 200000 - rnd.nextInt(1, 1000), leftEqualsRight(500000000, 1000000000));
        CASE(N = 200000 - rnd.nextInt(1, 10000), leftEqualsRight(rnd.nextInt(2, 5000), 1000000000));
        CASE(N = 200000 - rnd.nextInt(1, 10000), leftEqualsRight(rnd.nextInt(2, 100000), 1000000000));
        CASE(N = 200000 - rnd.nextInt(1, 50000), leftEqualsRight(rnd.nextInt(2, 500000000), 1000000000));

        CASE(N = 50000, multipleX(2, 2, 1000000000));
        CASE(N = 100000, multipleX(67, 67, 1000000000));
        CASE(N = 100000, multipleX(100, 200, 1000000000));
        CASE(N = 200000, multipleX(3458, 3458, 1000000000));
        CASE(N = 200000, multipleX(7000, 21000, 1000000000));
        CASE(N = 200000, multipleX(338047, 338047, 1000000000));
        CASE(N = 200000 - rnd.nextInt(1, 200), multipleX(100, 100, 1000000000));
        CASE(N = 200000 - rnd.nextInt(1, 1000), multipleX(5, 200, 1000000000));
        CASE(N = 200000 - rnd.nextInt(1, 30000), multipleX(100, 200, 1000000000));
        CASE(N = 200000 - rnd.nextInt(1, 30000), multipleX(13, 200, 1000000000));
    }

    void TestGroup9() {

        Subtasks({ 5, 6 });


        CASE(N = 100000, randomInterval(2, 1000000));
        CASE(N = 100000, randomLargeInterval(2, 1000000));
        CASE(N = 200000, randomInterval(2, 1000000));
        CASE(N = 200000, randomLargeInterval(2, 1000000));
        CASE(N = 200000, randomInterval(500000, 1000000));
        CASE(N = 200000 - rnd.nextInt(1, 1000), randomInterval(2, 1000000));
        CASE(N = 200000 - rnd.nextInt(1, 10000), randomInterval(rnd.nextInt(2, 500), 1000000));
        CASE(N = 200000 - rnd.nextInt(1, 10000), randomLargeInterval(rnd.nextInt(2, 1000), 1000000));
        CASE(N = 200000 - rnd.nextInt(1, 30000), randomLargeInterval(rnd.nextInt(2, 5000), 1000000));
        CASE(N = 200000 - rnd.nextInt(1, 30000), randomLargeInterval(rnd.nextInt(2, 10000), 1000000));
    }

    void TestGroup10() {

        Subtasks({ 6 });

        CASE(N = 200000, randomInterval(2, 1000000000));
        CASE(N = 200000, randomLargeInterval(2, 1000000000));
        CASE(N = 200000, randomInterval(rnd.nextInt(2, 1000000), 1000000000));
        CASE(N = 200000, randomLargeInterval(rnd.nextInt(2, 10000), 1000000000));
        CASE(N = 200000, randomLargeInterval(5000, 1000000000));
        CASE(N = 200000, randomLargeInterval(100000, 1000000000));
        CASE(N = 200000 - rnd.nextInt(1, 1000), randomInterval(2, 1000000000));
        CASE(N = 200000 - rnd.nextInt(1, 10000), randomInterval(rnd.nextInt(2, 500), 1000000000));
        CASE(N = 200000 - rnd.nextInt(1, 10000), randomInterval(rnd.nextInt(2, 100000), 1000000000));
        CASE(N = 200000 - rnd.nextInt(1, 10000), randomLargeInterval(rnd.nextInt(2, 1000), 1000000000));
        CASE(N = 200000 - rnd.nextInt(1, 10000), randomLargeInterval(rnd.nextInt(2, 5000), 1000000000));
        CASE(N = 200000 - rnd.nextInt(1, 30000), randomLargeInterval(rnd.nextInt(2, 10000), 1000000000));
        CASE(N = 200000 - rnd.nextInt(1, 30000), randomLargeInterval(rnd.nextInt(2, 20000), 1000000000));
    }

private:
    void randomIntervalWithOne(int right){
        for(int i = 1; i <= N; ++i){
            int l, r;

            if(i == 1){
                l = 1;
                r = rnd.nextInt(2, right);
            }
            else{
                l = rnd.nextInt(1, right - 1);
                r = rnd.nextInt(l + 1, right);
            }

            L.push_back(l);
            R.push_back(r);
        }
    }

    void leftEqualsRight(int left, int right){
        for(int i = 1; i <= N; ++i){
            int val = rnd.nextInt(left, right);

            L.push_back(val);
            R.push_back(val);
        }
    }

    void randomInterval(int left, int right){
        for(int i = 1; i <= N; ++i){
            int l, r;

            l = rnd.nextInt(left, right - 1);
            r = rnd.nextInt(l + 1, right);

            L.push_back(l);
            R.push_back(r);
        }
    }

    void randomLargeInterval(int left, int right){
        for(int i = 1; i <= N; ++i){
            int l, r;

            l = rnd.nextInt(left, right / 4);
            r = rnd.nextInt(l + 1, right);

            L.push_back(l);
            R.push_back(r);
        }
    }

    void multipleX(int X, int left, int right){
        for(int i = 1; i <= N; ++i){
            int val = X * rnd.nextInt(left / X, right / X);

            L.push_back(val);
            R.push_back(val);
        }
    }
};
