#pragma once
#include <limits.h>

namespace calcs{

enum errors{
ok = 0,
error_negative_power,
error_negative_factorial,
error_null_division,
error_overflow
};

int addition(int first, int second, int* result){
long long sum = (long long)first + second;
if (sum > INT_MAX || sum < INT_MIN){
return error_overflow;
}
*result = int(sum);
return ok;
}

int subtraction(int first, int second, int* result){
long long diff = (long long)first - second;
if (diff > INT_MAX || diff < INT_MIN){
return error_overflow;
}
*result = int(diff);
return ok;
}

int division(int first, int second, int* result){
if (second == 0){
return error_null_division;
}
long long div = (long long)first/second;
if (div > INT_MAX || div < INT_MIN){
return error_overflow;
}
*result = (int)div;
return ok;
}

int multiplication(int first, int second, int* result){
long long val = (long long)first * second;
if (val > INT_MAX || val < INT_MIN){
return error_overflow;
}
*result = (int)val;
return ok;
}

int factorial(int first, int* result){
if (first < 0){
return error_negative_factorial;
}
if (first == 0 || first == 1){
*result = 1;
return ok;
}
long long val = first;
int local_result = 0;
int err = factorial(first - 1, &local_result);
if (err != ok){
return err;
}
val *= (long long)local_result;
if (val > INT_MAX || val < INT_MIN){
return error_overflow;
}
*result = (int)val;
return ok;
}

int power(int first, int second, int* result){
if (second < 0){
return error_negative_power;
}
long long val = 1;
for (int i = 0; i < second; i++){
val *= first;
if (val > INT_MAX || val < INT_MIN){
return error_overflow;
}
}
*result = (int)val;
return ok;
}
}

