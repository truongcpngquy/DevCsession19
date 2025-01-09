#include<stdio.h> 
#include<string.h>

struct student{
	int id; 
	char studentName[25];
	char phoneNumber[11];
	int age; 
}; 
void deleteStudent(int id,struct student s[],int *currentLength){
	int found = 0;
    
    for (int i = 0; i < *currentLength; ++i) {
        if (s[i].id == id) {
            found = 1;
            
            for (int j = i; j < *currentLength - 1; ++j) {
                s[j] = s[j + 1];
            }
            
            (*currentLength)--;
            break;
        }
    }

    if (!found) {
        printf("Sinh vien co ID %d khong ton tai trong danh sach!\n", id);
    }
}

int main(){
	struct student s[5]={
	{1,"Truong Cong Quy","0147852369",18},
	{2,"Dang Hoang Bao","0258963147",18},
	{3,"Huynh Tran Phong","0123456789",18},
	{4,"Hua Nguyen Anh Khoa","9876543210",18},
	{5,"Nguyen Trong Nam","0369852147",18}
	};
	int currentLength =5; 
	printf("Danh sach sinh vien\n");
	for(int i=0;i<5;i++){
		printf("Id: %d\n",s[i].id);
		printf("Ten sv: %s\n",s[i].studentName);
		printf("Sdt: %s\n",s[i].phoneNumber); 
		printf("Tuoi: %d\n",s[i].age);
		printf{"\n"}; 
	} 
	int deleteID;
	printf("Nhap Id sv muon xoa: ");
	scanf("%d",&deleteID);
	
	deleteStudent(deleteID,s,&currentLength);
	
		printf("Danh sach sinh vien sau khi xoa \n");
	for(int i=0;i<currentLength;i++){
		printf("Id: %d\n",s[i].id);
		printf("Ten sv: %s\n",s[i].studentName);
		printf("Sdt: %s\n",s[i].phoneNumber); 
		printf("Tuoi: %d\n",s[i].age);
		printf{"\n"}; 
	} 
	 
	
	return 0; 
}
