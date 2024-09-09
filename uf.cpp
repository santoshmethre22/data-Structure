int find(int A[],int X)
{
    if(X==A[X]){
        return X;
    }
    
    return A[X]=find(A,A[X]);
}
void unionSet(int A[],int X,int Z)
{
	
	int x_p= find(A,X);
	int z_p=find(A,Z);
	
	if(x_p!=z_p){
	    A[x_p]=z_p;
	}
	
	
	
}