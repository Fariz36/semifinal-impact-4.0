#include <tcframe/spec.hpp>
using namespace tcframe;

class ProblemSpec : public BaseProblemSpec {
protected:
    int N;
    long long answer;

    void InputFormat() {
        LINE(N);
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
        CONS(1 <= N && N <= 1000000000);
    }

    void Subtask1() {
		Points(17);

		CONS(1 <= N && N <= 1000);
	}

	void Subtask2() {
		Points(31);

		CONS(1 <= N && N <= 1000000);
	}

	void Subtask3() {
		Points(52);

		CONS(1 <= N && N <= 1000000000);
	}

};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {

        Subtasks({ 1, 2, 3 });
        Input({
            "8"
        });
        Output({
            "2"
        });
    }

    void SampleTestCase2() {

        Subtasks({ 1, 2, 3 });
        Input({
            "9"
        });
        Output({
            "3"
        });
    }

    void TestGroup1() {

        Subtasks({ 1, 2, 3 });

        CASE(N = 1);
        CASE(N = 2);
        CASE(N = 5);
        CASE(N = 28);
        CASE(N = 149);
        CASE(N = 177);
        CASE(N = 512);
        CASE(N = 713);
        CASE(N = 815);
        CASE(N = 969);
        CASE(N = 998);
        CASE(N = 999);
        CASE(N = 1000);

    }

    void TestGroup2() {

        Subtasks({ 2, 3 });

        CASE(N = 999999);
        CASE(N = 167692);
        CASE(N = 696969);
        CASE(N = 867693);
        CASE(N = 487214);
        CASE(N = 33089);
        CASE(N = 523288);
        CASE(N = 531741);
        CASE(N = 510546);
        CASE(N = 724858);
        CASE(N = 1000000);
    }

    void TestGroup3() {

        Subtasks({ 3 });

        CASE(N = 1000000000);
        CASE(N = 999999999);
        CASE(N = 977973040);
        CASE(N = 855641120);
        CASE(N = 948804348);
        CASE(N = 977691364);
        CASE(N = 935829584);
        CASE(N = 977973041);
        CASE(N = 855641121);
        CASE(N = 948804349);
        CASE(N = 977691365);
        CASE(N = 935829585);
        CASE(N = 135232330);
        CASE(N = 694201773);
    }
};
