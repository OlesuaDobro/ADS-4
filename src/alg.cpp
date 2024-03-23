// Copyright 2021 NNTU-CS
int countpairs1(int *arr, int len, int value){
    int count = 0;
    for (int i = 0; i < len - 1; i++){
        for (int j = i + 1; j < len; j++){
            if (arr[i] + arr[j] == value)
                count++;
        }
    }
    return 0;
}
int countpairs2(int *arr, int len, int value){
    int count = 0;
    int left = 0;
    int right = len - 1;
    while (left < right){
        int sum = arr[left] + arr[right];
        if (sum == value){
            count++;
            left++;
            right--;
        } else if (sum < value)
            left++;
        else
            right--;
    }
    return 0;
}
int countpairs3(int *arr, int len, int value){
    int count = 0;
    for (int i = 0; i < len - 1; i++){
        int low = i + 1;
        int high = len - 1;
        while (low <= high){
            int mid = (low + high) / 2;
            int sum = arr[i] + arr[mid];
            if (sum == value){
                count++;
                break;
            }
            else if (sum < value)
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return 0;
}
