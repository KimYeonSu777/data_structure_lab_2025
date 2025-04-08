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
    // ������
    SparsePoly() {}

    // ���׽� �Է� �Լ�
    void read() {

        int deg;
        float value;
        int i = 0;

        printf("���� ������ �Է��ϼ���: ");
        scanf_s("%d", &numTerms);

        for (i = 0; i < numTerms; i++) {
            printf("%d��° ���� ����� ������ �Է��ϼ���:(��: ��� ���� ): ", i + 1);
            scanf_s("%f %d", &value, &deg);

            if (deg >= MAX_DEGREE) {
                printf("exeed MAX_DEGREE\n");
                printf("�ٽ��Է�\n");
                i--;
                continue;

            }

            coefficients.push_back(value);
            exponents.push_back(deg);

            //printf("coefficients = %f\n", coefficients[i]);
            //printf("exponents = %d\n", exponents[i]);
        }


    }

    // ���׽� ��� �Լ�
    void display(const char* str) {

        printf("%s", str);

        int i = 0;
        bool first_term = true;

        // Purpose: �׼���ŭ ���
        for (i = 0; i < numTerms; i++) {

            // ��ȣ ���(��, ù���� ��ȣ�� ������ ����)
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

    // ���׽� ���� �Լ�
    void add(SparsePoly a, SparsePoly b) {

        int exp;
        float coeff;
        int i;
        int j;
        bool same_exp;

        // ���� ��ü(this)�� ��� ���� �ʱ�ȭ
        exponents.clear();
        coefficients.clear();
        numTerms = 0;

        // Purpose: A ���׽� ����
        exponents = a.exponents;
        coefficients = a.coefficients;
        numTerms = a.numTerms;

        // Purpose: B ���׽� ó�� 
        for (i = 0; i < b.numTerms; i++) {
            exp = b.exponents[i];
            coeff = b.coefficients[i];

            // ������ ������ ���� Ȯ��
            same_exp = false;

            // ���� �����̸� ��� �ջ�
            for (j = 0; j < exponents.size(); j++) {
                if (exponents[j] == exp) {
                    coefficients[j] += coeff;      
                    same_exp = true;
                    break;
                }
            }

            // �ٸ� �����̸� ���ο� �� �߰�
            if (!same_exp) {
                exponents.push_back(exp);
                coefficients.push_back(coeff);
                numTerms++;
            }
        }
        // printf("Poly C�� �׼� = %d\n", numTerms);
    }
};
	
 