#include "../exercise.h"

constexpr unsigned long long fibonacci(int i) {
    // switch (i) {
    //     case 0:
    //         return 0;
    //     case 1:
    //         return 1;
    //     default:
    //         return fibonacci(i - 1) + fibonacci(i - 2);
    // }
    //dynamic programming
    if (i == 0) return 0;
    if (i == 1) return 1;

    unsigned long long prev1 = 0, prev2 = 1;
    unsigned long long result = 0;

    for (int j = 2; j <= i; ++j) {
        result = prev1 + prev2;
        prev1 = prev2;
        prev2 = result;
    }
    return result;
}

int main(int argc, char **argv) {
    constexpr auto FIB20 = fibonacci(20);
    ASSERT(FIB20 == 6765, "fibonacci(20) should be 6765");
    std::cout << "fibonacci(20) = " << FIB20 << std::endl;

    // TODO: 观察错误信息，修改一处，使代码编译运行
    // PS: 编译运行，但是不一定能算出结果……
    constexpr auto ANS_N = 90;
    const auto ANS = fibonacci(ANS_N);
    std::cout << "fibonacci(" << ANS_N << ") = " << ANS << std::endl;

    return 0;
}
