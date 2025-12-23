#include<stdio.h>
#define Max 20

int hasTable[Max];

int m;

void insert(int key){
    int index = key%m;
    if(hasTable[index]==-1){
        hasTable[index]=key;
    }
    else{
        int i=1;
        while(hasTable[(index+1)%m]!=-1){
            i++;
        }
        hasTable[(index+1)%m]=key;
    }

}

void display(){
    printf("\nHashTable: \n");
    for(int i=0; i<m; i++){
        if(hasTable[i]!=-1){
            printf("Address %d : %d \n",i , hasTable[i]);

        }
        else{
            printf("Address %d :Empty \n",i);

        }
    }
}
int main(){
    int n, key;
    printf("Enter size of hash table(m): ");
    scanf("%d",&m);

    printf("Enter number of employee recoreds: ");
    scanf("%d", &n);

    for(int i=0; i<m; i++){
        hasTable[i]=-1;
  }
  printf("Enter %d employee keys (4-digit): \n",n);
  for(int i=0; i<n; i++){
    scanf("%d",&key);
    insert(key);
  }
  display();
  return 0;
}
