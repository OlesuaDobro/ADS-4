// Copyright 2021 NNTU-CS
#include <alg.h>
#include <iostream>
#include <cstdint>
int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}
int countPairs2(int *arr, int len, int value) {
    int count = 0;
    int left = 0;
    int right = len - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == value) {
            count++;
            left++;
            right--;
        } else if (sum < value) {
            left++;
        } else {
            right--;
        }
    }
    return count;
}
int countPairs3(int* arr, int len, int value) {
    int count = 0, y = 0, left = 0, right = len;
    for (int i = 0; i < (len - 1); i++) {
        if (arr[i] > value) {
            break;
        }
        left = i;
        right = len - 1;
        while (left < right) {
            y = left + ((right - left) / 2);
            if (left == right) {
                break;
            }
            if ((arr[i] + arr[y]) > value) {
                for (int n = (y - 1); n >= left; n--) {
                    right = n + 1;
                    if (arr[y] != arr[n]) {
                        break;
                    }
                }
                if (right - left == 1) {
                    break;
                }
            }
            if ((arr[i] + arr[y]) < value) {
                for (int n = (y + 1); n <= right; n++) {
                    left = n - 1;
                    if (arr[y] != arr[n]) {
                        break;
                    }
                }
                if (right - left == 1) {
                    break;
                }
            }
            if ((arr[i] + arr[y]) == value) {
                int t = right;
                for (int n = (y + 1); n <= t; n++) {
                    right = n - 1;
                    if (arr[y] != arr[n]) {
                        break;
                    }
                }
                t = left;
                for (int n = (y - 1); n >= t; n--) {
                    left = n + 1;
                    if (arr[y] != arr[n]) {
                        break;
                    }
                }
                break;
            }
        }
        for (int j = left; j <= right; j++) {
            if (((arr[i] + arr[j]) == value) && (i != j)) {
                count++;
            }
        }
    }
    return count;
}
