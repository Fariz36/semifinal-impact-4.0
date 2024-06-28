#include <tcframe/spec.hpp>
using namespace tcframe;

class ProblemSpec : public BaseProblemSpec {
protected:
    int N, L, R;
    long long answer;

    void InputFormat() {
        LINE(N, L, R);
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
        CONS(1 <= N && N <= 1000);
        CONS(0 <= L && L <= N && 0 <= R && R <= N);
    }

    void Subtask1() {
		Points(8);

		CONS(1 <= N && N <= 6);
	}

	void Subtask2() {
		Points(13);

		CONS(1 <= N && N <= 50);
	}

	void Subtask3() {
		Points(10);

		CONS(1 <= N && N <= 500);
		CONS(L == 1 && R == 1);
	}

	void Subtask4() {
		Points(17);

		CONS(1 <= N && N <= 500);
		CONS(L + R == N);
	}

	void Subtask5() {
		Points(11);

		CONS(1 <= N && N <= 500);
		CONS(L + R == N - 1);
	}

	void Subtask6() {
		Points(18);

		CONS(1 <= N && N <= 500);
	}

	void Subtask7() {
		Points(23);
	}

};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {

        Subtasks({ 1, 2, 4, 6, 7 });
        Input({
            "3 2 1"
        });
        Output({
            "17985"
        });
    }

    void TestGroup1() {

        Subtasks({ 1, 2, 6, 7 });

        CASE(N = 2, L = 0, R = 0);
        CASE(N = 3, L = 0, R = 0);
        CASE(N = 6, L = 0, R = 0);
        CASE(N = 5, L = 0, R = 3);
        CASE(N = 6, L = 0, R = 3);
        CASE(N = 5, L = 3, R = 0);
        CASE(N = 6, L = 3, R = 0);
        CASE(N = 5, L = 4, R = 3);
        CASE(N = 6, L = 5, R = 4);
    }

    void TestGroup2() {

        Subtasks({ 1, 2, 3, 6, 7});

        CASE(N = 5, L = 1, R = 1);
        CASE(N = 6, L = 1, R = 1);
    }

    void TestGroup3() {

        Subtasks({ 1, 2, 4, 6, 7 });

        CASE(N = 6, L = 3, R = 3);
        CASE(N = 5, L = 2, R = 3);
    }

    void TestGroup4() {
        Subtasks({ 1, 2, 5, 6, 7 });

        CASE(N = 6, L = 2, R = 3);
        CASE(N = 5, L = 2, R = 2);
        CASE(N = 1, L = 0, R = 0);
    }

    void TestGroup5() {

        Subtasks({ 2, 6, 7 });

        CASE(N = 49, L = 0, R = 0);
        CASE(N = 50, L = 0, R = 0);
        CASE(N = 50, L = 24, R = 24);
        CASE(N = 50, L = 10, R = 10);
        CASE(N = rnd.nextInt(40, 50), L = rnd.nextInt(1, 10), R = rnd.nextInt(1, 10));
        CASE(N = rnd.nextInt(40, 50), L = rnd.nextInt(10, 20), R = rnd.nextInt(10, 20));
        CASE(N = rnd.nextInt(40, 50), L = rnd.nextInt(10, 20), R = rnd.nextInt(10, 20));
        CASE(N = rnd.nextInt(40, 50), L = rnd.nextInt(10, 20), R = rnd.nextInt(10, 20));

    }

    void TestGroup6() {

        Subtasks({ 2, 4, 6, 7 });

        CASE(N = 50, L = 1, R = 49);
        CASE(N = 50, L = 25, R = 25);
        CASE(N = 49, L = 25, R = 24);
    }

    void TestGroup7() {

        Subtasks({ 2, 5, 6, 7 });

        CASE(N = 50, L = 1, R = 48);
        CASE(N = 50, L = 25, R = 24);
    }

    void TestGroup8() {

        Subtasks({ 3, 6, 7 });

        CASE(N = 500, L = 1, R = 1);
        CASE(N = 400, L = 1, R = 1);
        CASE(N = 69, L = 1, R = 1);
        CASE(N = 190, L = 1, R = 1);
        CASE(N = 297, L = 1, R = 1);
        CASE(N = 345, L = 1, R = 1);
        CASE(N = 420, L = 1, R = 1);
    }

    void TestGroup9() {

        Subtasks({ 4, 6, 7 });

        CASE(N = 500, L = 500, R = 0);
        CASE(N = 500, L = 0, R = 500);
        CASE(N = 500, L = 499, R = 1);
        CASE(N = 500, L = 1, R = 499);
        CASE(N = 500, L = 250, R = 250);
        CASE(N = 500, L = 249, R = 251);
        CASE(N = 500, L = 122, R = N-L);
        CASE(N = rnd.nextInt(300, 500), L = rnd.nextInt(100, N), R = N-L);
        CASE(N = rnd.nextInt(300, 500), L = rnd.nextInt(200, N), R = N-L);
        CASE(N = rnd.nextInt(100, 200), L = rnd.nextInt(50, N), R = N-L);
    }

    void TestGroup10() {

        Subtasks({ 5, 6, 7 });

        CASE(N = 500, L = 499, R = 0);
        CASE(N = 500, L = 0, R = 499);
        CASE(N = 500, L = 498, R = 1);
        CASE(N = 500, L = 1, R = 498);
        CASE(N = 499, L = 249, R = 249);
        CASE(N = 500, L = 250, R = 249);
        CASE(N = 500, L = 122, R = N-L-1);
        CASE(N = rnd.nextInt(300, 500), L = rnd.nextInt(100, N), R = N-L-1);
        CASE(N = rnd.nextInt(300, 500), L = rnd.nextInt(200, N), R = N-L-1);
        CASE(N = rnd.nextInt(100, 200), L = rnd.nextInt(50, N), R = N-L-1);
    }

    void TestGroup11() {

        Subtasks({ 6, 7 });

        CASE(N = 500, L = rnd.nextInt(10, 50), R =  rnd.nextInt(10, 50));
        CASE(N = 500, L = rnd.nextInt(50, 100), R =  rnd.nextInt(10, 50));
        CASE(N = 500, L = rnd.nextInt(10, 50), R =  rnd.nextInt(50, 100));
        CASE(N = 500, L = rnd.nextInt(100, 200), R =  rnd.nextInt(100, 200));
        CASE(N = rnd.nextInt(400, 500), L = min(rnd.nextInt(300, 500), N), R = min(rnd.nextInt(300, 500), N));
        CASE(N = rnd.nextInt(300, 500), L = min(rnd.nextInt(200, 500), N), R = min(rnd.nextInt(200, 500), N));
    }

    void TestGroup12() {
        Subtasks({ 7 });

        CASE(N = 1000, L = 0, R = 0);
        CASE(N = 1000, L = 1, R = 1);
        CASE(N = 1000, L = 1, R = 2);
        CASE(N = 1000, L = rnd.nextInt(10, 50), R = rnd.nextInt(10, 50));
        CASE(N = 1000, L = rnd.nextInt(69, 420), R = rnd.nextInt(69, 420));
        CASE(N = rnd.nextInt(800, 1000), L = rnd.nextInt(400, 500), R = rnd.nextInt(400, 500));
        CASE(N = rnd.nextInt(800, 1000), L = rnd.nextInt(200, 500), R = rnd.nextInt(200, 500));
        CASE(N = rnd.nextInt(800, 1000), L = rnd.nextInt(10, 50), R = rnd.nextInt(10, 50));
    }
};
