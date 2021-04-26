import java.util.*;

public class Main{
	
	public static Scanner scn = new Scanner(System.in);
	
	
	public static void display(int[][] arr)
	{
        for(int i = 0; i < arr.length; i++){
        	
            for(int j = 0; j < arr[0].length; j++){
            	
                System.out.print(arr[i][j] + " ");
            }
            System.out.println();
    	}
	}
   
	//get 1d array
	public static int[] getOneDArray(int[][] a,int s)
	{
		int minr = s - 1;
		int minc = s - 1;
		int maxr = a.length - s;
		int maxc = a[0].length - s;
		
		int sz = 2 * (maxr - minr + maxc - minc);
		
		int[] oneDArray = new int[sz];
		
		int indx = 0;
		//left
		for(int i = minr;i<=maxr;i++)
		{
			oneDArray[indx] = a[i][minc];
			indx++;
		}
		minc++;
		
		//bottom
		for(int j = minc ;j<=maxc ;j++)
		{
			oneDArray[indx] = a[maxr][j];
			indx++;
		}
		maxr--;
		
		//right
		for(int i =maxr;i>=minr;i--)
		{
			oneDArray[indx] = a[i][maxc];
			indx++;
		}
		maxc--;
		
		//top
		for(int j = maxc;j>=minc;j--)
		{
			oneDArray[indx] = a[minr][j];
			indx++;
		}
		minr++;
		
		return oneDArray;
		
	}
	
	//reverse 1d array
	public static void reverse(int[] oneDArray,int left,int right)
	{
		while(left < right)
		{
			int temp = oneDArray[left];
			oneDArray[left] = oneDArray[right];
			oneDArray[right] = temp;
	
			left++;
			right--;
		}
	}
	
	
	//rotate onedarraay
	public static void rotate(int[] oneDArray,int r)
	{
		r = r % oneDArray.length;
		
		if(r<0)
		{
			r = r + oneDArray.length;
		}
		
		int n = oneDArray.length;
		
		reverse(oneDArray,0,n - 1 - r);
 		reverse(oneDArray,n - r,n - 1);
		reverse(oneDArray,0,n - 1);
			
	}
	
	public static void setOneDArray(int[][] a,int[] oneDArray,int s)
	{
		int minr = s - 1;
		int minc = s - 1;
		int maxr = a.length - s;
		int maxc = a[0].length - s;
		
		int sz = 2 * (maxr - minr + maxc - minc);
		
		
		int indx = 0;
		//left
		for(int i = minr;i<=maxr;i++)
		{
			a[i][minc] = oneDArray[indx];
			indx++;
		}
		minc++;
		
		//bottom
		for(int j = minc ;j<=maxc ;j++)
		{
			a[maxr][j] = oneDArray[indx];
			indx++;
		}
		maxr--;
		
		//right
		for(int i =maxr;i>=minr;i--)
		{
			a[i][maxc] = oneDArray[indx];
			indx++;
		}
		maxc--;
		
		//top
		for(int j = maxc;j>=minc;j--)
		{
			a[minr][j] = oneDArray[indx];
			indx++;
		}
		minr++;
		
	}
	
	//shell rotate
	public static void ringShellRotate(int[][] a,int s,int r){
		
		//get array
		int[] oneDArray = getOneDArray(a,s);
		
		//rotate oneDaray
		rotate(oneDArray,r);
		
		//set it again in sth shell of array
		setOneDArray(a,oneDArray,s);
	}
	
	
	public static void input(int[][] a)
	{
		for(int i = 0;i < a.length;i++)
		{
			for(int j = 0; j < a[i].length; j++)
			{
				a[i][j] = scn.nextInt();
			}
		}
	}
	
	public static void main(String[] args)
	{
		int n = scn.nextInt();
		
		int m = scn.nextInt();
		
		int[][] a = new int[n][m];
		
		input(a);
		
		int s = scn.nextInt();
		
		int r = scn.nextInt();
		
		ringShellRotate(a,s,r);
		
		display(a);
	}
}
