#include <iostream>

#include <vector>

using namespace std;

/*
10���� ���Ҹ� �Է¹ް� �Է¹����� �����ϱ�
���� ������ ��µǾߵȴ�
��������� ����  
*/

int number;
int heap[1000001];

void heapify(int i){
	//�����ڽĳ�� ����Ŵ  
	int c =2*i+1;
	//������ �ڽ� ��尡 �ְ�, ���� �ڽĳ�庸�� ũ�ٸ�  
	if(c < number && heap[c] <heap[c+1]){
		c++;
	}
	//�θ𺸴� �ڽ��� ũ�ٸ� ��ȯ 
	if(heap[i]<heap[c]){
		int temp=heap[i];
		heap[i]=heap[c];
		heap[c]=temp;
	}
	//number/2 ��ŭ�� �����ϸ�� 
	if(c<=number/2) heapify(c);
}
int main(void){
	cin >> number;
	for(int i=0;i<number;i++){
		cin >>heap[i];
	}
	//���� �����Ѵ� 
	for(int i=number/2;i>=0;i--){
		heapify(i);
	}
	//������ �����Ѵ�  
	for(int i=number-1;i>=0;i--){
		for(int j=0;j<number;j++){
			cout << heap[j] << ' ';
		}
		cout << '\n';
		int temp=heap[0];
		heap[0]=heap[i];
		heap[i]=temp;
		int root=0;
		int c=1;
		
		do{
			c=2*root+1;
			//�ڽ��߿� ��ū �� ã��  
			if(c < i-1 && heap[c] < heap[c+1]){
				c++;
			}
			//�θ𺸴� ũ�ٸ� ��ȯ  
			if(c<i && heap[root] < heap[c]){ 
				temp=heap[root];
				heap[root]=heap[c];
				heap[c]=root;		
			}
			root=c;
		
		}while(c<i);
	
	}
	
}
