#include <stdio.h>
//O(n)

int num=9;
int heap[9]={7,6,5,8,3,5,9,1,6};

int main(void){
	
	//��ü Ʈ�� ������ �ִ������� ���� 
	for(int i=1; i<num;i++){
		
		int c =i;
		
		do{
			int root=(c-1)/2;
			if(heap[root] < heap[c]){
				int temp =heap[root];
				heap[root] =heap[c];
				heap[c]=temp;
			}
			c=root;
		}while(c !=0);
		
	}
	
	//ũ�⸦ �ٿ����� �ݺ������� ���� ����(��������) 
	for (int i=num-1;i>=0;i--){
		//����ū���� �ǵڷ� ������  
		int temp=heap[0];
		heap[0]=heap[i];
		heap[i]=temp;
		
		int root= 0;
		int c=1; 
		
		do{
			c=2*root+1;
			//�ڽ��߿� �� ū�� ã��  
			if(heap[c] < heap[c+1] && c<i-1){
				c++;
			}
			//�θ�(��Ʈ)���� �ڽ��� ũ�ٸ� ��ȯ
			if(c<i && heap[root]<heap[c]){
				int temp =heap[root];
				heap[root] =heap[c];
				heap[c]=temp;
			}
			root= c;
		}while(c <i);
	} 
	
	//������
	for(int i=0;i<num;i++){
		printf("%d",heap[i]);
	} 
	
	
	
}
