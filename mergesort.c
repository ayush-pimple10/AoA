#include <stdio.h>
void merge(int arr[], int small, int mid, int large)
{
int temp[100];
int i = small, j = mid + 1, k = 0;
while (i <= mid && j <= large)
{
if (arr[i] <= arr[j]) {
temp[k++] = arr[i++];
}
else
{
temp[k++] = arr[j++];
}
}
while (i <= mid)
{
temp[k++] = arr[i++];
}
while (j <= large)
{
temp[k++] = arr[j++];
}

for (i = small, k = 0; i <= large; i++, k++)
{
arr[i] = temp[k];
}
}
void divide(int arr[], int small, int large)
{
if (small < large)
{
int mid = (small + large) / 2;
divide(arr, small, mid);
divide(arr, mid + 1, large);
merge(arr, small, mid, large);
}
}
int main()
{
int arr[] = {38, 274, 43, 36 ,9, 83, 8};
int n = sizeof(arr) / sizeof(arr[0]);
printf("Original array: ");
for (int i = 0; i < n; i++)
{
printf("%d ", arr[i]);
}
printf("\n");
divide(arr, 0, n - 1);

printf("Sorted array: ");
for (int i = 0; i < n; i++)
{
printf("%d ", arr[i]);
}
printf("\n");
return 0;
}
