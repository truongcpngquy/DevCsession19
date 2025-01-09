#include<stdio.h> 
#include<string.h>

struct student{
	int id; 
	char studentName[25];
	char phoneNumber[11];
	int age; 
};
	void swap(int n,struct student s[] ){
		struct student temp;
		for(int i=0;i<n;i++){
			for(int j=0;j<n-i-1;j++){
				if(s[j].id>s[j+1].id){
					
				temp = s[j];
				s[j]=s[j+1]; 
				s[j+1]=temp;
				}
			} 
		}
	} 

int main(){
	 
	struct student s[5]={
	{5,"Truong Cong Quy","0147852369",18},
	{2,"Dang Hoang Bao","0258963147",18},
	{3,"Huynh Tran Phong","0123456789",18},
	{4,"Hua Nguyen Anh Khoa","9876543210",18},
	{1,"Nguyen Trong Nam","0369852147",18}
	};
	
	printf("Danh sach sinh vien\n");
	for(int i=0;i<5;i++){
		printf("Id: %d\n",s[i].id);
		printf("Ten sv: %s\n",s[i].studentName);
		printf("Sdt: %s\n",s[i].phoneNumber); 
		printf("Tuoi: %d\n",s[i].age);
		printf("\n");
	} 
	
	swap(s,n);
	
	printf("Danh sach sinh vien sau khi sap xep\n");
	for(int i=0;i<5;i++){
		printf("Id: %d\n",s[i].id);
		printf("Ten sv: %s\n",s[i].studentName);
		printf("Sdt: %s\n",s[i].phoneNumber); 
		printf("Tuoi: %d\n",s[i].age);
		printf("\n");
	} 
	
	return 0; 
}
