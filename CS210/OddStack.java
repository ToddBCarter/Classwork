import java.util.Arrays;
import java.io.*;
public class OddStack
{
    private static final int DEFAULT_CAPACITY = 10;
    private int oddSize = 0;
    private int oddElements[];
	private int evenSize = 0;
    private int evenElements[];

    public OddStack() {
        oddElements = new int[DEFAULT_CAPACITY];
		evenElements = new int[DEFAULT_CAPACITY];
    }

    public void push(int e) {
		System.out.println("Pushing: " + e);
		if(oddSize + evenSize == DEFAULT_CAPACITY){
			System.out.println("Error: OddStack is full");
		}
		else
		{
			if(e % 2 == 1){
				oddElements[oddSize] = e;
				oddSize++;
			}else{
				evenElements[evenSize] = e;
				evenSize++;
			}
		}
    }

    public int pop() {
		if(oddSize + evenSize == 0){
			System.out.println("Error: OddStack is empty");
			return 0;
		}
		int temp = 0;
		if(oddSize > 0){
			temp = oddElements[--oddSize];
		}else{
			temp = evenElements[--evenSize];
		}
		return temp;
    }

    @Override public String toString()
    {
		StringBuilder sb = new StringBuilder();
		sb.append('[');
		for(int i = 0; i < evenSize; i++){
			sb.append(evenElements[i]);
			if(i < evenSize - 1 | oddSize > 0){
				sb.append(',');
			}
		}
		for(int i = 0; i < oddSize; i++){
			sb.append(oddElements[i]);
			if(i < oddSize - 1){
				sb.append(',');
			}
		}
		sb.append(']');
		return sb.toString();
    }
}
