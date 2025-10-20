#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define EPS 0.000001  // заданная точность

// Функции
double f1(double x) { return 0.6 * x + 3; }
double f2(double x) { return pow(x - 2, 3) - 1; }
double f3(double x) { return 3 / x; }

// Производные функций
double df1(double x) { return 0.6; }
double df2(double x) { return 3 * pow(x - 2, 2); }
double df3(double x) { return -3 / (x * x); }
// Переменные отображения статистики
char sh_root_counter = 0, sh_roots = 0;

// Функция для нахождения корня уравнения f(x) = g(x) методом касательных (Ньютона)
double root(double (*f)(double), double (*g)(double),
            double (*df)(double), double (*dg)(double),
            double x0, double eps) {
    double x = x0;
    double fx, gx, dfx, dgx, Fx, dFx;
    int iterations = 0;
    int max_iterations = 100;
    if (sh_root_counter)
        printf("  Newton method starting from x0 = %lf\n", x0);


    do {
        fx = f(x);
        gx = g(x);
        dfx = df(x);
        dgx = dg(x);

        Fx = fx - gx;        // F(x) = f(x) - g(x)
        dFx = dfx - dgx;     // F'(x) = f'(x) - g'(x)

        if (fabs(dFx) < eps) {
            printf("  Warning: Derivative too small at x = %lf\n", x);
            break;
        }

        double x_new = x - Fx / dFx;

        // Проверка на выход за разумные пределы
        if (isnan(x_new) || isinf(x_new)) {
            printf("  Error: Newton method diverged\n");
            return NAN;
        }

        if (fabs(x_new - x) < eps) {
            x = x_new;
            break;
        }

        x = x_new;
        iterations++;

    } while (iterations < max_iterations && fabs(Fx) > eps);

    if (iterations == max_iterations) {
        printf("  Warning: Maximum iterations reached\n");
    }

    if (sh_root_counter)
        printf("  Converged in %d iterations to x = %lf\n", iterations, x);
    return x;
}

// Функция для вычисления интеграла методом Симпсона
double integral(double (*f)(double), double a, double b, double eps) {
    if (a >= b) {
        printf("Error: Invalid interval [%lf, %lf]\n", a, b);
        return NAN;
    }

    int n = 2;
    double h = (b - a) / n;
    double integral_prev = 0;
    double integral_curr = (f(a) + 4 * f((a + b) / 2) + f(b)) * h / 3;

    int max_iterations = 50;

    do {
        integral_prev = integral_curr;
        n *= 2;
        h = (b - a) / n;
        integral_curr = f(a) + f(b);

        for (int i = 1; i < n; i++) {
            double x = a + i * h;
            if (i % 2 == 0) {
                integral_curr += 2 * f(x);
            } else {
                integral_curr += 4 * f(x);
            }
        }
        integral_curr *= h / 3;

        if (--max_iterations == 0) {
            printf("Warning: Maximum iterations reached for integration\n");
            break;
        }
    } while (fabs(integral_curr - integral_prev) > eps);

    return integral_curr;
}

// Тестирование функции root (метод Ньютона)
void test_root() {
    printf("=== TESTING ROOT (NEWTON METHOD) ===\n");

    struct TestCase {
        double (*f)(double);
        double (*g)(double);
        double (*df)(double);
        double (*dg)(double);
        double x0;
        const char* description;
        double expected_root; // Эталонное значение
        double tolerance; // Погрешность
        int should_converge; // Сходимость функции (0 - не сходится/1 - сходится)
    } test_cases[] = {
        // Корректные тесты
        {f1, f3, df1, df3, 0.8, "f1 and f3 intersection (expected ~0.854)", 0.854, 0.01, 1},
        {f1, f2, df1, df2, 0.8, "f1 and f2 intersection (expected ~3.847)", 3.847, 0.01, 1},
        {f2, f3, df2, df3, 0.8, "f2 and f3 intersection (expected ~3.243)", 3.243, 0.01, 1},
        {f1, f3, df1, df3, 0.5, "f1 and f3 with different start", 0.854, 0.01, 1},

        // Тест с плохим начальным приближением (может сойтись к другому корню или расходиться)
        {f2, f3, df2, df3, -20.1, "f2 and f3 with bad start (may fail)", 3.0, 0.01, 0},

        // Тест с функциями, которые не пересекаются в ожидаемой области
        {f1, f3, df1, df3, 0.0, "f1 and f3 far from root (may fail)", 1.0, 0.01, 0},
    };

    int total_tests = sizeof(test_cases) / sizeof(test_cases[0]);
    int passed_tests = 0;

    for (int i = 0; i < total_tests; i++) {
        printf("\nTest %d: %s\n", i + 1, test_cases[i].description);
        double result = root(test_cases[i].f, test_cases[i].g,
                                                test_cases[i].df, test_cases[i].dg,
                                                test_cases[i].x0, EPS);
        if (!isnan(result)) {
            double diff = test_cases[i].f(result) - test_cases[i].g(result);
            double root_error = fabs(result - test_cases[i].expected_root);

            printf("  Final result: x = %lf\n", result);
            printf("  f(x) = %lf, g(x) = %lf, difference = %le\n",
                   test_cases[i].f(result), test_cases[i].g(result), diff);
            printf("  Error from expected root: %le\n", root_error);

            // Проверка: учитываем как точность корня, так и разность функций
            int root_accurate = (root_error < test_cases[i].tolerance);
            int functions_match = (fabs(diff) < EPS);

            if (test_cases[i].should_converge) {
                if (root_accurate && functions_match) {
                    printf("  Status: PASS \n");
                    passed_tests++;
                } else {
                    printf("  Status: FAIL  (root accuracy: %s, functions match: %s)\n",
                           root_accurate ? "YES" : "NO", functions_match ? "YES" : "NO");
                }
            } else {
                // Для тестов, где сходимость не ожидается
                if (root_accurate && functions_match) {
                    printf("  Status: UNEXPECTED PASS \n");
                    passed_tests++;
                } else {
                    printf("  Status: EXPECTED FAILURE \n");
                    passed_tests++;
                }
            }
        } else {
            printf("  Root finding failed\n");
            if (!test_cases[i].should_converge) {
                printf("  Status: EXPECTED FAILURE \n");
                passed_tests++;
            } else {
                printf("  Status: FAIL \n");
            }
        }
    }

    printf("\n=== TEST SUMMARY ===\n");
    printf("Passed: %d/%d tests\n", passed_tests, total_tests);
    printf("Success rate: %.1f%%\n", (double)passed_tests / total_tests * 100);
}

// Тестирование функции integral
void test_integral() {
    printf("\n=== TESTING INTEGRAL FUNCTION ===\n");

    // Тестовые функции с известными интегралами
    double linear_func(double x) { return 2 * x + 1; } // integral(2x+1)dx = x² + x
    double square_func(double x) { return x * x; }     // integral(x*x)dx = x³/3
    double const_func(double x) { return 5; }          // integral(5)dx = 5x

    struct IntegralTest {
        double (*f)(double);
        double a;
        double b;
        double expected;
        const char* description;
    } tests[] = {
        {linear_func, 0, 2, 6.0, "integral(2x+1)dx from 0 to 2 = 6"},
        {square_func, 0, 1, 1.0/3.0, "integral(x*x)dx from 0 to 1 = 1/3"},
        {const_func, 1, 4, 15.0, "integral(5)dx from 1 to 4 = 15"},
        {f1, 0, 2, 7.2, "integral(0.6x+3)dx from 0 to 2 = 7.2"} // 0.3x² + 3x = 7.2
    };

    for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++) {
        printf("\nTest %d: %s\n", i + 1, tests[i].description);
        double result = integral(tests[i].f, tests[i].a, tests[i].b, EPS);

        if (!isnan(result)) {
            double error = fabs(result - tests[i].expected);
            printf("  Computed: %lf\n", result);
            printf("  Expected: %lf\n", tests[i].expected);
            printf("  Error: %le\n", error);
            printf("  Status: %s\n", error < EPS ? "PASS" : "FAIL");
        } else {
            printf("  Integration failed\n");
        }
    }
}

// Основной расчет площади
void calculate_main_area() {
    printf("\n=== MAIN AREA CALCULATION ===\n");

    double eps = EPS;

    printf("Computing area with precision %e\n", eps);

    // Находим точки пересечения методом Ньютона
    if (sh_root_counter)
    printf("\nFinding intersection points using Newton method:\n");

    double x_A = root(f3, f1, df3, df1, 0.8, eps);  // Точка A (f3 & f1)
    double x_B = root(f3, f2, df3, df2, 3.0, eps);  // Точка B (f3 & f2)
    double x_C = root(f2, f1, df2, df1, 0.8, eps);  // Точка C (f2 & f1)

    if (isnan(x_A) || isnan(x_B) || isnan(x_C)) {
        printf("Error: Could not find all intersection points\n");
        return;
    }
    if (sh_roots) {
        printf("\nIntersection points:\n");
        printf("A (f3 & f1): x = %lf, y1 = %lf, y2 = %lf\n", x_A, f3(x_A), f1(x_A));
        printf("B (f3 & f2): x = %lf, y1 = %lf, y3 = %lf\n", x_B, f3(x_B), f2(x_B));
        printf("C (f2 & f1): x = %lf, y2 = %lf, y3 = %lf\n", x_C, f2(x_C), f1(x_C));
    }

    // Вычисляем площадь как сумму площадей двух областей
    double area1 = fabs(integral(f1, x_A, x_B, eps)
     - integral(f3, x_A, x_B, eps)); // Между A и B
    double area2 = fabs(integral(f1, x_B, x_C, eps)
     - integral(f2, x_B, x_C, eps)); // Между B и C

    if (isnan(area1) || isnan(area2)) {
        printf("Error: Area calculation failed\n");
        return;
    }

    double total_area = area1 + area2 ;

    printf("\nArea results:\n");
    printf("Area 1 [A-B]: %lf\n", area1);
    printf("Area 2 [B-C]: %lf\n", area2);
    printf("Total area: %lf\n", total_area);
}

// Функция для вывода справки
void print_help(const char* fileName) {
    printf("Usage:\n");
    printf("  %s test_root          - test intersection finding (Newton method)\n", fileName);
    printf("  %s test_integral      - test numerical integration function\n", fileName);
    printf("  %s sh_roots           - show coordinates intersection points\n", fileName);
    printf("  %s sh_iteration       - show iterations of the intersection algorithm\n", fileName);
    printf("  %s area               - compute the main area with sh_iteration and sh_iteration\n", fileName);
    printf("  %s all                - run all tests and compute area\n", fileName);
    printf("  %s help               - show this help message\n", fileName);
    printf("  (no arguments)          - compute main area only\n");
}

int main(int argc, char *argv[]) {
    printf("\nCurve Area Calculator (Newton Method)\n");
    printf("Precision: %e\n", EPS);
    printf("Functions: \n");
    printf("\tf1 = %s\n", "0.6 * x + 3");
    printf("\tf2 = %s\n", "(x - 2)3 - 1");
    printf("\tf3 = %s\n", "3 / x\n");
    // Обработка аргументов командной строки
    if (argc == 1) {
        // Без аргументов - только основной расчет
        calculate_main_area();
    } else if (argc == 2) {
        if (strcmp(argv[1], "test_root") == 0) {
            sh_root_counter = 1;
            test_root();
        } else if (strcmp(argv[1], "test_integral") == 0) {
            test_integral();
        } else if (strcmp(argv[1], "sh_roots") == 0) {
            sh_roots = 1;
            calculate_main_area();
        } else if (strcmp(argv[1], "sh_iteration") == 0) {
            sh_root_counter = 1;
            calculate_main_area();
        } else if (strcmp(argv[1], "area") == 0) {
            sh_roots = 1;
            sh_root_counter = 1;
            calculate_main_area();
        } else if (strcmp(argv[1], "all") == 0) {
            sh_roots = 1;
            sh_root_counter = 1;
            test_root();
            test_integral();
            calculate_main_area();
        } else if (strcmp(argv[1], "help") == 0) {
            print_help(argv[0]);
        } else {
            printf("Unknown option: %s\n", argv[1]);
            print_help(argv[0]);
            return 1;
        }
    } else {
        printf("Too many arguments\n");
        print_help(argv[0]);
        return 1;
    }

    return 0;
}
