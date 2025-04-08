#pragma once
#include <stdio.h>
#include <vector>

#define MAX_DEGREE 101

using namespace std;

class SparsePoly {

    int numTerms;
    std::vector<int> exponents;
    std::vector<float> coefficients;

public:
    // 생성자
    SparsePoly() {}

    // 다항식 입력 함수
    void read() {

        int deg;
        float value;
        int i = 0;

        printf("항의 개수를 입력하세요: ");
        scanf_s("%d", &numTerms);

        for (i = 0; i < numTerms; i++) {
            printf("%d번째 항의 계수와 차수를 입력하세요:(에: 계수 차수 ): ", i + 1);
            scanf_s("%f %d", &value, &deg);

            if (deg >= MAX_DEGREE) {
                printf("exeed MAX_DEGREE\n");
                printf("다시입력\n");
                i--;
                continue;

            }

            coefficients.push_back(value);
            exponents.push_back(deg);

            //printf("coefficients = %f\n", coefficients[i]);
            //printf("exponents = %d\n", exponents[i]);
        }


    }

    // 다항식 출력 함수
    void display(const char* str) {

        printf("%s", str);

        int i = 0;
        bool first_term = true;

        // Purpose: 항수만큼 출력
        for (i = 0; i < numTerms; i++) {

            // 부호 출력(단, 첫항은 부호를 붙이지 않음)
            if (first_term == false) {
                if (coefficients[i] == 0)
                    continue;
                else {
                    if (coefficients[i] > 0)
                        printf(" + ");
                    else
                        printf(" - ");
                }
            }

            first_term = false;

            printf("%.1f", coefficients[i]);
            printf("x^%d", exponents[i]);
        }
        printf("\n");
    }

    // 다항식 덧셈 함수
    void add(SparsePoly a, SparsePoly b) {

        int exp;
        float coeff;
        int i;
        int j;
        bool same_exp;

        // 현재 객체(this)의 멤버 변수 초기화
        exponents.clear();
        coefficients.clear();
        numTerms = 0;

        // Purpose: A 다항식 복사
        exponents = a.exponents;
        coefficients = a.coefficients;
        numTerms = a.numTerms;

        // Purpose: B 다항식 처리 
        for (i = 0; i < b.numTerms; i++) {
            exp = b.exponents[i];
            coeff = b.coefficients[i];

            // 차수가 같은지 여부 확인
            same_exp = false;

            // 같은 차수이면 계수 합산
            for (j = 0; j < exponents.size(); j++) {
                if (exponents[j] == exp) {
                    coefficients[j] += coeff;      
                    same_exp = true;
                    break;
                }
            }

            // 다른 차수이면 새로운 항 추가
            if (!same_exp) {
                exponents.push_back(exp);
                coefficients.push_back(coeff);
                numTerms++;
            }
        }
        // printf("Poly C의 항수 = %d\n", numTerms);
    }
};
	
 