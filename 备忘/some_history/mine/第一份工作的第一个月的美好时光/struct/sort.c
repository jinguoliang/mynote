/*
*filename:	sort.c
*author: 	Jinux
*create:	Fri 25 Oct 2013 09:08:13 AM
*提示:		真正的去享受过程,真正的去体会过程,然后,认真就来了,细心就来了,代码之美就来了,短小精悍就来了
*/

#include <stdio.h>
#include <stdlib.h>

void arrPrint(int *arr,int n){
	static int count=1;
	int i;
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\nit's %dst\n",count++);
}
void swap(int *arr,int a,int b)
{
	int tmp=arr[a];
	arr[a]=arr[b];
	arr[b]=tmp;
}
void heapAdjust(int *arr,int h,int n)
{
	int s,tmp;
	
	tmp=arr[h];
	for(s=2*h+1;s<n;s=2*h){
		if(s+1<n&&arr[s+1]>arr[s])
			s++;

		if(arr[s]<tmp)
			break;

		arr[h]=arr[s];
		h=s;
	}

	arr[h]=tmp;
}
void HeapSort(int *arr,int n)
{
	int i;

	for(i=n/2;i>=0;i--){
		heapAdjust(arr,i,n);
	}

	for(i=n-1;i>=0;i--){
		swap(arr,i,0);
		heapAdjust(arr,0,i);
	}

}

#define MAX 10
void Merge(int *a1,int start,int m,int end,int *a2)
{
	int i,j,k;
	for(i=start,j=m+1,k=start;i<=m&&j<=end;k++){
		if(a1[i]<a1[j])
			a2[k]=a1[i++];
		else
			a2[k]=a1[j++];
	}

	while(i<=m){
		a2[k++]=a1[i++];
	}

	while(j<=end){
		a2[k++]=a1[j++];
	}
}
void MSort(int *arr,int start,int end,int *arr1)
{
	int buffer[MAX];
	int m;

	if(end>start){
		m=(end+start)/2;

		MSort(arr,start,m,buffer);
		MSort(arr,m+1,end,buffer);
		Merge(buffer,start,m,end,arr1);
	}else if(end==start){
		arr1[start]=arr[start];
	}else{
		perror("can't get here");
	}
}
void MergeSort(int *arr,int n)
{
	MSort(arr,0,n-1,arr);
}

void shellSort(int *arr,int n)
{
	int increment=n;
	int i,j,tmp;
	do{
		increment=increment/3+1;

		for(i=increment;i<n;i++){
			if(arr[i]<arr[i-increment]){//下边的所有的间隔都是increment
				tmp=arr[i];
				for(j=i-increment;j>=0;j-=increment){
					if(arr[j]>tmp)
						arr[j+increment]=arr[j];  
					else{
						break;
					}
				}
				arr[j+increment]=tmp;   //腾出位子放下tmp
			}
		}
	}while(increment>1);
}
int main(int argc,char *argv[])
{
	int arr[10];
	int n=10,i;
	for(i=0;i<n;i++){
		arr[i]=n-1-i;
	}
	arrPrint(arr,n);
	MergeSort(arr,n);
	arrPrint(arr,n);

	





	return 0;
}

