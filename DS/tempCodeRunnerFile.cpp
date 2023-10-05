int linearSearch(int arr[],int n,int key){
for (int i = 0; i < n; i++)
{
    if (key == arr[i])
    {
        cout<<"LINEAR SEARCH/n";
        return i;
    }
}
return -1;
}