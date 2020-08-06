#include <iostream>
#include <cmath>
using namespace std;

#include <stdio.h>
#define X_MIN 0.0 // 積分範囲の最小値
#define X_MAX 200.0 // 積分範囲の最大値
#define DIV_NUM 100 // 積分範囲の分割数
// 積分対象関数.
float function (float x)
{
    float result;
    // result = x; // 一次直線
    result = abs(sqrt(pow(100, 2) - pow(x - 100, 2))); // 半円形
    return result;
}
// 台形公式による積分
double trapezoid()
{
    double integral; // 積分結果
    double h; // 積分範囲を n 個に分割したときの幅
    double x, dA;
    // === 積分開始 ===
    h = (X_MAX - X_MIN) / DIV_NUM; // 分割幅
    integral = 0.0; // 積分結果の変数を初期化
    x = X_MIN; // 積分範囲の変数を初期化
    for (int i=0; i<DIV_NUM; i++) {
        // 微小範囲の面積Δ A
        // dA = trapezoid(x, h);
        dA = (function(x)+function(x+h))*h/2.0;
        integral += dA; // Σ
        x += h;
    }
    // === 積分終了 ===
    return integral;
}
// 中点法による数値積分
double midPoint()
{
    double integral; // 積分結果
    double h; // 積分範囲を n 個に分割したときの幅
    double x, dA;
    // === 積分開始 ===
    h = (X_MAX - X_MIN) / DIV_NUM; // 分割幅
    integral = 0.0; // 積分結果の変数を初期化
    x = X_MIN; // 積分範囲の変数を初期化
    for (int i=0; i<DIV_NUM; i++) {
        // 微小範囲の面積Δ A
        dA = function(x + h/2.0) * h;
        integral += dA; // Σ
        x += h;
    }
    // === 積分終了 ===
    return integral;
}
// Simpson 法による積分
double Simpson()
{
    double integral; // 積分結果
    double h; // 積分範囲を n 個に分割したときの幅
    double x, dA;
    
    h = (X_MAX - X_MIN) / (2.0*DIV_NUM); // 分割幅
    x = X_MIN; // 積分範囲の変数を初期化
    integral = function(x); // 積分結果の変数の初期値
    for (int i=1; i<DIV_NUM; i++) {
        dA = 4.0*function(x+h) + 2.0*function(x+2.0*h);
        integral += dA; // Σ
        x += 2.0*h;
    }
    integral += ( 4.0*function(x+h) + function(x+2.0*h) );
    integral *= h/3.0;
    
    return integral;
}

int main()
{
    // double integral = trapezoid();
    // double integral = midPoint();
    double integral = Simpson();
    printf ("積分範囲=[%f,%f] 分割数=%d\n", X_MIN, X_MAX, DIV_NUM);
    printf ("積分結果= %lf\n", integral);
    // printf ("解析的に求めた結果 (底辺 100，高さ 100 の直角三角形)=%lf\n",
    // (X_MAX-X_MIN)*function(X_MAX)/2.0);
    printf ("解析的に求めた結果 (半径 100の半円形)=%lf\n",
    3.1415926 * 100 * 100 /2.0);
    return(0);
}

