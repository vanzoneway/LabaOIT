package collections;

import java.util.NoSuchElementException;

public class DoublyLinckedList<AnyType> {
	private ListNode<AnyType> front;
	
	private int size;
	
	private class  ListNode<AnyType>{
		AnyType data;
		ListNode<AnyType> next;
		ListNode<AnyType> prev;
	}
	public DoublyLinckedList() {
		front = null;
		size = 0;
	}
	public void addFront(AnyType x){
		if(isEmpty()) {
			front = new ListNode<AnyType>();
			front.data = x;
		}
		else {
			ListNode<AnyType> temp = front;
			front = new ListNode<AnyType>();
			front.data = x;
			front.next = temp;
			temp.prev = front;
		}
		size++;
	}
	public void addEnd(AnyType x){
		if(isEmpty()) {
			front = new ListNode<AnyType>();
			front.data = x;
		}else {
			ListNode<AnyType> temp = front;
			while(temp.next!= null) {
				temp = temp.next;
			}
			ListNode<AnyType> lastSlot = new ListNode<AnyType>();
			temp.next = lastSlot;
			lastSlot.data = x;
			lastSlot.prev = temp;		
		}
		size++;
	}
	public void addBefore(AnyType x, AnyType y){
		if(isEmpty()) {
			throw new NoSuchElementException("Element "+ x.toString()+" not found");
		}
		ListNode<AnyType> current = front;
		while( current!= null && !current.data.equals(x)) {
			current = current.next;
		}
		if (current == null) {
			throw new NoSuchElementException("Element " + x.toString()+ " not found");
			
		}
		ListNode<AnyType> newNode =  new ListNode<AnyType>();
		newNode.data = y;
		newNode.prev = current.prev;
		newNode.next = current;
		if(current.prev!= null) {
			current.prev.next = newNode;
		}else {
			front = newNode;
			current.prev = newNode; 
		}
		size++;
		
	}
	public void addAfter(AnyType x, AnyType y){
		if (isEmpty()) {
			throw new NoSuchElementException("Element " + x.toString()+ " nor found");
			
		}
		ListNode<AnyType> current = front;
		while(current!=null && !current.data.equals(x)) {
			current = current.next;
		}
		if(current == null) {
		throw new NoSuchElementException("Element "+ x.toString()+ " not found");
		}	
		ListNode<AnyType> newNode = new ListNode<AnyType>();
		newNode.data = y;
		newNode.prev = current;
		newNode.next = current.next;
		if(current.next!=null) {
			current.next.prev = newNode;
			
		}
		current.next = newNode;
		size++;
	}
	public void remove(AnyType x) {
		if(isEmpty()) {
			throw new NoSuchElementException("Element "+ x.toString()+ " not found");
			
		}
		if(front.data.equals(x)) {
			front = front.next;
			return;
		}
		ListNode<AnyType> current = front;
		while(current!= null && !current.data.equals(x)) {
			current = current.next;
		}
		if (current == null) {
            throw new NoSuchElementException("Element " + x.toString() + " not found");
		}
		if(current.next!= null) {
			current.next.prev = current.prev;
		}
		current.next.prev = current.next;
		}
	public boolean isEmpty() {
		
		return size == 0;
	}
	public int size() {
		return size;
	}
	public void print() {
		ListNode<AnyType> current = front;
		while(current!=null) {
			System.out.print(current.data+ " ");
			current = current.next;
		}
	}




}
