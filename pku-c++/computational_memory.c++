#include <iostream>

using namespace std;

// version 1
namespace v1 {
    struct s1 {
        char a;
        char b;
        char c;
                // 4
        int x;  // 4

        char d; // 1
    };
}

// version 2
namespace v2 {
    struct s1 {
        char a;
        char b;
        char c;
        char d;

        int x;  // 4

    };
}

// version 3
namespace v3 {
    struct s2 { int j;  int k; int l; };

    struct s1 {
        char a;
        char b;
        char c;
                // 4
        int x;  // 4

        char d; // 1

        struct s2 u;
        // int j;  int k; int l;
    };
}

// version 4
namespace v4 {
    struct s2 { int j;  int k; int l; };

    struct s1 {
        char a;
        char b;
        char c;
                // 4
        int x;  // 4

        char d; // 1

        // struct s2 u;
        int j;  int k; int l;
    };
}

// version 5
namespace v5 {
    struct s2 { int j;  int k; long long l; };

    struct s1 {
        char a;
        char b;
        char c;
                // 4
        int x;  // 4

        char d; // 1

        struct s2 u;
        // int j;  int k; int l;
    };
}

// version 6
namespace v6 {
    struct s2 { int j;  long long k; int l; };

    struct s1 {
        char a;
        char b;
        char c;
                // 4
        int x;  // 4

        char d; // 1

        struct s2 u;
        // int j;  int k; int l;
    };
}

void testV1() {
    v1::s1 v1s1;
    printf("a-%s", &v1s1.a);
    printf("a-%s", &v1s1.b);
    printf("a-%s", &v1s1.c);
    printf("a-%s", &v1s1.x);
    printf("a-%s", &v1s1.d);
}

void testV2() {
    v2::s1 v2s1;
    printf("a-%s", &v2s1.a);
    printf("a-%s", &v2s1.b);
    printf("a-%s", &v2s1.c);
    printf("a-%s", &v2s1.d);
    printf("a-%s", &v2s1.x);
}

void testv3() {
    v3::s1 v3s1 ;
    v3::s2 v3s2;
    printf("a-%s", &v3s1.a);
    printf("a-%s", &v3s1.b);
    printf("a-%s", &v3s1.c);
    printf("a-%s", &v3s1.x);
    printf("a-%s", &v3s1.d);
    printf("a-%s", &v3s1.u);
    printf("a-%s", &v3s2.j);
    printf("a-%s", &v3s2.k);
    printf("a-%s", &v3s2.l);
}

void testv4() {
    v4::s1 v4s1;
    v4::s2 v4s2;
    printf("a-%s", &v4s1.a);
    printf("a-%s", &v4s1.b);
    printf("a-%s", &v4s1.c);
    printf("a-%s", &v4s1.x);
    printf("a-%s", &v4s1.d);
    printf("a-%s", &v4s1.j);
    printf("a-%s", &v4s1.k);
    printf("a-%s", &v4s1.l);
    printf("a-%s", &v4s2.j);
    printf("a-%s", &v4s2.k);
    printf("a-%s", &v4s2.l);
}

void testv5() {
    v5::s1 v5s1;
    v5::s2 v5s2;
    printf("a-%s", &v5s1.a);
    printf("a-%s", &v5s1.b);
    printf("a-%s", &v5s1.c);
    printf("a-%s", &v5s1.x);
    printf("a-%s", &v5s1.d);
    printf("a-%s", &v5s1.u);
    printf("a-%s", &v5s2.j);
    printf("a-%s", &v5s2.k);
    printf("a-%s", &v5s2.l);
}

void testv6() {
    v6::s1 v6s1;
    v6::s2 v6s2;
    printf("a-%s", &v6s1.a);
    printf("a-%s", &v6s1.b);
    printf("a-%s", &v6s1.c);
    printf("a-%s", &v6s1.x);
    printf("a-%s", &v6s1.d);
    printf("a-%s", &v6s1.u);
    printf("a-%s", &v6s2.j);
    printf("a-%s", &v6s2.k);
    printf("a-%s", &v6s2.l);
}
int main() {
    testV1();
    testV2();
    testv3();
    testv4();
    testv5();
    testv6();
    return 0;

}