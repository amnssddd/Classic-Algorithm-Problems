//�����㷨�����Ԫ������
#include<iostream>
using namespace std;

int getCount(int nums[], int target, int low, int high)
{
	int count = 0;
	for(int i=low; i<=high; i++){
		if(target==nums[i]){
			count++;
		}
	}
	return count;
}

int majorityElement(int nums[], int low, int high)
{
	//�ݹ���ֹ����
	if(low == high){
		return nums[low];
	}

	int mid = (low+high)/2;
	int left = majorityElement(nums, low, mid);
	int right = majorityElement(nums, mid+1, high);
	if(left == right){
		return left;
	}
	int leftCount = getCount(nums, left, low, high);
	int rightCount = getCount(nums, right, low, high);
	return (leftCount>rightCount)?left:right;
}

int main()
{
	int nums[] = { 3, 3, 4, 2, 2, 2, 2, 4, 4 };
	int len = sizeof(nums)/sizeof(nums[0]);
	int res = majorityElement(nums, 0, len-1);
	cout<<"�����г��ִ�������Ԫ��Ϊ"<<res<<endl;
	return 0;
}