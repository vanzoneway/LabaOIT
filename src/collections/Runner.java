package collections;

public class Runner {
	public static void main(String[] args) {
		DoublyLinckedList<Integer> list = new DoublyLinckedList<Integer>();
		list.addFront(1);
		list.addBefore(1, 3);
		list.addEnd(4);
		list.print();
		
		
	}

}
