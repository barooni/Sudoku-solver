#include <stdio.h>
enum boolean{f,t};
void print_arr(int arr[][10]){
    int i,j;
    printf("\n");
    for(i=1;i<10;i++){
        for(j=1;j<10;j++)
            printf("%d ",arr[i][j]);
        printf("\n");
    }
}
int solvenext(int arr[][10],int i,int j){
    if(j<9)
        return solve(arr,i,j+1);
    else
        return solve(arr,i+1,1);
}
int check(int arr[][10]){
    int i,j,k,l;
  //check Vertical & Horizontal
  for (i= 1; i < 10; ++i)
  {
    for (j = 1; j < 10; ++j)
    {
      for (k = 1; k < 10; ++k)
      {
        if (arr[i][j]==arr[i][k]&&k!=j&&arr[i][j]+arr[i][k]>0)
        {
          return f;
        }
        if (arr[i][j]==arr[k][j]&&k!=i&&arr[i][j]+arr[k][j]>0)
        {
          return f;
        }
      }
    }
  }

  //check each 9 square
  for (i = 1; i < 10; ++i)
  {
    for (j = 1; j < 10; ++j)
    {
        if(arr[i][j]!=0)
            for (k = (((i-1)/3)*3)+1; k <= (((i-1)/3)+1)*3 ; ++k)
            {
              for (l = (((j-1)/3)*3)+1; l<= (((j-1)/3)+1)*3 ; ++l)
              {
                if (arr[i][j]==arr[k][l]&&!(k==i&&l==j)&&arr[k][l]>0)
                {
                  return f;
                }
              }
            }
    }
  }
  return t;
}//end of check


int solve(int arr[][10],int n,int m){
    int i,j,k;
    
    if(check(arr)!=t)
        return f;
    if(n==10&&m==1){
        print_arr(arr);
        return t;
    }
    if(arr[n][m]==0)
        for(k=1;k<10;k++){
            arr[n][m]=k;
            if(solvenext(arr,n,m)==t)
                ;
            arr[n][m]=0;
            }
    else if(solvenext(arr,n,m)==t)
        ;
}

main(){
    int arr[10][10],c,i=1,j=1;
       char filename[100];
    printf("Please enter the file contain Sudoku to solve :");
   	scanf("%s",filename);
   	FILE *file = fopen ( filename, "r" );
   	if ( file != NULL )
   	{
      	while((c=getc(file))!=EOF){
      		if (c!='\n')
      		{
      			arr[i][j]=c-'0';
      			j++;
      		}
      		else
      		{
      			i++;
      			j=1;
      		}
   		}
	}
	else
		printf("file not exist!\n");
        if(solve(arr,1,1)==f)
            printf("\nit's not solved!\n");
} 
