#include <iostream>
#include <complex>
#include <vector>

// using namespace std; 를 사용하면 std::cout 에서 std 를 안써도 된다.
using namespace std;

double square(double x) {
    return x * x;
}

void print_square(double x) {
    cout << x <<" 의 제곱 : " << square(x);
}

//사용자 정의 타입 구조체
/*
struct Vector {
    int sz; //원소의 갯수
    double* elem; // 원소를 가르키는 포인터
};

void vector_init(Vector& v, int s) {
    // vector_init의 함수를 사용하는 Vector 참조자를 사용하여 포인터위치를 할당받기 때문에 원본의 Vector를 변수위치를 가져온다.
    //new 연산자는 자유 저장 공간(동적메모리 or 힙메모리 라고부름)영역에 메모리를 할당.
    v.elem = new double[s];
    v.sz = s;
}
double read_and_sum(int s) {
    Vector v;
    vector_init(v, s);

    //Vector의 elem는 포인터로 지정되었지만 init에서 참조자를 통해 v.elem을 배열형식으로 할당하여 v.elem[]에 저장가능
    for (int i = 0; i != s; ++i) {
        cin >> v.elem[i];
    }
    double sum = 0;
    for (int i = 0; i != s; ++i) {
        sum += v.elem[i];
    }
    return sum;
}

//void f(Vector v, Vector& rv, Vector* pv){
//    int i1= v.sz;   //이름을 통해 접근
//    int i2= rv.sz;  //참조자를 통해 접근
//    int i3= pv->sz; //포인터를 통해 접근
//}
*/
//사용자 정의 타입 클래스

class Vector {
public:
    //Vector 생성 vector_init 역할 Vector a(s) 형식으로 바로 선언가능
    Vector(int s) :elem{ new double[s] }, sz{ s } {} 
    // double 참조자로 operator[] 라는 첨자 함수로 참조자를 반환
    double& operator[](int i) { return elem[i]; } // 원소 접근 - 첨자
    int size() { return sz; }
private:
    double* elem;
    int sz;
};

double read_and_sum(int s) {
    Vector v(s);

    for (int i = 0; i != v.size(); ++i) {
        cin >> v[i];
    }
    double sum = 0;
    for (int i = 0; i != v.size(); ++i) {
        sum += v[i];
    }
    return sum;
}


int main()
{

    //print_square(1.234);
    
    //complex 타입 (복소수)
    /* 
    //complex를 사용할려면 include <complex>를 추가 해야한다. 하지만 complex는 실제 값을 나타내야 하기 때문에 거의 사용 x
    //complex 타입은 복소수(실수와 허수{i}의 합)를 표현하는데 사용한다.
    complex<double> a(1); // 1 + 0i 표현 (1,0)
    complex<double> b = 2; // 2 + 0i 표현 (2,0)
    complex<double> c = { 1,2 }; // 1 + 2i 표현 (1,2)
    */
    
    //vector
    /*
    //가장 일반적인 사용자 타입설정 배열
    //개수에 맞춰서 자동적으로 메모리 할당 배열 중간에 삽입 삭제 없을경우 효율적
    vector<int> v1{ 1,2,3,4,5,6 };
    vector<int> v2 = { 1,2,3,4,5,6 };
    vector<int> v3(5); // 초기값 0으로된 원소 5개 생성 {0, 0, 0, 0, 0}
    vector<int> v4(5, 2); // 2로 초기화된 원소 5개 생성 {2, 2, 2, 2, 2}


    cout << v1.front() << endl; // front 는 배열 맨 첫번쨰를 표시
    cout << v1.back() << endl;// back 은 배열 맨 마지막을 표사
    
    cout << v2.front() << endl; // front 는 배열 맨 첫번쨰를 표시
    cout << v2.back(); // back 은 배열 맨 마지막을 표사
    */
    //auto
    /*
    // auto 는 자동적으로 값에 맞도록 타입설정  명시적으로 언급할 특별한 이유가 없을 떄 사용
    auto a = 1;
    auto b = 'c';
    */
    //상수  const 와 constexpr
    /*
    int a = 10;

    const int num1 = 20; //컴파일 시간 상수
    const int num2 = a; //런타임 상수

    constexpr int num3 = 20; //컴파일 시간 상수
    //constexpr int num4 = a;    // ERROR : 런타임 상수
   
    //같은 상수 키워드 이지만 const는 컴파일 시간, 실행시간 상수 모두 만들수 있고 constexpr은 컴파일 시간 상수만 만들 수 있다.
    */
    //if case 는 검사 for while 는 루프
    //if는 yes or no 선택지가 2가지 있을떄 사용하고 case는 yes or no 둘중 하나가 아니고 응답해야할떄 default 사용한다.
    //for은 반복횟수를 알떄 주로 사용하고 while은 true 나 false 나올때까지 계속 사용할때 주로 사용

    //포인터와 배열 루프 포인터 중요
    /*
    char v[6] = {'a','b','c','d','e','f'}; //6개 문자의 배열
    //char* p; // 문자를 가르키는 포인터
    char* p = &v[3]; // p는 v의 네번째 원소(포인터)를 가르킨다.
    char x = *p; // x에 p안에 있는 포인터 값의 원소값을 복사해준다. 포인터 위치 x
    char& r1 = *p;
    char& r2 = v[3]; // r2 는 v[3]에 대한 포인터 값을 가지고 있으므로 r2의 값을 변경하면 v[3]의 값도 바뀐다.
    r2 = 'a';
    // *는 ~를 가르키는 포인터를 의미
    // &는 ~에 대한 참조자를 의미
    // 참조자는 할당된 하나의 메모리 공간에 다른 이름을 붙이는 것을 말한다.
    cout << *p << endl; // d
    cout << &p << endl; // d를 가르키는 포인터의 위치 출력
    cout << r1 << endl; // d 
    cout << r2 << endl; // d 
    cout << x << endl; // d
    
    // 만약 포인터변수의 포인터값을 없애고 싶다면 nuillptr 를 사용한다.
    char* p_null = nullptr;
    
    //T a[n]은 a[n]은 n개의 T로 이뤄진 배열
    //T* p에서 p는 T를 가르키는 포인터
    //T& r에서 r 은 T에 대한 참조자
    //T f(A)에서 f(A)는 A타입의 인자를 받아들여 T타입의 결과를 반환하는 함수

    int v1[10] = { 0,1,2,3,4,5,6,7,8,9 };
    int v2[10];
    //반복문의 i에서 전위증감이나 후위증감이나 결과에는 차이가 없으니 전위증감이 좀더 빠르다.
    for (auto i = 0; i != 10; ++i) {
        v2[i] = v1[i];
        cout << v2[i] << endl;
    }
    cout << "v2 print \n";
    int v3[] = { 0,1,2,3,4,5,6,7,8,9 };
    for (auto x : v3) {
        cout << x << "\n";
    }
    cout << "v3 print \n";
    for (auto x : { 10,21,32,43,54,65 }) {
        cout << x << "\n";
    }
    */
    //구조체 사용자정의 타입 16번째줄 부터 구조체사용
    /*
    double a = read_and_sum(5);
    cout << a;
    char* p;
    */
    
    
    int sum = read_and_sum(3);
    cout << sum << endl;
    
}