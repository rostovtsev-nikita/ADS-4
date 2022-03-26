//Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
int count = 0;
for (int i = 0; i < len; i++)
for (int j = 0; j < len; j++)
if (i != j)
if (arr[i] + arr[j] == value)
count++;
return count / 2;
}
int countPairs2(int *arr, int len, int value) {
int count = 0;
for (int i = 0; i < len; i++)
for (int j = len - 1; j > i; j--)
if (arr[i] + arr[j] == value)
count++;
return count;
}
int binar(int *arr, int l, int r, int x) {
int lft = l, rht = r, mid = 0; bool f = 0;
while (lft <= rht)  {
mid = (lft + rht) / 2;
if (arr[mid] == x) {
return binar(arr, l, mid - 1, x) + binar(arr, mid + 1, r, x) + 1;
}
if (x < arr[mid])
rht = mid - 1;
else
lft = mid + 1;
}
return 0;
}
int countPairs3(int *arr, int len, int value) {
int count = 0;
for (int i = 0; i < len; i++) {
count += binar(&arr[i + 1], 0 , len - i, value - arr[i]);
}
return count;
}
